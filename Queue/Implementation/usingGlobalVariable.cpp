#include<iostream>

using namespace std;

#define SIZE 5

int queue[SIZE],front=-1,rear=-1;

void enqueue(int element)
{
    if(rear==SIZE-1)
    {
        std::cout<<"Overflow!\n";
    }
    else
    {
        if(front==-1)
            front=0;
            
        rear++;
        
        cout<<element<<" was enqueued!\n";
        queue[rear]=element;
        

    }
}

void dequeue()
{
    if(front==-1)
     std::cout<<"Underflow!\n";
     
    else
    {
        std::cout<<queue[front]<<" was dequeued!\n";
        front++;
        
        if(front>rear)
            front=rear=-1;
    }
}

void display()
{
    if(front==-1)
        std::cout<<"Underflow!\n";
    
    int i;
    
    for(i=front;i<=rear;i++)
        std::cout<<queue[i]<<" ";
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    dequeue();
    dequeue();
    
    display();
}
