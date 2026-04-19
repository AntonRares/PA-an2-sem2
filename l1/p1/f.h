#pragma once
//lista liniara dublu inlantuita
class list
{
public:
    struct node
    {
        int data;
        node* prev;
        node* next;
    };
    list():head(nullptr){}
    ~list();
    void insert(int pos,int value);
    void afisare();
    static void afisareCounter();
private:
    node* head;
    static int counter;
};