//
// Created by HP-EliteBook on 11/18/2019.
//

#ifndef CNC_2012_FIRSTPROBLEM_H
#define CNC_2012_FIRSTPROBLEM_H

#include <string.h>

/* Question A-1 */
/****************/
char S[] = "0000607";
int stringNumbers() {
    for (int i = 0; S[i] != '\0' ; ++i) {
        if (S[i] < 48 || S[i] > 57) return 0;
    }
    return 1;
}

/* Question A-2 */
/****************/
void deleteZeros() {
    int i = 0, k = 0;
    for (i = 0; S[i] != '\0'; ++i) {
        if (S[i] != 48) break;
    }
    if (i < strlen(S)) {
        for (k = 0; S[i] != '\0'; ++k) {
            S[k] = S[i];
            i++;
        }
        S[k] = '\0';
    } else {
        S[k] = '0';
        S[k+1] = '\0';
    }
}

/* Question A-3 */
/****************/
void adder(char S1[], char S2[], char Sum[]) {
    unsigned int a = 0, i = 0, k = 0;
    unsigned int n1 = strlen(S1), n2 = strlen(S2), n = 0;
    if (n1 > n2) {
        n = n1 + 1;
        for (i = 0; i < n2; ++i) {
            a = a/10 + S1[n1-i-1] + S2[n2-i-1] - 2*'0';
            Sum[n-1-i] = '0' + a%10;
        }
        for (k = i; k < n1; ++k) {
            a = a/10 + S1[n1-k-1] - '0';
            Sum[n-1-k] = '0' + a%10;
        }
        a = a/10 - '0';
        Sum[k] = a + '0';
        Sum[k+1] = '\0';
    }
    printf("Sum = %s", Sum);
}

#endif //CNC_2012_FIRSTPROBLEM_H
