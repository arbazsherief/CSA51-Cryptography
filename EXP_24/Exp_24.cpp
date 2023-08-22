#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int extendedGCD(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcdValue = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcdValue;
}

int modInverse(int a, int m) {
    int x, y;
    int gcdValue = extendedGCD(a, m, &x, &y);

    if (gcdValue != 1) {
        printf("The modular inverse does not exist.\n");
        return -1;
    }

    return (x % m + m) % m;
}

int main() {
    int e = 31;
    int n = 3599;
    int p, q;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }

    int phi_n = (p - 1) * (q - 1);
    int d = modInverse(e, phi_n);

    if (d != -1) {
        printf("Private Key (d): %d\n", d);
    }

    return 0;
}

