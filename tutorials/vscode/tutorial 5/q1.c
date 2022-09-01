#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *  next;
};

struct node * head= NULL;

void create()
{
    int d;
    printf("enter the data: ");

    scanf("%d",&d);

    struct node *  n=(struct node *) malloc( sizeof(struct node));
    n->data=d;
    n->next=NULL;
    if(head==NULL)
    {
        head=n;
        head->next=head;
        return;
    }
    if(head->next==head)
    {
        head->next=n;
        n->next=head;
        return;
    }
    struct node* temp=head->next;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}

void print()
{
    if(head==NULL) {printf("NULL");return;}
    printf("->%d->",head->data);
   
    struct node * temp = head->next;
    while(temp!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main()
{
    int n;
    printf("enter the length of circular link list : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        create();
    }

    print();


}