#include <stdio.h>
#define LABOR_COST 0.35
#define TAX_RATE 0.085
//Function Declarations
void readData (int* l, int* w, int*d , float* sqrFoot);
void calc (int l, int w, int discount, float sqrFoot, float* price, float* subtotal, float* totalPrice );
int calcPrice (int l, int w, float sqrFoot);
int calcSubtotal (float* price, int discount);
int calcTotalPrice (float* subtotal);
void printResult (int l, int w, int discount, float sqrFoot, float price, float subtotal, float totalPrice);
void printMsr (int l, int w);
void printChrg (int discount, float sqrFoot, float price, float subtotal, float totalPrice );
int area;
int carpetChrg;
int laborChrg;
int discChrg;

int main (void)
{

	//Local declarations
	int l, w;
	int discount;
	float sqrFoot;
	float price, subtotal, totalPrice ;
	
	//Statements
	readData (&l, &w, &discount, &sqrFoot);

	calc (l, w, discount, sqrFoot, &price, &subtotal, &totalPrice);

	printResult (l, w, discount, sqrFoot, price, subtotal, totalPrice) ;

	return 0;
} // main

/* ==========readData=========
This function reads three integers from the keyboard.
	Parameters l,w and d
*/
void readData (int* l, int* w, int*d , float* sqrFoot) 
{
	printf("Length of the room (feet)?");
	scanf("%d", l);

	printf("Widht of room (feet)?");
	scanf("%d",w);

	printf("Customer discount (percent)?");
	scanf("%d",d);

	printf("Cost per square foot?");
	scanf("%f", sqrFoot);
 
 	return;
} // readData


 /* =========calc==========
 This function calls  three subfunctions. 
Each function is to use addresses to store their results.
	Parameters : price, subtotal, totalPrice
*/

void calc (int l, int w, int discount, float sqrFoot, 
float* price, float* subtotal, float* totalPrice ) 

{
	//Statements
	*price = calcPrice (l, w, sqrFoot);
	*subtotal = calcSubtotal (price, discount);
	*totalPrice = calcTotalPrice (subtotal);
}


int calcPrice (int l, int w, float sqrFoot) 
{
	area       = l*w;
	carpetChrg = area * sqrFoot;
	laborChrg  = area * LABOR_COST;
	return carpetChrg + laborChrg; 
}


int calcSubtotal (float* price, int discount)
{
	discChrg = (*price) * (discount/100);
	return (*price) - discChrg;
}


int calcTotalPrice (float* subtotal)
{
	return (*subtotal) + (*subtotal) * TAX_RATE ;
}


/*==========printResult=========
This function uses two subfunctions to print the results:
One to print measurement, and one to print the charges.
*/
void printResult (int l, int w, int discount, float sqrFoot, float price, float subtotal, float totalPrice)
{
	printMsr (l, w);
	printChrg (discount, sqrFoot, price, subtotal, totalPrice);
}

void printMsr (int l, int w)
{
	printf("\t\t\t\tMEASUREMENT\n");
	printf("LENGTH\t\t\t\t\t\t\t %d ft\n", l);
	printf("WIDTH\t\t\t\t\t\t\t %d ft\n", w);
	printf("AREA\t\t\t\t\t\t\t %d square ft\n", area);	
} 

void printChrg (int discount, float sqrFoot, float  price, float  subtotal, float  totalPrice )
{
	printf("\n\t\t\t\tCHARGES\n");
	printf("DESCRIPTION\t\t\tCOST/SQ.FT.\t\t\tCHARGE\n");
	printf("CARPET\t\t\t\t%.2f\t\t\t\t$%d\n", sqrFoot, carpetChrg);
	printf("Labor\t\t\t\t%.2f\t\t\t\t %d\n\n", LABOR_COST, laborChrg);
	printf("INSTALLED PRICE\t\t\t\t\t\t\t$%.2f\n", price);
	printf("Discount\t\t\t\t\t\t\t%2d\t\t\n\n", discount);
	printf("SUBTOTAL\t\t\t\t\t\t\t$%.2f\n", subtotal);
	printf("Tax\t\t\t\t\t\t\t\t%.2f\n", TAX_RATE);
	printf("TOTAL\t\t\t\t\t\t\t\t$%.2f\n", totalPrice);
} 


