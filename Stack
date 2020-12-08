#include <stdio.h>
#include <stdlib.h>

typedef struct link{
  int element;
  struct link* next;
}Link;

typedef struct stack{
  Link* top;
  int size;
}Stack;

Stack* createStack(){
  Stack* s = (Stack *)malloc(1*sizeof(Stack));
  s->size=0;
  s->top=NULL;
  return s;
}

Link* createLink(Link* next, int it){
  Link* l = (Link *)malloc(1*sizeof(Link));
  l->next = next;
  l->element=it;
  return l;
}

void clear(Stack* s){
  s->top=NULL;
  s->size=0;
}

void push(Stack* s, int it){
  s->top = createLink(s->top, it);
  s->size++;
}

int pop(Stack* s){
  if(s->top==NULL) exit(-1);
  int it = s->top->element;
  s->top = s->top->next;
  s->size--;
  return it;
}

int topValue(Stack* s){
  return s->top->element;
}

int length(Stack* s){
  return s->size;
}

int main() {
  Stack* s = createStack();
  push(s, 5);
  push(s,4);
  push(s,3);
  push(s,2);
  push(s,1);
  for(int i=0;i<5;i++){
    printf("%d ", pop(s));
  }
  printf("\n");
  printf("%d", length(s));
  return 0;
}
