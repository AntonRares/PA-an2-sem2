#include<iostream>
#include"f.h"
using namespace std;
void sorteaza_secv_bitonica(int a[],int i,int d,int s)
{
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        for(int j=i;j<i+d/2;j++)
        {
            compara_si_schimba(a[j],a[j+d/2],s);
        }
        sorteaza_secv_bitonica(a,i,d/2,s);
        sorteaza_secv_bitonica(a,i+d/2,d/2,s);
    }
}
void compara_si_schimba(int &x,int &y,int s)
{
    if((s==0 && x>y) || (s==1 && x<y))
    {
        int aux=x;
        x=y;
        y=aux;
    }
}
void batcher_sort(int a[],int i,int d,int s)
{
    if(d <= 1) return;
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        batcher_sort(a,i,d/2,0);
        batcher_sort(a,i+d/2,d/2,1);
        sorteaza_secv_bitonica(a,i,d,s);
    }
}
void generare(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
}
void array_sortat_cresc(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
}
void array_sortat_desc(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=n-i;
    }
}