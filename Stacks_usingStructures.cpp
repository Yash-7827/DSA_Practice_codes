#include<iostream>

using namespace std;

struct Stack{
    int top;
    int maxSize;
    int* array;
};

struct Stack* create(int max){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->maxSize=max;
    stack->array=(int*)malloc(stack->maxSize * sizeof(int));
    return stack;
}

bool isEmpty(struct Stack* stack){
    return stack->top==-1;
}

bool isFull(struct Stack* stack){
    return stack->top==stack->maxSize-1;
}

void push(struct Stack* stack,int item){
    if(isFull(stack)){
        std::cout<<"Maximum Size Reached\n";
        return;
    }
    else
    {
        stack->array[++stack->top]=item;
        std::cout<<item<<" Have been Pushed successfully\n";
    }
}

void pop(struct Stack* stack){
    if(isEmpty(stack)){
        std::cout<<"Stack Underflow";
        return;
    }
    else{
        std::cout<<stack->array[stack->top]<<" Have been Popped Successfully\n";
        stack->top--;
    }
}

int peek(struct Stack* stack){
    if(isEmpty(stack))
    {
        cout<<"Stack Underflow";
        return 0;
    }
    else
        return stack->array[stack->top];
}

int main(){
    struct Stack* stack=create(10);
    
    push(stack,5);
    push(stack,10);
    push(stack,15);
    std::cout<<peek(stack)<<"\n";
    pop(stack);
    pop(stack);
    std::cout<<peek(stack)<<"\n";
    std::cout<<isEmpty(stack)<<"\n";
    std::cout<<isFull(stack)<<"\n";
}
