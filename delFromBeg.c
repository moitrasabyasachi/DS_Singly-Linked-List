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
void del_beg();

struct node *start=NULL;	//global variable	

void main()
{	
	//insert at end
	append(10);
	append(20);
	append(30);
	
	display();	//display the list
	
	printf("\n");
	
	del_beg();	//delete from beginning
	
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

void del_beg()
{
	struct node *temp;

	temp=start;	
	start=start->next; //right shift start pointer
	free(temp);	// free the first node
}
