#include <iostream>
#include <sstream>
#include <string>

// ( 4 + 5 ) * 3
// 4 5 + 3 *
// # 27

// ( 2 + 1 ) / 5
// 2 1 + 5 /
// #0

// ( 4 + 5 ) / ( 2 + 1 )
// 4 5 + 2 1 + /
// # 9 / 3 = 3
// 1 2 3 4 5 - - - -
// # 1 2 3 -1 - - -; 1 2 4 - - ; 1 -2 -; 3

/*
** Program to compute final result of expression  reverse polish notation, it is assumed that input is given in reverse polish notation
** maximum 10 intermediate calculations are supported
** Authror :- Alok Kumar Mishra
** e-mail: akmishra_99@yahoo.com
** Date :- Saturday May 9,2026
** in this program basic testing is done,extensive testing still needs to be done 
** here is how to compile this program
** C:\Users\akmis\scratch_may_10_2026>g++ -g -o reverse_polish_calculation10 reverse_polish_calculation10.cpp
** here are output of running this program with sample input provided at the top
C:\Users\akmis\scratch_may_10_2026>.\reverse_polish_calculation10.exe
Hello from .\reverse_polish_calculation10.exe
 4 5 + 3 *
given line =  4 5 + 3 * inputcin =  4 5 + 3 *
You entered  and immediately pressed Enter. result[0] = 9
 result[1]= 27
 final result = 27
C:\Users\akmis\scratch_may_10_2026>.\reverse_polish_calculation10.exe
Hello from .\reverse_polish_calculation10.exe
2 1 + 5 /
given line = 2 1 + 5 / inputcin = 2 1 + 5 /
You entered  and immediately pressed Enter. result[0] = 3
 result[1]= 0
 final result = 0

C:\Users\akmis\scratch_may_10_2026>

C:\Users\akmis\scratch_may_10_2026>.\reverse_polish_calculation10.exe
Hello from .\reverse_polish_calculation10.exe
4 5 + 2 1 + /
given line = 4 5 + 2 1 + / inputcin = 4 5 + 2 1 + /
You entered  and immediately pressed Enter. result[0] = 9
 result[1]= 3
 final result = 3

C:\Users\akmis\scratch_may_10_2026>
C:\Users\akmis\scratch_may_10_2026>.\reverse_polish_calculation10.exe
Hello from .\reverse_polish_calculation10.exe
1 2 3 4 5 - - - -
given line = 1 2 3 4 5 - - - - inputcin = 1 2 3 4 5 - - - -
You entered  and immediately pressed Enter. result[0] = 0
final result = 3
 result[1]= 4
C:\Users\akmis\scratch_may_10_2026>


** 
*/
const uint8_t MAX_RESULTS = 10;
uint8_t minimum_result = 0;
uint8_t maximum_result = 0;
std::string minus("-"),plus("+"),multiply("*"),divide("/"),unary_minus("-");
std::string numbers [MAX_RESULTS] = {""};
int operator_index = -1, data_index = -1,current_operating_index = 0;
bool intermediate_value = false; // to indicate there is no intermediate value while computing unary operator e.g 1 2 3 4 5 - - - -
int result[MAX_RESULTS] = {0};

