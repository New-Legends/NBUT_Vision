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

#define DEMO_GENERAL_USING_GLOG
#ifdef DEMO_GENERAL_USING_GLOG

#include <glog/logging.h>
#include <mutex>
#include <memory>

/**
 * @brief glog库的封装，使用懒汉单例模式
 *
 */
class Glog
{
    Glog(const char *argv);

public:
    static std::shared_ptr<Glog> GetSingleton(const char *argv);
    template <class... Args>
    constexpr void Log(const int info_level, Args... args);
    ~Glog();
};

/**
 * @brief Construct a new Glog:: Glog object 初始化
 *
 * @param argv 程序名
 */
Glog::Glog(const char *argv)
{
    // 清除上次的log日志
    system("rm -f ../src/data_file/logs/*");
    // 初始化
    google::InitGoogleLogging(argv);
    // 是否将日志输出到文件和stderr
    FLAGS_alsologtostderr = true;
    // 是否启用不同颜色显示
    FLAGS_colorlogtostderr = true;
    // INFO级别的日志都存放到logs目录下且前缀为INFO_
    google::SetLogDestination(google::GLOG_INFO, "../src/data_file/logs/info_");
    // WARNING级别的日志都存放到logs目录下且前缀为WARNING_
    google::SetLogDestination(google::GLOG_WARNING, "../src/data_file/logs/warning_");
    // ERROR级别的日志都存放到logs目录下且前缀为ERROR_
    google::SetLogDestination(google::GLOG_ERROR, "../src/data_file/logs/error_");
    // FATAL级别的日志都存放到logs目录下且前缀为FATAL_
    google::SetLogDestination(google::GLOG_FATAL, "../src/data_file/logs/fatal_");
}

/**
 * @brief Destroy the Glog:: Glog object 释放
 *
 */
Glog::~Glog()
{
    // 释放
    google::ShutdownGoogleLogging();
}

/**
 * @brief
 *
 * @tparam Args 信息类型的形参包
 * @param info_level 信息等级
 * @param args 信息
 */
template <class... Args>
constexpr void Glog::Log(const int info_level, Args... args)
{
    switch (info_level)
    {
    case 0:
        ((LOG(INFO) << args), ...);
        break;
    case 1:
        ((LOG(WARNING) << args), ...);
        break;
    case 2:
        ((LOG(ERROR) << args), ...);
        break;
    case 3:
        ((LOG(FATAL) << args), ...);
        break;
    default:
        break;
    }

    return;
}
/**
 * @brief 下面是单例模式的实现
 *
 */
static std::mutex glog_mutex;
static std::shared_ptr<Glog> glog = nullptr;

std::shared_ptr<Glog> Glog::GetSingleton(const char *argv)
{
    if (glog == nullptr)
    {
        std::unique_lock<std::mutex> lock(glog_mutex);
        if (glog == nullptr)
        {
            auto temp = std::shared_ptr<Glog>(new Glog(argv));
            glog = temp;
        }
    }
    return glog;
}

#endif // DEMO_GENERAL_USING_GLOG