/*Author:Bhoomik Gupta*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *left;
	int data;
	struct node *right;
}node;
void insert(node **,int );
void inorderDisplay(node *); 
void preorderDisplay(node *); 
void postorderDisplay(node *); 
char menu();
void destroy(node **root);
int main(){	
	int flag=1;
	node *root=NULL;
	int val;
	char ch;
	while(flag){
	ch=menu();
	switch(ch){
		case 1:
			printf("enter element\n");
			scanf("%d", &val);
			insert(&root, val);
			break;
		case 2:
			printf("in-order display\n");
			inorderDisplay(root);
			break;	
		case 3:
			printf("pre-order display\n");
			preorderDisplay(root);
			break;	

		case 4:
			printf("post-order display\n");
			postorderDisplay(root);
			break;
		case 6:
			destroy(&root);
			flag=0;
			break;
		default:
		puts("Wrong input is given");
		break;	
	}
	}
}
	
void inorderDisplay(node *root){
	if(root!=NULL){
		inorderDisplay(root->left);
		printf("%d \t",root->data);
		inorderDisplay(root->right);
	}
}
void preorderDisplay(node *root){
	if(root!=NULL){
		printf("%d \t",root->data);
		preorderDisplay(root->left);
		preorderDisplay(root->right);
	}
}
void postorderDisplay(node *root){
	if(root!=NULL){
		postorderDisplay(root->left);
		postorderDisplay(root->right);
		printf("%d \t",root->data);
	}
}
void insert(node **root,int val){
	if(*root == NULL ){
		*root = (struct node *)malloc(sizeof(struct node));
		(*root)->left=NULL;
		(*root)->data=val;
		(*root)->right=NULL;
	} else {
		if(val>(*root)->data ){
			// right
			insert( &((*root)->right),val);	
		} else {
			// left
			insert( &((*root)->left),val);	
		}
	}	
}
char menu()
{
	char ch;
	puts("\n\t\ttree\n1. insert\n2. inorder\n3. preorder\n4. postorder\n5. delete\n6. exit");
	scanf("%hhd",&ch);
	return ch;
}
void destroy(node **root)
{
	if(*root==NULL)
	{
		return;
	}
	destroy(&(*root)->left);
	destroy(&(*root)->right);
	free(*root);
}

