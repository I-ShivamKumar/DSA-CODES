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


void Insert_after_data(node *ptr)
{   
    int a;
    cout<<"Enter the data after which node should be inserted"<<endl;
    cin>>a;
    int d;
    cout<<"Enter the data to be inserted"<<endl;
    cin>>d;
    node *cpt= new node(d);
    while(ptr->data!=a)
    {
        ptr=ptr->link;
    }
    
    cpt->link=ptr->link;
    ptr->link=cpt;
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
    Insert_after_data(first);
    display(first);
    return 0;
}
