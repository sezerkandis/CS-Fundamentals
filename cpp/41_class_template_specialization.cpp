https://www.hackerrank.com/challenges/cpp-class-template-specialization

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Enter your code here.
// --------------------------------------------------------- // 
	
#include <vector>
std::vector<std::string> fruits { "apple", "orange", "pear" };
std::vector<std::string> colors { "red", "green", "orange" };

template<>
struct Traits<Fruit> {
    static std::string name(int index) {
        if (index < 0 || index >= 3) {
            return "unknown";
        }
        return fruits.at(index).c_str();
    }
};

template<>
struct Traits<Color> {
    static std::string name(int index) {
        if (index < 0 || index >= 3) {
            return "unknown";
        }
        return colors.at(index).c_str();
    }
};

// --------------------------------------------------------- // 

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
