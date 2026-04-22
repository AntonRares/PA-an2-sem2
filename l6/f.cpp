#include<iostream>
#include"f.h"
using namespace std;
void rucsac1(double w[],double p[],int n,int M,double x[])
{
    int C=0;//capacitatea ocupata
    Obiect o[10];
    for(int i=0;i<n;i++)
    {
        o[i].w=w[i];
        o[i].p=p[i];
        o[i].r=p[i]/w[i];//pret per kg
        o[i].index=i;//ind in vct init
    }
    BubbleSort(o,n);//sortat desc in fun de r
    for(int i=0;i<n , C<M;i++)
    {
        if(C+o[i].w<=M)//intra tot
        {
            x[o[i].index]=1;
            C+=o[i].w;
        }
        else//trb determ fractiunea
        {
            x[o[i].index]=(M-C)/o[i].w;
            C=M;
        }
    }
}
void BubbleSort(Obiect o[],int n)
{
    bool sortat=true;
    do
    {
        sortat=true;
        for(int i=0;i<n-1;i++)
        {
            if(o[i].r<o[i+1].r)
            {
                Obiect aux=o[i];
                o[i]=o[i+1];
                o[i+1]=aux;
                sortat=false;
            }
        }
    } while (!sortat);
    
}