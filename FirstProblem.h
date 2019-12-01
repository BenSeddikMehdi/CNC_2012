//
// Created by HP-EliteBook on 11/18/2019.
// Author : El Mehdi Benseddik
//

#ifndef CNC_2012_FIRSTPROBLEM_H
#define CNC_2012_FIRSTPROBLEM_H

#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/****************************/
/*A : String Representation*/
/****************************/
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
        if (string[i] != '0') break;
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
    return op_ptr(S1, S2, Sum);
}

char* add(char S1[], char S2[], char Sum[]) {
    unsigned int a = 0, i = 0, k = 0;
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


/****************************/
/*B : Linked List Representation*/
/****************************/

typedef struct List {
    int16_t part;
    struct List *next;
} NumberList_t;

/* Question 4 */
/**************/
/* Function to create a new node with given data */
NumberList_t* newNode(int16_t a) {
    NumberList_t* new_node = malloc(sizeof(NumberList_t));
    new_node->part = a;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the beginning of the Singly Linked List */
void push(NumberList_t** head_ref, int16_t a) {
    /* allocate node */
    NumberList_t* new_node = newNode(a);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)   = new_node;
}

NumberList_t* gatherNumbers(const char S[]) {// S = "7964 3756 9423 4"
    NumberList_t *firstElement = NULL;
    int16_t a = 0;
    int8_t n = 4;
    for (int j = 0; S[j] != '\0'; j = j + n) {
        a = 0;
        for (int i = j; i < n + j; ++i) {
            a += (S[i] - '0')*power(10,n+j-i-1);
        }
        push(&firstElement, a);
    }
    return firstElement;
}

void printStruct(NumberList_t *newStruct) {
    printf("part = ");
    while (newStruct != NULL) {
        printf("%d ", newStruct->part);
        newStruct = newStruct->next;
    }
    printf("\n");
}

#endif //CNC_2012_FIRSTPROBLEM_H
