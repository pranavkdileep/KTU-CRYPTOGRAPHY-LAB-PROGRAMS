#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main() {
    char instr[100], crypt[100], decrypt[100];
    int shift, k;

    printf("\n Enter your string\n");
    fgets(instr, sizeof(instr), stdin);  // Use fgets to read a full line

    printf("\n Enter your key\n");
    scanf("%d", &shift);

    printf("\nOriginal string is: %s", instr);

    // Encryption
    for (k = 0; instr[k] != '\0'; k++) {
        char aa = tolower(instr[k]);  // Convert to lowercase
        if (aa >= 'a' && aa <= 'z') { // Only shift alphabetic characters
            aa = ((aa - 'a' + shift) % 26) + 'a';
        }
        crypt[k] = aa;
    }
    crypt[k] = '\0'; // Null-terminate the encrypted string
    printf("\nEncrypted string is: %s", crypt);

    // Decryption
    for (k = 0; crypt[k] != '\0'; k++) {
        char aa = crypt[k];
        if (aa >= 'a' && aa <= 'z') { // Only shift alphabetic characters
            aa = ((aa - 'a' - shift + 26) % 26) + 'a';  // Handle negative shifts
        }
        decrypt[k] = aa;
    }
    decrypt[k] = '\0'; // Null-terminate the decrypted string
    printf("\nDecrypted string is: %s", decrypt);
}
