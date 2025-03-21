#include<stdio.h>
#include<stdlib.h>
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
int insertNodeAtBegin(node **head,node **tail, int data) {
    node *n = initNode(data);
    if(*head==NULL)
    {
    	*head=*tail=n;
    	(*tail)->next=*head;
    	return 1;
    }
    n->next=*head;
    *head=n;
    (*tail)->next=*head;
    return 1;
}
void display(node *head) {
    node *ptr = head;
    int i=0;
 	if(ptr==NULL)
 		printf("\nList Empty\n\n");
 	else
 		printf("\nList Elements:\n\n");
    while (ptr->next!=head)
    {
    	printf("%d\t",ptr->data);
    	i++;
        ptr = ptr->next;
    }
    printf("\n\nList Count %d\n",i);
}
int main()
{
	node *head,*tail;
	tail=head=NULL;
	insertNodeAtBegin(&head,&tail,5);
	insertNodeAtBegin(&head,&tail,6);
	insertNodeAtBegin(&head,&tail,7);
	insertNodeAtBegin(&head,&tail,8);
	display(head);
	return 0;
}