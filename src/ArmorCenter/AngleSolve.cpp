#include <iostream>
#include <math.h>
#include <fstream>
#include <array>
#include <vector>
#include <pybind11/pybind11.h>
#include <opencv4/opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include "ArmorCenter.h"
#include "AngleSolve.h"

// 获取相机外参和畸变参数
void AngleSolver::GetCameraParams()
{
    // 读取XML文件
    cv::FileStorage fs("/home/davi/rmVison4.0/DataExchange/camera_params.xml", cv::FileStorage::READ);

    // 读取Y_DISTANCE_BETWEEN_GUN_AND_CAM
    double y_distance = fs["Y_DISTANCE_BETWEEN_GUN_AND_CAM"];
    std::cout << "Y_DISTANCE_BETWEEN_GUN_AND_CAM: " << y_distance << std::endl;

    // 读取CAMERA_MATRIX_1（内参1）
    cv::Mat camera_matrix1;
    fs["CAMERA_MATRIX_1"] >> camera_matrix1;
    std::cout << "CAMERA_MATRIX_1:" << std::endl;
    std::cout << camera_matrix1 << std::endl;

    // // 读取CAMERA_MATRIX_2（内参2）
    // cv::Mat camera_matrix2;
    // fs["CAMERA_MATRIX_2"] >> camera_matrix2;
    // std::cout << "CAMERA_MATRIX_2:" << std::endl;
    // std::cout << camera_matrix2 << std::endl;

    // 读取DISTORTION_COEFF_1（畸变参数1）
    cv::Mat distortion_coeff1;
    fs["DISTORTION_COEFF_1"] >> distortion_coeff1;
    std::cout << "DISTORTION_COEFF_1:" << std::endl;
    std::cout << distortion_coeff1 << std::endl;

    // // 读取DISTORTION_COEFF_2（畸变参数2）
    // cv::Mat distortion_coeff2;
    // fs["DISTORTION_COEFF_2"] >> distortion_coeff2;
    // std::cout << "DISTORTION_COEFF_2:" << std::endl;
    // std::cout << distortion_coeff2 << std::endl;

    AngleSolver::intrinsic_matrix = camera_matrix1;
    AngleSolver::Extrinsics_matrix = distortion_coeff1;
    // 关闭文件
    fs.release();
}

// 角度解算函数，解算出相机坐标系
void AngleSolver::AngleSolve()
{
    cv::solvePnP();
}

class PNPCoordinate
{
public:
public:
    template <class T>
    bool PNPSolve(T inputArray) noexcept;
};

template <class T>
bool PNPCoordinate::PNPSolve(T inputArray) noexcept
{
    // pnp求解
    for (size_t i = 0; i < 4; ++i)
    {
        imagePoints[i] = inputArray[i];
    }

    // imagePoints[0] = (cv::Point2d(152, 92));
    // imagePoints[1] = (cv::Point2d(426, 94));
    // imagePoints[2] = (cv::Point2d(428, 394));
    // imagePoints[3] = (cv::Point2d(126, 380));
    worldPoints[0] = (cv::Point3d(-100.0f, -100.0f, 0)); // 左上角
    worldPoints[1] = (cv::Point3d(+100.0f, -100.0f, 0));
    worldPoints[2] = (cv::Point3d(+100.0f, +100.0f, 0));
    worldPoints[3] = (cv::Point3d(-100.0f, +100.0f, 0));

    // 默认ITERATIVE方法，可尝试修改为EPNP（CV_EPNP）,P3P（CV_P3P）
    try
    {
        solvePnP(worldPoints, imagePoints, camera_matrix, dist_coeffs, rotation_vector, translation_vector, 0,
                 cv::SOLVEPNP_ITERATIVE);
    }
    catch (const std::exception &e)
    {
        std::cerr << "某些坐标可能还没有初始值\n\n\n";
        std::cerr << e.what() << '\n';
        return false;
    }

    cv::Mat Rvec;
    cv::Mat_<float> Tvec;
    rotation_vector.convertTo(Rvec, CV_32F);    // 旋转向量转换
    translation_vector.convertTo(Tvec, CV_32F); // 平移向量转换格式

    cv::Mat_<float> rotMat(3, 3);//相机位姿
    cv::Rodrigues(Rvec, rotMat);
    // 旋转向量转成旋转矩阵
    // std::cout << "旋转矩阵" << rotMat << "\n\n\n";

    cv::Mat P_oc;
    P_oc = -rotMat.inv() * Tvec;
    solvePoint.x = P_oc.at<float>(0);
    solvePoint.y = P_oc.at<float>(1);
    solvePoint.z = P_oc.at<float>(2);
    // std::cout << solvePoint;
    return true;
}