#include<iostream>
#include<thread>
#include<pybind11/pybind11.h>
#include<opencv2/opencv.hpp>
#include"./src/ArmorCenter/ArmorCenter.h"

int main()
{
    Armor box1;
    std::thread thread1(&Armor::Yolov5_Run,&box1);
    thread1.join();
    return 0;
}