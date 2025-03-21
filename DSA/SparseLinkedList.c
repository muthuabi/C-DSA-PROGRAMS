#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int i;
	int j;
	int data;
	struct Node* next;
}node;
node* initNode(int i,int j,int data)
{
	node *n=(node*)malloc(sizeof(node));
	n->i=i;
	n->j=j;
	n->data=data;
	n->next=NULL;
	return n;
}
void insertNodeAtBegin(node **head,int i,int j,int data)
{
	node *n=initNode(i,j,data);
	if(head)
		n->next=*head;
	*head=n;
}
void display(node *head) {
    node *ptr = head;
    while (ptr) {
    	printf("%d x %d = %d\t",ptr->i,ptr->j,ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int** initMatrix(int r,int c)
{
	int i,j;
	int **matrix=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		*(matrix+i)=(int*)malloc(c*sizeof(int));
		for(j=0;j<c;j++)
		{
			printf("%d x %d:",i,j);
			//scanf("%d",&matrix[i][j]);
			scanf("%d",(*(matrix+i)+j));
		}
	}
	return matrix;
}
void printMatrix(int **matrix,int r,int c)
{
	int i,j;
	printf("\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void startSparse(int **matrix,int r,int c,node **head)
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(matrix[i][j]!=0)
				insertNodeAtBegin(head,i,j,matrix[i][j]);
}
int main()
{
	node *head=NULL;
	int **matrix,r,c,i,j;
	printf("Enter row and column:\n");
	scanf("%d%d",&r,&c);
	matrix=initMatrix(r,c);
	printf("\nMatrix Elements\n");
	printMatrix(matrix,r,c);
	startSparse(matrix,r,c,&head);
	printf("\nLinked List Nodes\n");
	display(head);
	return 0;
}
