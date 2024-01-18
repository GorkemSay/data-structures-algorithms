#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int item;
    struct s *next;
}STACK;
STACK *sp = NULL;

int push(int item){
    STACK *p;
    p = (STACK*)malloc(sizeof(STACK));
    if(p == NULL){
        printf("Not enough memory\n");
        return -1;
    }
    else{
        p->item = item;
        p->next = sp;
        sp = p;
        printf("Pushed.\n");
        return 0;
    }
}
int pop(){
    STACK *p;
    int i;
    if(sp == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        p = sp;
        i = sp->item;
        sp = sp->next;
        free(p);
        printf("Popped.\n");
        return i;
    }
}
int main(){
    push(10);
    push(20);
    pop();
}