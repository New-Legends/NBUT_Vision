#ifndef KALMAN_h
#define KALMAN_h

#include <iostream>
#include <math.h>
#include <fstream>
#include <array>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <pybind11/pybind11.h>
#include <opencv4/opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include "ArmorCenter.h"
#include "AngleSolve.h"

class Kalman
{
public:
	Eigen::MatrixXf statePre;			   // predicted state (x'(k)): x(k)=A*x(k-1)+B*u(k)
	Eigen::MatrixXf stateOpt;			   // corrected state (x(k)): x(k)=x'(k)+K(k)*(z(k)-H*x'(k))
	Eigen::MatrixXf transMat;			   // state transition matrix (A)
	Eigen::MatrixXf transMat_slow;		   // state transition matrix (A)
	Eigen::MatrixXf contrMat;			   // control matrix (B) (not used if there is no control)
	Eigen::MatrixXf measureMat;			   // measurement matrix (H)
	Eigen::MatrixXf processNoiseCov;	   // process noise covariance matrix (Q)
	Eigen::MatrixXf processNoiseCov_Slow;  // process noise covariance matrix (Q)  SLOW speed
	Eigen::MatrixXf processNoiseCov_Fast;  // process noise covariance matrix (Q)  Fast speed
	Eigen::MatrixXf measureNosiseCov;	   // measurement noise covariance matrix (R)
	Eigen::MatrixXf measureNosiseCov_Slow; // measurement noise covariance matrix (R) SLOW speed
	Eigen::MatrixXf measureNosiseCov_Fast; // measurement noise covariance matrix (R) Fast speed
	Eigen::MatrixXf errorCovpre;		   // priori error estimate covariance matrix (P'(k)): P'(k)=A*P(k-1)*At + Q)
	Eigen::MatrixXf Kgain;				   //  Kalman gain matrix (K(k)): K(k)=P'(k)*Ht*inv(H*P'(k)*Ht+R)
	Eigen::MatrixXf errorCovOpt;		   //   posteriori error estimate covariance matrix (P(k)): P(k)=(I-K(k)*H)*P'(k)

	/*
	@breif Standard Kalman filter
	*/
	Eigen::MatrixXf &predict();

	// updates the predicted state from the measurement
	MatrixXf &correct(MatrixXf &measurement);

	/*
	@brief Re-initializes Kalman filter.
	@param dynamParams Dimensionality of the state.//状态矩阵的维度
	@param measureParams Dimensionality of the measurement.测量矩阵的维度
	@param controlParams Dimensionality of the control vector.控制矩阵的维度
	*/
	void init(int dynamParams, int measureParams, int controlParams);

	// temporary Mat
	MatrixXf tmp1;
	MatrixXf tmp2;
	MatrixXf tmp3;
	MatrixXf tmp4;
	MatrixXf tmp5; // innovation sequence vk 创新序列vk
private:
	int cP;
}
#endif KALMAN