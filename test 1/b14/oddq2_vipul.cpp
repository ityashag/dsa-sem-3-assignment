//done by vipul
#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node *prev;
    node(int n){
        data=n;
        next=NULL;
        prev=NULL;
    }
};
void insert(node *&head,int n){
    if(head==NULL){
        head=new node(n);
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node(n);
        temp->next->prev=temp;
    }
}
void create(node *&head){
    cout<<"Enter the number of elements to be inserted "; 
    int n;
    cin>>n;
    cout<<"Enter elements ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        insert(head,a);
    }
}
void display(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

}
void operation(node *head){
    node *front=head;
    node *rear=head;
    node *tempf=head;
    node *tempr=head;
    int c=0;
    while(tempf!=NULL){
        tempf=tempf->next;
        c++;
        if(tempf!=NULL)
        rear=tempf;
    }
    tempf=head;
    for(int i=0;i<(c-1)/2;i++){
        tempf=front->next;
        tempr=rear->prev;
        front->next=rear;
        rear->prev=front;
        rear->next=tempf;
        tempf->prev=rear;
        front=front->next->next;
        rear=tempr;
        rear->next=NULL;
    }
}
int main(){
    node *head=NULL;
    create(head);
    display(head);
    operation(head);
    cout<<"\n";
    display(head);

}