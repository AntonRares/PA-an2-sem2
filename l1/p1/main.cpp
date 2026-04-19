#include<iostream>
#include"f.h"
using namespace std;
int list::counter=0;
int main()
{
    list l;
    l.insert(0,7);
    l.insert(0,2);
    l.insert(0,4);
    l.insert(0,9);
    l.afisare();
    l.insert(2,200);
    l.afisare();
    l.afisareCounter();
    l.insert(5,7000);
    
    return 0;
}