/**
 * @file using_xml.hpp
 * @author 谭xx (2112216825@qq.com)
 * @brief
 * @version 0.1
 * @date 2023-03-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#define DEMO_GENERAL_USING_XML_HPP_
#ifdef DEMO_GENERAL_USING_XML_HPP_

#include <string>
#include <opencv2/core.hpp>
class XML
{
public:
  XML(const char *file_name,const int mode = 0) 
  : file_name_(file_name)
  {};
  {};
  ~XML(){};
  template <typename T>
  void GetValue(cv::FileStorage &file_storage, T &&date, const std::string xml_date_name);

  template <typename T>
  bool ReadXML(const std::string file_name, T &&get_xml_date, const std::string xml_date_name);

  bool WriteXML(const std::string file_name, bool mode = false);

private:
  std::string file_name_;
  cv::FileStorage file_storage_;
};

template <typename T>
void XML::GetValue(cv::FileStorage &file_storage, T &&date, const std::string xml_date_name)
{
  // 读取变量
  // cv::FileNode n1 = fs["opencv_storage"];
  // n1[XMLdateName] >> Date;
  file_storage[xml_date_name] >> date;
  // n1["int"] >> Date;
  file_storage.release();
  return;
}

template <typename T>
bool XML::ReadXML(const std::string file_name, T &&get_xml_date, const std::string xml_date_name)
{
  // 读取XML文件
  cv::FileStorage fs(file_name, cv::FileStorage::WRITE);
  if(mode)
  fs(file_name, cv::FileStorage::APPEND);
  // cv::FileStorage fs("test.xml", cv::FileStorage::READ);
  if (!fs.isOpened())
  {
    std::cerr << "Failed to open XML file." << std::endl;
    return false;
  }

  getValue(fs, get_xml_date, xml_date_name);
  // getValue(fs, getXMLDate, "int");
  return true;
}

bool XML::WriteXML(const std::string file_name, bool mode)
{
  
  cv::FileStorage fs(file_name, cv::FileStorage::Mode::WRITE);

  if (!fs.isOpened())
  {
    // std::cerr << "Failed to open XML file." << std::endl;
    return false;
  }

  // 读取整型变量
  int num1 = (int)fs["num1"];
  // std::cout << "num1: " << num1 << std::endl;

  // 读取字符串变量
  std::string str1;
  fs["str1"] >> str1;
  // std::cout << "str1: " << str1 << std::endl;

  // 读取数组
  cv::Mat mat1;
  fs["mat1"] >> mat1;
  // std::cout << "mat1: " << mat1 << std::endl;

  return true;
}
#endif // DEMO_GENERAL_USING_XML_HPP_