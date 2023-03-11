#include <iostream>
#include <eigen3/Eigen/Dense>
#include "kalman.h"

// 初始化卡尔曼参数矩阵
void Kalman::init(int DP, int MP, int CP)
{
    CP = std::max(CP, 0);

    statePre = Eigen::MatrixXf::Zero(Dp, 1);                   // predicted state (x'(k)): x(k)=A*x(k-1)+B*u(k)
    stateOpt = Eigen::MatrixXf::Zero(DP, 1);                   // corrected state (x(k)): x(k)=x'(k)+K(k)*(z(k)-H*x'(k))
    transMat = Eigen::MatrixXf::Identity(DP, DP);              // A
    transMat_slow = Eigen::MatrixXf::Identity(DP, DP);         // A
    processNoiseCov = Eigen::MatrixXf::Identity(DP, DP);       // Q
    processNoiseCov_Slow = Eigen::MatrixXf::Identity(DP, DP);  // Q Slow_speed
    processNoiseCov_Fast = Eigen::MatrixXf::Identity(DP, DP);  // Q Fast_speed
    measureMat = Eigen::MatrixXf::Zero(MP, DP);                // H
    measureNosiseCov = Eigen::MatrixXf::Identity(MP, MP);      // R
    measureNosiseCov_Slow = Eigen::MatrixXf::Identity(MP, MP); // R Slow_speed
    measureNosiseCov_Fast = Eigen::MatrixXf::Identity(MP, MP); // R Fast_speed

    errorCovpre = MatrixXf::Zero(DP, DP); //(P'(k)): P'(k)=A*P(k-1)*At + Q)
    errorCovOpt = MatrixXf::Zero(DP, DP); //(P(k)) : P(k) = (I - K(k)*H)*P'(k)
    Kgain = MatrixXf::Zero(DP, MP);       //(K(k)) : K(k) = P'(k)*Ht*inv(H*P'(k)*Ht + R)

    if (CP > 0)
        contrMat = MatrixXf::Zero(DP, CP);

    tmp1 = MatrixXf::Zero(DP, DP);

    // tmp2 = MatrixXf::Zero(MP, DP);
    tmp2 = MatrixXf::Zero(DP, MP);
    tmp3 = MatrixXf::Zero(MP, MP);
    // tmp4 = MatrixXf::Zero(MP, DP);
    tmp4 = MatrixXf::Zero(DP, MP);
    tmp5 = MatrixXf::Zero(MP, 1);
    cP = CP;
}

Eigen::&Kalman::predict()
{
    // update the state: x'(k) = A*x(k) + B*u
    if (cP > 0)
    {
        statePre = transMat * stateOpt + contrMat * stateOpt(2, 0);
    }
    else
    {
        statePre = transMat * stateOpt;
    }
    // cout << stateOpt(2, 0) << endl;

    // update error covariance matrices : tmp1 = A*P(k)
    tmp1 = transMat * errorCovOpt;

    // P'(k) = temp1*At + Q
    errorCovpre = tmp1 * transMat.transpose() + processNoiseCov;

    // iteration
    stateOpt = statePre;
    errorCovOpt = errorCovpre;

    return statePre;
}

MatrixXf &Kalman::correct(MatrixXf &measurement)
{
    // tmp2 = H*P'(k)
    // tmp2 = measureMat * errorCovpre;
    tmp2 = errorCovpre * measureMat.transpose();

    // tmp3 = tmp2*H + R
    // tmp3 = tmp2*measureMat.transpose() + measureNosiseCov;
    tmp3 = measureMat * tmp2 + measureNosiseCov;

    // tmp4 = inv(tmp3)*temp2 = Kt(k) /----/ (K(k)): K(k)=P'(k)*Ht*inv(H*P'(k)*Ht+R)
    // tmp4 = tmp3.inverse() * tmp2;
    tmp4 = tmp2 * tmp3.inverse();

    // K(k)
    // Kgain = tmp4.transpose();
    Kgain = tmp4;

    // tmp5 = z(k) - H*x'(k)
    tmp5 = measurement - measureMat * statePre;

    // x(k) = x'(k) + K(k)*temp5
    stateOpt = statePre + Kgain * tmp5;

    // P(k) = P'(k) - K(k)*H*P'(k)
    // errorCovOpt = errorCovpre - Kgain *tmp2;
    errorCovOpt = errorCovpre - Kgain * measureMat * errorCovpre;

    return stateOpt;
}