/**
 * @file using_python.hpp
 * @author 谭xx (2112216825@qq.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#define DEMO_GENERAL_USING_PYTHON_HPP_
#ifdef  DEMO_GENERAL_USING_PYTHON_HPP_

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>


namespace py = pybind11;


/**
 * @brief 调用python的类
 * 只封装了了调用模块和类
 * 函数什么的要自己写----object.attr("name")(args...)
 * 
 */
class UsingPython
{
private:
  std::shared_ptr<py::object> pmodule_;
  py::object object_;
public:
  UsingPython();
  bool UsingModule(const char* module_name);
  const py::object& GetObject(const char* object_name);
};


/**
 * @brief Construct a new Using Python:: Using Python object  初始化
 * 
 */
UsingPython::UsingPython() : pmodule_(std::make_shared<py::object>())
{
  // python调用
  Py_Initialize();
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append('../src/general/python')");
  PyRun_SimpleString("sys.path.append('../src/python')");

  // PyRun_SimpleString("sys.path.append('../')");
  // py::scoped_interpreter py

  // sys模块
  // py::object path = sys.attr("path");          // sys的path变量
  // path.attr("append")("../");                  // path的方法添加路径
}



/**
 * @brief 调用模块
 * 
 * @param module_name 模块的名字
 * @return true 
 * @return false 
 */
bool UsingPython::UsingModule(const char* module_name)
{
  *pmodule_ = py::module_::import(module_name);
  return pmodule_ ? true : false;
}



/**
 * @brief 调用当前对象(模块)的函数或者类，返回其引用
 * 
 * @param object_name 对象名
 * @return const py::object&  函数或者其他的py对象引用
 */
const py::object& UsingPython::GetObject(const char* object_name)
{
  object_ = pmodule_->attr(object_name);
  return object_;
}

#endif  //DEMO_GENERAL_USING_GLOG_HPP_