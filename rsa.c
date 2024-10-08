#include <stdio.h>

#include <stdlib.h>

#include <math.h>

int ged(int a, int b) {

if (b= 0) {

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

int generate Prime() {

int num;

do {

num = rand() % 100 + 2; // Generate a random number between 2 and 101 (not very

secure)

} while (!isPrime(num));
return num;

}

calculateE(int phi) { int

int e = 2;

while (e < phi) {

if (gcd(e, phi)=1) { break; } } return e;

e++;

}

int calculateD(int e, int phi) {

int d = 1;

while (1) {

if ((de)% phi = 1) { break; } }

d++;

return d;

}

int encrypt(int plaintext, int e, int n) {

int cipher = 1;

for (int i=0; i<e; ++i) {

cipher (cipher * plaintext) % n;

}

return cipher;

}

int decrypt(int ciphertext, int d, int n) {

int plain = 1;

for (int i = 0; i < d; ++i) {

plain (plain ciphertext) % n; }

return plain;

}

int main() {

int p, q, n, phi, e, d;

int plaintext = 88; // Message to encrypt
// Generate two random prime numbers

p = generatePrime();

q = generate Prime();

n = p * q; *

phi (p-1)* (q - 1);

e = calculateE(phi);

d = calculateD(e, phi);

// Encryption int ciphertext = encrypt(plaintext, e, n);

// Decryption int decryptedtext = decrypt(ciphertext, d, n);

printf("Plaintext: %d\n", plaintext);

printf("Ciphertext: %d\n", ciphertext); printf("Decrypted text: %d\n", decryptedtext);

return 0;

}
