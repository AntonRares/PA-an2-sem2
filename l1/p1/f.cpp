#include<iostream>
#include"f.h"
using namespace std;
list::~list()
{
    if(head!=nullptr)
        {
            node* current=head;
            node* next;
            while(current!=nullptr)
            {
                next=current->next;
                delete current;
                current=next;
            }
            delete head;
        }
}
void list::afisare()
{
    if(head==nullptr)
    {
        cout<<"\nlista vida";
        return;
    }
    cout<<"\nafisare lista: ";
    node* p=head;
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
}
void list::insert(int pos,int value)
{
    switch(pos)
    {
        case 0:
            if(head==nullptr)
            {
                head=new node;
                head->data=value;
                head->next=nullptr;
                head->prev=nullptr;
            }
            else
            {
                node* p=new node;
                p->data=value;
                p->next=head;
                head->prev=p;
                head=p;
            }
            counter++;
            break;
        default:
            if(head==nullptr || pos>= counter+1)
            {
                cout<<"\ninvalid";
                break;
            }
            else
            {
                node* p=head;
                node* q=new node;
                q->data=value;
                int cnt=0;
                while(cnt<pos-1)
                {
                    cnt++;
                    p=p->next;
                }
                q->prev=p;
                q->next=p->next;
                p->next->prev=q;
                p->next=q;
                counter++;
                break;
            }
    }
}
void list::afisareCounter()
{
    cout<<"\ncounter="<<counter;
}