// https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int valInteger;
    long valLong;
    char valChar;
    float valFloat;
    double valDouble;

    // Enter your code here.
    // --------------------------------------------------------- // 
    scanf("%d %ld %c %f %lf", &valInteger, &valLong, &valChar, &valFloat, &valDouble);
    printf("%d\n%ld\n%c\n%0.3f\n%0.9lf", valInteger, valLong, valChar, valFloat, valDouble);
    // --------------------------------------------------------- // 
	
    return 0;
}

