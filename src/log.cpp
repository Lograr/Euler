#include "log.hpp"

Log::Log( std::string log_file, Verbosity verbosity ) {
    verbosity_level = verbosity;

    log_stream.open( log_file.c_str() );
    if( !log_stream.is_open() ) {
        std::cout << "Log file, " << log_file << ", could not be opened." << std::endl;
        std::cout << "Errors/warnings will be redirected to console output." << std::endl;
    }
    else {
        write( "Using log file: " + log_file + ".\n", Verbosity::Quiet );
    } 
}

void Log::write( std::string message, Verbosity level ) {
    if( level <= verbosity_level ) {
        if( log_stream.is_open() ) {
            log_stream << message;
        }
        else {
            std::cout << message;
        }
    }
}

Log::~Log() {
    log_stream.close();
}
