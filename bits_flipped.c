#include<stdio.h>
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
** Date Oct 23,2025
** this program finds the number of bits flipped in a given number
*/
unsigned long  count_bits_flipped_in_a_number(unsigned long  given_number)
{
    unsigned long int temp = given_number;
    unsigned long  int temp2 = given_number;
    unsigned int number_of_zero_bits = 0;
    unsigned int number_of_one_bits = 0;
    int zero_bits_flipped =0;
    int one_bits_flipped = 0;
    int total_bits_flipped = 0;
    int previous_zero_bit = 0;
    int previous_one_bit = 0;
    for (int i = 0; i < sizeof(given_number) *8; i++)
    {   
        temp = temp2 & 0x0000000000000001;


        if (temp) {
            previous_one_bit++;
            number_of_one_bits++;
            if (previous_zero_bit) {
                previous_zero_bit = 0;
                zero_bits_flipped++;
                total_bits_flipped++;

            }
        }
        else
        {
            previous_zero_bit++;
            number_of_zero_bits++;
            if (previous_one_bit) {
                previous_one_bit = 0;
                one_bits_flipped++;
                total_bits_flipped++;
            }
    ;
        }
        temp2 = temp2 >> 1;

    }
    return total_bits_flipped;

}


int main(int argc, char const **argv,char **envp)
{
    unsigned long a_number = 3; /* this is  hex number 3*/
    unsigned long b_number = 5; /* this is hex number 5*/
    unsigned long c_number = 0x11 ; /* this is  decimal number 17*/
    unsigned long d_number = 0x101; /* this is decimal number 257 */
    unsigned long e_number = 0b1010101010101010; /* this is decimal number 43690 hex number AAAA */
    printf("in given hex number = %X total_number of bits flipped = %d\n",a_number,count_bits_flipped_in_a_number(a_number));
    printf("in given hex number = %X total_number of bits flipped = %d\n",b_number,count_bits_flipped_in_a_number(b_number));
    printf("in given hex number = %X total_number of bits flipped = %d\n",c_number,count_bits_flipped_in_a_number(c_number));
    printf("in given hex number = %X total_number of bits flipped = %d\n",d_number,count_bits_flipped_in_a_number(d_number));  
    printf("in given hex number = %X total_number of bits flipped = %lu\n",e_number,count_bits_flipped_in_a_number(e_number));
    return 0;
    


}