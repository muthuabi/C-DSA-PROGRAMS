#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node* initNode(int data) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}


int insertNodeAtBegin(node **head, int data) {
	
    node *n = initNode(data);
    n->next = *head;
    *head = n; 
    return 1;
}

int insertNodeAtEnd(node **head, int data) {
    node *n = initNode(data);
    if (*head == NULL) {
        *head = n; 
        
    }
	 else
	  {
        node *ptr = *head;
        while (ptr->next) 
            ptr = ptr->next;
        ptr->next = n; 
    }
    return 1;
}

int insertNodeAtSpec(node **head,int target,int data)
{
	node *n=initNode(data);
	node *t,*ptr=*head;
	if(*head)
	{
		while(ptr)
		{
		//printf("%d \t \t",ptr->data);
			if(ptr->data==target)
			{
				
				t=ptr->next;
				ptr->next=n;
				n->next=t;
				return 1;
				//break;
			}
			ptr=ptr->next;
		}
	
	}
	// else
	// {
	// 	n->next=NULL;
	// 	*head=n;
	// }
	return 0;
}
int deleteNodeAtBegin(node **head)
{
	if(*head)
	{
		node *t=*head;
		*head=(*head)->next;
		free(t);
		return 1;
	}
	return 0;
}
int deleteNodeAtEnd(node **head)
{
	if(*head)
	{
		node *pr,*cr;
		pr=cr=*head;
		while(cr->next)
		{
			pr=cr;
			cr=cr->next;
		}
		if(pr==cr)
			deleteNodeAtBegin(head);
		else
		{
			pr->next=NULL;// pr->next=cr->next;
			free(cr);
		}
		return 1;
		
	}
	return 0;
}
int deleteNodeAtSpec(node **head,int target)
{
	if(*head)
	{
		node *pr,*cr;
		pr=cr=*head;
		while(cr)
		{
				//printf("%p %p %d %d \n",pr,cr,pr->data,cr->data);
			if(cr->data==target)
			{
				//printf("%p %p\n",pr,cr);
				if(pr==cr)
					deleteNodeAtBegin(head);
				else
				{
					pr->next=cr->next;
					free(cr);
				}
				return 1;
				break;
			}
			pr=cr;
			cr=cr->next;
		}
	
		
	}
	return 0;
}
void display(node *head) {
    node *ptr = head;
    int i=0;
 	if(ptr==NULL)
 		printf("\nList Empty\n\n");
 	else
 		printf("\nList Elements:\n\n");
    while (ptr) {
    	printf("%d\t",ptr->data);
    	i++;
        ptr = ptr->next;
    }
    printf("\n\nList Count %d\n",i);
}
int searchNode(node *head,int target)
{
	int i=0;
	node *ptr=head;
	while(ptr)
	{
		if(ptr->data==target)
			return (i+1);
		ptr=ptr->next;
		i++;
	}
	return 0;
}
node* findNode(node *head,int n)
{
	int i=0;
	node *ptr=head;
	while(ptr)
	{
		if((i+1)==n)
			return ptr;
		ptr=ptr->next;
		i++;
	}
	return (node*)(NULL);
}
// int main() {
//     node *head=NULL,*t;
//     int ch,x,y,c;
//   	do
//   	{
//   		printf("\n-----MENU-----\n1. Insert\n2. Delete\n3. Search\n4. Find Node\n5. Display\n6. Exit\n");
// 		printf("YOUR CHOICE:");
// 		scanf("%d",&ch);
// 		switch(ch)
// 		{
// 			case 1:
// 				printf("Enter the Data:");
// 				scanf("%d",&x);
// 				printf("\n-----SUB MENU-----\n1. Insert Begin\n2. Insert End\n3. Insert Specific\n");
// 				printf("YOUR CHOICE:");
// 				scanf("%d",&c);
// 				switch(c)
// 				{
// 					case 1:
// 						if(insertNodeAtBegin(&head,x))
// 							printf("Element Inserted Begin");
// 						break;
// 					case 2:
// 						if(insertNodeAtEnd(&head,x))
// 							printf("Element Inserted End");
// 						break;
// 					case 3:
// 						printf("Enter the Target:");
// 						scanf("%d",&y);
// 						if(insertNodeAtSpec(&head,y,x))
// 							printf("Element Inserted");
// 						else
// 						{
// 							printf("There is No Such Data\nShall I just Insert\n1. BEGIN\n2. END\n3. CANCEL\nYOUR CHOICE:");
// 							scanf("%d",&c);
// 							if(c==1)
// 							{
// 								if(insertNodeAtBegin(&head,x))
// 									printf("Element Inserted Begin");
// 							}
// 							else if(c==2)
// 							{
// 								if(insertNodeAtEnd(&head,x))
// 									printf("Element Inserted End");
// 							}
// 							else
// 								printf("\nCANCELLED\n");

// 						}
// 						break;
// 					default:
// 						break;
// 				}
// 				break;
// 			case 2:
// 				printf("\n-----SUB MENU-----\n1. Delete Begin\n2. Delete End\n3. Delete Specific\n");
// 				printf("YOUR CHOICE:");
// 				scanf("%d",&c);
// 				switch(c)
// 				{
// 					case 1:
// 						if(deleteNodeAtBegin(&head))
// 							printf("Element Deleted Begin");
// 						break;
// 					case 2:
// 						if(deleteNodeAtEnd(&head))
// 							printf("Element Deleted End");
// 						break;
// 					case 3:
// 						printf("Enter the Target:");
// 						scanf("%d",&y);
// 						if(deleteNodeAtSpec(&head,y))
// 							printf("Element Deleted");
// 					default:
// 						break;
// 				}
// 				break;
// 			case 3:
// 				printf("Enter the Target:");
// 				scanf("%d",&y);
// 				if((x=searchNode(head,y)))
// 					printf("\nNode Found and It is the Node %d\n",x);
// 				else
// 					printf("\nNode Not Found\n");
// 				break;
// 			case 4:
// 				printf("Enter the n:");
// 				scanf("%d",&y);
// 				if((t=findNode(head,y)))
// 					printf("There is a node %d",t->data);
// 				else 
// 					printf("Index out of Bound");
// 				break;
// 			case 5:
// 				display(head);
// 				break;
// 			case 6:
// 				printf("\nThank You!\n");
// 				break;
// 			default:
// 				printf("\nINVALID CHOICE\n");
// 		}
// 		getchar();
// 		printf("\npress again to continue...\n");
// 		getchar();
//   	}while(ch!=6);
//     return 0;
// }