bool not_a_operator(std::string given_item) 
{
    // returns true if given_item is number else if operator returns false
    if ((given_item == minus) || (given_item == plus) || (given_item == multiply) || (given_item == divide)) 
        return false;
    else 
        return true;

}
bool is_operator(std::string given_item)
{
    // returns true if given_item is operator else if number returns false)
    return !not_a_operator(given_item);
}
bool erase_number()
{

    for (int i = 0; i < current_operating_index; i++) {
        numbers [i] = "";
    }
    current_operating_index = 0;
    return true;
}
int count_total_operators()
{
    int operator_index = 0;
    for (int i = 0; i < current_operating_index; i++) {
        if (is_operator(numbers[i]))
            operator_index++;
    }
    return operator_index;


}
bool process_number()
{   
    int total_result = 0 ,temp_value = 0;
    int total_elements = current_operating_index -1;
    auto upper_limit = count_total_operators();
    for ( int l = 0; l < upper_limit ; l++ ) {
        if (!intermediate_value) {
            if ((data_index - 1 > 0) && (data_index -2) >= 0 ) {
                if (numbers[operator_index].c_str()[0] == '-') {
                    temp_value = std::stoi(numbers[data_index -2]) -  std::stoi(numbers[data_index -1]);
                }
                else if (numbers[operator_index++].c_str()[0] == '+') {
                    temp_value = std::stoi(numbers[data_index -2]) +  std::stoi(numbers[data_index -1]);
                }
                else if (numbers[operator_index++].c_str()[0] == '*') {
                    temp_value = std::stoi(numbers[data_index -2]) *  std::stoi(numbers[data_index  -1]);
                }
                else if (numbers[operator_index++].c_str()[0] == '/') {
                    temp_value = std::stoi(numbers[data_index -2]) /  std::stoi(numbers[data_index -1]);
                }

                intermediate_value = true;
                data_index--;
                result[l] = temp_value;
            }
        }
        else {
            data_index--;
            if (numbers[operator_index++].c_str()[0] == '-') {
                
                temp_value = std::stoi(numbers[data_index - 1]) -  temp_value    ;       
            }
            else if (numbers[operator_index++].c_str()[0] == '+') {
                temp_value = std::stoi(numbers[data_index -1]) +  temp_value    ;
            }
            else if (numbers[operator_index++].c_str()[0] == '*') {
                temp_value = std::stoi(numbers[data_index -1]) *  temp_value    ;
            }
            else if (numbers[operator_index++].c_str()[0] == '/') {
            temp_value = std::stoi(numbers[data_index -1]); numbers[operator_index++].c_str()[0]; temp_value;
            // intermediate_value = false;
            }
            else {
                temp_value = std::stoi(numbers[data_index -1]) /  temp_value    ;
            }
            
            result[l] = temp_value;
        }
    }

    if ( (upper_limit -1) >= 0) {
        std::cout << "final result = " << result[upper_limit -1] << std::endl;
        return true;
    }
    return false;
}
int calculate_result(std::string operand1,std::string operand2,std::string valid_operator) 
{
    int result = -1;
    if (valid_operator == plus) {
        result = std::stoi(operand1) + std::stoi(operand2);
        return result;
    }
    else if (valid_operator == minus) {
        result= std::stoi(operand1) - std::stoi(operand2);
        return result;
    }
    else if (valid_operator == multiply) {
        result = std::stoi(operand1) * std::stoi(operand2);
        return result;
    }
    else if (valid_operator == divide) {
        if (std::stoi(operand2) != 0) {
            result = std::stoi(operand1) / std::stoi(operand2);
            return result;
        }
    }
    return result;

}


