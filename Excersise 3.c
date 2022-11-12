/*************************************
������� 2�
���������� ���������� 
��.��. : 2014030069
*************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int code_part; /* ������� ��������� */
	int quantity; /* ������� ������������ ��������� ��� ���� �� ������ */
} parts;

typedef struct
{
	int code; /* ������� ��������� */
	char* name; /* ����� ��������� */
	int npieces; /* ������� ��� ������� �� ���������*/ 
	int needed; /* ���� �������� ����������� ��� ����� */
	parts *usage; /* ��� ���� ����������� ����������� */
	int nuses; /* ��� ���� ����������� ����������� */
} products;

void neededproducts(int size, int tip, int num, products* list); /*������ �� ����������� ���������� ���(����������) */

int main()
{   
    products* product = NULL;
    int num_of_orders,nbr_of_products; /*������� �������� ��� ������� ����������� */
	int retValue;
	char ans1,buf[15],mat_word[15]; /*� �������� ��� ��� ����� �������, ���� ������� ��� ���������� ��������� �� ����� ���� ���������, ���� ������� ��� ���������� ��� ���� ��� ������� 3 ��� �����*/
	int ans2; /*� �������� ��� ��� ��������� ���� �� ����� ���� ������� ��� ����� */
	int a_code;
	int i,j,k,l,x,y,q; /* ���������� ��� for */
	int order_code=0,order_needed=0;
	FILE* fp; /* ��������� ������� ������� */
	FILE* cp; /* ��������� ������� ������� */
	
	printf("Welcome to our order manager.\n\n"); /* ����������� ��� ������ */
	printf("Press (M) to show you the menu or press (Q) to quit the programm.\n");
	scanf("%c", &ans1);
	do{	                                                               
	    if(ans1 != 'M' && ans1 != 'Q')
	    {
	      printf("Please give a compatible option.\n");
	      scanf("%c", &ans1);
	    }
	}while(ans1 != 'M' && ans1 != 'Q');
	
	if(ans1 == 'Q')
	{
		return 0;
	}
	if(ans1 == 'M')/*������� ����� */
	{
		printf("This is our menu.\n\n");
		printf("To read the data (it is needed first) text press(1)\n");
		printf("To show you the list of our storage press(2)\n");
		printf("To show you the parts of products press(3)\n");
		printf("To print the final order text press(4)\n");
		printf("To exit the programm press(0)\n");
		scanf("%d", &ans2);
		
		if(ans2 == 1) /* ������� �� ��������� ��� �������� �� �������� ��� */
		{
		  
			fp = fopen("datain.txt", "r");
	
	        if(fp != NULL)
	        {
		      retValue = fscanf(fp, "%d\n", &nbr_of_products);
		
		      if(retValue == EOF)
		      {
			    printf("Empty File! Programm will close.......");
			    return 0;
		      }
		
		     product = (products*)malloc(nbr_of_products * sizeof(products));
		
	       	 for(i= 0; i < nbr_of_products; i++)
	         {
		        fscanf(fp, "%d %s %d %d", &product[i].code, buf, &product[i].npieces, &product[i].nuses);
		
		        product[i].name = (char*) malloc((strlen(buf) + 1) * sizeof(char)); 
                strcpy(product[i].name, buf);
		
		        if(product[i].nuses != 0)
		        {
			      product[i].usage = (parts*)malloc(sizeof(parts)*product[i].nuses);
			
			      for(j = 0; j < product[i].nuses; j++)
			      {
				    fscanf(fp, "%d %d \n", &product[i].usage[j].code_part, &product[i].usage[j].quantity);
				  }
		        }
		     }
			 printf("The file open successfully!\n");
		    }
	        else
	         {
		       printf("An ERROR has occured while loading the corrrect file. Please try again");
		       printf("Programm will close.......");
		       return 0;
	         }
	         printf("\nChoose other option:\n");
		     printf("To show you the list of our storage press(2)\n");
		     printf("To show you the parts of products press(3)\n");
			 printf("To print the final order text press(4)\n");
			 printf("To exit the programm press(0)\n");
	         scanf("%d", &ans2);
	    }
	    if(ans2 == 2) /* ��������� �� ����� ��� ��� �������� ���� ���� ������� */
	    {
	        for(x = 0; x < nbr_of_products; x++) 
            {      
                 printf("\nCode: %d \nName: %s \nAvailable In Store: %d \n", product[x].code, product[x].name, product[x].npieces);
	        }
	       printf("\nChoose other option:\n");
		   printf("To show you the list of our storage press(2)\n");
		   printf("To show you the parts of products press(3)\n");
		   printf("To print the final order text press(4)\n");
		   printf("To exit the programm press(0)\n");
	       scanf("%d", &ans2);
		    
	    }
	    while(ans2 == 3) /* �������� �� ��������� ���� ������ ��� ��� �������� ���� ���� ������� */
	    {
	    	fseek(stdin,0,SEEK_END);
	        printf("Type the material you want to search:\n");
	        gets(mat_word);
	        i=0;
	        while(strcmp(mat_word,product[i].name) != 0)
	    	{
	    		i++;
	        }
	    	for(j=0; j < product[i].nuses; j++)
	    	{
	    	    a_code = product[i].usage[j].code_part;
			    printf("It is made by %s (available: %d).\n", product[a_code-1].name, product[a_code-1].npieces);
				    
	    	}
	    	
			printf("\nChoose other option:\n");
			printf("To show you the list of our storage press(2)\n");
			printf("To show you the parts of products press(3)\n");
			printf("To print the final order text press(4)\n");
			printf("To exit the programm press(0)\n");
	    	scanf("%d", &ans2);
	    }
	    if(ans2 == 4)/* ����������� needed ��� ���������� ������� ������ */
	    {
	    	cp = fopen("dataout.txt","w");
	    	fscanf(fp,"%d\n",&num_of_orders);
	    	for(l=0; l<num_of_orders; l++)
	    	{
	    		fscanf(fp,"%d %d\n", &order_code, &order_needed);
	    	}
			neededproducts(nbr_of_products, order_code, order_needed, product);
	    	
			fprintf(cp,"Number of material types: %d\n", nbr_of_products);
	    	
	    	for(q=0; q<nbr_of_products; q++)
	    	{
	    		fprintf(cp,"%d/%s - %d units in stock - %d units needed.\n", product[q].code, product[q].name, product[q].npieces, product[q].needed);
	    	}
	    	printf("\nYour order is ready!!\n");
	    	printf("\nChoose other option:\n");
	    	printf("To show you the list of our storage press(2)\n");
			printf("To show you the parts of products press(3)\n");
			printf("To print the final order text press(4)\n");
			printf("To exit the programm press(0)\n");
	    	scanf("%d", &ans2);
	    }
	    if(ans2 == 0) /* �������� ������� ��� ������������ */
	    {
	    	for(k = 0; k < nbr_of_products; ++k) 
            {    
              if(product[k].name != NULL)
              free(product[k].name);
            }       
   
            free(product);
			fclose(fp);
		    return 0;
	    }
    }
	    
 }

void neededproducts(int size, int tip, int num, products* list)
{
	int m,n,point;
	
	for(m=0; m<size; m++)
	{
		list[m].needed = 0;
		if(tip == list[m].code)
		{
			
			for(n=0; n<list[m].nuses; n++)
			{
			    point = list[m].usage[n].code_part;
				list[point].needed = num * list[m].usage[n].quantity;
			}
		}
	}
}



 



