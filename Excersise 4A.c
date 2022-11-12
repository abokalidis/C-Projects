/*******************************************
���������� ���������� (Bokalidis Anastasios)
��.����. : 2014030069
*******************************************/
#include <stdio.h>
#include <stdlib.h>

int search_array(int *table, int x, int l_num, int m);

main()
{
	int length,result; 
	int i,n;
	char ans;
	
	printf("Press (y) to start the programm or (n) to close it.\n");
	scanf("%c", &ans);
	
	while(ans != 'y' && ans != 'n')   /* ������� ��� ����������� ��� �� �� � ������� ����� ����� ��������. */                          
	{
		printf("Error, please give one compatible answer.\n");
		scanf("\n%c", &ans);
    }
    while(ans == 'y') /* ������� ��� �� ���� �� ������� �� ������ ������� ��� ��� ������. */
    {
    	printf("Please give me the number of integers you want.\n");
	    scanf("%d", &length);
	
	while(length == 0) /* ������� ����������� ��� �� �� � ������� ����� 0 ��� ������ ������. */
	{
		printf("Please give me another number of integers.\n");
		scanf("%d", &length);
	}
	
	int *Array = (int *)malloc(length * sizeof(int)); /*�������� �������� ������ ��� ��� ������. */
	
	printf("Now give the numbers want inside the array.\n");
	
	for(i=0; i < length; i++) /* �������� ��������� ���� �����. */
	{
		scanf("%d", &Array[i]);
	}
	n = Array[0];
	
	printf("\n\nNow we will check if there are numbers in your array that their sum is equal to the first number of your array..\n");
	i=0;
	result = search_array(Array, i, length, n); /* ������� ���������� */
	printf("\nThe returning value of function: %d\n\n", result); /* ��������� ��� ���� ���������� ��� ���������� */
	
	for(i=0; i < length; i++) /* ��� ������� � ���������� ��� ������ ��� ������ */
	{
		free(&Array[i]);
	}
	
	printf("To start the programm again press (y) or (n) to exit.\n"); /* ������� ��� ��� �� ���������� �� ��������� � ���. */
	scanf("\n%c", &ans);
    }
	
}

int search_array(int *table, int x, int l_num, int m) /*������ ���������� ����������. */
{ 
   
    if(x <= l_num /2)
    {
        if(table[x] + table[l_num-1] != m)                                        /*��� �� �������� ��� ����������� ������ ��� ������� �� �� ����� ����*/
        {                                                                         /*��� ���������� � ������� ��� ������ ��� ���� ������ ��� ����� ���*/
	    return search_array(table, x+1 , l_num-1, m); /* ������� ��� �������� */         /*������ �� ��������������� � ��������*/
	    }
	    else
	    {
		printf("\n%d and %d verify the function. \n", table[x], table[l_num-1]);
		return(x);
	    }
    }
    else
    {
    	 printf("\nSorry but your function has no results. \n");
		 return(-1);
	}
}


