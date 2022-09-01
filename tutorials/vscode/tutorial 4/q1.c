#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;  
};
struct node * head=NULL;

void create()
{
    int d;
    printf("enter the data : ");
    scanf("%d",&d);


    struct node  * n= (void *) malloc(sizeof(struct node));
    n->next=NULL;
    n->data=d;
    if(head==NULL)
    {
        head=n;
        return;
    }
    else
    {
        struct node *  temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        
    }
}
void print()
{
    struct node *  temp=head;
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
    printf("enter the size of link list  : ");
    scanf("%d",&n);

    
    for(int i=0;i<n;i++)
    {
        create();
    }
    print();
    return 0;
}