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
        if(data > prev->data){
            prev->right = newNode;
        }else{
            prev->left = newNode;
        }
        printf("\n* node having data %d was inserted.", data);
    }
}
struct node *delete(struct node *root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->data){
        root->left = delete(root->left, key);
    }else if(key > root->data){
        root->right = delete(root->right, key);
    }
    else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = smallestNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}
int search(int key){
    struct node *temp = root;
    while(temp != NULL){
        if(key == temp->data){
            return 1;
        }else if(key > temp->data){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    return 0;
}