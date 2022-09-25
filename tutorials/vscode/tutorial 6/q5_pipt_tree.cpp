#include<iostream>

using namespace std;
int arr[100]={0};

void inorder(int pos)
{
    int i=(2*pos)+1,j=(2*pos)+2;

    if(arr[i]!=0)inorder(i);
    cout<<arr[pos]<<" ";
    if(arr[j]!=0)inorder(j);
}
void preorder(int pos)
{
    int i=2*pos+1,j=2*pos+2;
        cout<<arr[pos]<<" ";

    if(arr[i]!=0)preorder(i);

    if(arr[j]!=0)preorder(j);
}
void postorder(int pos)
{
    int i=2*pos+1,j=2*pos+2;

    if(arr[i]!=0)postorder(i);
    
    if(arr[j]!=0)postorder(j);
    cout<<arr[pos]<<" ";
}
int main()
{
   
    
    int count=0;
    int d,i;
    
    int c=1;

    while(c)
    {
        cout<<"enter 1 to insert element\nenter 2 to delete\nenter 3 to search\nenter 4 for preorder traversal\nenter 5 for inorder traversal\nenter 6 for postorder traversal\nenter your choice ";
        cin>>c;

        switch(c)
        {
            case 1:
                cout<<"\nenter data ";
                cin>>d;
                arr[count++]=d;
                break;
            case 2:
                cout<<"\nenter the element  to delete ";
                cin>>d;
                for( i=0;i<count;i++)
                {
                    if(arr[i]==d)
                    {
                        arr[i]=0;
                        break;
                    }
                }
                if(i==count)cout<<"\nthe element is not found \n";
                break;
            
            case 3:
                cout<<"\nenter the element  to search ";
                cin>>d;
                for( i=0;i<count;i++)
                {
                    if(arr[i]==d)
                    {
                        cout<<"\npresent : \n";
                        break;
                    }
                }
                if(i==count)cout<<"the element is not found \n ";
                break;
                
            case 4:
                cout<<"preorder : ";
                preorder(0);
                cout<<"\n";
                break;
                
            case 5:
               cout<<"inorder : ";
                inorder(0);
                cout<<"\n";
                break;
                
            case 6:
               cout<<"postorder : ";
                postorder(0);
                cout<<"\n";
                break;

        }

    }
}