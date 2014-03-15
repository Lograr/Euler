#include "main.hpp"

#define ss std::to_string

void calculate( Log *log, int max_number ) {
    int fibonacci_sum;

    int last_number = 1;
    int next_number = 2;
    int i = 0;
    while( i < max_number ) {
        next_number = last_number;
        last_number = i;
        if( i % 2 == 0 ) {
            log->write( ss( i ) + " is an even Fibonacci number.\n", Verbosity::Verbose );
            fibonacci_sum += i;
        }
        i = last_number + next_number;
    }

    log->write( "Sum of all even Fibonacci numbers up to " + ss( max_number ) + " is " 
               + ss( fibonacci_sum ) + ".\n", Verbosity::Console );
}

void loop( Log *log ) {
    bool is_running = true;
    while( is_running ) {
        std::string input;

        std::cout << PROMPT;
        std::cin >> input;

        if( input == "q" )
            break;

        calculate( log, std::atoi( input.c_str() ) );
    }
}

int main( int argc, char *argv[] ) {
    std::cout << PROG_NAME << " " << VERSION << std::endl;
    std::cout << PROG_DESC << std::endl << std::endl;

    Log log( default_log_file );

    if( argc > 1 ) {
        std::string option = std::string( argv[1] );
        if( option[0] == '-' ) {
            switch( option[1] ) {
            case 'v':
                log.write( "Option -v used; log will be verbose.\n" );
                log.verbosity_level = Verbosity::Verbose;
                break;
            default:
                std::cout << "Invalid argument '" << option << "'.\n";
                return 0;
            }

            if( argc > 2 )
                calculate( &log, std::atoi( argv[2] ) );
            else
                loop( &log );
        }
        else
            calculate( &log, std::atoi( option.c_str() ) );
    }
    else
        loop( &log );

    return 0;
}
