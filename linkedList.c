#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
  int element;
  struct Link* next;
}Link;

typedef struct List{
  struct Link* head;
  struct Link* tail;
  struct Link* curr;
  int cnt; //list size
}List;

struct Link* createLink(int it, struct Link* nextval){

  Link* n = (Link *)malloc(1*sizeof(Link));
  n->element = it;
  n->next = nextval;
  return n;
}

struct Link* createLink2(struct Link* nextval){
  Link* n = (Link *)malloc(1*sizeof(Link));
  n->next = nextval;
  return n;
};

List *createList(){
  List *l = (List *)malloc(1*sizeof(List));
  l->head = l->tail = l->curr = createLink2(NULL); //header
  l->cnt = 0;
  return l;
}

void clear(List* l){
  l->head = l->tail = l->curr = createLink2(NULL);
  l->cnt = 0;
}

void insert(int it, List* l){
  l->curr->next = createLink(it, l->curr->next);
  if(l->curr == l->tail) l->tail = l->curr->next;
  l->cnt++;
}

void append(int it, List* l){
  l->tail->next = createLink(it, NULL);
  l->tail = l->tail->next;
  l->cnt++;
}

void removee(List* l){
  if(l->curr->next != NULL){
    if (l->curr->next == l->tail) l->tail = l->curr;
    l->curr->next = l->curr->next->next;
    l->cnt--;
  }
}

void moveToStart(List* l){
  l->curr = l->head;
}

void moveToEnd(List* l){
  l->curr = l->tail;
}

void prev(List* l){
  if(l->curr == l->head) return ;
  struct Link* temp = l->head;
  while (temp->next != l->curr){
    temp = temp->next;
  }
  l->curr = temp;
  free(temp);
}

void next(List* l){
  if(l->curr != l->tail) l->curr = l->curr->next;
}

int length(List* l){
  return l->cnt;
}

int currPos(List* l){
  struct Link* temp = l->head;
  int i = 0;
  while(temp!=l->curr){
    temp = temp->next;
    i++;
  }
  free(temp);
  return i;
}

void moveToPos(List* l, int pos){
  int i = 0;
  if(pos<0 || pos>=l->cnt) exit(-1);
  l->curr = l->head;
  while (i!=pos){
    l->curr = l->curr->next;
    i++;
  }
}

int getValue(List* l){
  if(l->curr->next == NULL){};
  return l->curr->next->element;
}


int main() {
  List* l = createList();
  insert(4,l); //5th
  insert(3,l);
  insert(2,l);
  insert(1,l);
  insert(55,l); //1st
  //head -> 55 -> 1 -> 2 -> ...
  //  0  ->1st ->2nd->3rd-> ...
  int i=0;
  for(i=0;i<l->cnt;i++){
    moveToPos(l, i);
    printf("%d ", getValue(l));
  }
  moveToPos(l, 2);
  removee(l);
  printf("\n");
  for(i=0;i<l->cnt;i++){
    moveToPos(l, i);
    printf("%d ", getValue(l));
  }
  moveToPos(l, 2); //2 was removed
  insert(6,l);
  printf("\n");
  for(i=0;i<l->cnt;i++){
    moveToPos(l, i);
    printf("%d ", getValue(l));
  }

  return 0;
}
