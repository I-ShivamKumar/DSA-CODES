#include <bits/stdc++.h>
using namespace std;

class node{
        public:
            int data;
            node * link;
            node(int data){
                this->data=data;
                this->link=NULL;
            }
};node *first;


void create_SLL(int *val,int N)
{   
    int i=0;
    node *ptr,*cpt;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=val[i];
    ptr->link=NULL;
    first=ptr;
    
    do
    {   
        i++;
        cpt=( node*)malloc(sizeof( node));
        cpt->data=val[i];
        ptr->link=cpt;
        ptr=cpt;
    } while (i<N-1);
    ptr->link=NULL;
}

void display(node *ptr)
{
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
    cout<<endl;
}


void Remove_loop(node *slow,node * head)
{
    while(slow->link!=head->link)
    {
        slow=slow->link;
        head=head->link;
    }
    slow->link=NULL;
}


void detect_loop(node * head)
{
    node *slow;
    node *fast;
    slow=fast=head;
    while(fast!=NULL && fast->link!=NULL)
    {
        slow=slow->link;
        fast=fast->link->link;
        if(slow==fast)
        {
            Remove_loop(slow,head);
        }
    }
}

int main() {
    int N;
    cin>>N;
    int value[N];
    for (int i=0;i<N;i++)
    {
        cin>>value[i];
    }
    create_SLL(value,N);
    display(first);
    first->link->link->link->link->link=first->link;
    detect_loop(first);
    display(first);
    return 0;
}