int main( int argc, char **argv )
{
    bool beggining = true;
   
    std::cout << "Hello from " << argv[0] <<std::endl;

    std::string operand1, operand2, valid_operator,input_item;
    int final_result = 0, i = 0, j = 0 ;


    std::string line;
    while(getline(std::cin,line)) {
        
        i = 0;
        std::istringstream inputcin(line);
        std::cout << "given line = " << line << " inputcin = " << inputcin.str() << std::endl;
        while(!inputcin.eof()) {
            
        
        

            
            if (!inputcin.eof()) {
                inputcin>> operand1;
                numbers[current_operating_index++] = operand1;
            }

            
            if (!inputcin.eof()) {
                inputcin>> operand2;
                numbers[current_operating_index++] = operand2;
            
            }
            else {
                if (is_operator(operand1)) {
                    valid_operator = operand1;
                    operand2 ="";
                    operand1 = "";
                    erase_number();
                    
                }
                
            }
            if (!inputcin.eof()) {
                inputcin>> valid_operator;
                numbers[current_operating_index++] = valid_operator;    
            }
            else {
                if (is_operator(operand2)) {
                    valid_operator = operand2;
                    operand2 ="";
                    operand1 = "";
                    erase_number();
                    
                }
                else if (is_operator(valid_operator)) {
                    erase_number();
                
                }
                else 
                    numbers[current_operating_index++] = valid_operator;
            }
            if (!inputcin.eof()) {
                std::cout << "You entered  and immediately pressed Enter.";
                if (beggining) {
                    if (valid_operator == divide) {
                        if (std::stoi(operand2) == 0) {
                            std::cout << "incorrect entry divide by zero " << std::endl;
                            beggining = true;
                            result[j] = 0;
                            final_result = 0;
                            if ( j > 0)
                                j--;
                    
                        }
                    }
                    else if (is_operator(valid_operator ))
                        result[j] = calculate_result(operand1,operand2,valid_operator);

                    beggining = false;
                    
                }
            
                else {
                    if (is_operator(operand2)) {
                        valid_operator = operand2;
                        operand2 = "";              
                        
                    }
                    if (valid_operator == divide) {
                        if (std::stoi(operand2) == 0) {
                            std::cout << "incorrect entry divide by zero " << std::endl;
                            beggining = true;
                            result[j] = 0;
                            final_result = 0;
                            if ( j > 0)
                                j--;
                    
                        }
                    }
                    else 
                        result[j] = calculate_result(operand1,operand2,valid_operator);
                
                }
            
            }
            else {
                // EOF was reached during the last read attempt
                if ( (!j) && (!minimum_result) && (!maximum_result)) {
                    int temp1,temp2;
                    temp1 = std::stoi(operand1);
                    temp2 = std::stoi(operand2);
                    if  (is_operator(valid_operator)) {
                        result[j] = calculate_result(operand1,operand2,valid_operator);
                        std::cout << " result[" << j << "] = " << result[j] << std::endl;
                        final_result = result[j];
                        std::cout << " final result = " << final_result << std::endl;
                        exit(0);
                    }
                    
                }

                if (valid_operator == plus) {
                    if ((maximum_result - minimum_result) == 1 )
                        final_result = result[0];
                    for ( uint8_t  k = minimum_result; k < maximum_result; k++ )
                        final_result += result[k];
                }
                else if (valid_operator == minus) {
                    for ( uint8_t k = minimum_result; k < maximum_result; k++ )
                        final_result -= result[k];
                }
                else if (valid_operator == multiply) {
                    if (final_result == 0)
                        final_result = 1;
                    for ( uint8_t k = minimum_result; k < maximum_result; k++ )
                        final_result *= result[k];
                }
                else if (valid_operator == divide) {
                        final_result = result[0];
                        for ( uint8_t k = minimum_result; k < maximum_result; k++ ) {
                            if (k == 0) {
                                final_result = result[k];
                                continue;
                            }
                            if (result[k] != 0) {
                                final_result /= result[k];

                            }
                        }
                }
                else {
                        std::cout << "incorrect entry " << std::endl;
                        beggining = true;
                        final_result = 0;
                        result[j] = 0; 
                }
                std::cout << " final result = " << final_result << std::endl;
                exit(0);
                    
            }

            std::cout << " result[" << j << "] = " << result[j] << std::endl;

            
            j++;
            maximum_result = j;

            
    
            inputcin >> input_item;
            

            operand1 = input_item;
            if (not_a_operator(operand1)) {
                if (inputcin.peek() != '\n') {
                    numbers[current_operating_index++] = operand1;
                    if (inputcin.peek() != '\n') {
                    inputcin >> operand2 ;
                    if (not_a_operator(operand2)) {
                        if (inputcin.peek() != '\n') {
                            numbers[current_operating_index++] = operand2;
                            inputcin >> valid_operator;
                            if (beggining && (not_a_operator(valid_operator))) {
                                std::cout << "invlaid entry" << std::endl;
                                exit(1);    
                            }
                        }
                        else {
                            valid_operator = operand2;
                            operand2 ="";
                            erase_number();
                        }

                    
                    }
                
                    else {
                        valid_operator = operand2;
                        erase_number();
                        operand2 = "";
                        
                        if (beggining) {
                            if (valid_operator == unary_minus) {
                                result[j] = -1 * std::stoi(operand1);
                                erase_number();
                                beggining = false;
                            }
                            else if (valid_operator ==  plus) {
                                result[j] = std::stoi(operand1);
                                beggining = false;
                                erase_number();
                            }

                            
                        }

                    }
                }
                else {
                    valid_operator = operand1;
                    operand2 = "";
                    operand1 = "";
                    erase_number();
                    
                }

            }
            else {
                

                if ( not_a_operator(operand1) && not_a_operator (operand2)     && not_a_operator(valid_operator )) {

                    while (i < 255) { // we are putting upper limit to number of conscutive numbers
                            inputcin >> operand1 >> operand2 >> valid_operator;
                            numbers[current_operating_index++] = operand1;
                            numbers[current_operating_index++] = operand2;
                            numbers[current_operating_index++] = valid_operator;

                            if (is_operator(operand2)) {
                                valid_operator = operand2; 
                                operand2 =""; 
                                erase_number();             
                                // operand1 = final_result;

                            }
                            beggining = false;
                            break;

                    }
                }
            }
            if (beggining && is_operator(operand1)) {
                std::cout << "incorrect entry " << std::endl;
                result[j] = 0;
                final_result = 0;
                if (beggining) {
                    beggining = false;
                }
                erase_number();
            }
            else if ( operand2 == unary_minus)   {
                result[j] = -1 * std::stoi(operand1);
                erase_number();
            }
            else if (operand2 == plus) {
                result[j] = std::stoi(operand1);
                erase_number();
            }
            else if (beggining && (operand2 == multiply)) {
                beggining = false;
                std::cout << "incorrect entry " << std::endl;
                erase_number();
            }
            else if  (beggining && (operand2 == divide))  {
                std::cout << "incorrect entry " << std::endl;
                beggining = false;
                erase_number();
            }
            else if (valid_operator == plus) {
                if (operand2 == "") {
                    result[j] = std::stoi(operand1) + result[j - 1];
                    erase_number();

                }
                else {
                    result[j] = std::stoi(operand1) + std::stoi(operand2);
                    erase_number();
                }


            }
            else if (valid_operator == minus) {
                    if (current_operating_index >= 5) {
                        
                        numbers[current_operating_index ] = valid_operator;
                        data_index = operator_index = current_operating_index;
                        operator_index++;
                        current_operating_index++;

                        while(!inputcin.eof()) {
                            inputcin >> numbers[current_operating_index++];
                        }
                        process_number();
                        
                    }
                    else if (operand2 == "") {
                        result[j] =  result[j - 1] - std::stoi(operand1) ;
                        erase_number();

                    } 
                    else {
                        result[j] = std::stoi(operand1) - std::stoi(operand2);
                        erase_number();
                    }

                    // result[j] = std::stoi(operand1) - std::stoi(operand2);
            }
            else if ( valid_operator == multiply) {
                if (operand2 == "") {
                    result[j] =  result[j - 1] * std::stoi(operand1) ;
                    erase_number();


                }
                else {
                    result[j] = std::stoi(operand1) * std::stoi(operand2);
                    erase_number();
                }
                // result[j] = std::stoi(operand1) * std::stoi(operand2);
            }
            else if ( valid_operator == divide) {
                if (operand2 != "") {
                    if (std::stoi(operand2) == 0) {
                        std::cout << "incorrect entry divide by zero " << std::endl;
                        beggining = true;
                        result[j] = 0;
                        final_result = 0;
                        erase_number();
                        continue;
                    }
                    else {
                        result[j] = calculate_result(operand1,operand2,valid_operator);
                        erase_number();
                    }
                }
                else {
                    
                    result[j] = result[j - 1] / std::stoi(operand1);
                    erase_number();
                }
            }
            minimum_result = j;
            std::cout << " result[" << j  << "]= " << result[j] << std::endl; 
            j++;
            maximum_result = j;
 
            }
            if (current_operating_index >= 5) {
                data_index = operator_index = current_operating_index;
                current_operating_index++;

                while (!inputcin.eof()) {
                    inputcin >> numbers[current_operating_index++];

                }            
                process_number();
            }
        
        }
        if (inputcin.eof()) {

            
            break;
        }
    
    }




    if (valid_operator == multiply) {
        final_result = 1;
    }
    if (valid_operator == plus) {
        final_result = result[0];
    }

    for ( uint8_t k = minimum_result; k < maximum_result; k++ ) {
        if (valid_operator == plus) {
            final_result += result[k];
        }
        else if (valid_operator == minus)   {
            final_result -= result[k];
        }
        else if (valid_operator == multiply) {
            final_result *= result[k];
        }
        else if (valid_operator == divide) {
            if (result[k] != 0) {
                if (maximum_result - minimum_result == 1)
                    final_result = result[k];
                else 
                    final_result /= result[k];
            }
        }
    }
    std::cout << " final result = " << final_result << std::endl;
    return EXIT_SUCCESS;
}