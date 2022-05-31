// USEFUL LINKS
// https://www.toptal.com/developers/sorting-algorithms/bubble-sort
// https://www.geeksforgeeks.org/bubble-sort/

#include <iostream>
#include <vector>

template <typename T> void printVector(std::vector<T> t)
{
    std::cout << "{";
    for (int i = 0; i < t.size() - 1; i++) {
        std::cout << t[i] << ", ";
    }
    if (t.size() > 0) {
        std::cout << t[t.size() - 1];
    }
    
    std::cout << "}" << std::endl;
}

std::vector<int> bubbleSortFast(std::vector<int> data) {
    for(int step = 0; step < data.size(); step++) {
        bool sorted = false;
        for(int i = 0; i < data.size() - step; i++) {
            if (data[i] > data[i + 1]) {
                int temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                sorted = true;
            }
        }
        if (!sorted) {
            break;
        }
    }
    return data;
}

std::vector<int> bubbleSort(std::vector<int> data) {
    for(int step = 0; step < data.size(); step++) {
        for(int i = 0; i < data.size() - step; i++) {
            if (data[i] > data[i + 1]) {
                int temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
    }
    return data;
}

int main()
{
    std::vector<int> data {5, 32, 6, -85, 696, 0, 13, -99, 147, 1};
    std::cout << "Original Data: ";
    printVector(data);
    
    data = bubbleSortFast(data); 
    std::cout << "Sorted Data  : ";
    printVector(data);
    return 0;
}

// ---------------------------- OUTPUT ---------------------------- // 
// Original Data: {5, 32, 6, -85, 696, 0, 13, -99, 147, 1}
// Sorted Data  : {-99, -85, 0, 1, 5, 6, 13, 32, 147, 696}