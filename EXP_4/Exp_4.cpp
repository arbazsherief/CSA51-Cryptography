#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptVigenere(const char *plaintext, const char *key, char *ciphertext) {
    int keyLength = strlen(key);
    int textLength = strlen(plaintext);

    for (int i = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) {
            int keyIndex = i % keyLength;
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + key[keyIndex] - 'A') % 26 + base;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[textLength] = '\0';
}

int main() {
    char plaintext[1000];
    char key[100];

    printf("Enter the plaintext: ");
    scanf("%[^\n]s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    char ciphertext[1000];
    encryptVigenere(plaintext, key, ciphertext);

    printf("Original message: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}
