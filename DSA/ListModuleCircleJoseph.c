#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    	*tail=n;
    }
    n->next=*head;
    *head=n;
    (*tail)->next=*head;
    return 1;
}
int insertNodeAtEnd(node **head,node **tail,int data)
{
    node *n=initNode(data);
    node *ptr=*head;
    if(*head)
    {
        // while(ptr->next!=*head)
        //     ptr=ptr->next;
        // n->next=ptr->next;
        // ptr->next=n;
        // *tail=n;
        //OR
        n->next=(*tail)->next;
        (*tail)->next=n;
        *tail=n;
    }
    else
    {
        *head=n;
        n->next=*head;
        *tail=n;
    }
    return 1;
}
int insertNodeAtSpec(node **head,node **tail,int target,int data)
{
    node *n=initNode(data);
    if(*head)
    {
        node *ptr=*head;
        do
        {
            if(ptr->data==target)
            {
                if(ptr->next==*head) //FIRST NODE OR LAST NODE
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    *tail=n;
                }
                else
                {
                    n->next=ptr->next;
                    ptr->next=n;
                }
                return 1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=*head);
    }
    return 0;
}
int deleteNodeAtBegin(node **head,node **tail)
{
    if(*head)
    {
        if((*head)->next==*head)
            *head=*tail=NULL;
        else
        {
            *head=(*head)->next;
            (*tail)->next=*head;
        }
        return 1;
    }
    return 0;
}
int deleteNodeAtEnd(node **head,node **tail)
{
    if(*head)
    {
        node *ptr=*head;
        while(ptr->next!=*tail)
            ptr=ptr->next;
        if(ptr==*tail)
        {
            *head=*tail=NULL;
            return 1;
        }
        else
        {
            ptr->next=(*tail)->next;
            *tail=ptr;
        }
        return 1;
    }
    return 0;
}
int deleteNodeAtSpec(node **head,node **tail,int target)
{
    if(*head)
    {
        node *ptr=*head;
        node *t=*head;
        do
        {
            //printf("%d",ptr->data);
            if(ptr->data==target)
            {   
                if(ptr->next==*head && (ptr==t)) //ONLY NODE
                {
                    *tail=*head=NULL;
                }
                else if(ptr==t)
                {
                    *head=(*head)->next;
                    (*tail)->next=*head;
                }
                else if(ptr->next==*head)// LAST NODE
                {
                    t->next=ptr->next;
                    *tail=t;
                }
                else
                    t->next=ptr->next;
                break;
            }
            t=ptr;
            ptr=ptr->next;
        }while(ptr!=*head);
    }
    return 0;
}
void display(node *head,node *tail) {
    //tail not needed
    node *ptr = head;
    int i=0;
 	if(ptr==NULL)
    {
 		printf("\nList Empty\n\n");
        return;
    }
 	else
 		printf("\nList Elements:\n\n");
    do
    {
    	printf("%d\t",ptr->data);
    	i++;
        ptr = ptr->next;
    }while (ptr!=head);
    printf("\n\nList Count %d\n",i);
}
int searchNode(node *head,node *tail,int target)
{
    //tail not needed
    int i=0;
    node *ptr=head;
    if(head)
    {
        do
        {
            if(ptr->data==target)
                return (i+1);
            ptr=ptr->next;
            i++;
        }while(ptr!=head);
    }
    return 0;
}
void josephus(node **head,int k)
{
	if(*head)
	{
		node *prev=*head;
		node *cur=*head;
		int i=0;
		while(prev->next!=prev)
		{
			for(i=1;i<k;i++)
			{
				prev=cur;
				cur=cur->next;
			}
			prev->next=cur->next;
			cur=prev->next;
		}
		printf("joseph %d",cur->data);
	}
}
node* findNode(node *head,node *tail,int n)
{
    //tail not needed
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
int main() {
    node *head=NULL,*t;
    node *tail=NULL;
    int ch,x,y,c,n,i;
    do
    {
        printf("\n-----CIRCULAR MENU-----\n1. Insert\n2. Delete\n3. Search\n4. Find Node\n5. Display\n6. Exit\n");
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
                        if(insertNodeAtBegin(&head,&tail,x))
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
                        if(insertNodeAtEnd(&head,&tail,x))
                            printf("Element Inserted End\n");
                        }
                        break;
                    case 3:
                        printf("Enter the Target:");
                        scanf("%d",&y);
                        printf("Enter Element:");
                        scanf("%d",&x);
                        if(insertNodeAtSpec(&head,&tail,y,x))
                            printf("Element Inserted");
                        else
                        {
                            printf("There is No Such Data\nShall I just Insert\n1. BEGIN\n2. END\n3. CANCEL\nYOUR CHOICE:");
                            scanf("%d",&c);
                            if(c==1)
                            {
                                if(insertNodeAtBegin(&head,&tail,x))
                                    printf("Element Inserted Begin\n");
                            }
                            else if(c==2)
                            {
                                if(insertNodeAtEnd(&head,&tail,x))
                                    printf("Element Inserted End\n");
                            }
                            else
                                printf("\nCANCELLED\n");

                        }
                        break;
                    case 4:
                    	josephus(&head,2);
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
                        if(deleteNodeAtBegin(&head,&tail))
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
                        if(deleteNodeAtEnd(&head,&tail))
                            printf("Element Deleted End\n");
                        else
                            break;
                        }
                        break;
                    case 3:
                        printf("Enter the Target:");
                        scanf("%d",&y);
                        if(deleteNodeAtSpec(&head,&tail,y))
                            printf("Element Deleted\n");
                    default:
                        break;
                }
                break;
            case 3:
                printf("Enter the Target:");
                scanf("%d",&y);
                if((x=searchNode(head,tail,y)))
                    printf("\nNode Found and It is the Node %d\n",x);
                else
                    printf("\nNode Not Found\n");
                break;
            case 4:
                printf("Enter the n:");
                scanf("%d",&y);
                if((t=findNode(head,tail,y)))
                    printf("There is a node %d",t->data);
                else 
                    printf("Index out of Bound");
                break;
            case 5:
                display(head,tail);
                break;
            case 6:
                printf("\nThank You!\n");
                break;
            default:
                printf("\nINVALID CHOICE\n");
        }
        getchar();
        printf("\npress again to continue...\n");
        getchar();
    }while(ch!=6);
    return 0;
}
