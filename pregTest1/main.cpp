#include<iostream>
#include<list>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include"f.h"
using namespace std;
int main()
{
    int nrp;
    cout<<"nrp=";
    cin>>nrp;
    //rucsac1
    double p1[]={2,4,5};
    double w1[]={2,1,2.5};
    double x1[3];
    double val1=0;
    //rucsac2
    int p2[]={10,30,20};
    int w2[]={3,5,6};
    //sortari
    int a[10];
    int tmp[10];
    switch(nrp)
    {
        case 1:
            cout<<"radix\n";
            citireVector(a,5);
            radixSort(a,5);
            afisareVector(a,5);
            break;
        case 2:
            cout<<"merge\n";
            citireVector(a,5);
            mergeSort(a,0,4,tmp);
            afisareVector(a,5);
            break;
        case 3:
            cout<<"quickSort1\n";
            citireVector(a,5);
            quickSort1(a,0,4);
            afisareVector (a,5);
            break;
        case 4:
            cout<<"quickSort2\n";
            citireVector(a,5);
            quickSort2(a,0,4);
            afisareVector(a,5);
            break;
        case 5:
            cout<<"batcher sort\n";
            citireVector(a,8);
            batcherSort(a,0,8,0);
            afisareVector(a,8);
            break;
        case 6:
            cout<<"LEP\n";
            constructieArbore();
            break;
        case 7:
            cout<<"rucsac continuu\n";
            rucsac1(3,3,w1,p1,x1);
            for(int i=0;i<3;i++)
            {
                val1+=x1[i]*p1[i];
            }
            cout<<"rez="<<val1<<endl;
            break;
        case 8:
            cout<<"rucsac discret\n";
            cout<<"rez="<<rucsac2(3,10,p2,w2);
            break;
    }
    return 0;
}