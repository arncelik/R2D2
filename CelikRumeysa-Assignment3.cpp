/* This Program allows a user to enter five numbers 
	and then choose between finding the smallest,largest, sum, or average.
	Written by: Rumeysa Celik
	Date: 10/14/2016
*/

#include <stdio.h>
#include <stdlib.h>
//Function Declarations
	int getOption (void);
	void getData   (int* num1, int* num2, int* num3, int* num4, int* num5);
	float calc     (int option, int num1, int num2, int num3, int num4, int num5);
	float sum      (int num1, int num2, int num3, int num4, int num5 );
	float average  (int num1, int num2, int num3, int num4, int num5 );
	float smallest  (int num1, int num2, int num3, int num4, int num5 );
	float largest  (int num1, int num2, int num3, int num4, int num5 ); 		

int main (void) 

{
//Local Declarations 
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int option;
	float result;
//Statements
	option = getOption () ;
	getData ( &num1, &num2, &num3, &num4, &num5);
	calc (option, num1, num2, num3, num4, num5 );

	return 0;	
} // main

/* ========================getOption========================

This function shows a menu and reads the user option.

*/

int getOption (void)

{

//Local Declarations 

	int option;

//Statements 
	printf("\t************************************");
	printf("\n\t*              MENU                *");
	printf("\n\t*                                  *");
	printf("\n\t*  1. SUM                          *");
  	printf("\n\t*  2. AVERAGE                      *");
  	printf("\n\t*  3. SMALLEST                     *");
  	printf("\n\t*  4. LARGEST                      *");
  	printf("\n\t*                                  *");
  	printf("\n\t************************************");
  
  	printf("\n\nPlease type your choice : ");
	scanf("%d", &option);

	return option;

} //getOption

/* ====================getData=======================
	This function reads five integers from the keyboard. 
*/

void getData (int* num1, int* num2, int* num3, int* num4, int* num5)
{
	printf("PLease enter five integer numbers: \n");
	scanf(" %d %d %d %d %d", num1, num2, num3, num4, num5 );
	return;

} //getData

/*========================calc=========================
	This function  determie the type of operation 
	and calls a function to perform it.
*/

float calc (int option, int num1, int num2, int num3, int num4, int num5)
{
//Local Declarations
	float result;
 
 //Statements
   switch (option) 
   		{
   			case 1:  result = sum (num1, num2, num3, num4, num5);
                       break;
            case 2:  result = average (num1, num2, num3, num4, num5 );
              		   break;
            case 3:  result = smallest (num1, num2, num3, num4, num5);
            			break;
            case 4: result = largest (num1, num2, num3, num4, num5);
            			break;
            default :
						{
            			 printf("\n\aError: ");
            			 printf("***Invalid option***\n");
            			 exit(0);
						}
   		}
		printf ("%.2f\n", result);
}


float sum (int num1, int num2, int num3, int num4, int num5 )
{
	return num1+ num2 + num3 + num4 + num5;
}

float average  (int num1, int num2, int num3, int num4, int num5 )
{
	float sumNumbers = sum (num1, num2, num3, num4, num5 );
	return sumNumbers / 5;
}

float smallest  (int num1, int num2, int num3, int num4, int num5 )
{
	int min;
	
	if (num1<num2) 	min=num1;
    else 			min=num2;
            			
    if (min>num3) 	min=num3;
            		
    if (min>num4) 	min=num4;
    
    if (min>num5)	min=num5;
    
    return (float)min;			
}

float largest  (int num1, int num2, int num3, int num4, int num5 )
{
	int max;
	
	if (num1>num2)  max=num1;
	else            max=num2;
	
	if (max<num3)   max=num3;
	
	if (max<num4)   max=num4;
	
	if (max<num5)   max=num5;
	
	return (float)max;
	
} 




