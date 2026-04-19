#include<iostream>
#include<chrono>
#include<vector>
#include"f.h"
using namespace std;

int main()
{
    int n;
    cout << "n (putere a lui 2) = ";
    cin >> n;

    vector<int> v(n);

    // crescator
    array_sortat_cresc(v.data(), n);

    auto start = chrono::high_resolution_clock::now();
    batcher_sort(v.data(), 0, n, 0);
    auto end = chrono::high_resolution_clock::now();

    auto us = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "a-> " << us.count() << " microsec\n";


    // descrescator
    array_sortat_desc(v.data(), n);

    start = chrono::high_resolution_clock::now();
    batcher_sort(v.data(), 0, n, 0);
    end = chrono::high_resolution_clock::now();

    us = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "b-> " << us.count() << " microsec\n";


    // random
    generare(v.data(), n);

    start = chrono::high_resolution_clock::now();
    batcher_sort(v.data(), 0, n, 0);
    end = chrono::high_resolution_clock::now();

    us = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "c-> " << us.count() << " microsec\n";

    return 0;
}
/*
a-> 4801 microsec
b-> 2346 microsec
c-> 3397 microsec
pt primul test, cand e sortat desc win
*/