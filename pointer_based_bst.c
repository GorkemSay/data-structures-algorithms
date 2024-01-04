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
struct node *smallestNode(struct node *root){
    struct node *curr = root;
    while(curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
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
struct node *largestNode(struct node *root){
    struct node *curr = root;
    while(curr != NULL && curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}
void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}
int getData(){
    int data;
    printf("\nPlease enter data: ");
    scanf("%d", &data);
    return data;
}
int main(){
    int userChoice;
    char userActive = 'Y';
    int data;
    struct node* result = NULL;
 
    while (userActive == 'Y' || userActive == 'y')
    {
        printf("\n\n------- Binary Search Tree ------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Get Larger Node Data");
        printf("\n5. Get smaller Node data");
        printf("\n\n-- Traversals --");
        printf("\n\n6. Inorder ");
        printf("\n7. Post Order ");
        printf("\n8. Pre Oder ");
        printf("\n9. Exit");
 
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &userChoice);
        printf("\n");
 
        switch(userChoice)
        {
            case 1:
                data = getData();
                insert(data);
                break;
 
            case 2:
                data = getData();
                root = delete(root, data);
                break;
 
            case 3:
                data = getData();
                if (search(data) == 1)
                {
                    printf("\nData was found!\n");
                }
                else
                {
                    printf("\nData does not found!\n");
                }
                break;
 
            case 4:
                result = largestNode(root);
                if (result != NULL)
                {
                    printf("\nLargest Data: %d\n", result->data);
                }
                break;
 
            case 5:
                result = smallestNode(root);
                if (result != NULL)
                {
                    printf("\nSmallest Data: %d\n", result->data);
                }
                break;
 
            case 6:
                inorder(root);
                break;
 
            case 7:
                postorder(root);
                break;
 
            case 8:
                preorder(root);
                break;
 
            case 9:
                printf("\n\nProgram was terminated\n");
                break;
 
            default:
                printf("\n\tInvalid Choice\n");
                break;
        }
 
        printf("\n__________\nDo you want to continue? ");
        fflush(stdin);
        scanf(" %c", &userActive);
    }
 
    return 0;
}