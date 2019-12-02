#include <stdio.h>
#include "FirstProblem.h"
#include "SecondProblem.h"
int main() {
    char string[] = "000000000080";
    NumberList_t *test = NULL;
    test = gatherNumbers(string);
    printStruct(test);
    free(test);
    return 0;
}