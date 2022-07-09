#include <iostream>

using namespace std;

class Node{
    public: 
    int data;
    Node* previous;
    Node* next;
};

class DoublyLinkedList{
    private:
        Node* head;
    public:
    DoublyLinkedList(){
        head = NULL;
    }
    int calcSize();
    void insertAtStart(int element);
    void insertAtEnd(int element);
    void insertAtPos(int pos, int element);
    void deleteElement(int element);
    void deleteAtPos(int pos);
    void display();
};

int DoublyLinkedList::calcSize()
{
    Node* temp = new Node();
    temp=head;
    
    int size=0;
    
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}

void DoublyLinkedList::insertAtStart(int element)
{
    Node* newNode = new Node();
    
    newNode->data = element;
    newNode->previous = NULL;
    newNode->next=head;
    
    if(head!=NULL)
        head->previous=newNode;
 
    head=newNode;
}

void DoublyLinkedList::insertAtEnd(int element)
{
    Node* newNode = new Node();
    Node* temp = new Node();
    
    if(head==NULL)
        insertAtStart(element);
    
    temp = head;
    
    while(temp->next!=NULL)
        temp=temp->next;
    
    newNode->data = element;
    newNode->next = NULL;
    newNode->previous = temp;
    
    temp->next=newNode;
}

void DoublyLinkedList::insertAtPos(int pos, int element)
{
    Node* newNode = new Node();
    Node* temp = new Node();
    Node* previous = new Node();
    
    temp = head;
    
    int size = calcSize();
    
    if(size<pos)
    {
        std::cout<<"Enter a valid position. (pos<"<<size<<")\n";
        return;
    }    
    
    if(pos==1)
    {
        insertAtStart(element);
        return;
    }
    
    if(pos==size)
    {
        insertAtEnd(element);
        return;
    }    
    
    newNode->data=element;
    newNode->previous=NULL;
    newNode->next=NULL;
    
    while(--pos)
    {
        previous=temp;
        temp=temp->next;
    }
    
    previous->next=newNode;
    newNode->previous= previous;
    temp->previous=newNode;
    newNode->next=temp;
}

void DoublyLinkedList::deleteElement(int element)
{
    Node* temp = new Node();
    Node* previous = new Node();
    Node* next = new Node();
    temp=head;
    
    if(temp->previous==NULL&&temp->data==element)
    {
        temp->previous = NULL;
        head=temp->next;
        std::cout<<element<<" is deleted!\n";
        delete(temp);
        return;
    }
    
    while(temp!=NULL&&temp->data!=element)
    {
        previous=temp;
        temp=temp->next;
    }
    
    if(temp->next==NULL&&temp->data==element)
    {
        previous = temp->previous;
        previous->next = NULL;
        delete(temp);
        std::cout<<element<<" is deleted!\n";
        return;
    }
    
    next = temp->next;
    
    previous->next = next;
    next->previous = previous;
    delete(temp);
    std::cout<<element<<" is deleted!\n";
    
}

void DoublyLinkedList::deleteAtPos(int pos){
    Node* temp = new Node();
    
    temp=head;
    
    if(pos>calcSize())
    {
        std::cout<<"Enter a valid position (pos<"<<calcSize()<<")\n";
        return;
    }
    
    while(--pos)
    {
        temp=temp->next;
    }
    
    deleteElement(temp->data);
    
}

void DoublyLinkedList::display(){
    Node* temp = new Node();
    temp=head;
    std::cout<<"\n";
    while(temp!=NULL)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<"\n";
}

int main() {
    DoublyLinkedList* myList = new DoublyLinkedList();
    
    myList->insertAtStart(20);
    myList->insertAtStart(30);
    myList->insertAtStart(40);
    myList->insertAtStart(50);

    myList->insertAtEnd(60);
    myList->insertAtEnd(70);
    myList->insertAtEnd(80);
    myList->insertAtEnd(90);

    myList->insertAtPos(1,12);
    myList->insertAtPos(4,45);
    myList->insertAtPos(7,55);
    
    myList->display();
    
    myList->deleteElement(55);
    myList->deleteElement(40);
    myList->deleteElement(12);

    myList->display();
    
    myList->deleteAtPos(4);
    
    myList->display();
    return 0;
}
