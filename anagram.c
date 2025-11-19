#include<stdio.h>
#include<unistd.h>
#include<strings.h>
#include<stdlib.h>

/*
** code to find anagram of two strings
* to compile this file use command
* g++ -o .\anagram .\anagram.c
* PS C:\Users\akmis\scratch_nov_18_2025> .\anagram abcd cabd
* two strings are anagram
* PS C:\Users\akmis\scratch_nov_18_2025> .\anagram abacd cabda
* two strings are anagram
* PS C:\Users\akmis\scratch_nov_18_2025> .\anagram abacd cabde
* two strings are not anagram
* PS C:\Users\akmis\scratch_nov_18_2025>
*/
int compare_order(const void *one,const void *two)
{

    return (*(char *) one - *(char *)two);


}


int main(int argc,char **argv,char **envp)
{
    char *string1,*string2;
    int success = 0; /* zero means anagram 1 means not */
    if (argc <3) {


        printf("usage %s string1 and string2\n",argv[0]);
        exit(1);

    }
    string1 = argv[1];
    string2 = argv[2];

    if (strlen(string1) != strlen(string2)) {

        printf("two strings are not anagram\n");
        exit(1);
    

    
    }

    /* convert strings to lower case */
    strlwr(string1);
    strlwr(string2);
    qsort(string1,strlen(string1),sizeof(char),compare_order);
    qsort(string2,strlen(string2),sizeof(char),compare_order);
    
    success = strcmp(string1,string2);
    if (success == 0)
        printf("two strings are anagram\n");
    else
        printf("two strings are not anagram\n");

    return 0; 
}

