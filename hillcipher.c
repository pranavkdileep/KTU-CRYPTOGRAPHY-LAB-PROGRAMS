#include<stdio.h>
#include<string.h>


void encrypt(char plaintext[3],int keyarr[3][3])
{
int plainarr[3];
for(int i =0;i<3;i++)
{
plainarr[i] = plaintext[i] - 'a';
}

//printf("\nAfter encryption\n");
// multiply and mod
int result[3];
for (int i = 0; i < 3; i++) 
{
result[i] = 0;
}
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
result[i] += keyarr[i][j] * plainarr[j];

}

result[i] = result[i]%26;


}
//end multiplication and mod
char cipher[3];
for(int i =0;i<3;i++)
{
cipher[i] = result[i] + 'a';
}
for(int i =0;i<3;i++)
{
printf("%c",cipher[i]);
}



}



int main()
{
int temp=0,i;
int keyarr[3][3];
char plaintext[100];

printf("Enter Key Matrix:\n");
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
scanf("%d",&keyarr[i][j]);
}
}

printf("\nEnter Plain Text: ");
scanf("%s",plaintext);

char chunk[3]; 

int len = strlen(plaintext);

for (int i = 0; i < len; i += 3) {

int j;
for (j = 0; j < 3 && (i + j) < len; j++) {
chunk[j] = plaintext[i + j];
}


encrypt(chunk,keyarr);
}





}

#include <stdio.h>
#include <string.h>

// Function to find the determinant of a 3x3 matrix
int determinant(int matrix[3][3]) {
    int det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
            - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
            + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det % 26;
}

// Function to find the modular inverse of a number under modulo 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Function to find the adjugate of a 3x3 matrix
void adjugate(int matrix[3][3], int adj[3][3]) {
    adj[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) % 26;
    adj[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) % 26;
    adj[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) % 26;
    adj[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) % 26;
    adj[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) % 26;
    adj[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) % 26;
    adj[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) % 26;
    adj[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) % 26;
    adj[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26;
}

// Function to find the inverse of a 3x3 matrix under modulo 26
void inverseMatrix(int matrix[3][3], int inv[3][3]) {
    int det = determinant(matrix);
    int invDet = modInverse(det, 26);
    int adj[3][3];
    adjugate(matrix, adj);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inv[i][j] = (adj[i][j] * invDet) % 26;
            if (inv[i][j] < 0) {
                inv[i][j] += 26;
            }
        }
    }
}

// Function to decrypt a chunk of ciphertext
void decrypt(char ciphertext[3], int keyarr[3][3]) {
    int invKey[3][3];
    inverseMatrix(keyarr, invKey);

    int cipherarr[3];
    for (int i = 0; i < 3; i++) {
        cipherarr[i] = ciphertext[i] - 'a';
    }

    int result[3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i] += invKey[i][j] * cipherarr[j];
        }
        result[i] = result[i] % 26;
    }

    char plain[3];
    for (int i = 0; i < 3; i++) {
        plain[i] = result[i] + 'a';
    }

    for (int i = 0; i < 3; i++) {
        printf("%c", plain[i]);
    }
}

int main() {
    int keyarr[3][3];
    char ciphertext[100];

    printf("Enter Key Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &keyarr[i][j]);
        }
    }

    printf("\nEnter Cipher Text: ");
    scanf("%s", ciphertext);

    char chunk[3];
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i += 3) {
        int j;
        for (j = 0; j < 3 && (i + j) < len; j++) {
            chunk[j] = ciphertext[i + j];
        }
        while (j < 3) {
            chunk[j++] = 'x'; // Padding with 'x' if necessary
        }
        decrypt(chunk, keyarr);
    }

    return 0;
}