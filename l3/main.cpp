#include<iostream>
#include<chrono>
#include"f.h"
using namespace std;
int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    int original[n],v1[n],v2[n],v3[n],temp[n];
    generare(original, n);
    for(int i=0;i<n;i++)
    {
        v1[i]=original[i];v2[i]=original[i];v3[i]=original[i];
    }

    //mergesort
    auto start = chrono::high_resolution_clock::now();
    mergeSort(v1,0,n-1,temp);
    auto end = chrono::high_resolution_clock::now();
    auto duration = (end - start);
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(duration); // Microsecond (as int)
    cout<<"mergeSort->"<<us.count()<<" microsec\n";

    //quicksor1
    start = chrono::high_resolution_clock::now();
    mergeSort(v2,0,n-1,temp);
    end = chrono::high_resolution_clock::now();
    duration = (end - start);
    us = std::chrono::duration_cast<std::chrono::microseconds>(duration); // Microsecond (as int)
    cout<<"quickSort1->"<<us.count()<<" microsec\n";

    //quickSort2
    start = chrono::high_resolution_clock::now();
    mergeSort(v3,0,n-1,temp);
    end = chrono::high_resolution_clock::now();
    duration = (end - start);
    us = std::chrono::duration_cast<std::chrono::microseconds>(duration); // Microsecond (as int)
    cout<<"quickSort2->"<<us.count()<<" microsec\n";
    return 0;
}
/*
mergeSort->1782 microsec
quickSort1->1125 microsec
quickSort2->847 microsec
pt un test, quickSort2 win
*/