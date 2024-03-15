/* Chef recently graduated Computer Science in university, so he was looking for a job. 
 * He applied for several job offers, but he eventually settled for a software engineering job at ShareChat. 
 * Chef was very enthusiastic about his new job 
 * and the first mission assigned to him was to implement a message encoding feature to ensure the chat is private and secure.

Chef has a message, which is a string S with length N containing only lowercase English letters. 
It should be encoded in two steps as follows:

Swap the first and second character of the string S, 
then swap the 3rd and 4th character, then the 5th and 6th character and so on. 
If the length of S is odd, the last character should not be swapped with any other.
Replace each occurrence of the letter 'a' in the message obtained after the first step by the letter 'z', 
each occurrence of 'b' by 'y', each occurrence of 'c' by 'x', etc, 
and each occurrence of 'z' in the message obtained after the first step by 'a'.
The string produced in the second step is the encoded message.
Help Chef and find this message. */


#include<stdio.h>
#include<string.h>
void swap(char *,int );
void replace(char *);


int main()
{
    int t;
    printf("enter the no of test\n");
    scanf("%d",&t);

    while(t--)
    {
        int len;
        printf("enter the length of string\t");
        scanf("%d",&len);
        char str[len];
        printf("\nenter the string\t");
        scanf("%s",str);
        
        if((islower(str)))
            {
                printf("\nplease enter lower case only\n");
            }
        else
            {
                swap(str,len);   
            }
        
    }
}

void swap(char *str,int len)
{

    char temp;
    if(len%2==0)
    {
        for(int i=0;i<len-1;i=i+2)
        {
            temp = str[i];
            str[i]= str[i+1];
            str[i+1]= temp;
        }
    }
    else
    {
        for(int i=0;i<len-2;i=i+2)
        {
            temp = str[i];
            str[i] = str[i+1];
            str[i+1] = temp;
        }
    }
    printf("after swapping the string is %s\n",str);
    replace(str);
}

void replace(char *str)
{
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        str[i] = 'z' + 'a' - str[i];
    }
    printf("the encoded string is %s\n",str);
}
