#include<iostream>
#include<list>
#include<cmath>
#include"radix.h"
using namespace std;
void radixSort(int l[],int n)
{
    list<int> pachete[10];
    int d=getD(l,n);
    for(int i=0;i<d;i++)
    {
        //impachetare
        for(int j=0;j<n;j++)
        {
            int cifra=getCifra(l[j],i);
            pachete[cifra].push_back(l[j]);
        }
        //despachetarea
        int index=0;
        for(int j=0;j<10;j++)
        {
            for(int numar:pachete[j])//for echivalent pt liste
            {
                l[index++]=numar;
            }
            pachete[j].clear();
        }
    }
}
int getD(int l[],int n)
{
    int nrMaxCif=0;
    for(int i=0;i<n;i++)
    {
        int x=l[i];
        int nrCif=0;
        while(x)
        {
            nrCif++;
            x=x/10;
        }
        if(nrCif>nrMaxCif)
        {
            nrMaxCif=nrCif;
        }
    }
    return nrMaxCif;
}
int getCifra(int x, int i)
{
    for(int k = 0; k < i; k++)
        x /= 10;

    return x % 10;
}