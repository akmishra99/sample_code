#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<strings.h>

#define TRUE 1
#define FALSE 0
#define CHARACTER_FOUND TRUE
#define CHARACTER_NOT_FOUND FALSE

/*
* find anagram of two strings
** bascically logic is to pick character from first string and see if it is contained in
** second string it is then set the success array flag to 1 ,each success array 
** denotes that char from first string is found in string2
** then we check if any contents of success array is not TRUE then it is not a anagram 
** Please note upper and lower case are treated as different ,this program is 
** case sensitive upper case letters and lowecase letters are treated as different string,
** Please see last example
** return value of 1 means  anagram 0 means not a anagram
** two compile this program use
** PS C:\Users\akmis\scratch_nov_18_2025> g++ -o .\anagram2 .\anagram2.c
** here is sample run of this program
** PS C:\Users\akmis\scratch_nov_18_2025> .\anagram2.exe abcd cabf
two strings are not anagram
** PS C:\Users\akmis\scratch_nov_18_2025> .\anagram2.exe abcd cabd
two strings are anagram
** PS C:\Users\akmis\scratch_nov_18_2025> .\anagram2.exe abcd dabcp
two strings are not anagram
** PS C:\Users\akmis\scratch_nov_18_2025> .\anagram2.exe pabcd dabcp
two strings are anagram
** PS C:\Users\akmis\scratch_nov_18_2025> .\anagram2.exe aAcd cabd
two strings are not anagram
** PS C:\Users\akmis\scratch_nov_18_2025> .\anagram2.exe abcd cAbd
two strings are not anagram
** 
** Author:- Alok Kumar Mishra
** e-mail :- akmishra_99@yahoo.com
** Tuesday November 18, 2025
*/
int anagram(const char *string1,const char *string2)
{
    int success[strlen(string1)] = { CHARACTER_NOT_FOUND }; /* 1 means character from first string1 is  found in string2 otherwise
                                                            **
                                                            * 0 means not */
    
    int all_character_found = TRUE;
    int k = 0;
    for (int i =0; i < strlen(string1); i++) {
        for (int j = 0; j < strlen(string2); j++) {
            if (string1[i] == string2[j]) {
                success[k++] = CHARACTER_FOUND ;
                
            }
        }
    }
    for (int i = 0; i < strlen(string1); i++) 
    {
        if (success[i] == CHARACTER_FOUND)
            continue;        
        else {           
            all_character_found = FALSE;
            break;
        }
    }        
    return all_character_found;
}

int main(int argc,char **argv,char **envp)
{
    int success = FALSE;
    
    if (argc != 3) {
        printf("usage %s string1 and string2\n",argv[0]);
        exit(1);
    }

    const char *string1 = argv[1];
    const char *string2 = argv[2];
    if (strlen(string1) != strlen(string2)) {
        printf("two strings are not anagram\n");
        exit(0);
    }

    success = anagram(string1,string2);
    if (success == TRUE)
        printf("two strings are anagram\n");
    else
        printf("two strings are not anagram\n");
    return 0;

}