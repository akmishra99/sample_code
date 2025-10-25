#include<stdio.h>
#include<stdint.h>
/*
** file bits_flipped.c
to compile use following command
PS C:\Users\akmis\scratch_oct_23_2025> g++ -g -o bits_flipped .\bits_flipped.c
to run use following command, followed by are output of this program 
PS C:\Users\akmis\scratch_oct_23_2025> .\bits_flipped
in given hex number = 3 total_number of bits flipped = 1
in given hex number = 5 total_number of bits flipped = 3
in given hex number = 11 total_number of bits flipped = 3
in given hex number = 101 total_number of bits flipped = 3
in given hex number = AAAA total_number of bits flipped = 16, Please note AAAA is in hex and in binary it is 1010101010101010
*/
/*
** Author:- Alok Kumar Mishra
** e-mail:- akmishra_99@yahoo.com
** Date Oct 24,2025
** this program finds the number of bits flipped in a given number,it also prints 
** count of number of zero bits and one bits ,also prints number of zero and 1 bits flipped
*/

typedef struct bit_info {    
    unsigned long given_number = 0;
    uint8_t number_of_zero_bits = 0;
    uint8_t number_of_one_bits = 0;
    uint8_t zero_bits_flipped = 0;
    uint8_t one_bits_flipped = 0;
    uint8_t total_bits_flipped = 0 ;
} t_bit_info;

t_bit_info  count_bits_flipped_in_a_number(unsigned long  given_number)
{
    unsigned long int temp = given_number;
    unsigned long  int temp2 = given_number;
    uint8_t number_of_zero_bits = 0;
    uint8_t number_of_one_bits = 0;
    uint8_t zero_bits_flipped =0;
    uint8_t one_bits_flipped = 0;
    uint8_t total_bits_flipped = 0;
    bool previous_zero_bit = false;
    bool previous_one_bit = false;
    t_bit_info bit_info;
    for (int i = 0; i < sizeof(given_number) *8; i++)
    {   
        temp = temp2 & 0x00000000000000000000000000000001;


        if (temp) {
            previous_one_bit = true;
            number_of_one_bits++;
            if (previous_zero_bit) {
                previous_zero_bit = false;
                zero_bits_flipped++;
                total_bits_flipped++;

            }
        }
        else
        {
            previous_zero_bit = true;
            number_of_zero_bits++;
            if (previous_one_bit) {
                previous_one_bit = false;
                one_bits_flipped++;
                total_bits_flipped++;
            }
    ;
        }
        temp2 = temp2 >> 1;

    }
    
    bit_info.given_number = given_number;
    bit_info.number_of_zero_bits = number_of_zero_bits;
    bit_info.number_of_one_bits = number_of_one_bits;  
    bit_info.zero_bits_flipped = zero_bits_flipped;
    bit_info.one_bits_flipped = one_bits_flipped;
    bit_info.total_bits_flipped = total_bits_flipped;   

    return bit_info;

}
void print_bit_info(t_bit_info bit_info)
{
    printf("\t\ttotal_number of bits flipped = %d\n",bit_info.total_bits_flipped   );
    printf("\t\tnumber_of_zero_bits = %d\n",bit_info.number_of_zero_bits   );
    printf("\t\tnumber_of_one_bits = %d\n",bit_info.number_of_one_bits   );
    printf("\t\tzero_bits_flipped = %d\n",bit_info.zero_bits_flipped   );
    printf("\t\tone_bits_flipped = %d\n",bit_info.one_bits_flipped   );
    
}    

int main(int argc, char const **argv,char **envp)
{
    unsigned long a_number = 3; /* this is  hex number 3*/
    unsigned long b_number = 5; /* this is hex number 5*/
    unsigned long c_number = 0x11 ; /* this is  decimal number 17*/
    unsigned long d_number = 0x101; /* this is decimal number 257 */
    unsigned long e_number = 0b1010101010101010; /* this is decimal number 43690 hex number AAAA */
    printf("in given hex number = 0x%X\n",a_number);
    print_bit_info(count_bits_flipped_in_a_number(a_number));
    printf("in given hex number = 0x%X\n",b_number);
    print_bit_info(count_bits_flipped_in_a_number(b_number));
    printf("in given hex number = 0x%X\n",c_number);
    print_bit_info(count_bits_flipped_in_a_number(c_number));
    printf("in given hex number = 0x%X\n",d_number);
    print_bit_info(count_bits_flipped_in_a_number(d_number));  
    printf("in given hex number = 0x%X\n",e_number);
    print_bit_info(count_bits_flipped_in_a_number(e_number));
    return 0;
    


}