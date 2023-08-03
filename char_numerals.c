#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void addStringNumerals(char a[N], char b[N], char c[N]);
void mulStringNumerals(char a[N], char b[N], int x);
char *factorial(int n);

int main() {
    char a[N] = "5";
    char b[N] = "81";
    char c[N];

    addStringNumerals(a, b, c);
    printf("RESULT: %s\n", strrev(c));

    mulStringNumerals(a, c, 100);
    printf("RESULT: %s\n", strrev(c));

    printf("FACTORIAL RESULT: %s\n", factorial(5));

    return 0;
}

// a + b = c
void addStringNumerals(char a[N], char b[N], char c[N]) {
    int i, len_long, len_a, len_b, carry, digit_a, digit_b, digit_sum;
    char copy_a[N], copy_b[N];

    strcpy(copy_a, a);
    strcpy(copy_b, b);
    // Is copy necessary??
    len_a = strlen(copy_a);
    len_b = strlen(copy_b);
    if (len_a > len_b) {
        len_long = len_a;
    } else {
        len_long = len_b;
    }

    carry = 0;
    for (i = 0; i < len_long; i++) {

        if (i >= len_a) 
            digit_a = 0;
        else 
            digit_a = copy_a[i] - '0';
        if (i >= len_b)
            digit_b = 0;
        else 
            digit_b = copy_b[i] - '0';

        if (carry == 1) {
            digit_a += 1;
            carry = 0;
        }

        if (digit_a + digit_b > 9) {
            digit_sum = digit_a + digit_b - 10;
            carry = 1;
        } else {
            digit_sum = digit_a + digit_b;
            carry = 0;
        }
        c[i] = digit_sum + '0';
    }

    if (carry == 1) {
        c[i] = '1';
        c[i+1] = '\0';
    } else {
        c[i] = '\0';
    }
}

// x times a -> b
void mulStringNumerals(char a[N], char b[N], int x) {
    int i;
    strcpy(b, a);
    for (i = 1; i < x; i++) {
        addStringNumerals(a, b, b);
    }
}

char *factorial(int n) {
    int i;
    char *a = (char*) calloc(N, sizeof(char));
    char b[N];

    a[0] = '1';
    a[1] = '\0';

    for (i = 2; i <= n; i++) {
        mulStringNumerals(a, b, i);
        strcpy(a, b);
    }
    strrev(a);

    return a;  
}

