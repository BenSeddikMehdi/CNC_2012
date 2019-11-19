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
}

#endif //CNC_2012_FIRSTPROBLEM_H
