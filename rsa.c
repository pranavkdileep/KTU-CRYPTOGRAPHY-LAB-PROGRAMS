#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0) {  // Fixed = to == for comparison
        return a;
    }
    return gcd(b, a % b);
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generatePrime() {
    int num;
    do {
        num = rand() % 100 + 2; // Generate a random number between 2 and 101
    } while (!isPrime(num));
    return num;
}

int calculateE(int phi) {
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            return e;
        }
    }
    return -1; // In case no valid 'e' is found
}

int calculateD(int e, int phi) {
    int d = 1;
    while (1) {
        if ((d * e) % phi == 1) {
            break;
        }
        d++;
    }
    return d;
}

int encrypt(int plaintext, int e, int n) {
    int cipher = 1;
    for (int i = 0; i < e; ++i) {
        cipher = (cipher * plaintext) % n;
    }
    return cipher;
}

int decrypt(int ciphertext, int d, int n) {
    int plain = 1;
    for (int i = 0; i < d; ++i) {
        plain = (plain * ciphertext) % n;
    }
    return plain;
}

int main() {
    srand(time(NULL));  // Added random seed initialization
    
    int p, q, n, phi, e, d;
    int plaintext = 499; // Message to encrypt
    
    // Generate two different prime numbers
    do {
        p = generatePrime();
        q = generatePrime();
    } while (p == q);  // Ensure p and q are different
    
    n = p * q;
    phi = (p - 1) * (q - 1);
    
    e = calculateE(phi);
    if (e == -1) {
        printf("Error: Could not find valid public exponent\n");
        return 1;
    }
    
    d = calculateD(e, phi);
    
    // Encryption
    int ciphertext = encrypt(plaintext, e, n);
    
    // Decryption
    int decryptedtext = decrypt(ciphertext, d, n);
    
    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decrypted text: %d\n", decryptedtext);
    
    return 0;
}