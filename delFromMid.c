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
void del_after(int);

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
	
	del_after(30);	//delete from mid
	
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

void del_after(int item)
{
	struct node *temp, *temp2;
	
	temp=start;	//assign a temporary pointer variable to the start node for traversing
		
	//traversing the list until the second last node is reached
	while(temp->next->info!=item)
	{
		temp=temp->next;
	}
	
	temp2 = temp->next;
	temp->next=temp->next->next;
	free(temp2);	// free the mid node
}
