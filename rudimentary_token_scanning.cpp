/*
** a rudimentary command line parser that can parse a string of the form:
** "--compile -f=\"c:\\my files\\rka=12-17.txt\" --debug=true"
** Author :- Alok Kumar Mishra
** e-mail: akmishra_99@yahoo.com
** July 14,2026
** to compile and run this code, use the following command:
** g++ -std=c++17 rudimentary_token_scanning.cpp -o rudimentary_token_scanning && ./rudimentary_token_scanning
** here is a brief explanation of the code:
** The code defines a simple command line parser that can parse a string of the form:   
** "--compile -f=\"c:\\my files\\rka=12-17.txt\" --debug=true"
** The code uses a struct called pair to hold the token and its corresponding value.
** here is output of the code:
** C:\Users\akmis\scratch_july_14_2026>.\rudimentary_token_scanning.exe
Token: --compile, Value: -f="c:\my files\rka=12-17.txt" --debug=true
Token: -f, Value: c:\my files\rka=12-17.txt
Token: --debug, Value: true
*/

// Output should be:
// param: compile value 
// param: f  value: c:\my files\rka.txt
// param: debug value: true
// For now, just print the original string


#include <iostream>
#include <string>

int main() {
    typedef struct pair {
        std::string first;
        std::string second;

    } t_pair;
    t_pair token_and_value[10]; // Array to hold up to 10 pairs of tokens and values
    char s[] = "--compile -f=\"c:\\my files\\rka=12-17.txt\" --debug=true";
    // Escaping double quotes and using a newline
    
    std::string given_string(s);
    uint8_t beg = 0, at_equal = 0,at_equal3 = 0, i = 0;
    while(given_string.find(" ") != std::string::npos) {
        beg = given_string.find(" ");
        if (beg != std::string::npos) {
            std::string token = given_string.substr(0, beg);
            std::string rest_of_string = given_string.substr(beg + 1);
            token_and_value[i].first = token;
            token_and_value[i].second = rest_of_string;
            // at this point, token_and_value[i].first contains the token (e.g., "--compile") and token_and_value[i].second contains the rest of the string (e.g., "-f=\"c:\\my files\\rka=12-17.txt\" --debug=true")
            // token_and_value[0].first = "--compile"
            // token_and_value[0].second = "-f=\"c:\\my files\\rka=12-17.txt\" --debug=true"

            i++;

            at_equal = rest_of_string.find("=");
            if (at_equal != std::string::npos) {
                token_and_value[i].first = rest_of_string.substr(0, at_equal);
                rest_of_string = rest_of_string.substr(at_equal + 1);
                uint8_t at_equal2 = rest_of_string.find("\"");
                if ( at_equal2 != std::string::npos) {
                    rest_of_string = rest_of_string.substr(at_equal2 + 1);
                    at_equal3 = rest_of_string.find("\"");
                    if (at_equal3 != std::string::npos) {
                        token_and_value[i].second = rest_of_string.substr(0, at_equal3);
                        rest_of_string = rest_of_string.substr(at_equal3 + 1);
                    }
                    // rest_of_string = " --debug=true"
                    // token_and_value[1].first = "-f"
                    // token_and_value[1].second = c:\\my files\\rka=12-17.txt
                    i++;
                    uint8_t at_equal4 = rest_of_string.find(" ");
                    if (at_equal4 != std::string::npos) {
                        if (rest_of_string[0] == ' ') {
                            rest_of_string = rest_of_string.substr(1);
                        }
                        if (at_equal4 != 0 ) {
                            token_and_value[i].first = rest_of_string.substr(0, at_equal4);
                            rest_of_string = rest_of_string.substr(at_equal4 + 1);
                        }
                        // token_and_value[i].first = rest_of_string.substr(0, at_equal4);
                        // rest_of_string = rest_of_string.substr(at_equal4 + 1);
                        uint8_t at_equal5 = rest_of_string.find("=");
                        if (at_equal5 != std::string::npos) {
                            token_and_value[i].first = rest_of_string.substr(0, at_equal5);
                            rest_of_string = rest_of_string.substr(at_equal5 + 1);

                            int at_equal6 = rest_of_string.find(" ");
                            if (at_equal6 != std::string::npos) {
                                token_and_value[i].second = rest_of_string.substr(0, at_equal6);
                                rest_of_string = rest_of_string.substr(at_equal6 + 1);
                            }
                            else {
                                token_and_value[i].second = rest_of_string;
                                rest_of_string = "";
                            }
                            i++;


                        }
                    }
                }
            
            }
            given_string = rest_of_string;
            if (given_string.empty()) {
                break;
            }

        }
    }
    for ( uint8_t j = 0; j < i; j++) {
        std::cout << "Token: " << token_and_value[j].first << ", Value: " << token_and_value[j].second << std::endl;
    }
    return 0;

}

