/*  This program will print student's scores and 
    calculates and print the statistics for each quiz.
    Written by: Rumeysa Celik
	Date      : 10/13/2016
*/

#include <stdio.h>
#define Students 40
#define Quizes 5
#define INF 101

int ID [Students];
int Quiz [Students][Quizes];
int numStudents;

int HighScore [Quizes];
int LowScore [Quizes];
double Avrg [Quizes];
	

//Function Declarations
void Report (void);
void Average (void);
void FindHighScore (void);
void FindLowScore(void);


int main (void) 
{ 
	// Local Declarations
	FILE *fptr;
	fptr = fopen ("StudentScores.data.txt", "r");

	numStudents = 0;
	while (fscanf(fptr, "%d", &ID[numStudents]) != EOF) {
		for (int i=0; i < 5; i++)
			fscanf(fptr, "%d",&Quiz[numStudents][i]);
		numStudents++;
	}

	Report ();

	return 0;

 } //main


/*=====================Average=======================
   This function calculates the column averages for a Quiz
   	Pre Quiz with values
   	Post averages calculated and in aaverage array
*/
void Average ()
{
	for (int i=0; i<Quizes; i++) {
		double sum=0;
		for (int j=0; j < numStudents; j++)
			sum += Quiz[j][i];
   		Avrg[i] = sum/numStudents;
   	}
    return; 
}

void FindLowScore()
{
	for (int i=0; i<Quizes; i++) {
		int min=INF;
		for (int j=0; j < numStudents; j++) {
			if (Quiz[j][i] < min)
				min = Quiz[j][i];
		}
		LowScore[i] = min;
	}			
	return;	    
}

void FindHighScore ()
{
	for (int i=0; i<Quizes; i++) {
		int max=0;
		for (int j=0; j < numStudents; j++) {
			if (Quiz[j][i] > max)
				max = Quiz[j][i];
		}
		HighScore[i] = max;
	}			
	return;				
}
	
void Report ()
{	
	printf("ID\t\t Q1\tQ2\tQ3\tQ4\tQ5\n");	
	for(int r=0; r<numStudents; r++)
	{
    	printf("%d\t\t",ID[r]);
     	for(int i=0; i<Quizes; i++)
     		printf("%d\t",Quiz[r][i]);
     	printf("\n");
	}

	FindHighScore();
	printf("High score\t");	
	for(int i=0; i<Quizes; i++)
		printf("%d\t",HighScore[i]);
  	printf("\n");

  	FindLowScore();
	printf("Low score\t");
	for(int i=0; i<Quizes; i++)
  		printf("%d\t",LowScore[i]);
  	printf("\n");
	
	Average();
	printf("Average\t");
	for(int i=0; i<Quizes; i++)
  		printf("\t%2.1f",Avrg[i]);
  	printf("\n");
}
	
