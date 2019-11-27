//
// Created by HP-EliteBook on 11/27/2019.
//

#ifndef CNC_2012_SECONDPROBLEM_H
#define CNC_2012_SECONDPROBLEM_H

/*****************************/
/* RC4 Encryption Algorithm */
/*****************************/

#define L1 256
#define L2 256
char cleanText[L1];
char key[L2];
char encryptedText[L1];
char K[256];
int S[256];

/************************************/
/* Phase I- Key Scheduling Algorithm*/

/**************/
/* Question 1 */
void s_identity(void) {
    for (int i = 0; i < 256; ++i) {
        S[i] = i;
    }
}

/**************/
/* Question 2 */
void k_initializer(void) {
    for (int i = 0; i < 256; ++i) {
        K[i] = key[i % L2];
    }
}

/**************/
/* Question 3 */
void swap_S(int i, int j) {
    int tmp = 0;
    tmp= S[i];
    S[i] = S[j];
    S[j] = tmp;
}

/**************/
/* Question 4 */
void ksa_algorithm(void) {
    s_identity();
    k_initializer();
    int i, j = 0;
    for (i = 0; i < 256; ++i) {
        j = (j + S[j] + K[i]) % 256;
        swap_S(i, j);
    }
}

/***********************************************/
/* Phase II- Pseudo Random Generator Algorithm */

/**************/
/* Question 5 */
typedef int (*do_operation)(int, int);

int do_operation_ptr(do_operation op, int a, int b) {
    return op(a, b);
}
int power(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; ++i) {
        p *= a;
    }
    return p;
}

void dec_to_bin(int bit[], int number) {
    for (int i = 0; i < 8; ++i) {

    }
}



#endif //CNC_2012_SECONDPROBLEM_H
