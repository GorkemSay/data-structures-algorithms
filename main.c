#include <stdio.h>
#include <stdlib.h>
struct s{
    int *arr;
    int head;
    int size;
};
typedef struct s stack;
stack *define(){
    stack *s = (stack*) malloc(sizeof (stack));
    s->arr = NULL;
    s->size = 2;
    s->head = 0;
    return s;
}
int pop(stack *s){
    if(s->head<=0 || s->arr == NULL){
        printf("Array is empty. ");
        return -1;
    }
    if(s->head <= s->size/4 && s->size > 2){
        int *arr2 = (int*)malloc(sizeof(int)*s->size/2);
        for(int i = 0; i<s->head; i++){
            arr2[i] = s->arr[i];
        }
        int * temp = s->arr;
        s->arr = arr2;
        free(temp);
        s->size /= 2;
    }
    return s->arr[--s->head];
}
void push(int a, stack *s){
    if(s->arr == NULL){
        s->arr = (int*)malloc(sizeof(int)*2);
    }
    if(s->head >= s->size){
        int *arr2 = (int*)malloc(sizeof(int)*s->size*2);
        for(int i = 0; i<s->head; i++){
            arr2[i] = s->arr[i];
        }
        int * temp = s->arr;
        s->arr = arr2;
        free(temp);
        s->size *= 2;
    }
    s->arr[s->head++] = a;
}
void print(stack *s){
    printf("Size: %d\n", s->size);
    for(int i = 0; i<s->head; i++){
        printf("%d ", s->arr[i]);
    }
}
int main() {
    stack *s1 = define();
    stack *s2 = define();
    for(int i = 0; i< 10; i++){
        push(i*10,s1);
    }
    print(s1);
    for (int i = 0; i<10; i++){
        push(pop(s1), s2);
    }
    print(s2);
    print(s1);
    return 0;
}
