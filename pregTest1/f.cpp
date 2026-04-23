#include<iostream>
#include<list>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include"f.h"
using namespace std;
//radix sort
int getD(int a[],int n)
{
    int maxim=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>maxim)
        {
            maxim=a[i];
        }
    }
    return maxim;
}
int getCif(int x,int i)
{
    return (x/int(pow(10,i)))%10;
}
void radixSort(int a[],int n)
{
    int d=getD(a,n);
    for(int i=0;i<d;i++)
    {
        list<int> pachete[10];//vct de list
        //impachetare
        for(int j=0;j<n;j++)
        {
            int cif=getCif(a[j],i);
            pachete[cif].push_back(a[j]);
        }
        //despachetare
        int index=0;
        for(int j=0;j<10;j++)
        {
            for(int nr:pachete[j])
            {
                a[index++]=nr;
            }
            pachete[j].clear();
        }
    }
}
void citireVector(int a[],int n)
{
    printf("vector cu %d elem:",n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void afisareVector(int a[],int n)
{
    cout<<"afisare vector:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}
// merge sort
void interclasare(int a[],int p,int q,int m,int tmp[])
{
    int i=p;
    int j=m+1;
    int k=0;
    while(i<=m && j<=q)
    {
        if(a[i]<=a[j])
        {
            tmp[k++]=a[i++];
        }
        else
        {
            tmp[k++]=a[j++];
        }
    }
    while(i<=m)
    {
        tmp[k++]=a[i++];
    }
    while(j<=q)
    {
        tmp[k++]=a[j++];
    }
}
void mergeSort(int a[],int p,int q,int tmp[])
{
    if(p<q)
    {
        int m=(p+q)/2;
        mergeSort(a,p,m,tmp);
        mergeSort(a,m+1,q,tmp);
        interclasare(a,p,q,m,tmp);
        for(int i=p;i<=q;i++)
        {
            a[i]=tmp[i-p];
        }
    }
}
//quickSort1
void partitionare(int a[],int p,int q,int &k)
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
            if(a[i]>x && a[j]<x)
            {
                int aux=a[i];
                a[i]=a[j];
                a[j]=aux;
                i++;
                j--;
            }
        }
    }
    k=i-1;
    a[p]=a[k];
    a[k]=x;
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
//quickSort2
void quickSort2(int a[],int p,int q)
{
    while(p<q)
    {
        int k;
        partitionare(a,p,q,k);
        if(2*k>p+q)
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
//batchersort DE RESCRIS
void compara_si_schimba(int &x,int& y,int &s)
{
    if((x<y && s==1) || (x>y && s==0))
    {
        int aux=x;
        x=y;
        y=aux;
    }
}
void sorteaza_secv_bitonica(int a[],int i,int d,int s)
{
    if(d<2)
    {
        return;
    }
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        for(int j=0;j<d/2;j++)
        {
            compara_si_schimba(a[i+j],a[i+j+d/2],s);
        }
        sorteaza_secv_bitonica(a,i,d/2,s);
        sorteaza_secv_bitonica(a,i+d/2,d/2,s);
    }
}
void batcherSort(int a[],int i,int d,int s)
{
    if(d<2)
    {
        return;
    }
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        batcherSort(a,i,d/2,0);
        batcherSort(a,i+d/2,d/2,1);
        sorteaza_secv_bitonica(a,i,d,s);
    }
}
//LEP
int calculLEP(Node *root,int depth)
{
    if(root==nullptr)
    {
        return 0;
    }
    if(root->left==nullptr && root->right==nullptr)
    {
        return root->data*depth;
    }
    return calculLEP(root->left,depth+1)+calculLEP(root->right,depth+1);
}
void constructieArbore()
{
    priority_queue<Node*,vector<Node*>,Compare> B;
    int n,x;
    cout<<"n=";cin>>n;
    cout<<"cele n elem:";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        B.push(new Node(x));
    }
    //
    while(B.size()>1)
    {
        Node *t1=B.top();
        B.pop();
        Node *t2=B.top();
        B.pop();
        Node *t=new Node(t1->data+t2->data);
        t->left=t1;
        t->right=t2;
        B.push(t);
    }
    cout<<"rezultat = "<<calculLEP(B.top(),0)<<'\n';
    stergereArbore(B.top());
}
void stergereArbore(Node *root)
{
    if(root==nullptr)
    {
        return;
    }
    stergereArbore(root->right);
    stergereArbore(root->left);
    delete root;
}
//rucsac continuu
void rucsac1(int n,int M,double w[],double p[],double x[])
{
    Obiect o[10];
    int C=0;
    for(int i=0;i<n;i++)
    {
        o[i].w=w[i];
        o[i].p=p[i];
        o[i].index=i;
        o[i].r=p[i]/w[i];
    }
    BubbleSort(o,n);
    for(int i=0;i<n;i++)
    {
        if(C+o[i].w<=M)
        {
            C+=o[i].w;
            x[o[i].index]=1;
        }
        else
        {
            x[o[i].index]=(M-C)/o[i].w;
            C=M;
        }
    }
}
void BubbleSort(Obiect o[],int n)//in fun de r,desc
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
    }while(!sortat);
}
//rucsac discret
int maxim(int a,int b)
{
    return a>b ? a:b;
}
int rucsac2(int n,int M,int p[],int w[])//fara memorizare
{
    if(n==0)
    {
        return 0;
    }
    if(M<=0)
    {
        return -1e9;
    }
    int st=rucsac2(n-1,M,p,w);
    int dr=rucsac2(n-1,M-w[n-1],p,w)+p[n-1];
    return maxim(st,dr);
}