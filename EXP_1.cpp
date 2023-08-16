#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char *text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            } else if (islower(text[i])) {
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            }
        }
    }
}

int main() {
    char text[1000];
    int shift;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Shift value should be between 1 and 25.\n");
        return 1;
    }

    caesarCipher(text, shift);

    printf("Encrypted message: %s\n", text);

    caesarCipher(text, 26 - shift);
    printf("Decrypted message: %s\n", text);

    return 0;
}
