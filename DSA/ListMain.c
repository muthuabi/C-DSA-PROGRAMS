#include "ListModuleDouble.c"
//#include "ListModuleSingle.c"
//void Inorder(node* tree)
//{  //INFINITE LOOP
//	if(tree==NULL)
//		return;
//	Inorder(tree->prev);
//	printf("%d\t",tree->data);
//	Inorder(tree->next);
//}
int main() {
    node *head=NULL,*t;
    int ch,x,y,c,n,i;
  	do
  	{
  		printf("\n-----MENU-----\n1. Insert\n2. Delete\n3. Search\n4. Find Node\n5. Display\n6. Exit\n");
		printf("YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				
				printf("\n-----SUB MENU-----\n1. Insert Begin\n2. Insert End\n3. Insert Specific\n");
				printf("YOUR CHOICE:");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
						printf("Enter the no of elements:");
						scanf("%d",&n);
						for(i=0;i<n;i++)
						{
						printf("Enter Element:");
						scanf("%d",&x);
						if(insertNodeAtBegin(&head,x))
							printf("Element Inserted Begin\n");
						}
						break;
					case 2:
						printf("Enter the no of elements:");
						scanf("%d",&n);
						for(i=0;i<n;i++)
						{
						printf("Enter Element:");
						scanf("%d",&x);
						if(insertNodeAtEnd(&head,x))
							printf("Element Inserted End\n");
						}
						break;
					case 3:
						printf("Enter the Target:");
						scanf("%d",&y);
						printf("Enter Element:");
						scanf("%d",&x);
						if(insertNodeAtSpec(&head,y,x))
							printf("Element Inserted");
						else
						{
							printf("There is No Such Data\nShall I just Insert\n1. BEGIN\n2. END\n3. CANCEL\nYOUR CHOICE:");
							scanf("%d",&c);
							if(c==1)
							{
								if(insertNodeAtBegin(&head,x))
									printf("Element Inserted Begin\n");
							}
							else if(c==2)
							{
								if(insertNodeAtEnd(&head,x))
									printf("Element Inserted End\n");
							}
							else
								printf("\nCANCELLED\n");

						}
						break;
					default:
						break;
				}
				break;
			case 2:
				printf("\n-----SUB MENU-----\n1. Delete Begin\n2. Delete End\n3. Delete Specific\n");
				printf("YOUR CHOICE:");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
						printf("Enter the no of elements:");
						scanf("%d",&n);
						for(i=0;i<n;i++)
						{
						if(deleteNodeAtBegin(&head))
							printf("Element Deleted Begin\n");
						else
							break;
						}
						break;
					case 2:
						printf("Enter the no of elements:");
						scanf("%d",&n);
						for(i=0;i<n;i++)
						{
						if(deleteNodeAtEnd(&head))
							printf("Element Deleted End\n");
						else
							break;
						}
						break;
					case 3:
						printf("Enter the Target:");
						scanf("%d",&y);
						if(deleteNodeAtSpec(&head,y))
							printf("Element Deleted\n");
					default:
						break;
				}
				break;
			case 3:
				printf("Enter the Target:");
				scanf("%d",&y);
				if((x=searchNode(head,y)))
					printf("\nNode Found and It is the Node %d\n",x);
				else
					printf("\nNode Not Found\n");
				break;
			case 4:
				printf("Enter the n:");
				scanf("%d",&y);
				if((t=findNode(head,y)))
					printf("There is a node %d",t->data);
				else 
					printf("Index out of Bound");
				break;
			case 5:
				display(head);
				break;
			case 6:
				printf("\nThank You!\n");
				break;
//			case 7:
//				printf("\nINORDER TRAVERSAL\n");
//				Inorder(head);
//				break;
			default:
				printf("\nINVALID CHOICE\n");
		}
		getchar();
		printf("\npress again to continue...\n");
		getchar();
  	}while(ch!=6);
    return 0;
}
