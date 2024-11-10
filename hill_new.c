#include<stdio.h>
#include<string.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

int main() {
    int a[3][3] = { { 1, 2, 3 }, { 0, 1, 4 }, { 5, 6, 0 } };
    int b[3][3];
    int determinant = 0;

    // Calculate determinant
    for(int i = 0; i < 3; i++) {
        determinant += a[0][i] * (a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][(i+1)%3]);
    }

    // Calculate modular inverse of determinant
    int det_inv = modInverse(determinant, 26);

    // Calculate inverse matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            b[j][i] = ((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3] - a[(i+1)%3][(j+2)%3] * a[(i+2)%3][(j+1)%3]) * det_inv) % 26;
            if (b[j][i] < 0) {
                b[j][i] += 26;
            }
        }
    }

    // Print inverse matrix
    printf("Inverse Matrix: \n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }


    int c[3],p[3];
    char s[4];
    printf("Enter Plain Text: ");
    scanf("%s", s);
    for(int i=0;i<3;i++) {
        p[i] = s[i] - 65;
        printf("%d ", p[i]);
    }
    printf("\n");
    for(int i=0;i<3;i++) {
        int t = 0;
        for(int j=0;j<3;j++) {
            t += a[i][j]*p[j];
        }
        c[i] = t % 26;
    }
    printf("Cipher Text: ");
    for(int i=0;i<3;i++) {
        printf("%c", c[i] + 65);
    }
    printf("\n");
    for(int i=0;i<3;i++) {
        int t = 0;
        for(int j=0;j<3;j++) {
            t += b[i][j]*c[j];
        }
        p[i] = t % 26;
    }
    printf("Decipher Text: ");
    for(int i=0;i<3;i++) {
        printf("%c", p[i] + 65);
    }
    printf("\n");

    return 0;
}