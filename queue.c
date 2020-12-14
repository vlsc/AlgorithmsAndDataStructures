#include <stdio.h>
#include <stdlib.h>

typedef struct link{
  struct link* next;
  int element;
}Link;

typedef struct queue{
  Link* front;
  Link* rear;
  int size;
}Queue;

Link* createLink(Link* next, int it){
  Link* l = (Link *)malloc(1*sizeof(Link));
  l->next = next;
  l->element = it;
  return l;
}

Link* createLink2(Link* next){
  Link* l = (Link *)malloc(1*sizeof(Link));
  l->next = next;
  return l;
}

Queue* createQueue(){
  Queue* q = (Queue *)malloc(1*sizeof(Queue));
  q->front = q->rear = createLink2(NULL);
  q->size = 0;
  return q;
}

void clear(Queue* q){
  q->front = q->rear = createLink2(NULL);
  q->size = 0;
}

void enqueue(Queue* q, int it){
  q->rear->next = createLink(NULL, it);
  q->rear = q->rear->next;
  q->size++;
}

int dequeue(Queue* q){
  if(q->size == 0) exit(-1);
  int it = q->front->next->element;
  q->front->next = q->front->next->next;
  if(q->front->next == NULL) q->rear = q->front;
  q->size--;
  return it;
}

int frontValue(Queue* q){
  return q->front->next->element;
}

int length(Queue* q){
  return q->size;
}

int main(void) {
  Queue* q = createQueue();
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  for(int i=0;i<5;i++){
    printf("%d ", dequeue(q));
  }
  printf("\n");
  printf("%d", length(q)); 
  return 0;
}
