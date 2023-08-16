#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *encryptMessage(const char *plaintext, const char *key) {
    char *ciphertext = (char *)malloc(strlen(plaintext) + 1);

    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = key[plaintext[i] - 'A'];
            } else {
                ciphertext[i] = tolower(key[plaintext[i] - 'a']);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

int main() {
    char plaintext[1000];
    char key[26];

    printf("Enter the plaintext: ");
    scanf("%[^\n]s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    char *ciphertext = encryptMessage(plaintext, key);

    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: %s\n", ciphertext);

    free(ciphertext);

    return 0;
}
