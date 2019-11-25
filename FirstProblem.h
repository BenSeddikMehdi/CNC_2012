//
// Created by HP-EliteBook on 11/18/2019.
// Author : El Mehdi Benseddik
//

#ifndef CNC_2012_FIRSTPROBLEM_H
#define CNC_2012_FIRSTPROBLEM_H

#include <string.h>

/* Question A-1 */
/****************/
//char S[] = "0000607";
int stringNumbers(const char string[]) {
    for (int i = 0; string[i] != '\0' ; ++i) {
        if (string[i] < '0' || string[i] > '9') return 0;
    }
    return 1;
}

/* Question A-2 */
/****************/
void deleteZeros(char string[]) {
    int i = 0, k = 0;
    for (i = 0; string[i] != '\0'; ++i) {
        if (string[i] != 48) break;
    }
    if (i < strlen(string)) {
        for (k = 0; string[i] != '\0'; ++k) {
            string[k] = string[i];
            i++;
        }
        string[k] = '\0';
    } else {
        string[k] = '0';
        string[k+1] = '\0';
    }
}

/* Question A-3 */
/****************/
unsigned int length(const char string[]) {
    unsigned int i = 0;
    while (string[i] != '\0')i++;
    return i;
}

unsigned int power(unsigned int a, unsigned int b) {
    unsigned int ans = 1;
    for (unsigned int i = 0; i < b; ++i) {
        ans *= a;
    }
    return ans;
}

void adder(char S1[], char S2[], char Sum[]) {
    unsigned int a = 0, i = 0, k = 0, b = 0, j = 0;
    unsigned int n1 = length(S1), n2 = length(S2), n = 0;
    n = n1 + 1;
    for (i = 0; i < n1; ++i) {
        a += (S1[n1-i-1] - '0')*power(10, i);
    }
    for (k = 0; k < n2; ++k) {
        b += (S2[n2-k-1] - '0')*power(10, k);
    }
    a += b;
    for (j = 0; j < n; ++j) {
        Sum[n-j-1] = (char)(a % 10 + '0');
        a /= 10;
    }
    Sum[j] = '\0';
    deleteZeros(Sum);
    printf("Sum = %s", Sum);
}

typedef char* (*do_operation) (char [], char [], char[]);

char* do_ptr(do_operation op_ptr, char S1[], char S2[], char Sum[]) {
    op_ptr(S1, S2, Sum);
}

char* add(char S1[], char S2[], char Sum[]) {
    unsigned int a = 0, i = 0, k = 0, b = 0, j = 0;
    unsigned int n1 = length(S1), n2 = length(S2), n = 0;
    if (n1 >= n2) {
        n = n1 + 1;
        char ans[n];
        for (i = 0; i < n2; ++i) {
            a = a/10 + S1[n1-i-1] + S2[n2-1-i] - 2*'0';
            ans[n-1-i] = (char) (a % 10 + '0');
        }
        for (k = i; k < n1; ++k) {
            a = a/10 + S1[n1-k-1] - '0';
            ans[n-1-k] = (char) (a % 10 + '0');
        }
        ans[n-1-k] = (char) (a/10 + '0');
        ans[n] = '\0';
        deleteZeros(ans);
        strcpy(Sum, ans);
    } else {
        n = n2 + 1;
        char ans[n];
        for (i = 0; i < n1; ++i) {
            a = a/10 + S1[n1-i-1] + S2[n2-1-i] - 2*'0';
            ans[n-1-i] = (char) (a % 10 + '0');
        }
        for (k = i; k < n2; ++k) {
            a = a/10 + S2[n2-k-1] - '0';
            ans[n-1-k] = (char) (a % 10 + '0');
        }
        ans[n-1-k] = (char) (a/10 + '0');
        ans[n] = '\0';
        deleteZeros(ans);
        strcpy(Sum, ans);
    }
    return Sum;
}


#endif //CNC_2012_FIRSTPROBLEM_H
