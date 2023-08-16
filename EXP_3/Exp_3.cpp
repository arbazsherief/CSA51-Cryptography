#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char keyMatrix[SIZE][SIZE];

void generateKeyMatrix(const char *key) {
    int i, j, k = 0;
    int filled[26] = {0};

    for (i = 0; i < strlen(key); i++) {
        if (!filled[toupper(key[i]) - 'A']) {
            keyMatrix[k / SIZE][k % SIZE] = toupper(key[i]);
            filled[toupper(key[i]) - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!filled[i] && i != ('J' - 'A')) {
            keyMatrix[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }
}

void encryptPlayfair(const char *plainText, char encryptedText[]) {
    int len = strlen(plainText);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;

        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (keyMatrix[r][c] == toupper(plainText[i])) {
                    row1 = r;
                    col1 = c;
                }
                if (keyMatrix[r][c] == toupper(plainText[i + 1])) {
                    row2 = r;
                    col2 = c;
                }
            }
        }

        if (row1 == row2) {
            encryptedText[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            encryptedText[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedText[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            encryptedText[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            encryptedText[i] = keyMatrix[row1][col2];
            encryptedText[i + 1] = keyMatrix[row2][col1];
        }
    }
    encryptedText[len] = '\0';
}

int main() {
    char key[100];
    char plainText[100];
    char encryptedText[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plainText);

    generateKeyMatrix(key);
    encryptPlayfair(plainText, encryptedText);

    printf("Key Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", keyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Original text: %s\n", plainText);
    printf("Encrypted text: %s\n", encryptedText);

    return 0;
}
