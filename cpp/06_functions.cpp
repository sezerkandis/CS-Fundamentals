// https://www.hackerrank.com/challenges/c-tutorial-functions/problem

#include <iostream>
#include <cstdio>
using namespace std;

// Enter your code here.
// --------------------------------------------------------- // 
int max_of_four(int x, int y, int z, int t)
{
    int max = 0;
    if (x > max)
        max = x;
    if (y > max)
        max = y;
    if (z > max)
        max = z;
    if (t > max)
        max = t;
    return max;
}
// --------------------------------------------------------- // 

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

