#ifndef ARMOR_CENTER
#define ARMOR_CENTER
#include <array>
#include <vector>
#include <pybind11/pybind11.h>
#include <opencv2/opencv.hpp>

class Armor
{
public:
    void Yolov5_Run();                 // 调用yolo5识别脚本
    bool IfArmor(std::vector<double>); // 判断是否为装甲板(排除是误识别的情况)
    void GetArmorCenter();             // 获得yolo5识别的装甲板的中心像素坐标
private:
    std::vector<double> armor_center;
};
#endif ARMOR_CENTER