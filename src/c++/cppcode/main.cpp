/**
 * @file main.cpp
 * @author 谭xx (2112216825@qq.com)
 * @brief 框架，
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */



// TODO:将demo填入工程文件

//  测试
#include"../hppcode/demo_example.hpp"
#include"../../general/c++/using_python.hpp"
// #include"../../general/c++/using_glog.hpp"

/**
 * @brief main
 * demo测试的框架，每个demo都应该先通过demo测试再填入项目
 * @param argc 传入参数个数 
 * @param argv 传入的字符串 [0]是程序名字
 * @return int 略
 */
int main(int argc,char* argv[])
{
    Demo demo;
    demo.Print("测试中","测试结束\n");

    UsingPython demo_python;
    //调用python脚本
    demo_python.UsingModule("demo_example1");
    //获得该脚本中的类或者函数
    auto py_class_demo = demo_python.GetObject("demo");
    //调用类的函数
    py_class_demo.attr("print")(1234,"\n");

    //打印日志的
    auto glog = Glog::GetSingleton(argv[0]);
    glog->Log(1,"1111111111\n\n\n");
    glog->Log(2,"2222222222\n\n\n");
    //!glog->Log(3,"3333333333\n\n\n"); //!会让程序崩溃，在严重错误的时候使用
    
    return 0;
}
