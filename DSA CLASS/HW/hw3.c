#include <stdio.h>
#include <string.h>
/*Write a function to perform basic string compression using the counts of repeated characters.
For example, the string "aabcccccaaa" would become "a2b1c5a3". If the "compressed" string would 
not become smaller than the original string, your function should return the original string.*/
void compress(char *str, char *com) 
{// Function to compress a string
    int n = strlen(str);
    int j = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        // Check if the next character is the same as the current one
        if (i+1 < n && str[i]==str[i+1]) 
        {
            count++;
        } 
        else 
        {
        // Append the current character and its count to the result
            com[j++]=str[i];
            com[j++]='0'+count;
            count=1; //Reset count
        }
    }
    com[j]='\0'; // Null-terminate the compressed string
    if (strlen(com) >= n) 
    {
        strcpy(com, str);
    }
}
int main() {
    char str[100];
    char com[200];
    printf("Enter a string: ");
    scanf("%s", str);
    compress(str, com);
    printf("Resulting string: %s\n", com);
    //printing the resulting string
    return 0;
}
