#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int valInteger;
    long valLong;
    char valChar;
    float valFloat;
    double valDouble;

    scanf("%d %ld %c %f %lf", &valInteger, &valLong, &valChar, &valFloat, &valDouble);
    printf("%d\n%ld\n%c\n%0.3f\n%0.9lf", valInteger, valLong, valChar, valFloat, valDouble);

    // Complete the code.
    return 0;
}

