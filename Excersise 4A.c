/*******************************************
Μποκαλίδης Αναστάσιος (Bokalidis Anastasios)
Αρ.Μητρ. : 2014030069
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
	
	while(ans != 'y' && ans != 'n')   /* Έλεγχος για εκγυρότητας για το αν ο χρήστης έδωσε σωστή απάντηση. */                          
	{
		printf("Error, please give one compatible answer.\n");
		scanf("\n%c", &ans);
    }
    while(ans == 'y') /* Σηνθήκη για το πότε να αρχίζει να ζητάει νούμερα απο τον χρήστη. */
    {
    	printf("Please give me the number of integers you want.\n");
	    scanf("%d", &length);
	
	while(length == 0) /* Έλεγχος εγκυρότητας για το αν ο χρήστης έδωσε 0 για αριθμό κελιών. */
	{
		printf("Please give me another number of integers.\n");
		scanf("%d", &length);
	}
	
	int *Array = (int *)malloc(length * sizeof(int)); /*Δυναμική δέσμευση μνήμης για τον πίνακα. */
	
	printf("Now give the numbers want inside the array.\n");
	
	for(i=0; i < length; i++) /* Εισαγωγή στοιχείων στην λίστα. */
	{
		scanf("%d", &Array[i]);
	}
	n = Array[0];
	
	printf("\n\nNow we will check if there are numbers in your array that their sum is equal to the first number of your array..\n");
	i=0;
	result = search_array(Array, i, length, n); /* Κάλεσμα συνάρτησης */
	printf("\nThe returning value of function: %d\n\n", result); /* Εκτυπώνει την τιμή επιστροφής της συνάρτησης */
	
	for(i=0; i < length; i++) /* Εδώ αρχίζει η ελευθέρωση των κελιών του πίνακα */
	{
		free(&Array[i]);
	}
	
	printf("To start the programm again press (y) or (n) to exit.\n"); /* Έλεγχος για τον αν ξανατρέξει το πρόγραμμα ή όχι. */
	scanf("\n%c", &ans);
    }
	
}

int search_array(int *table, int x, int l_num, int m) /*Δήλωση αναδρομιής συνάρτησης. */
{ 
   
    if(x <= l_num /2)
    {
        if(table[x] + table[l_num-1] != m)                                        /*Εάν το άθροισμα των κατοπτρηκών κελιών δεν ισούται με το πρώτο κελί*/
        {                                                                         /*και ταυτόχρονα ο δείκτης των κελιών δεν έχει φτάσει στο μέσον του*/
	    return search_array(table, x+1 , l_num-1, m); /* Κάλεσμα για αναδρομή */         /*πίνακα να πραγματοποιήται η αναδρομή*/
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


