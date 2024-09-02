#include<stdio.h>
#include<string.h>

void performoperation(char *str, char op)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(op == 'A')
        {
            str[i] = str[i] & 127;
        }
        else if(op == 'X')
        {
            str[i] = str[i] ^ 127;
        }
    }
}

int main()
{
    char str[] = "Hejjjjjjjjjjjjjjjjllo World!";
    performoperation(str, 'X');
    printf("Encrypted string: %s\n", str);
    strcpy(str, "Hello World!");
    performoperation(str, 'A');
    printf("Encrypted string: %s\n", str);
    return 0;
}