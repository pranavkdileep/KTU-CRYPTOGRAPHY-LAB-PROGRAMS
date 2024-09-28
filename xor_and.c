#include <stdio.h>
#include <string.h>

void perform_operation(char *str, char op) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (op == 'A') {
            str[i] &= 127;
        } else if (op == 'X') {
            str[i] ^= 127;
        } else if (op == 'O') {
            str[i] |= 127;
        }
    }
}

int main() {
    char str[50], str1[50];

    printf("Enter the string: ");
    scanf("%s", str1);

    strcpy(str, str1);
    perform_operation(str, 'X');
    printf("XOR Encrypted string: %s\n", str);

    strcpy(str, str1);
    perform_operation(str, 'A');
    printf("AND Encrypted string: %s\n", str);

    strcpy(str, str1);
    perform_operation(str, 'O');
    printf("OR Encrypted string: %s\n", str);

    return 0;
}