#include <stdio.h>
#include <string.h>
/*Q2.Implement a function that checks if two given strings are 
anagrams of each other. Ignore spaces and capitalization.*/
void modify(char *str) 
{
    int i,j=0;
    for(i=0;str[i];i++) 
    {
        if (str[i]!=' ') 
        {
            str[j++]=str[i];
        }//removes blank spaces from string
    }
    for(i=0;str[i];i++) 
    {
        if(str[i]>='A' && str[i]<='Z') 
        {
            str[i]=str[i]+('a' - 'A');
        }//converts a string to lower case

    }
}
// Function to sort a string
void sort(char *str) 
{
    int n=strlen(str);
    for (int i=0; i<n-1; i++) 
    {
        for (int j=i+1 ; j<n; j++) 
        {
            if (str[i]>str[j]) 
            {
                char temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
}
int main() 
{
    char s1[50];
    char s2[50];
    printf("Enter 1st word: ");
    scanf(" %[^\n]s", s1);
    printf("Enter 2nd word: ");
    scanf(" %[^\n]s", s2);
    if (strlen(s1)!=strlen(s2)) 
    {
        printf("The strings are not anagrams\n");
        return 0;
    }// Check if the lengths of the strings are the same
    modify(s1);
    modify(s2);
    sort(s1);
    sort(s2);
    //converts the string to lower case and then sorts them
    if (strcmp(s1,s2)== 0) //comparing whether two strings are same
    {
        printf("They are anagrams\n");
    } 
    else 
    {
        printf("The strings are not anagrams\n");
    }
    return 0;
}
