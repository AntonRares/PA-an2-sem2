#include<iostream>
#include<list>
#include"radix.h"
using namespace std;
int main()
{
    int v[8];
    for(int i=0;i<8;i++)
    {
        cin>>v[i];
    }
    radixSort(v,8);
    for(int i=0;i<8;i++)
    {
        cout<<v[i]<<' ';
    }
    return 0;
}