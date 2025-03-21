#include "ListManip.c"
int main() // TOTALLY INEFFICIENT
{
	int *list,n,ch,temp,t,in1,in2;
	//list=initList(list,&n);
	list=initList(&n);
	do 
	{
		printf("\n-----MENU-----\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Find Duplicate\n6. Full Duplication Detection \n7. Exit\n");
		printf("YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertElement(list,&n);
				break;
			case 2:
				deleteElement(list,&n);
				break;
			case 3:
				printf("\n1. Firt to Last Search\n2. Last to First Search\nYour Choice:");
				scanf("%d",&temp);
				temp=searchElement(list,&n,temp); // SEARCH DOESN'T NEED PASS BY REFERENCE
				temp?printf("Element Found at %d\n",temp):printf("Element Not Found\n");
				break;
			case 4:
				displayList(list,&n);
				break;
			case 5:
				printf("NOTE: We Only Check two values at maximum to check for duplication\nEnter the target:");
				scanf("%d",&temp);
				in1=searchElementTarget(list,&n,1,temp); // SEARCH DOESN'T NEED PASS BY REFERENCE
				in2=searchElementTarget(list,&n,2,temp); // SEARCH DOESN'T NEED PASS BY REFERENCE
				if(in1!=in2)
				{
					printf("There is a Duplicate for %d found at general index %d and %d\n",temp,in1,in2);
					printf("shall i delete the duplicate?(1 - YES | 0 - NO)");
					scanf("%d",&t);
					if(!t)
						break;
					printf("\nWhich element shall I delete FIRST(DEF.) OR LAST?\n1. First\n2. Last\nYour Choice:");
					scanf("%d",&t);
					if(t==2)
						deleteElementIndex(list,&n,in2);
					else
						deleteElementIndex(list,&n,in1);
					
				}
				else
					printf("\nThere is NO Duplicate or No Element at all\n");
				break;
			case 6: // DOESN'T NEED PASS BY REFERENCE
				fullDupDetect(list,&n);
				break;
			case 7:
				printf("\nThank You!\n");
				break;
			default:
				printf("\nINVALID CHOICE\n");

		}
		getchar();
		printf("\nPress again to go further....\n");
		getchar();
	}while(ch!=7);
	return 0;
}
