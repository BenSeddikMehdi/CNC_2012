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
char cleanText[L1] = "";
char key[L2] = "";
char encryptedText[L1] = "";
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
/***********************************************/

/**************/
/* Question 5 */
void dec_to_bin(int bit[], int number) {
    for (int i = 0; i < 8; ++i) {
        bit[8-i-1] = number % 2;
        number /= 2;
    }
}

/**************/
/* Question 6 */
typedef int (*do_two_power) (int);

int do_two_power_operation(do_two_power op, int a) {
    return op(a);
}

int two_to_power(int n) {
    if (n == 0) {
        return 1;
    } else {
        return 2*two_to_power(n-1);
    }
}

/**************/
/* Question 7 */
typedef int (*do_bin_to_dec) (const int []);

int do_bin_to_dec_operation(do_bin_to_dec op, const int bit[]) {
    return op(bit);
}

int bin_to_dec(const int bit[]) {
    int octet = 0;
    for (int i = 0; i < 8; ++i) {
        octet += bit[i]*do_two_power_operation(two_to_power,8-i-1);
    }
    return octet;
}

/**************/
/* Question 8 */
typedef int (*do_exclusive) (int, int);

int do_or_exclusive(do_exclusive op, int x, int y) {
    return op(x, y);
}

int orExclusive(int x, int y) {
    int xBin[8] = {0}, yBin[8] = {0}, zBin[8] = {0};
    dec_to_bin(xBin, x);
    dec_to_bin(yBin, y);
    for (int i = 0; i < 8; ++i) {
        if (xBin[i] == yBin[i]) zBin[i] = 0;
        else zBin[i] = 1;
    }
    return do_bin_to_dec_operation(bin_to_dec, zBin);
}

/**************/
/* Question 9 */
void pgra_algorithm(void) {
    int i = 0, j = 0;
    int octet;
    for (int a = 0; a < L1-1; ++a) {
        i = (i + 1) % 256;
        j = (j + cleanText[i]) % 256;
        swap_S(i, j);
        octet = S[(S[i] + S[j]) % 256];
        encryptedText[a] = (char) do_or_exclusive(orExclusive, key[a], octet);
    }
}

/********************************************************/
/* Part B: Encryption of a text file using RC4 Algorithm*/
/********************************************************/

/*****************/
/* Question 10-a */

typedef char* (*RC4_Algorithm)(char*, int, char*);

char* do_rc4_string(RC4_Algorithm op, char* rawString, int L, char* rc4_key) {
    return op(rawString, L, rc4_key);
}

char* rc4String(char* rawString, int L, char* rc4_key) {
    strncpy(rawString, cleanText, L);
    strncpy(rc4_key, key, L2);
    pgra_algorithm();
    return encryptedText;
}

/*****************/
/* Question 10-b */

typedef void (*RC4_Algorithm_File)(char*, char*, char*);

void do_rc4_file(RC4_Algorithm_File op, char* rawFile, char* rc4key, char* encryptedFile){
    op(rawFile, rc4key, encryptedFile);
}

void rc4File(char* rawFile, char* rc4key, char* encryptedFile) {
    FILE* pFile = fopen(rawFile, "r");
    FILE* pEncryptedFile = fopen(encryptedFile, "w");
    while (pFile != NULL) {
        char* line = NULL;
        fgets(line, 80, pFile);
        fputs(do_rc4_string(rc4String, line, 80, rc4key), pEncryptedFile);
    }
}

#endif //CNC_2012_SECONDPROBLEM_H
