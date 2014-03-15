#include "main.hpp"

#define ss std::to_string

void calculate( Log *log, int number ) {
    int multiples_three_sum;
    int multiples_five_sum;

    for( int i = 1; i < number; i++ ) {
        if( i % 3 == 0 ) {
            log->write( ss( i ) + " is a multiple of 3.\n", Verbosity::Verbose );
            multiples_three_sum += i;
        } else if( i % 5 == 0 ) {
            log->write( ss( i ) + " is a multiple of 5.\n", Verbosity::Verbose );
            multiples_five_sum += i;
        }
    }

    std::cout << "Sum of all multiples of 3 and 5 below " << ss( number ) << " is "
              << multiples_five_sum + multiples_three_sum << ".\n";
    log->write( "Sum of all multiples of 3 below " + ss( number ) + " is " 
               + ss( multiples_three_sum ) + ".\n" );
    log->write( "Sum of all multiples of 5 below " + ss( number ) + " is "
               + ss( multiples_five_sum ) + ".\n" );
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
