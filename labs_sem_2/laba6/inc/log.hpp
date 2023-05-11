#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <ctime>
#pragma warning(disable : 4996)

namespace utils
{

    enum class Level
    {
        DEBUG,
        RELEASE
    };

    /*class Logger
    {

        static std::ofstream m_out;
        static Level m_level;

    public:
        static void SetLogFile(const std::string& path = "log.txt")
        {
            m_out.open(path);
        }

        static void SetLogLevel(Level level)
        {
            m_level = level;
        }

        static void Write(const std::string& msg)
        {
            if (m_level != Level::RELEASE) {
                std::cout << msg << std::endl;
                m_out << msg << std::endl;
            }
        }


    };*/

    //std::ofstream Logger::m_out;
    //Level Logger::m_level = Level::DEBUG;


    enum class LogType
    {
        INFO,
        DEBUG,
        RELEASE
    };

    class Log
    {
        static std::ofstream m_out;
        std::stringstream m_ss;
        LogType m_logType;

    public:

        explicit Log(LogType logType) : m_logType(logType)
        {
            //std::cout << "Constuctor" << std::endl;
        }
        static void SetLogFile(const std::string& path = "log.txt")
        {
            m_out.open(path);
        }
        ~Log()
        {
            auto currTime = std::chrono::system_clock::now();
            std::time_t end_time = std::chrono::system_clock::to_time_t(currTime);
            
            switch (m_logType) 
            {
            case LogType::INFO:
                std::cerr << "[INFO]" << m_ss.str() << std::endl << std::ctime(&end_time) << " "<<std::endl;
                break;
            case LogType::RELEASE:
                m_out << "[RELEASE]" << m_ss.str() << std::endl << std::ctime(&end_time) << " " << std::endl;
                break;
            case LogType::DEBUG:
                std::cerr << "[DEBUG]" << m_ss.str() << std::endl << std::ctime(&end_time) << " " << std::endl;
                m_out << "[DEBUG]" << m_ss.str() << std::endl << std::ctime(&end_time) << " " << std::endl;
                break;
            }
            
        }

        template<typename T>
        Log& operator<<(const T& t)
        {
            m_ss << t;
            return *this;
        }

    };
}
std::ofstream utils::Log::m_out;
utils::Log logInfo()
{
    return utils::Log(utils::LogType::INFO);
}

utils::Log logDebug()
{
    return utils::Log(utils::LogType::DEBUG);
}

utils::Log logRelease()
{
    return utils::Log(utils::LogType::RELEASE);
}