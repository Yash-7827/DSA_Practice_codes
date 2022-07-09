#include<iostream>

using namespace std;

class node{
    public:
        int data;
        
        node* next;
};

class LinkedList{
    private:
        node* head;
    public:
        LinkedList()
        {
            head=NULL;
        }
    
    int calcSize();
    void insertAtStart(int element);
    void insertAtEnd(int element);
    void insertAtPos(int pos, int element);
    void deleteNode(int element);
    void display();
    void deleteAtPos(int pos);
    
};

int LinkedList::calcSize()
{
    node* temp=new node();
    
    temp=head;
    int size=0;
    
    while(temp!=NULL)
    {
        temp=temp->next;
        size++;
    }
    
    return size;
}

void LinkedList::insertAtStart(int element)
{
    node* newNode = new node();
    
    newNode->data=element;
    newNode->next=head;
    
    head=newNode;
}

void LinkedList::insertAtEnd(int element)
{
    node* newNode = new node();
    
    newNode->data=element;
    newNode->next=NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = new node();
    
    temp = head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void LinkedList::insertAtPos(int pos, int data) {
    int size = calcSize();

    //If pos is 1 then should use insertStart method
    //If pos is less than or equal to 0 then can't enter at all
    //If pos is greater than size then bufferbound issue
    if (pos < 1 || size < pos) {
        printf("Can't insert, %d is not a valid position\n", pos);

    } else {
        node * temp = head;
        node * newNode = new node();

        newNode -> data = data;
        newNode -> next = NULL;

        while (--pos) {
            temp = temp -> next;
        }
        //(25)->next = 10 as 12->next is 10 
        newNode -> next = temp -> next;
        // (12)->next = 25
        temp -> next = newNode;
        //new node added in b/w 12 and 10
    }
}

void LinkedList::deleteNode(int element)
{
    node* temp= new node();
    node* previous = new node();
    temp=head;
    
    if(temp->next==NULL)
    {
        head==NULL;
        delete(temp);
        std::cout<<element<<" deleted\n";
        
        return;
    }
    
    if(temp!=NULL&&temp->data==element)
    {
        head=temp->next;
        delete(temp);
        std::cout<<element<<" deleted\n";
        return;
    }
    
    while(temp!=NULL&&temp->data!=element)
    {
        previous=temp;
        temp=temp->next;
    }
    
    if(temp==NULL)
    {
        std::cout<<"Value not found in the list!\n";
        return;
    }
    previous->next=temp->next;
    delete(temp);
    std::cout<<element<<" deleted\n";
}

void LinkedList::deleteAtPos(int pos)
{
    node* temp = new node();
    node* previous = new node();
    temp=head;
    
    if(calcSize()<pos)
        std::cout<<"Enter a valid position! (pos<"<<calcSize()<<"\n";
     
    if(pos==0)
    {
        head = temp->next;
        cout<<temp->data<<" deleted\n";
        delete(temp);
        return;
    }
    
    while(--pos)
    {
        previous=temp;
        temp=temp->next;
    }    
    previous->next=temp->next;   
    cout<<temp->data<<" deleted\n";
    delete(temp);
}

void LinkedList::display(){
    node* temp = new node();
    
    temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<"\n";
}

int main()
{
    LinkedList* myList = new LinkedList();
    
    myList -> insertAtStart(12);
    myList -> insertAtStart(16);
    myList -> insertAtStart(20);

    myList -> insertAtEnd(10);
    myList -> insertAtEnd(14);
    myList -> insertAtEnd(18);
    myList -> insertAtEnd(11);

    // Inserts after 3rd position
    myList -> insertAtPos(3, 25);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    myList -> display();
    
    myList -> deleteNode(12);
    myList -> deleteNode(11);
    
    myList -> deleteAtPos(3);
    myList -> deleteAtPos(0);
    
    myList -> display();
    return 0;
}
