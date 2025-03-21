#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node* left;
	int data;
	struct Node* right;
}node;

node* initNode(int x)
{
	node *n=(node*)malloc(sizeof(node));
	n->data=x;
	n->left=NULL;
	n->right=NULL;
	return n;
}
node* BINARYSEARCH(node *root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
	{
		return root;
	}
	else if(x<root->data)
	{
		BINARYSEARCH(root->left,x);
	}
	else if(x>root->data)
	{
		BINARYSEARCH(root->right,x);
	}
}
node* BST(node *vertex,int x)
{
	if(vertex==NULL)
		return initNode(x);
	else if(x>vertex->data)
		vertex->right=BST(vertex->right,x);
	else if(x<vertex->data)
		vertex->left=BST(vertex->left,x);
	else
		return vertex;
}

node* leftMost(node *root)
{
	if(root)
	{
		while(root->left)
			root=root->left;
		return root;
	}
	return NULL;
}
node* rightMost(node *root)
{
	if(root)
	{
		while(root->right)
			root=root->right;
		return root;
	}
	return NULL;
}
int isLeftOrRight(node *prev,int v)
{
	if(prev==NULL)
		return 0;
	if(prev->left)
	{
		if(prev->left->data==v)
			return 1;
	}
	if(prev->right)
	{
		if(prev->right->data==v)
			return 2;
	}
}
void deleteSingleorNochild(node *prev,node *root)
{
		switch(isLeftOrRight(prev,root->data))
		{
			case 0:
				root=(root->left)?(root->left):(root->right);
			case 1:
				prev->left=(root->left)?(root->left):(root->right);
			case 2:
				prev->right=(root->left)?(root->left):(root->right);
		}
}
void DeleteBST(node *root,node *prev,int v)
{
	node *t;
	if(root)
	{
		if(root->data==v)
		{
			if(root->left && root->right)
			{
				t=leftMost(root->right);
				root->data=t->data;
				DeleteBST(root->right,root,t->data);
			}
			else
			{
				deleteSingleorNochild(prev,root);
			}
		}
		else if(v<root->data)
		{
			DeleteBST(root->left,root,v);	
		}
		else if(v>root->data)
		{
			
			DeleteBST(root->right,root,v);
		}
	}	
}


int count=0;
node* KINORDER(node *vertex,int x)
{
	if(vertex==NULL)
		return;
	KINORDER(vertex->left,x);
	count++;
	if(count==x)
	{
		printf("%d",vertex->data);
		//exit(0);
	}
	KINORDER(vertex->right,x);
}
int c=0;
void INORDER(node *vertex)
{
	if(vertex==NULL)
		return;
	INORDER(vertex->left);
	printf("%d ",vertex->data);
	printf("c:%d ",c++);
	INORDER(vertex->right);
}
int main()
{
	node *root=NULL,*temp;
	int n,x,i,c;
	do 
	{
		printf("\nBST\n1.Insert\n2.Delete\n3.Display\n4.K-Small\n5.Exit\n");
		printf("Enter the choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nEnter the n:");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("ELEMENT %d: ",(i+1));
					scanf("%d",&x);
					root=BST(root,x);
				}
				break;
			case 2:
				printf("\nEnter the target:");
				scanf("%d",&n);
				DeleteBST(root,NULL,n);
				break;
			case 3:
				printf("\nBST ELEMENTS:\n");
				INORDER(root);
				break;
			case 4:
				printf("\nEnter the target:");
				scanf("%d",&n);
				KINORDER(root,n);
				break;
			case 5:
				printf("\nThank You!");
				break;
		}
	}while(c!=5);
	return 0;	
}
