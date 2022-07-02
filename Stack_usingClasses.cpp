#include<iostream>

using namespace std;

class Stack{
    
    int top;
    int maxSize;
    int* array;
    
    public:
    
    Stack(int size){
        top=-1;
        maxSize=size;
        array= new int [maxSize];
    }
    
    void push(int item);
    void pop();
    bool isFull();
    bool isEmpty();
    void peek();
    void display();
};

void Stack::push(int item)
{
    if(isFull())
        return;
    else
    {
        array[++top]=item;
        std::cout<<item<<" Have been successfully pushed\n";
    }
}

void Stack::pop()
{
    if(isEmpty())
        return;
    else
    {
        std::cout<<array[top]<<" Have been successfully popped\n";
        top--;
    }
}

bool Stack::isFull()
{
    if(top>=maxSize-1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Stack::isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

void Stack::peek(){
    cout<<array[top]<<"\n";
    return;
}

void Stack::display(){
    for(int i=0;i<=top;i++)
        cout<<array[i]<<" ";
}

int main()
{
    class Stack s(5);
    
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.peek();
    std::cout<<s.isEmpty()<<"(0-Flase/1-True)\n";
    std::cout<<s.isFull()<<"(0-Flase/1-True)\n";
    s.pop();
    s.pop();
    s.peek();
    s.display();
}
