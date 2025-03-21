#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    int power;
    struct Node *next;
} node;
// Function to initialize a new node
node* initNode(int data,int power) {
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->power=power;
    n->next = NULL;
    return n;
}
// Insert node at the beginning
void insertNodeAtBegin(node **head, int data,int power) {
    node *n = initNode(data,power);
    n->next = *head;
    *head = n; // Update the head pointer to point to the new node
}

// Insert node at the end
void insertNodeAtEnd(node **head, int data,int power) {
    node *n = initNode(data,power);
    if (*head == NULL) {
        *head = n; // If the list is empty, set head to new node
    } else {
        node *ptr = *head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = n; // Link the new node at the end
    }
}
// Display the linked list
void display(node *head) {
    node *ptr = head;
    while (ptr) {
    	if(ptr->power==0)
    		printf("%d",ptr->data);
    	else
        	printf("%dx^%d\t",ptr->data,ptr->power);
        ptr = ptr->next;
    }
    printf("\n");
}
node* polynomialAddition(node *head1,node *head2)
{
	node *ptr1=head1;
	node *ptr2=head2;
	node* head=NULL;
	while(ptr1 || ptr2)
	{
		if(ptr1==NULL && ptr2!=NULL)
		{
			insertNodeAtEnd(&head,ptr2->data,ptr2->power);
			ptr2=ptr2->next;
			continue;
		}
		if(ptr2==NULL && ptr1!=NULL)
		{
			insertNodeAtEnd(&head,ptr1->data,ptr1->power);
			ptr1=ptr1->next;
			continue;
		}
		if(ptr1->power==ptr2->power)
		{
			insertNodeAtEnd(&head,ptr1->data+ptr2->data,ptr1->power);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->power>ptr2->power)
		{
			insertNodeAtEnd(&head,ptr1->data,ptr1->power);
			ptr1=ptr1->next;
		}
		else
		{
			insertNodeAtEnd(&head,ptr2->data,ptr2->power);
			ptr2=ptr2->next;
		}
	}
	return head;
}
// Main function to test the linked list
int main() {
    node *head1=NULL;
    node *head2=NULL;
    node *head3=NULL;
    int co,po,size,i;
    printf("Enter Polynomial One Size:\n");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
    	printf("Enter the Power:");
    	scanf("%d",&po);
    	printf("X^%d:",po);
    	scanf("%d",&co);
    	insertNodeAtEnd(&head1,co,po);
    }
    display(head1);
    printf("Enter Polynomial Two Size:\n");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
    	printf("Enter the Power:");
    	scanf("%d",&po);
    	printf("X^%d:",po);
    	scanf("%d",&co);
    	insertNodeAtEnd(&head2, co,po);
    }
    display(head2);
    head3=polynomialAddition(head1,head2);
    printf("ADDITION OF TWO POLYNOMIALS:\n");
    display(head3);
    return 0;
}
