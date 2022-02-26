/*Q4. Write a C/C++ program to implement priority queue data
structure using array.
	Author:Bhoomik Gupta*/
#include<stdio.h>
#include<stdlib.h>					// use any name
typedef unsigned char priority_t;			// 0 -  255, can use any other data-type as well like char for -128 to +127 priority range
typedef struct node{
	int val;
	priority_t prio;		// priority of the node
	struct node *link;	
}node_t;
node_t *createNode(int, priority_t);
void display(struct node const *);
void removeTopPriorityNode(node_t **);
void insertPriorityNode(node_t **, int, priority_t);
void removelowest(node_t **head);	
void destroy(node_t **head);
void peep(node_t *const head);
char menu();// implement
int main(void)
{
	node_t *head =  NULL;
	int flag=1;
	char ch;
	int val;
	priority_t prior;
	while(flag){
			ch=menu();
			switch(ch){
				case 1:
				puts("Enter a priority");
				scanf("%hhd",&prior);
				puts("Enter the value");
				scanf("%d",&val);
				insertPriorityNode(&head,val,prior);
				break;
				case 2:
				display(head);
				break;
				case 3:
				removeTopPriorityNode(&head);
				break;
				case 4:
				removelowest(&head);
				break;
				case 5:
				peep(head);
				break;
				case 6:
				destroy(&head);
				break;
				case 7:
				destroy(&head);
				flag=0;
				break;
				default:
				puts("Wrong input is given");
				break;
			}
	}	
	return 0;
}
void display(struct node const *temp)
{
	puts("========Display=====");
	if(temp == NULL){
		puts("List is empty");
		return;
	}

	while(temp){
		printf("[val:%d Prio: %hhu]-->", temp->val, temp->prio);
		temp = temp->link;
	}
	puts("NULL\n");
}
void removeTopPriorityNode(node_t **head)
{
	if(*head == NULL){
		puts("List is empty");
		return;
	}

	node_t *temp = *head;
	*head = (*head)->link;
	printf("Deleted Node ==> [val: %d Priority: %hhu]\n", temp->val, temp->prio);
	free(temp);
}
void insertPriorityNode(node_t **head, int val, priority_t prio)
{
	puts("======== priority insert=========");

	node_t *newNode  = createNode(val, prio);

	//--- whether the list is NULL/Empty
	if(*head == NULL){
		*head = newNode;
		printf("Inserted Node ==> [val: %d Priority: %hhu]\n", newNode->val, newNode->prio);
		return;
	}

	// in case new node is having higer priority than head node then it should become head node 
	else if( (*head)->prio > newNode->prio){

		newNode->link = *head;
		*head		  =  newNode;
		printf("Inserted Node ==> [val: %d Priority: %hhu]\n", newNode->val, newNode->prio);
		return;
	}

	node_t *temp = *head;

	while((temp->link != NULL) && (newNode->prio  > temp->link->prio)){

		temp =  temp->link;
	}

	newNode->link =  temp->link;   // from diagram 
	temp->link	  = newNode;
	
	printf("Inserted Node ==> [val: %d Priority: %hhu]\n", newNode->val, newNode->prio);
}
node_t *createNode(int val, priority_t prio)
{
	node_t *temp = malloc(sizeof(node_t));

	if(temp == NULL){		// NULL check
		puts("Malloc Failed");
		exit(0);
	}

	temp->val	= val;
	temp->prio  = prio;
	temp->link  = NULL;

	return temp;
}
void peep(node_t *const head)
{
	printf("[Most priority node %d  Value=%d]",head->prio,head->val);
}
void destroy(node_t **head)
{
	node_t *ptr=*head;
	while(*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->link;
		free(ptr);	
	}
	puts("Successfully deleted all the nodes");
}
void removelowest(node_t **head)
{
	node_t *ptr=*head;
	node_t *preptr=*head;
	if(*head==NULL){
		puts("Priority queue is empty");
		return ;
	}
	else if((*head)->link==NULL){
		free(ptr);
		*head=NULL;
		return ;
	}
	while(ptr->link!=NULL){
		preptr=ptr;
		ptr=ptr->link;
	}
	preptr->link=NULL;
	printf("[lowest priority node %d data=%d]\n",ptr->prio,ptr->val);
	free(ptr);
}
char menu()
{
	char ch;
	puts("\n\t\tPriority Queue\n1. Insert Node\n2. display\n3. remove top priority node\n4. remove lowest priority node\n5. peep\n6. destroy\n7. exit");
	scanf("%hhd",&ch);
	return ch;	
}
