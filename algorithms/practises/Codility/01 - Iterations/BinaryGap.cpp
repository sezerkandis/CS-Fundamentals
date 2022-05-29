// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cmath>
// https://app.codility.com/demo/results/training7V4PDQ-MPU/
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    //int number_pf_bits = floor(std::log2(N)) + 1;
    //cout << number_pf_bits << endl;

    int maximum_gap = 0;
    int temp_gap = 0;
    bool found_one = false;
    while(N > 0)
    {
        bool binary = N % 2;
        if (binary == 1)
            found_one = true;
       
        //cout << int(binary) << endl;
        if (found_one)
        {
            if (binary == 0)
            {
                temp_gap++;
                //cout << "temp_gap:" << temp_gap << endl;
            }
            else  if (temp_gap > 0)
            {               
                if (temp_gap > maximum_gap)
                    maximum_gap = temp_gap;

                //cout << "maximum_gap:" << maximum_gap << endl;
                temp_gap = 0;
            }
        }
        else
            temp_gap = 0;

        N = N / 2;
    }
    return maximum_gap;
}