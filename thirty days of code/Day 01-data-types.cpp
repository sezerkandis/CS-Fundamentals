// https://www.hackerrank.com/challenges/30-data-types/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    
    // Read and save an integer, double, and String to your variables.
    
    // Print the sum of both integer variables on a new line.
    
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

// Enter your code here.
// --------------------------------------------------------- // 
    int integer;
    double decimal;
    string str;
    std::cin >> integer >> decimal;
    std::getline(std::cin, str);
    std::getline(std::cin, str);

    std::cout <<  i + integer << std::endl;
    std::cout <<  std::setprecision(1) << std::fixed << d + decimal << std::endl;
    std::cout <<  s + str << std::endl;
// --------------------------------------------------------- // 
    
    return 0;
}