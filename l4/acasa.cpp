#include<iostream>
using namespace std;
void compara_si_schimba(int &x,int &y,int s)
{
    if( (s==0 && x>y) || (s==1 && x<y) )
    {
        //s=0 cresc, s=1 desc
        int aux=x;
        x=y;
        y=aux;
    }
}
void sorteaza_secventa_bitonica(int a[],int i,int d,int s)
{
    if(d<=1)
    {
        return;
    }
    if(d==2)//desc i,i+1
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        for(int j=0;j<d/2;j++)
        {
            compara_si_schimba(a[i+j],a[i+j+d/2],s);
        }
        sorteaza_secventa_bitonica(a,i,d/2,s);
        sorteaza_secventa_bitonica(a,i+d/2,d/2,s);
    }
}
void batcher_sort(int a[],int i,int d,int s)
{
    if(d<=1)
    {
        return;
    }
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        batcher_sort(a,i,d/2,0);
        batcher_sort(a,i+d/2,d/2,1);
        sorteaza_secventa_bitonica(a,i,d,s);
    }
}
int main()
{
    int a[]={3,5,8,9,10,12,14,20,95,90,60,40,35,23,18,0};
    batcher_sort(a,0,16,0);
    // al III param = cate elem
    for(int i=0;i<16;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}