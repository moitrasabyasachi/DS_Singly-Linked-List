#include<stdio.h>
#include<stdlib.h>

//defining a node
struct node
{
	int info;
	struct node *next;
};

void append(int);
void display();
void append_after(int,int);

struct node *start=NULL;	//global variable	

void main()
{	
	//insert at end
	append(10);
	append(20);
	append(30);
	append(40);
	
	display();	//display the list
	
	printf("\n");
	
	append_after(30,35);	//insert after
	
	display();	//display the list
}

void append(int data)
{
	struct node *n,*temp;
	
	//creating a node
	n=malloc(sizeof(struct node));
	n->info=data;
	n->next=NULL;
	
	//checking if the list is null or not
	if(start==NULL)
		start=n;	//assign the first node as start node
	else
	{
		temp=start;	//assign a temporary pointer variable to the start node for traversing
		
		//traversing the list until the last node is reached
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=n;	//append the new node at the end
	}
	
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

void append_after(int item,int data)
{
	struct node *n,*temp;
	
	//creating a node
	n=malloc(sizeof(struct node));
	n->info=data;
	n->next=NULL;
	
	temp=start;	//assign a temporary pointer variable to the start node for traversing
		
	//traversing the list until the desired node is reached
	while(temp->info!=item)
	{
		temp=temp->next;
	}
	
	//append after the desired node
	n->next=temp->next;	//next part of new node points to next part of temp node
	temp->next=n; //next part of temp node points to new node
	
	fflush(stdin);	//clean the buffer
}
