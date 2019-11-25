#include <stdio.h>
#include "FirstProblem.h"

int main() {
    char *ans;
    //adder("9843","19",Sum);
    ans = do_ptr(add,"123","324");
    printf("Sum = %s\n", ans);

    return 0;
}