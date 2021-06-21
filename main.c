#include <stdio.h>

extern int add (int, int);
extern int sub(int,int);

int main() {
    printf("%d\n", add(1,2));
    printf("%d", sub(2,1));
    return 0;
}
