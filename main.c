#include <stdio.h>
#include "FirstProblem.h"
#include "SecondProblem.h"
int main() {
    char string[] = "65438276";
    NumberList_t *test;
    test = gatherNumbers(string);
    printStruct(test);
    return 0;
}