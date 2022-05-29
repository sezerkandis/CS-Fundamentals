// https://www.hackerrank.com/challenges/c-tutorial-pointer/

#include <stdio.h>

void update(int *a,int *b) {
    // Enter your code here.
    // --------------------------------------------------------- // 
    printf("%d\n", (*a) + (*b));
    int sub = (*a) - (*b);
    if (sub < 0) {
        sub *= (-1);
    }
	printf("%d\n", sub);
    // --------------------------------------------------------- // 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    //printf("%d\n%d", a, b);

    return 0;
}