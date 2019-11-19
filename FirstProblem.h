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
unsigned int length(const char string[]) {
    unsigned int i = 0;
    while (string[i] != '\0')i++;
    return i;
}
void adder(char S1[], char S2[], char Sum[]) {
    unsigned int a = 0, i = 0, k = 0;
    unsigned int n1 = length(S1), n2 = length(S2), n = 0;
    char ans[] = "";
    if (n1 > n2) {
        n = n1 + 1;
        for (i = 0; i < n2; ++i) {
            a = a / 10 + S1[n1-1-i] + S2[n2-1-i] - 2*'0';
            k = a % 10;
            ans[n-1-i] = (char) (k + '0');
        }
        ans[n-1-i] = '\0';
        /*for (k = i; k < n1; ++k) {
            a = a/10 + S1[n1-1-k] - '0';
            ans[n-1-k] = (char) (a%10 + '0');
        }
        ans[k] = (char) (a/10 + '0');
        ans[++k] = '\0';*/
        printf("Sum = %s\na = %u\n", ans, a);
    }
}

#endif //CNC_2012_FIRSTPROBLEM_H
