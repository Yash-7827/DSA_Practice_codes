#include<iostream>

using namespace std;

struct myQueue{
    int front,rear;
    unsigned size;
    
    int* array;
};

struct myQueue* createQueue(unsigned size)
{
    struct myQueue* Queue = (struct myQueue*)malloc(sizeof(struct myQueue));
    
    Queue->front=-1;
    Queue->rear=-1;
    Queue->size=5;
    
    Queue->array=(int*)malloc(Queue->size * sizeof(int));
    return Queue;
}

bool isEmpty(struct myQueue* queue)
{
    if(queue->front==-1)
    {
        std::cout<<"Underflow!\n";
    }
    
    return queue->front==-1;
}

bool isFull(struct myQueue* queue)
{
    if(queue->rear==queue->size-1)
    {
        std::cout<<"Overflow!\n";
    }
    
    return queue->rear==queue->size-1;
}

bool enqueue(struct myQueue* queue,int element)
{
    if (isFull(queue)) 
        return false; 
        
    if(queue->front == -1)
        queue->front = 0;
    
    queue->rear++;
    queue->array[queue->rear] = element;
    std::cout<<element<<" added to the queue\n";
}
bool dequeue(struct myQueue* queue)
{
    if(isEmpty(queue))
        return false;
    else
    {
        queue->front++;
        std::cout<<queue->array[queue->front]<<" has been dequeued!\n";
        
        return true;
    }
}

void display(struct myQueue* queue)
{
    int i;
    
    for(i=queue->front;i<=queue->rear;i++)
    {
        std::cout<<queue->array[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    struct myQueue* queue = createQueue(5);
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    
    display(queue);
    
    isFull(queue);
    
    dequeue(queue);
    dequeue(queue);
}
