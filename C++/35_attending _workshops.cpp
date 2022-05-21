// https://www.hackerrank.com/challenges/attending-workshops/

#include<bits/stdc++.h>
#include<bits/stdc++.h>

#include<bits/stdc++.h>

using namespace std;

#include "iostream"
#include <vector>

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

// Enter your code here.
// --------------------------------------------------------- // 
struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int n = 0;
    vector<Workshop> workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops* ptr = new Available_Workshops;    
    if (n >= 1 && n <= 100000)
    {
        ptr->n = n;
        for (int i = 0; i < n; i++) {
            Workshop ws;
            ws.start_time = start_time[i];
            ws.duration = duration[i];
            ws.end_time = ws.start_time + ws.duration;
            ptr->workshops.push_back(ws);
        }
    }
    return ptr;
}

int CalculateMaxWorkshops(Available_Workshops * ptr)
{        
    std::sort(ptr->workshops.begin(), ptr->workshops.end(), [](const Workshop  &a, const Workshop &b)
    { 
        return a.end_time < b.end_time; 
    });
    
    int end_time = 0;
    int count = 0;
    
    for (int i = 0; i < ptr->n; i++) {
        if (ptr->workshops[i].start_time >= end_time) {
            end_time = ptr->workshops[i].end_time;
            count++;
        }
    }    
    return count;
}
// --------------------------------------------------------- // 

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
