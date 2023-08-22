#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16

void cbc_mac(unsigned char *key, unsigned char *iv, unsigned char *plaintext, unsigned char *mac) {
    unsigned char block[BLOCK_SIZE];
    memcpy(block, iv, BLOCK_SIZE);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= plaintext[i];
    }

    for (int i = 1; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= mac[j];
        }
    }

    memcpy(mac, block, BLOCK_SIZE);
}

int main(int argc, char *argv[]) {
    unsigned char key[BLOCK_SIZE] = "012345abcdef";
    unsigned char iv[BLOCK_SIZE] = "012345abcdef";
    unsigned char plaintext[BLOCK_SIZE] = "Hello World!!!\0";
    unsigned char mac[BLOCK_SIZE];

    cbc_mac(key, iv, plaintext, mac);

    printf("MAC is:\n");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", mac[i]);
    }
    printf("\n");

    return 0;
}

