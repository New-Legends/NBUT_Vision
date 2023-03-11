/**
 * @file using_xml.hpp
 * @author 谭xx (2112216825@qq.com)
 * @brief xml序列化反序列化
 * @version 0.1
 * @date 2023-03-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#define DEMO_GENERAL_USING_XML_HPP_
#ifdef DEMO_GENERAL_USING_XML_HPP_

#include <iostream>
#include <string>
#include <opencv2/core.hpp>

/// @brief 
class XML
{
public:
  XML(std::string file_name)
      : file_name_("../src/data_file/data/"+file_name), file_storage_(file_name_, cv::FileStorage::READ){  };

  ~XML() { file_storage_.release(); };

  template <typename T>
  void GetValue(const std::string &xml_date_name,T &&get_xml_date);

  template <typename T>
  bool ReadXML(const std::string &xml_date_name, T &&get_xml_date);

  template <typename T>
  bool WriteXML(const std::string &data_name,T write_data,bool is_append = false);

private:
  std::string file_name_;
  cv::FileStorage file_storage_;
};

template <typename T>
void XML::GetValue(const std::string &xml_date_name,T &&get_xml_date)
{
  //读取变量
  file_storage_[xml_date_name] >> get_xml_date;

  return;
}

template <typename T>
bool XML::ReadXML(const std::string &xml_date_name,T &&get_xml_date)
{
  //读取XML文件
  file_storage_.open(file_name_,cv::FileStorage::READ);
  // cv::FileStorage fs("test.xml", cv::FileStorage::READ);
  if (!file_storage_.isOpened())
  {
    std::cerr << "没能打开该文件，请检查文件路径\n";
    return false;
  }

  // 得到数据
  GetValue(xml_date_name,get_xml_date);

  return true;
}
template<typename T>
bool XML::WriteXML(const std::string &write_data_name,T write_data,bool is_append)
{
  is_append ?
  file_storage_.open(file_name_,cv::FileStorage::APPEND) :
  file_storage_.open(file_name_,cv::FileStorage::WRITE);

  if (!file_storage_.isOpened())
  {
    std::cerr << "没能打开该文件，请检查文件路径\n";
    return false;
  }

  file_storage_<< write_data_name << write_data;

  return true;
}
#endif // DEMO_GENERAL_USING_XML_HPP_