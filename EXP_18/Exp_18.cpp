#include <stdio.h>
#define KEY_SIZE 64
#define SUBKEY_SIZE 48
unsigned char initialKey[KEY_SIZE] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF
};
int keyCompressionPermTable[SUBKEY_SIZE] = {
    14, 17, 11, 24, 1, 5, 3, 28,
    15, 6, 21, 10, 23, 19, 12, 4,
    26, 8, 16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32
};

void generateSubkeys(unsigned char *key, unsigned char *subkeys) {
    unsigned char leftKey[KEY_SIZE / 2];
    unsigned char rightKey[KEY_SIZE / 2];
        for (int round = 0; round < 16; ++round) {
        for (int i = 0; i < SUBKEY_SIZE; ++i) {
            int index = keyCompressionPermTable[i] - 1;
            subkeys[round * SUBKEY_SIZE + i] = key[index];
        }
    }
}

int main() {
    unsigned char subkeys[16 * SUBKEY_SIZE];
    
    generateSubkeys(initialKey, subkeys);
    for (int round = 0; round < 16; ++round) {
        printf("Subkey %2d:", round + 1);
        for (int i = 0; i < SUBKEY_SIZE / 8; ++i) {
            printf(" %02X", subkeys[round * SUBKEY_SIZE + i]);
        }
        printf("\n");
    }
    
    return 0;
}
