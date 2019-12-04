#include <stdio.h>
#include "FirstProblem.h"
#include "SecondProblem.h"
int main() {
    char string[] = "00663470789767009";
    NumberList_t *test = NULL;
    printf("the address of the first element = 0x%p\n", test);
    test = gatherNumbers(string);
    printf("the address of the first element = 0x%p\n", test);
    printStruct(test);
    printf("the address of the first element = 0x%p\n", test);
    free(test);
    return 0;
}