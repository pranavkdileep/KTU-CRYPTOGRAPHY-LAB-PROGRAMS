#include<stdio.h>

int main()
{
    char message[100];
    printf("Enter the message: ");
    scanf("%s",message);
    for(int i =0;message[i] != '\0';i++)
    {
        message[i] = message[i] ^ 10;
    }
    printf("XOR: %s\n",message);
    for(int i =0;message[i] != '\0';i++)
    {
        message[i] = message[i] ^ 10;
    }
    printf("Original: %s\n",message);
    return 0;
}