#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	int height;
	struct Node *left;
	struct Node *right;
}node;

node* initNode(int x)
{
	node *n=(node*)malloc(sizeof(node));
	n->data=x;
	n->left=NULL;
	n->right=NULL;
	n->height=0;
	return n;
}
int max(int x,int y)
{
	return (x>y)?x:y;
}
int S_Height(node *vertex)
{
	if(vertex)
		return vertex->height;
	return 0;
}
int Height(node *vertex)
{
	int lh,rh;
	if(vertex==NULL)
		return 0;
	lh=Height(vertex->left);
	rh=Height(vertex->right);
	return 1+((lh>rh)?lh:rh);
}
int isBalance(node *vertex)
{	
	int bal;
	if (vertex==NULL)
		return 0;
	bal=Height(vertex->left)-Height(vertex->right);
	return bal;
}
node* leftRotation(node* n)
{
	node *t=n->right;
	n->right=t->left;
	t->left=n;
	n->height=max(Height(n->left),Height(n->right))+1;
	t->height=max(Height(t->left),Height(t->right))+1;
	return t;
}
node* rightRotation(node *n)
{
	node *t=n->left;
	n->left=t->right;
	t->right=n;
	n->height=max(Height(n->left),Height(n->right))+1;
	t->height=max(Height(t->left),Height(t->right))+1;
	return t;
}
node* balancer(node *vertex,int x)
{
	vertex->height=max(Height(vertex->left),Height(vertex->right))+1;
	if (isBalance(vertex)<-1)
	{
		if(x<vertex->right->data)
			vertex->right=rightRotation(vertex->right);
		return leftRotation(vertex);
	}
	else if(isBalance(vertex)>1)
	{
		if(x>vertex->left->data)
			vertex->left=leftRotation(vertex->left);
		return rightRotation(vertex);
	}
	return vertex;
}
node* AVL(node *vertex,int x)
{
	if(vertex==NULL)
		return initNode(x);
	else if(x>vertex->data)
		vertex->right=AVL(vertex->right,x);  
	else if(x<vertex->data)
		vertex->left=AVL(vertex->left,x);
	else
		return vertex;
	return balancer(vertex,x);

}
node* leftMost(node* vertex)
{
	if(vertex->left==NULL)
		return vertex;
	return leftMost(vertex->left);
}
node* Delete(node* vertex,int x)
{
	if(vertex)
	{
		if(vertex->data==x)
		{
			if(vertex->left && vertex->right)
			{
				vertex->data=leftMost(vertex->right)->data;
				vertex->right=Delete(vertex->right,vertex->data);
			}
			else if(vertex->left)
			{
				vertex=vertex->left;
			}
			else if(vertex->right)
			{
				vertex=vertex->right;
			}
			else
				vertex=NULL;
		}
		else if(x>vertex->data)
			vertex->right=Delete(vertex->right,x);
		else if(x<vertex->data)
			vertex->left=Delete(vertex->left,x);
	}
		if(vertex==NULL)
			return vertex;
		return balancer(vertex,x);
}

int count=0;
void INORDER(node *vertex)
{
	if(vertex==NULL)
		return;
	INORDER(vertex->left);
	printf("%d   ",vertex->data);
	//printf("%d  ",count++);
//	printf("h: %d   ",vertex->height);
	INORDER(vertex->right);
}
int main()
{
	node *root=NULL,*temp;
	int n,x,i;
	printf("Enter the n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("ELEMENT %d: ",(i+1));
		scanf("%d",&x);
		root=AVL(root,x);	
	}
	INORDER(root);
	printf("\n");
	Delete(root,5);
	Delete(root,6);
	INORDER(root);
	return 0;	
}
