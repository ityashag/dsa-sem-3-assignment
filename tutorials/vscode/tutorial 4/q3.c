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


    struct node  * n=(struct node *)malloc(sizeof(struct node));
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

int  count()
{
    struct node *  temp=head;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;

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
  
   printf("the number of node in the link list is  : %d",count());
    return 0;
}