#include<stdio.h>
#include<string.h>
/* Q1. Write a function to find the longest substring of a given string 
that contains all unique characters. */
int main()
{
    char s[100];
    printf("Enter a string\n");
    scanf("%[^\n]s", s);
    char c[100];
    char sub[100];
    int l;
    for(int i=0;i<100;i++)
    {
        sub[i]=s[i];
        //making a substring of each length
        for(int j=0;j<=i;j++)
        {          
            for(int k=j+1;k<=i;k++)
            {
                if(sub[k]==sub[j])
                    goto exit;
                    /*loop control goes to exit block
                    when repeating charachter encountered*/
            }
        }
    }
    exit:
        l=strlen(sub);
        sub[l-1]='\0';//last charachter was repeating hence deleted
        printf("%s", sub);
}