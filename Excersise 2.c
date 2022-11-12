/* ANASTASIOS BOKALIDIS A.M. 2014030069*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LICENSE_PLATE_LENGTH 7
#define LICENSE_PLATE_ALPHA_LENGTH 3
#define LICENSE_PLATE_NUM_LENGTH 4

typedef struct Rental{
    int nDays;
    float kmsDriven;
    char carLicensePlate[LICENSE_PLATE_LENGTH+1];
    char *clientName;
    char chargingCategory;
}Rental;

void insertRental(int x,int num_of_rentals,Rental* rent);
void showrentals(int x,Rental* rent);
int deleteRental(int x,Rental* rent);
float ammountDueA(int nDays, float kmsDriven);
float ammountDueB(int nDays, float kmsDriven);
float ammountDueC(int nDays, float kmsDriven);

main()
{
    Rental *rent=NULL;
    int option,num_of_rentals=0,x=0;

    printf("Welcome to the Car Rental Charging System!\n\n");
    printf("Welcome to the Car Rental Manager\n");
    printf("How many rentals do you plan to manage? :");
    scanf("%d",&num_of_rentals);
    rent=(Rental*)malloc(num_of_rentals*sizeof(Rental));
    printf("Program menu-Please select one of the following options:\n1.Insert new rental\n2.Delete rental\n3.Show rentals\n4.Terminate Program\n--->");
    scanf("%d",&option);
    while(1){
    switch(option){                 /*Edw ksekinan oi periptwseis gia to menu*/
    case(1) :
    	if(x<num_of_rentals)
    	{
		   insertRental(x,num_of_rentals,rent);   /*kathe fora pou kanw ena insert auksanetai kai o deikths mexri na ftasei ston arithmo paraggeliwn pou edwsa*/
           x++;
		   break;
    	}else{
    		printf("You can't make other rentals.\n");
    		break;
    	}        
    case(2) :
        x=deleteRental(x,rent);
        break;
    case(3) :
        showrentals(x,rent);
        break;
    case(4) :
        printf("Program terminated.....Bye!!");
        free(rent);
        system("pause");
        return 0;
        break;
    default :
        printf("Your Option Does Not Exist.");
        break;
    }
    printf("\nProgram menu-Please select one of the following options:\n1.Insert new rental\n2.Delete rental\n3.Show rentals\n4.Terminate Program\n--->");
    scanf("\n%d",&option);
    switch(option);
    }

}
void insertRental(int x,int num_of_rentals,Rental* rent)
{
  char name[100];
  int i,j;

      printf("Give license plate of rented car :");
      scanf("%s",&rent[x].carLicensePlate);
      for(i=0; i<LICENSE_PLATE_ALPHA_LENGTH; i++)
      {
          rent[x].carLicensePlate[i]=toupper(rent[x].carLicensePlate[i]);         /*metatrepw ta prwta 3 grammata se kefalaia*/
      }
      while(isalpha(rent[x].carLicensePlate[0])==0 ||
            isalpha(rent[x].carLicensePlate[1])==0 ||
            isalpha(rent[x].carLicensePlate[2])==0 ||
            isdigit(rent[x].carLicensePlate[3])==0 ||
            isdigit(rent[x].carLicensePlate[4])==0 ||
            isdigit(rent[x].carLicensePlate[5])==0 ||
            isdigit(rent[x].carLicensePlate[6])==0 ||
            strlen(rent[x].carLicensePlate)!=LICENSE_PLATE_LENGTH){             /*Elegxw ama edwse o xrhsths swstes pinakides*/
                    printf("Error with your license plate. Try again :");
                    scanf("%s",&rent[x].carLicensePlate);
      }

      printf("Give name of client that made the rental :");
      getchar();
      gets(name);
      rent[x].clientName = (char*) malloc((strlen(name) + 1) * sizeof(char));
      strcpy(rent[x].clientName, name);

      printf("Give days of rental :");
      scanf("\n%d",&rent[x].nDays);
      while(rent[x].nDays<=0)
      {
           printf("Please give a positive number :");
           scanf("\n%d",&rent[x].nDays);
      }

      printf("Give kilometers driven :");
      scanf("\n%d",&rent[x].kmsDriven);
      while(rent[x].kmsDriven<=0)
      {
          printf("Please give a positive number :");
          scanf("\n%d",&rent[x].kmsDriven);
      }

      printf("Give charging category :");
      scanf("\n%c",&rent[x].chargingCategory);
      while(rent[x].chargingCategory!='A' && rent[x].chargingCategory!='B' && rent[x].chargingCategory!='C')
      {
          printf("Please Choose A or B or C (only upper chars):");
          scanf("\n%c",&rent[x].chargingCategory);
      }
      printf("The Rental Has Been Saved.\n\n");
}

