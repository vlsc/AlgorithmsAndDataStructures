#include <stdio.h>
#include <stdlib.h>

typedef struct List{
  int maxSize; 
  int listSize; //current list size 
  int curr; //current position
  int *arrayList; 
}List;

List* createList(int size){
  List* l = (List *) malloc(sizeof(List));
  l -> maxSize = size; //l->maxSize = size;
  l -> listSize = 0;
  l -> curr = 0;
  l -> arrayList = (int *) malloc(size*sizeof(int));
  return l;
}

void clear(List* l){
  l->listSize = l->curr = 0;
}

void insert(List* l, int it){
  if (l->listSize >= l->maxSize) exit(-1); //ensures that it will not exceed the maximum size
  while (i > l->curr){
    l->arrayList[i] = l->arrayList[i-1]; //shift right
    i--;
  }
  l->arrayList[l->curr] = it; //add element
  l->listSize++;
}

void append(List* l, int it){
  if(l->listSize >= l->maxSize) exit(-1); 
  l->arrayList[l->listSize] = it; //add to the end
  l->listSize++;
}

int removee(List* l){
  if(l->curr < 0 || l->curr > l->listSize) exit (-1);
  int element = l->arrayList[l->curr];
  int i = l->curr;
  while(i < l->listSize-1){
    l->arrayList[i] = l->arrayList[i+1]; //shift left
    i++;
  }
  l->listSize--;
  return element;
}

void moveToStart(List* l){
  l->curr = 0;
}

void moveToEnd(List* l){
  l->curr = l->listSize;
}

void prev(List* l){
  if(l->curr > 0) l->curr = l->curr--;
}

void next(List* l){
  if(l->curr < l->listSize) l->curr = l->curr++;
}

int length(List* l){
  return l->listSize;
}

int currPos(List* l){
  return l->curr;
}

void moveToPos(List* l, int pos){
  if (pos <= l->listSize && pos >= 0) l->curr = pos;
}

int getValue(List* l){
  if (l->curr < 0 || l->curr > l->listSize) exit(-1);
  return l->arrayList[l->curr];
}

int main (){
  List *l = createList(5);
  insert(l, 1);
  insert(l, 2);
  insert(l, 3);
  insert(l, 4);
  insert(l, 5);
  for (int i = 0; i < l->listSize; i++){
    printf("this is the %d element of the list: %d\n", i, l->arrayList[i]);
  }
  l->curr = 2;
  removee(l);
  insert(l, 90);
  printf("changed list:\n");
  for (int i = 0; i < l->listSize; i++){
    printf("this is the %d element of the list: %d\n", i, l->arrayList[i]);
  }
  return 0;
}
