#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
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
int height(node *n)
{
	if (n==NULL)
		return 0;
	return n->height;
}
node* leftRotate(node *root)
{
	node *t=root->right;
	root->right=t->left;
	t->left=root;
	root->height=1+max(height(root->left)+height(root->right));
	t->height=1+max(height(t->left)+height(t->right));
	return t;
}
node* rightRotate(node *root)
{
	node *t=root->left;
	root->left=t->right;
	t->right=root;
	root->height=1+max(height(root->left)+height(root->right));
	t->height=1+max(height(t->left)+height(t->right));
	return t;
}
int max(int x,int y)
{
	return (x>y?x:y);
}
int isBalance(node *root)
{
	return height(root->left)-height(root->right);
}
node* Balancer(node *root,int x)
{
	if(root==NULL)
		return root;
	root->height=1+max(height(root->left),height(root->right));
	if(isBalance(root)<-1)
	{
		if(x<root->right->data)
			root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	else if(isBalance(root)>1)
	{
		if(x>root->left->data)
			root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	return root;
}
node* rightMost(node *root)
{
	node *t=root;
	while(t->right)
		t=t->right;
	return t;
	
}
node* insert(node *root,int data)
{
	if(root==NULL)
		return initNode(data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	else if(data<root->data)
		root->left=insert(root->left,data);
	return Balancer(root,data);
}
node* deleteN(node *root,int data)
{
	if(root)
	{
		if(root->data==data)
		{
			if(root->left && root->right)
			{
				root->data=rightMost(root->left)->data;
				root->left=deleteN(root->left,root->data);
			}
			else if(root->right)
				root=root->right;
			else if(root->left)
				root=root->left;
			else
				root=NULL;
			return Balancer(root,data);
		}
		else if(data<root->data)
			root->left=deleteN(root->left,data);
		else if(data>root->data)
			root->right=deleteN(root->right,data);
		return root;
	}
}
void Inorder(node *root)
{
	if(root)
	{
		Inorder(root->left);
		printf("%d ",root->data);
		Inorder(root->right);
	}
}
int main()
{
	node *root=NULL;
	root=insert(root,5);
	root=insert(root,4);
	root=insert(root,6);
	root=insert(root,7);
	root=insert(root,8);
	root=deleteN(root,5);
	root=deleteN(root,4);
	
	Inorder(root);
	printf("head:%d",root->data);
//	printf("head:%d",root->right->data);
	return 0;
}