void showrentals(int x,Rental* rent)
{
    char name[50];
    char lic[LICENSE_PLATE_LENGTH+1];
    float charge=0;
    int i;

    printf("Give license plate for finding rentals to show ('*' for any plate):");
    scanf("%s",&lic);
    printf("Give client name for finding rentals to show ('*' for any client):");
    getchar();
    gets(name);
    for(i=0; i<x; i++)
    {
        if(strcmp(lic,rent[i].carLicensePlate)==0 && strcmp(name,rent[i].clientName)==0)
        {
            printf("Rental for car %s by client %s\n",rent[i].carLicensePlate,rent[i].clientName);
            if(rent[i].chargingCategory == 'A')
            {
                charge+=ammountDueA(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'B')
            {
                charge+=ammountDueB(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'C')
            {
                charge+=ammountDueC(rent[i].nDays,rent[i].kmsDriven);
            }
        }
        if(lic[0]=='*' && name[0]=='*')
        {
            printf("Rental for car %s by client %s\n",rent[i].carLicensePlate,rent[i].clientName);
            if(rent[i].chargingCategory == 'A')
            {
                charge+=ammountDueA(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'B')
            {
                charge+=ammountDueB(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'C')
            {
                charge+=ammountDueC(rent[i].nDays,rent[i].kmsDriven);
            }
        }
        if(lic[0]=='*' && strcmp(name,rent[i].clientName)==0)
        {
            printf("Rental for car %s by client %s\n",rent[i].carLicensePlate,rent[i].clientName);
            if(rent[i].chargingCategory == 'A')
            {
                charge+=ammountDueA(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'B')
            {
                charge+=ammountDueB(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'C')
            {
                charge+=ammountDueC(rent[i].nDays,rent[i].kmsDriven);
            }
        }
        if(strcmp(lic,rent[i].carLicensePlate)==0 && name[0]=='*')
        {
            printf("Rental for car %s by client %s\n",rent[i].carLicensePlate,rent[i].clientName);
            if(rent[i].chargingCategory == 'A')
            {
                charge+=ammountDueA(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'B')
            {
                charge+=ammountDueB(rent[i].nDays,rent[i].kmsDriven);
            }
            else if(rent[i].chargingCategory == 'C')
            {
                charge+=ammountDueC(rent[i].nDays,rent[i].kmsDriven);
            }
        }
        if(rent==NULL)
        {
            printf("There are no rentals");
        }
    }
    printf("Total charge :%.2f\n",charge);  /*To charge kathe fora pou vriskei enan komvw prostithete sto hdh yparxwn charge kai etsi vgainei to teliko poso*/
}

int deleteRental(int x,Rental* rent)
{
    char name[50];
    char lic[LICENSE_PLATE_LENGTH+1];
    int i,j,k,temp,l,counter =0;

    printf("Give license plate for finding rentals to delete ('*' for any plate):");
    scanf("%s",&lic);
    printf("Give client name for finding rentals to delete ('*' for any client):");
    getchar();
    gets(name);
    for(i=0; i<x; i++)
    {
        if(strcmp(lic,rent[i].carLicensePlate)==0 && strcmp(name,rent[i].clientName)==0)
        {
            for(j=i; j<x-1; j++){ /*diagrafw to stoixeio pou thelw kai metaferw ola ta alla kata ena pisw*/
                rent[j]=rent[j+1];
                if(j==x-1)
                {
                	free(rent[j].clientName);
                	free(&rent[j]);
                }
            }
            x--;
            return x;
        }
        if(lic[0]=='*' && name[0]=='*') /*ta diagrafw ola apo to telos pros thn arxh. to temp voithitikh metablhth*/
        {
            temp = x;
            for(j=temp; j>=0; j--){
                free(rent[j].clientName);
                free(&rent[j]);
                x--;
            }
			return x;
        }
        if(lic[0]=='*' && strcmp(name,rent[i].clientName)==0) /*kathe fora pou vriskei auto pou thelw auksanw enan counter kai meta ektelw thn diagrafh oses fores to vrhke*/
        {
            counter=0;
        	for(k=0 ; k<x-1 ;k++){
        		if(strcmp(name,rent[k].clientName)==0)
        		counter ++;
        	}
        	for(l=0 ; l<counter ;l++){
        		for(k=0 ; k<x-1 ;k++){
        			if(strcmp(name,rent[k].clientName)==0){
        				for(j=k; j<x-1; j++)
						{
             				 rent[j]=rent[j+1];
             				 if(j==x-1)
             				 {
             				   free(rent[j].clientName);
             				   free(&rent[j]);
             				 }

        				}
        			}
                }
        		x--;
        	}

        	return x;
        }
        if(strcmp(lic,rent[i].carLicensePlate)==0 && name[0]=='*')
        {
            counter=0;
        	for(k=0 ; k<x-1 ;k++){
        		if(strcmp(lic,rent[k].carLicensePlate)==0)
        		counter ++;
        	}
        	for(l=0 ; l<counter ;l++){
        		for(k=0 ; k<x-1 ;k++){
        			if(strcmp(lic,rent[k].carLicensePlate)==0){
        				for(j=k; j<x-1; j++)
						{
             				 rent[j]=rent[j+1];
             				 if(j==x-1)
             				 {
             				   free(rent[j].clientName);
             				   free(&rent[j]);
             				 }

        				}
        			}
                }
        		x--;
        	}

        	return x;
        }

    }
}
float ammountDueA(int nDays, float kmsDriven)
{
    float Cost,cost_day,cost_km;

    cost_day = 25 * nDays; /*kostos hmeras = timh * arithmo hmerwn*/
    cost_km = 0.15 * kmsDriven; /*kostso km = timh * arihmo dianithenwn km*/

    Cost = cost_day + cost_km; /*teliko kostos to athroisma twn parapanw*/
    return(Cost);
}

float ammountDueB(int nDays, float kmsDriven)
{
    float Cost1,cost_day1,cost_km1,km_average1,km1;

    km_average1 = kmsDriven / nDays ; /*mesos oros km*/
    cost_day1 = 35 * nDays; /*kostos hmeras = timh * hmeres*/

    if(km_average1 <= 100) /*periptwsh opou o mesos oros < twn 100km*/
    {
        Cost1 = cost_day1;
        return(Cost1);
    }
    else{
        km1 = (km_average1-100)*nDays;
        cost_km1 = km1 * 0.15;
        Cost1 = cost_day1 + cost_km1;
        return(Cost1);
    }
}

float ammountDueC(int nDays, float kmsDriven)
{
    float Cost2,cost_day2,cost_week,cost_km2,km_average2,km2;
    int n;
    n= nDays / 7; /*symvolizw tis meres symfwna me thn ebdomada pou anoikoun*/

    km_average2 = kmsDriven / (n+1) ;  /*mesos oros km*/
    cost_day2 = 120 * (n+1); /*kostos hmeras h ebdoamadas*/

    if(km_average2 <= 900)
    {
        Cost2 = cost_day2;
        return(Cost2);
    }
    if(km_average2 > 900 && km_average2<=1500)
    {
        cost_week = 60*(n+1);
        Cost2 = cost_day2 + cost_week;
        return(Cost2);
    }
    if(km_average2>1500)
    {
        km2 = (km_average2 - 1500)*(n+1);
        cost_km2 = km2 * 0.15;
        cost_week = 130 * (n+1);
        Cost2 = cost_day2 + cost_km2 + cost_week;
        return(Cost2);
    }
}

