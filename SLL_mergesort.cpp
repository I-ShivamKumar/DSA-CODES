#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> link;
    
    while(fast != NULL && fast -> link != NULL) {
        slow = slow -> link;
        fast = fast -> link -> link; 
    }
    return slow;
}

node* merge(node* left, node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> link = left;
            temp = left;
            left = left -> link;
        }
        else
        {
            temp -> link = right;
            temp = right;
            right = right -> link;
        }
    }
    
    while(left != NULL) {
        temp -> link = left;
        temp = left;
        left = left -> link;
    }
    
    while(right != NULL) {
        temp -> link = right;
        temp = right;
        right = right -> link;
    }
    
    ans = ans -> link;
    return ans;
    
}


node* mergeSort(node *head) {
    //base case
    if( head == NULL || head -> link == NULL ) {
        return head;
    }
    
    // break linked list into 2 halves, after finding mid
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->link;
    mid -> link = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    node* result = merge(left, right);

    return result;
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
    first=mergeSort(first);
    display(first);
    return 0;
}
