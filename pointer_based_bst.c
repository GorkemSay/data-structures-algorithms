#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL; //globally initialized root pointer

struct node *createNode(int data) //create new node
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("\nMemory for new node can not be allocated");
        return NULL;
    }
    newNode ->data = data;
    newNode ->left = NULL;
    newNode ->right = NULL;
    return newNode;    
};

void insert(int data){
    struct node *newNode = createNode(data);
    if(newNode != NULL){
        if(root == NULL){
            root = newNode;
            printf("\n* node having data %d is inserted.", data);
            return;
        }
        struct node *temp = root;
        struct node *prev = NULL;
        while(temp != NULL){
            prev = temp;
            if(data > temp->data){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        
    }
}