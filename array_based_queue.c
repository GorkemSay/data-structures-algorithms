#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queueArray[MAX];
int front = -1;
int rear = -1;

void insert(){
    int addItem;
    if(rear == MAX -1){
        printf("Queue is overflow. Please dequeue some elements or choose another operation. \n");
    }
    else{
        if(front == -1){
            front = 0; //If queue is empty
            }
        printf("Insert an element to queue: ");
        scanf("%d", &addItem);
        rear += 1;
        queueArray[rear] = addItem;
        
    }
}

void delete(){
    if(front == -1 || front > rear){
        printf("Queue is underflow. Please insert some elements before attempting deletion. \n");
    }
    else{
        printf("Element delete from queue is: %d \n", queueArray[front]);
        front += 1;
    }    
}

void display(){
  int i;
  if(front == -1){
    printf("Queue is empty \n");
  }
  else{
    printf("Queue is: \n");
    for(i= front; i <= rear; i++){
        printf("%d ", queueArray[i]);
        printf("\n");
    }
  }
}

int main(){
    int choice;
    while(1){
        printf("1- Insert an element to queue \n");
        printf("2- Delete an element from queue \n");
        printf("3- Display all element of queue \n");
        printf("4- Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice!!!");
        }
    }
}