/**
 * @file main.cpp
 * @author 谭xx (2112216825@qq.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef DEMO_DEMO_EXAMPLE_HPP_
#define DEMO_DEMO_EXAMPLE_HPP_

#include <iostream>
#include"../../general/c++/using_glog.hpp"

/**
 * @brief demo测试的头文件例子
 * 
 */
class Demo
{
private:
    const char *KPRINT_TEXT_ {"这是一个demo测试"};
public:
    Demo() : is_print_{true}{};
    ~Demo() = default;
    //是否打印
    bool is_print_ ;
    //打印的函数
    template <class... Args>
    void Print(Args... args);
};

/// @brief 打印
/// @tparam ...Args
/// @param ...args 传入的数据
template <class... Args>
void Demo::Print(Args ...args)
{
    if (!is_print_)
        return;
    try
    {
        // ((std::cout << args << " "),...);
        glog = Glog::GetSingleton("demo_example");
        glog->Log(0,KPRINT_TEXT_,args...);
        // std::endl(std::cout);
    }
    catch (const std::exception &e)
    {
        // std::cerr << "测试失败\n克能4may油重载《 操作符" << '\n';
        // std::cerr << e.what() << '\n';
        glog = Glog::GetSingleton("demo_example");
        glog->Log(1,"测试失败\n克能4may油重载《 操作符\n",e.what());

    }

    return;
}

#endif // DEMO_DEMO_EXAMPLE_HPP_
