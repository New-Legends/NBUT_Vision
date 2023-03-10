#ifndef ANGLE_SOLVER
#define ANGLE_SOLVER

#include <iostream>
#include <math.h>
#include <fstream>
#include <array>
#include <vector>
#include <pybind11/pybind11.h>
#include <opencv2/opencv.hpp>

class AngleSolver
{
public:
    AngleSolver()=default;
    ~AngleSolver()=default;
    void GetCameraParams();
    void PnPSolve();
    void AngleSolve();

    
    cv::Point3d solvePoint;// 解算结果向量

private:
    // Camera params
    std::array<cv::Point2d, 4> imagePoints;
    std::array<cv::Point3d, 4> worldPoints;
    
    // 旋转向量
    cv::Mat rotation_vector;
    // 平移向量
    cv::Mat translation_vector;

    // 相机内参矩阵和畸变系数均由相机标定结果得出
  // 相机内参矩阵
  cv::Mat camera_matrix = (cv::Mat_<double>(3, 3) << 505.1666120558573, 0, 310.1660811401983, 0, 488.6105193422827,
                           249.9495562500046, 0, 0, 1);
  // 相机畸变系数
  cv::Mat dist_coeffs = (cv::Mat_<double>(5, 1) << 0.1311093141581356, -0.9654453502019078, 0.001118708198552768,
                         -0.001126801336773416, 2.286059640823912);
}

#endif