#include<iostream>
#include"f.h"
using namespace std;
void mergeSort(int a[],int p,int q,int temp[])
{
    if(p<q)
    {
        int m=(p+q)/2;
        mergeSort(a,p,m,temp);
        mergeSort(a,m+1,q,temp);
        interclasare(a,p,q,m,temp);
        for(int i=p;i<=q;i++)
        {
            a[i]=temp[i-p];
        }
    }
}
void interclasare(int a[],int p,int q,int m,int temp[])
{
    int i=p,j=m+1,k=-1;
    while((i<=m) && (j<=q))
    {
        k=k+1;
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
    }
    while(i<=m)
    {
        k=k+1;
        temp[k]=a[i];
        i=i+1;
    }
    while(j<=q)
    {
        k=k+1;
        temp[k]=a[j];
        j=j+1;
    }
}
void quickSort1(int a[],int p,int q)
{
    if(p<q)
    {
        int k;
        partitionare(a,p,q,k);
        quickSort1(a,p,k-1);
        quickSort1(a,k+1,q);
    }
}
void quickSort2(int a[],int p,int q)
{
    while(p<q)
    {
        int k;
        partitionare(a,p,q,k);
        if(k-p > q-k)
        {
            quickSort2(a,k+1,q);
            q=k-1;
        }
        else
        {
            quickSort2(a,p,k-1);
            p=k+1;
        }
    }
}
void partitionare(int a[],int p,int q,int& k)
{
    int x=a[p];
    int i=p+1;
    int j=q;
    while(i<=j)
    {
        if(a[i]<=x)
        {
            i++;
        }
        if(a[j]>=x)
        {
            j--;
        }
        if(i<j)
        {
            if(a[i]>x && x>a[j])
            {
                //interschimb
                int aux=a[i];
                a[i]=a[j];
                a[j]=aux;
                //
                i++;
                j--;
            } 
        }
    }
    k=i-1;
    a[p]=a[k];
    a[k]=x;
}
void afisareVct(int a[])
{
    cout<<"\nafisare vct 8 elem:\n";
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<' ';
    }
}
void citireVct(int a[])
{
    cout<<"\ncitire vector 8 elem:\n";
    for(int i=0;i<8;i++)
    {
        cin>>a[i];
    }
}
void generare(int v[],int n)
{
    for(int i=0;i<n;i++)
    {
        v[i]=rand();
    }
}