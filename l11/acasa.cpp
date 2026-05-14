#include<iostream>
#include<vector>
#include<queue>
#include<list>
#define NMAX 30
using namespace std;
class Digraph
{
public:
    int n;
    vector<list<int>> LAD;
    int indegree[NMAX];
    Digraph()
    {
        cout<<"n=:";
        cin>>n;
        LAD.resize(n);
        for(int i=0;i<n;i++)
        {
            indegree[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            cout<<"lista pt "<<i<<":";
            int v;
            while(cin>>v && v!=-1)
            {
                LAD[i].push_back(v);
                indegree[v]++;
            }
        }
    }
};
bool sortareTopologica(Digraph D,vector<int>& sol)
{
    queue<int> C;
    for(int i=0;i<D.n;i++)
    {
        if(D.indegree[i]==0)
        {
            C.push(i);
        }
    }
    while(C.size()!=0)
    {
        int u=C.front();
        C.pop();
        sol.push_back(u);
        for(int l:D.LAD[u])
        {
            D.indegree[l]--;
            if(D.indegree[l]==0)
            {
                C.push(l);
            }
        }
        if(C.size()==0 && sol.size()!=D.n)
        {
            return false;//are ciclu
        }
    }
    return true;
}
int main()
{
    Digraph D;
    vector<int> sol;
    if(sortareTopologica(D,sol))
    {
        for(int nr:sol)
        {
            cout<<nr<<' ';
        }
        cout<<'\n';
        return 0;
    }
    else
    {
        cout<<"graful avea cicluri\n";
        return 0;
    }
}