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
    void display();
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

void LinkedList::display(){
    node* temp = new node();
    
    temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
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

    //Inserts after 3rd position
    myList -> insertAtPos(3, 25);

    /*No need for & i.e. address as we do not
    need to change head address
    */
    myList -> display();
    return 0;
}
