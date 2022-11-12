/************************************
ANASTASIOS BOKALIDIS A.M.:2014030069
************************************/

#include <stdio.h>
#include <stdlib.h>

#define Days 20 /*synolo timwn gia hmeres tou pinaka*/
#define AverageKm 200 /*synolo timwn gia xiliometra tou pinaka*/
#define Step 20 /*kathe poso auksanontai ta km tou pinaka*/

float ammountDueA(int nDays, float kmsDriven);
float ammountDueB(int nDays, float kmsDriven);
float ammountDueC(int nDays, float kmsDriven);
void print();

int main()
{
    char option;
    int num_of_days;
    int start_km;
    int final_km;
    float driven_km;
    float amount;

    printf("Welcome To The Car Rental System.");
    printf("\n\nPlease Choose Your Category\nA or a-Basic Plan\nB or b-Daily Plan\nC or c-Weekly Plan\nQ or q-Quit Program : ");
    scanf("%c", &option);
    while(1)       /*Edw Arxizei H Switch Gia Ta Programmata Pou Theleis Na Dialekseis*/
    {
        switch(option){
    case 'A': case 'a':
        printf("\nPlease Ender The Number Of Days You'll Rent The Vehicle: ");
        do {
            scanf("%d", &num_of_days);
        }while(num_of_days <= 0);
        printf("\nPlease Ender The Km At The Start: ");
        do {
            scanf("%d", &start_km);
        }while(start_km < 0);
        printf("\nPlease Ender The Km At The End: ");
        do {
             scanf("%d", &final_km);
        }while(final_km <= 0);


        printf("Customer Summary : \n"); /*Typwnei Ta Antistoixa Apotelesmata */
        printf("\nCategory Code : %c", option);
        printf("\nRental Period (days) : %d", num_of_days);
        printf("\nOdometer Reading At Start : %d", start_km);
        printf("\nOdometer Reading At End : %d", final_km);
        driven_km = final_km - start_km;
        printf("\nNumber Of Km Driven : %.1f ", driven_km/10);
        amount = ammountDueA(num_of_days,driven_km/10);
        printf("\n\nAmount Due: %.2f", amount);
        break;

    case 'B': case 'b':
        printf("\nPlease Ender The Number Of Days You'll Rent The Vehicle: ");
        do {
            scanf("%d", &num_of_days);
        }while(num_of_days <= 0);
        printf("\nPlease Ender The Km At The Start: ");
        do {
            scanf("%d", &start_km);
        }while(start_km < 0);
        printf("\nPlease Ender The Km At The End: ");
        do {
             scanf("%d", &final_km);
        }while(final_km <= 0);

        printf("Customer Summary : \n"); /*Typwnei Ta Antistoixa Apotelesmata */
        printf("\nCategory Code : %c", option);
        printf("\nRental Period (days) : %d", num_of_days);
        printf("\nOdometer Reading At Start : %d", start_km);
        printf("\nOdometer Reading At End : %d", final_km);
        driven_km = final_km - start_km;
        printf("\nNumber Of Km Driven : %.1f ", driven_km/10);
        amount = ammountDueB(num_of_days,driven_km/10);
        printf("\n\nAmount Due: %.2f", amount);
        break;

    case 'C': case 'c':
        printf("\nPlease Ender The Number Of Days You'll Rent The Vehicle: ");
        do {
            scanf("%d", &num_of_days);
        }while(num_of_days <= 0);
        printf("\nPlease Ender The Km At The Start: ");
        do {
            scanf("%d", &start_km);
        }while(start_km < 0);
        printf("\nPlease Ender The Km At The End: ");
        do {
             scanf("%d", &final_km);
        }while(final_km <= 0);

        printf("Customer Summary : \n"); /*Typwnei Ta Antistoixa Apotelesmata */
        printf("\nCategory Code : %c", option);
        printf("\nRental Period (days) : %d", num_of_days);
        printf("\nOdometer Reading At Start : %d", start_km);
        printf("\nOdometer Reading At End : %d", final_km);
        driven_km = final_km - start_km;
        printf("\nNumber Of Km Driven : %.1f ", driven_km/10);
        amount = ammountDueC(num_of_days,driven_km/10);
        printf("\n\nAmount Due: %.2f", amount);
        break;

    case 'Q': case 'q':    /*H Periptwsh Opou To Programma Termatizei*/
        printf("\nCustomer optimal charging tableaux :\n----------------------------------\n");
        print();
        printf("\n\nProgram terminated. Bye!\n");
        system("Pause");
        return 0;
        break;

    default : /*Periptwsh Opou Kapoios Dwsei Opoiodhpote Allo Stoixeio Ektos Apo Auta Pou Symvolizoun Programmata*/
        printf("Your Option Does Not Exist.");
        break;
    }
    printf("\n\nPlease Choose Your Category\nA or a-Basic Plan\nB or b-Daily Plan\nC or c-Weekly Plan\nQ or q-Quit Program : ");
    scanf("\n%c", &option);
    switch(option);
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
/*  h synarthsh pou typwnei ton pinaka otan o xrhsths pathsei eksodo tou programmatos*/
void print(){
    int i,j;
    float d,res,res1,res2;

    printf("\t");
    i=1;
    while(Step*i<=AverageKm)
    {
       printf("%3d    ",Step*i);
       i++;
    }
    for(j=1; j<=Days; j++)
       {
        printf("\n%d\t", j);
        i=1;
        while(Step*i<=AverageKm)
        {
             d=Step*i*j;
             res = ammountDueA(j,d);
             res1 = ammountDueB(j,d);
             res2 = ammountDueC(j,d);

             if(res<res1 && res<res2){
                printf(" A     ");
             }
             if(res1<res && res1<res2){
                printf(" B     ");
             }
             if(res2<res && res2<res1){
                printf(" C     ");
             }
             i++;
        }
       }

}




