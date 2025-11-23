#include<stdio.h>
#include<stdlib.h>

//defining a node
struct node
{
	int info;
	struct node *next;
};

void create_node(int);
void display();
void append_beg(int);

struct node *start=NULL;	//global variable

void main()
{	
	create_node(40);	//creates a single node
		
	display();	//display the list
	
	printf("\n");
	
	//insert at beginning
	append_beg(30);
	append_beg(20);
	append_beg(10);
	
	display();	//display the list
}

void create_node(int data)
{
	struct node *n;
	
	//creating a node
	n=malloc(sizeof(struct node));
	n->info=data;
	n->next=NULL;
	
	//checking if the list is null or not
	if(start==NULL)
		start=n;	//assign the first node as start node	
		
	fflush(stdin);	//clean the buffer
}

void display()
{
	struct node *temp;
	
	temp=start;	//assign a temporary pointer variable to the start node for traversing
	
	//traversing the list until there is no node left
	while(temp!=NULL)
	{
		printf("%d->",temp->info);
		temp=temp->next;
	}
	printf("X");
}

void append_beg(int data)
{
	struct node *n;
	
	//creating a node
	n=malloc(sizeof(struct node));
	n->info=data;
	n->next=start;	//points to the start node
	
	start=n;	//left shift start ponter to make the new node as the start node
	
	fflush(stdin);	//clean the buffer
}
