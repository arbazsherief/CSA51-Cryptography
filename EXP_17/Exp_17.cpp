#include <stdio.h>

void generateSubkeys(const unsigned char *masterKey, unsigned char subkeys[16][6]) {
 
    unsigned char leftHalf[4];
    unsigned char rightHalf[4];
    int i,round,j;
    for ( i = 0; i < 4; i++) {
        leftHalf[i] = masterKey[i];
        rightHalf[i] = masterKey[i + 4];
    }

   
    for ( round = 0; round < 16; round++) {
       
        int shiftAmount = (round < 2 || round == 8 || round == 15) ? 1 : 2;
        for (i = 0; i < shiftAmount; i++) {
            unsigned char temp = leftHalf[0];
            for (j = 0; j < 3; j++) {
                leftHalf[j] = leftHalf[j + 1];
                rightHalf[j] = rightHalf[j + 1];
            }
            leftHalf[3] = temp;
            rightHalf[3] = temp;
        }
        for ( i = 0; i < 3; i++) {
            subkeys[round][i] = leftHalf[i];
            subkeys[round][i + 3] = rightHalf[i];
        }
    }
}

int main() {
    int i,j;
    unsigned char masterKey[8] = {0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1};

    unsigned char subkeys[16][6];

    generateSubkeys(masterKey, subkeys);

   
    printf("Generated Subkeys:\n");
    for (i = 0; i < 16; i++) {
        printf("Subkey %2d: ", i + 1);
        for (j = 0; j < 6; j++) {
            printf("%02X ", subkeys[i][j]);
        }
        printf("\n");
    }

    return 0;
}
