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


void delete_given_data(node *ptr)
{   
    int a;
    cout<<"Enter the data to be deleted"<<endl;
    cin>>a;
    node *cpt=ptr;
    while(ptr->data!=a)
    {   
        cpt=ptr;
        ptr=ptr->link;
    }
    cpt->link = ptr->link;
    ptr->link = NULL;
    delete ptr;

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
    delete_given_data(first);
    display(first);
    return 0;
}
