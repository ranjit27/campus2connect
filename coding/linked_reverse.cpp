#include<iostream>
using namespace std ;

class node
{
    public:
    int no ;
    node *next;
 
    
};

class linked{
 node *head, *tail ;
public:
linked()
{
    head=tail =NULL;
}
    void insert(){
        int n ;
        cout<<"insert size of list:"<<endl;
        cin>>n ;
        head = new node ;
         tail = head ;
    cout<<"insert in linkedList:"<<endl;
    cin>>head->no;
    for(int i = 0 ;i< n-1;i++)
    {
        head->next = new node ;
        head = head->next ;
        cin>>head->no;
    }
   
    head->next = NULL;
}

void linked_from_end(){
    node* prev = NULL;
    node *head =tail ;
     node* current =head;
     cout<<"Reverse Linkedlist: ";
       
       while(current != NULL)
        {
         node *temp = current->next ;
            current->next= prev ;
            prev= current;
            current= temp ;
            
        }
        while(prev!=NULL)
        {
            cout<<prev->no<<"-<";
            prev= prev->next;
        }

        
}


};

int main()
{
    linked ll ;
    ll.insert();
   
    ll.linked_from_end();

    return 0 ;
}
