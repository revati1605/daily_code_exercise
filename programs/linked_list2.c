#include"header.h"
int count=0;
int main()
{
	struct list* head=NULL;
	int choice;
	while(1)
	{
	l1:	printf("\n1:add\n2:Display\n3:print mth node from last\n4:remove mutiples\n5:adding in sorted order\n6:Delete last\n7:Reverse list\n8:exit\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				while(1)
				{
					printf("1:add at first 2:add at last\n3:exit\n");
					int op;
					printf("Enter option: ");
					scanf("%d",&op);
					switch(op)
					{
						case 1:
							head=add_first(head);
							count++;
							break;
						case 2:
							head=add_last(head);
							count++;
							break;
					/*	case 3:
							head=add_in_sorted(head);
							count++;
							break;*/
						case 3:
							goto l1;
					}
				}
			case 2:
				Display(head);
				break;
			case 3:
				print_mth_node_from_last(head);
				break;
			case 4:
				head=remove_multiple(head);
				break;
			case 5:
				head=add_in_sorted(head);
				count++;
				break;
			case 6:
				head=delete_last(head);
				count--;
				break;
//			case 7:
//				head=reverse_list(head);
//				break;
			case 8:
				exit(0);
		}
	}
}
// functon for adding at the first position of the pointer
struct list* add_first(struct list* ptr)
{
	struct list* newnode=NULL;
	//creating the node
	newnode=(struct list*)calloc(1,sizeof(struct list));
	if(newnode==NULL)
	{
		printf("Node not created\n");
	}
	else
	{
		printf("Enter value: ");
		scanf("%d",&newnode->value);
		if(ptr==NULL)
		{
			ptr=newnode;
		}
		else
		{
			newnode->link=ptr;
			ptr=newnode;
		}
		return ptr;
	}

}
struct list* add_last(struct list* ptr)
{
	 struct list* newnode=NULL,*temp=NULL;
         //creating the node
         newnode=(struct list*) calloc (1,sizeof(struct list));
         if(newnode==NULL)
         {
                 printf("Node not created\n");
         }
         else
         {
                printf("Enter value: ");
                scanf("%d",&newnode->value);
                if(ptr==NULL)
                {
                         ptr=newnode;
                }
		else
		{
			temp=ptr;
			while(temp->link)
			{
				temp=temp->link;
			}
			temp->link = newnode;
		}
		return ptr;
	}
}

struct list* add_in_sorted(struct list* ptr)
{
	struct list* newnode=NULL, *temp=NULL, *prev=NULL;
	newnode = (struct list*) calloc (1,sizeof(struct list));
	if(newnode==NULL)
	{
		printf("Node not created\n");
	}
	else
	{
		printf("Enter value: ");
		scanf("%d",&newnode->value);
		if((ptr==NULL) || (newnode->value < ptr->value))
		{
			if(ptr)
			{
				newnode->link = ptr;
			}
			ptr = newnode;
		}
		else
		{
			prev=ptr;
			temp=prev->link;
			while(temp && newnode->value > temp->value)
			{
				prev=temp;
				temp=temp->link;
			}
			prev->link=newnode;
			if(temp)
			{
				newnode->link=temp;
			}
		}
	}
	return ptr;
}

void Display(struct list* ptr)
{
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List is:\n");
		while(ptr)
		{
			printf("%d ",ptr->value);
			ptr=ptr->link;
		}
	}
}

void print_mth_node_from_last(struct list* ptr)
{
	int m,i;
	printf("Enter m value: ");
	scanf("%d",&m);
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		for(i=0; i < count-m ; i++)
		{
			ptr=ptr->link;
		}
		printf("%d\n",ptr->value);
	}
}

struct list* remove_multiple(struct list* ptr)
{
	struct list* temp=NULL, *prev=NULL,*demo=NULL;
	demo=ptr;
	while(demo)
	{
		int data;
		temp=demo;
		data=temp->value;
		temp=temp->link;
		prev=demo;
		while(temp)
		{
	//	prev=demo;
		while(temp && temp->value!=data)
		{
			prev=temp;
			temp=temp->link;
		}
		if(temp==NULL)
		{
			printf("Data not found\n");
		}
		else
		{
			prev->link=temp->link;
      			free(temp);
			temp=NULL;
			count--;
			temp=prev->link;
		}
		}
		demo=demo->link;
	}
	return ptr;
}

struct list* delete_last(struct list* ptr)
{
	struct list* temp=NULL,*prev=NULL;
	if(ptr==NULL)
	{
		printf("List is empty\n");
		return ptr;
	}
	else
	{
		temp=ptr;
		while(temp->link)
		{
			prev=temp;
			temp=temp->link;
		}
		free(temp);
		temp=NULL;
		if(prev)
		{
			prev->link=NULL;
		}
		else
		{
			ptr=NULL;
		}
	}
	return ptr;
}

