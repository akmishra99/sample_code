#include<stdio.h>
#include<strings.h>
#include<unistd.h>
/*

PS C:\Users\akmis\scratch_nov_18_2025> g++ -o .\string_reverse .\string_reverse.c
PS C:\Users\akmis\scratch_nov_18_2025> .\string_reverse abcdef
given string = abcdef
and it's reverse = fedcba
PS C:\Users\akmis\scratch_nov_18_2025> .\string_reverse abcdefg
given string = abcdefg
and it's reverse = gfedcba
PS C:\Users\akmis\scratch_nov_18_2025>



*/
char *my_reverse_string(char *given_string)
{

   int string_length = strlen(given_string);
   int upper_bound = 0; 
   char temp = 0;
       upper_bound = string_length / 2;
   for (int j = 0; j < upper_bound; j++ ) {
       temp = given_string[j];
       given_string[j] = given_string[string_length -j - 1]; 
       given_string[string_length -j  -1 ] = temp;

   }
   return given_string;
}

int main(int argc,char **argv,char **envp)
{

   if ( argc != 2 ) {
       printf("%s usage: string",argv[0]);
       exit(1);
   }
   
   printf("given string = %s\n" ,argv[1]);

   printf("and it's reverse = %s\n",my_reverse_string(argv[1]));



}
