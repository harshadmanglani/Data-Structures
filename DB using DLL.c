#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define newl printf("\n");

typedef struct student					//student structure for the database 
{
	char name[50];
	char branch[10];
	int roll;
}student;


typedef struct node{					
	student obj;
	struct node *next, *prev;
}node;

node* getnode(node* newvar, student data)		//helper function to dynamically allocate new nodes
{
	newvar = (node*)malloc(sizeof(node));
	newvar->obj = data;
	newvar->next = newvar->prev = NULL;
	return newvar;
}

node* addnode(node* head, node* newvar, student data, int pos)
{
	newvar = getnode(newvar, data);
	struct node* temp = head;
	int i=1;
	
	while(temp->next!=NULL && i<pos-1)
	{	
		temp = temp->next;
		i++;
	}
	if(pos==1)					//add to the head of the list
	{
		newvar->next = head;
		head->prev = newvar;
		head = newvar;
		return head;
	}
	
	newvar->next = temp->next;
	if(temp->next!=NULL)
	temp->next->prev = newvar;
	temp->next = newvar;
	newvar->prev = temp;
	return head;
}

void displaystud(student var)
{
	printf("Name: "); printf("%s", var.name); newl
	printf("Branch: "); printf("%s", var.branch);newl
	printf("Roll: "); printf("%d", var.roll);newl
	newl newl
}	

void display(node* head)
{
	struct node* tempvar = head;
	while(tempvar!=NULL)
	{	
		displaystud(tempvar->obj);
		tempvar = tempvar->next;
	}
}

void displayrev(node* head)
{
	struct node* tempvar = head;
	while(tempvar->next!=NULL)
	{	
		tempvar = tempvar->next;
	}
	newvarl
	newvarl
	while(tempvar!=NULL)
	{	
		displaystud(tempvar->obj);
		tempvar = tempvar->prev;
	}
}

void deletenode(node* head, int pos)
{
    if(pos==1 && head->next==NULL)
	{
		printf("Deleting the head node will lead to unexpected errors. Setting values to default.\n");
		head->obj.name[0] = head->obj.branch[0] = '\0';
		head->obj.roll = -1;
		return;
	}
	//need to work on a way to fill these values without adding a new node and letting this remain.
	if(pos==1 && head->next!=NULL)
	{
		head = head->next;
		return;
	}

	int i=1;
	struct node* temp = head;
	while(i<pos && temp->next!=NULL)
	{
		i++;
		temp = temp->next;
	}
	if(pos>i)
	{
		temp->prev->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		if(temp->next!=NULL)
		temp->next->prev = temp->prev;
		if(temp->prev!=NULL)
		temp->prev->next = temp->next;
		temp->prev = NULL;
		temp->next = NULL;
	}
}


int main()
{
	student var;
	struct node *head;
	int c = 0, flag = 0, pos;
	while(c!=5)
	{
		printf("\n1.Add\n2.Delete\n3.Display\n4.Display in reverse\n5.Quit\n");
		scanf("%d", &c);
		switch(c)
		{
			case 1:
			printf("Enter the details: \n");
			printf("Name: "); scanf("%s", var.name); 
			printf("Branch: ") ;scanf("%s", var.branch); 
			printf("Roll: "); scanf("%d", &var.roll); 
			if(flag == 0)
				{head = getnode(head, var);
				flag++;}
			else
				{	
					printf("Enter the position at which you wanna insert this element: ");
					scanf("%d", &pos);
					struct node* temp;
					head = addnode(head, temp, var, pos);}
			break;
			
			case 2:
			printf("Enter the position of the element you want to delete: ");
			scanf("%d", &pos);
			deletenode(head, pos);
			break;
			
			case 3:
			display(head);
			break;
			
			case 4:
			displayrev(head);
			break;
			
			case 5:
			free(head);
			break;
		}
	}	 
			
			
	return 0;
}
