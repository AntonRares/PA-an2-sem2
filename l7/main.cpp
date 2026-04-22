#include<iostream>
#include<cstring>
const int MAX_N = 100;
const int MAX_M = 1000;
int dp[MAX_N][MAX_M];
int rucsac(int n,int M,int w[],int p[]);
int maxim(int a,int b)
{
    return a>b? a:b;
}
int main()
{
    int w[]={3,5,6};
    int p[]={10,30,20};
    int M=10,n=3;
    std::memset(dp, -1, sizeof(dp));//initial cu -1
    int rez=rucsac(n,M,w,p);
    std::cout<<rez;
    return 0;
}
//problema rucsacului varianta discreta
int rucsac(int n,int M,int w[],int p[])
{
    if(n==0)return 0;
    if(M<0)return -1e9;
    if(dp[n][M]!=-1)return dp[n][M];
    int st=rucsac(n-1,M,w,p);
    int dr=rucsac(n-1,M-w[n-1],w,p)+p[n-1];
    dp[n][M]=maxim(st,dr);
    return dp[n][M];
}