//O(1)=spatiu constant
#include<iostream>
using namespace std;
int main()
{
    int a[4][4],i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i<j)//deasupra diag princip
            {
                int aux=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=aux;
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i<2)
            {
                int aux=a[i][j];
                a[i][j]=a[4-1-i][j];
                a[4-1-i][j]=aux;
            }
        }
    }
    cout<<"\n afisare:\n";
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}