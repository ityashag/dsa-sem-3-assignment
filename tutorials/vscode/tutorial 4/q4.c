
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

void insert_at_any_pos(int pos)
{
    int d;
    printf("enter the data : ");
    scanf("%d",&d);
    struct node  * n=(struct node *)malloc(sizeof(struct node));
    n->next=NULL;
    n->data=d;
    if(pos==1)
    {
        n->next=head;
        head=n;
    }
    else{
        int ct=1;
        struct node  * temp=head;
        while(ct<pos-1)
        {
            temp=temp->next;
            ct++;

        }
        n->next=temp->next;
        temp->next=n;
    }

}
void insert_at_middle()
{
    int d=0;
    struct node *  temp=head;
    while(temp!=NULL)
    {
        d++;
        temp=temp->next;
    }
    insert_at_any_pos(d/2 + 1);




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
   insert_at_middle();
   print();
    return 0;
}