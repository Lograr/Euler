#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include <fstream>

enum class Verbosity {
    Quiet = 0,
    Verbose = 1
};

const std::string default_log_file = "log.txt";

class Log {
public:
    Log( std::string log_file = default_log_file, Verbosity verbosity = Verbosity::Quiet );
    void write( std::string message, Verbosity level = Verbosity::Quiet );
    ~Log();
    Verbosity verbosity_level;
private:
    std::ofstream log_stream;
};

#endif
