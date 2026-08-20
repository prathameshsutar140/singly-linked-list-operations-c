#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node * next;
};
void main()
{
	struct Node * head = 0, * newnode = 0, * temp,*pre;
	int ch,choose,choice,key,pos,i;

	do
	{
		newnode=(struct Node*)malloc(sizeof(struct Node));


		printf("Eneter a data:");
		scanf("%d",&newnode->data);

		newnode->next=0;

		if(head==0)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}

		printf("if you want to continue enter yes/0 no/1");
		scanf("%d",&ch);
	}while(ch!=1);
	do
	{
		printf("enter 1:insert at start \n 2:insert in between\n 3:insert at end\n 4:delete\n 5:display\n 6:exit\n");
		printf("enter your choice:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1: newnode=(struct Node*) malloc(sizeof(struct Node));
				printf("enter a data:");
				scanf("%d",&newnode->data);
				newnode->next=head;
				head=newnode;
				break;
			case 2: newnode=(struct Node*)malloc(sizeof(struct Node));
				printf("enter a data:");
				scanf("%d",&newnode->data);
				printf("Eneter position:");
				scanf("%d",&pos);
				temp=head;
				for(i=1;i<pos-1;i++)
				{
					temp->next=newnode;
					newnode->next=temp->next;
				}
				newnode->next=temp->next;
				temp->next=newnode;
				break;
			case 3: newnode=(struct Node*)malloc(sizeof(struct Node));
				temp=head;
				while(temp->next!=0)
				{
					temp=temp->next;
				}
				newnode->next=0;
				temp->next=newnode;
				break;
			case 4: printf("enter a element to delete:\n");
				scanf("%d",&key);
				if(head->data!=key)
				{
					temp=head;
					head=head->next;
					free(temp);
				}
				else
				{
					temp=head;
					while(temp->data!=key)
					{
						pre=temp;
						temp=temp->next;
					}
					pre->next=temp->next;
					free(temp);
				}
				break;
			case 5: temp=head;
				while(temp!=0)
				{
					printf("%d\n",temp->data);
					temp=temp->next;
				}
				break;
			case 6: printf("Exiting......");
				break;
			default: printf("invalid choice enter valid choice:");
		}
	}while(choose!=6);

	getch();
	clrscr();

}