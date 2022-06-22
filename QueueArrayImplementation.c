#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->rear == q->size-1) {
        return 1;
    } 
    return 0;
}

int isEmpty(struct Queue *q){
    if(q->rear == q->front) {
        return 1;
    } 
    return 0;
}


void enqueue(struct Queue *q, int val)
{
    if( isFull(q)) {
        printf("Queue is Full!");
    }  else {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct Queue *q)
{
    int a=-1;
    if( isEmpty(q)) {
        printf("Queue is Empty!");
    }  else {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main() {
    struct Queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 15);
    
    printf("Dequeueing element %d\n", dequeue(&q));
    printf("Dequeueing element %d\n", dequeue(&q));

    if(isEmpty(&q)) {
        printf("Queue is Empty!");
    }

}
