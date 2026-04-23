#pragma once
//radix sort
int getD(int a[],int n);
int getCif(int x,int i);
void radixSort(int a[],int n);
void citireVector(int a[],int n);
void afisareVector(int a[],int n);
void interclasare(int a[],int p,int q,int m,int tmp[]);
//merge sort
void interclasare(int a[],int p,int q,int m,int tmp[]);
void mergeSort(int a[],int p,int q,int tmp[]);
//quickSort1
void partitionare(int a[],int p,int q,int &k);
void quickSort1(int a[],int p,int q);
void quickSort2(int a[],int p,int q);
//batcherSort DE RESCRIS
void sorteaza_secv_bitonica(int a[],int i,int d,int s);
void batcherSort(int a[],int i,int d,int s);
//LEP
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
struct Compare
{
    bool operator()(Node*a,Node*b)
    {
        return a->data>b->data;
    }
};
int calculLEP(Node *root,int depth);
void constructieArbore();
void stergereArbore(Node *root);
//rucsac continuu
struct Obiect
{
    double w,p,r;
    int index;
};
void rucsac1(int n,int M,double w[],double p[],double x[]);
void BubbleSort(Obiect o[],int n);
//rucsac discret
int maxim(int a,int b);
int rucsac2(int n,int M,int p[],int w[]);








