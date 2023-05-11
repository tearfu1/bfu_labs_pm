#include <iostream>
#include "log.hpp"
#pragma warning(disable : 4996)
 
int main() {
    utils::Log::SetLogFile();
    logDebug() << "test" << 123 << 3.4;
    //utils::Logger::Write("somehow");

    //auto start = std::chrono::system_clock::now();
    //// Some computation here
    //auto end = std::chrono::system_clock::now();

    //std::chrono::duration<double> elapsed_seconds = end - start;
    //std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    //std::cout << "finished computation at " << std::ctime(&end_time)<< std::endl;
    
    return 0;
}