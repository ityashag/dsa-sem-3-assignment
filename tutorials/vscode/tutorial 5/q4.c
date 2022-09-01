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
        return;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void sort()
{
    struct node* i=head;
    while(i!=NULL)
    {
        struct node*j=head;
        while(j->next!=NULL)
        {
            if(j->data > j->next->data)
            {
                int temp=j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
            j=j->next;
        }
        i=i->next;
    }
}

void print()
{
    if(head==NULL) {printf("NULL");return;}
    struct node * temp = head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
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

    sort();
    print();

}