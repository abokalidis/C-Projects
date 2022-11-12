/*******************************************
���������� ���������� (Bokalidis Anastasios)
��.����. : 2014030069
*******************************************/
#include <stdio.h>
#include <stdlib.h>

struct list{
	int value;
	struct list *next;
};

void insertNodelist(int dgt, struct list **ptr);
struct list *search_list(struct list *l);
void freeList(struct list *head2);

main()
{
    struct list *head;
    struct list *n1;
	int length;
	int num;
	int i;
	char ans;
	struct list *result;
	
	printf("Press (y) to start the programm or (n) to close it.\n");
	scanf("%c", &ans);
	
	while(ans != 'y' && ans != 'n')   /* ������� ��� ����������� ��� �� �� � ������� ����� ����� ��������. */                          
	{
		printf("Error, please give one compatible answer.\n");
		scanf("\n%c", &ans);
    }
	while(ans == 'y')
	{
		head = NULL;
	
	printf("How many numbers do you want in your list? \n"); /*���� ������ ������� ���� �� ���� � �����. */
	scanf("%d", &length);
    
	printf("Now give the numbers you want into your list. \n"); /*�������� ������� ����� �������. */
	
	for(i=0; i<length; i++) /* ���������� ������. */
	{
		scanf("%d", &num);
		insertNodelist(num, &head);
	}
	
	n1 = head;
	
    while(n1 != NULL) /* �������� ������(��� �������� ������ ��� ������������� �� �������� ��������. */
	{
		printf("%d ", n1->value);
		n1 = n1->next;
    }   

	printf("\nNow we are waiting for the results of the function. \n");	
	result = search_list(head); /* ������� ����������� ����������. */
	printf("The returning value of the function is: %d\n\n", result);
	
	freeList(head); /* ���������� ���� ������� ���� ����������. */
	
	printf("To start the programma again press (y) or (n) to exit.\n"); /* ������� ��� ��� �� ���������� �� ��������� � ���. */
	scanf("\n%c", &ans);
	}
}

void insertNodelist(int dgt, struct list **ptr) /* ��������� ��� �� ���������� ���� �������. */
{
	struct list *node;
	struct list *tmp = *ptr;
	
	node = (struct list*)malloc(sizeof(struct list));
	node->value = dgt;
	node->next = NULL;
	
	if(*ptr == NULL)
	{
		*ptr = node;
	}
	else
	{
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}	
		tmp->next = node; 
    }
}

struct list *search_list(struct list *l) /* �������� ��� �� ������� �� ��������� ��� �������(����������). */
{   
    int res;
    
    if(l == NULL || l->next == NULL || l->next->next == NULL) /* ������� ��� �� ���� �������� 2 � ��������� ������. */
    {
    	printf("Your list verify succesfully the function. \n");
		return(NULL);
    }
    else
    {
	    res = (l->next)->value * ((l->next)->next)->value; /* �� �������� ��� �������. */
        
		if(res <= l->value)
		{
			printf("Sorry but %d, %d and %d from your list does not verify the function.\n\n", l->value, (l->next)->value, ((l->next)->next)->value);
			return(l);
		}
		else
		{
			l = l->next;
	        search_list(l); /* ������� ��� ��������. */
		}
	}
}

void freeList(struct list *head2) /* ��������� ��� �� ��������� ���� �������. */
{
	struct list *p;
	if(head2 == NULL)
	{
		return;
	}
	p = head2;
	head2 = head2->next;
	free(p);
	freeList(head2);
}

