#include <stdio.h>
#include <stdlib.h>

struct node {char ch; struct node *next;};

void print_list(struct node* s){
  printf("%c", s->ch);
  if (s->next != NULL) {
    printf(", ");
    print_list(s->next);
  }
  printf("\n");
}

struct node* insert_front(struct node* s, struct node* front){
  front->next = s;
  s = front;
  return s;
}

struct node* free_list(struct node* s){
  free(s);
  if (s->next != NULL) {
    s->next = free_list(s->next);
  }
  //  s->ch = 0;
  return s;
}


int main(){
  /* always a struggle (not working ;-;)
  struct node *t1;
  struct node *h;
  char hold = 'm';
  t1.c = hold;
  while(t1.c != 'a'){
    hold--;
    h.c = hold;
    h.next = struct *t1;
    t1 = h;
  }
  */
  struct node *a, *b, *c;
  a = (struct node*)malloc(sizeof(struct node));
  b = (struct node*)malloc(sizeof(struct node));
  c = (struct node*)malloc(sizeof(struct node));

  a->ch = 'h';
  b->ch = 'u';
  c->ch = 'e';

  b->next = c;
  a->next = b;


  //testing print_list(node *s)
  printf("Testing print_list\n");
  print_list(a);

  //testing insert_front(node *s, node *front)                             be freeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
  struct node *aa;
  aa = (struct node*)malloc(sizeof(struct node));
  aa->ch = 'c';
  print_list(insert_front(a, aa));

  //testing free_list(node *s)

  print_list(free_list(a));
  if(a==NULL){
    printf("Success!");
  }else{
    printf("Step up\n");
  }
  //free list won't clear out the "next" variable; empty nodes leftover?
  return 21;
}
