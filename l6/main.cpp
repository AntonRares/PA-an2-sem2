#include<iostream>
#include"f.h"
using namespace std;
int main()
{
    int n=3,M=10;
    double p[]={10,30,20};
    double w[]={};
    double x[n];
    rucsac1(w,p,n,M,x);
    int val=0;
    for(int i=0;i<n;i++)
    {
        val+=p[i]*x[i];
    }
    cout<<val;
    return 0;
}