#include <iostream>
#include <math.h>
#include <fstream>
#include <array>
#include <vector>
#include <pybind11/pybind11.h>
#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include "ArmorCenter.h"

void Armor::Yolov5_Run()
{
    Py_Initialize();
    if (!Py_IsInitialized())
    {
        std::cout << "python init fail" << std::endl;
        return;
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/davi/rmVison4.0/scripts')");
    // PyRun_SimpleString("sys.path.append('./scripts')");//使用相对路径有问题

    PyObject *pModule = PyImport_ImportModule("detect");
    if (pModule == NULL)
    {
        std::cout << "module not found" << std::endl;
        return;
    }

    PyObject *pFunc1 = PyObject_GetAttrString(pModule, "run");
    PyObject *pFunc2 = PyObject_GetAttrString(pModule, "parse_opt");
    PyObject *pFunc3 = PyObject_GetAttrString(pModule, "main");

    PyObject_CallObject(pFunc1, NULL);
    PyObject_CallObject(pFunc2, NULL);
    PyObject_CallObject(pFunc3, NULL);

    Py_Finalize();
}

void Armor::GetArmorCenter()
{
    std::vector<double> center;

    // 读取Yolodata.xml文件中的最后一个四维向量last_vector
    cv::FileStorage fs("/home/davi/rmVison4.0/DataExchange/Yolodata.xml", cv::FileStorage::READ);

    std::string vector_str = fs["root"]["vector"];
    std::vector<std::string> vector_list;
    std::stringstream ss(vector_str);
    std::string item;
    while (std::getline(ss, item, ']'))
    {
        if (!item.empty())
        {
            item += "]";
            vector_list.push_back(item);
        }
    }

    std::string last_vector_str = vector_list.back();
    std::stringstream last_ss(last_vector_str.substr(1));
    std::vector<double> last_vector;
    double value;
    while (last_ss >> value)
    {
        last_vector.push_back(value);
    }
    fs.release();

    if (IfArmor(last_vector) != false)
    {
        center[0] = ((last_vector[0] + last_vector[2]) / 2);
        center[1] = ((last_vector[1] + last_vector[3]) / 2);
    }
    Armor::armor_center=center;
}

// 排除装甲板误识别的情况 |x1-x2|>=80 |y1-y2|>=50
bool Armor::IfArmor(std::vector<double> vec)
{
    if (abs(vec[0] - vec[2]) >= 80 and abs(vec[1] - vec[3]) >= 50)
        return true;
}
