
// C Program for Calculating factorial of any Big Number.
// Developer : Aniket Hase

#include<stdio.h> 
#define MAX 1000

int calculation(int i, int result[], int result_size); // Function declaraction..

// factorial() function finds factorial of large numbers and prints them..
 
void factorial(int num) 
{ 
	int result[MAX], i; 

	result[0] = 1; 		// Initialize result 
	int result_size = 1; 

	for (i=2; i<=num; i++) 
		result_size = calculation(i, result, result_size); 

	printf("\n Factorial of given number is : "); 
	for (i=result_size-1; i>=0; i--) 
		printf("%d", result[i]); 
} 

// calculation() function calculate each element using carry.
// It simply returns size of the result..

int calculation(int x, int result[], int result_size) 
{ 
	int carry = 0, i; // Initialize carry... 

	// One by one multiply n with individual digits of result[] 
	for (i=0; i<result_size; i++) 
	{ 
		int prod = result[i] * x + carry; 

		// Store last digit of 'prod' in result[] 
		result[i] = prod % 10; 

		// Put rest in carry
		carry = prod/10;	 
	} 

	// Put carry in result and increase result size 
	while (carry) 
	{ 
		result[result_size] = carry%10; 
		carry = carry/10; 
		result_size++; 
	} 
	return result_size; 
} 

// Driver program 

int main() 
{ 
	int num;
	char choice;
	do
	{
		printf("\n\n Enter any Number which you want to Calculate Factorial : ");
		scanf("%d", &num);
		
		if(num < 0) {
			printf("\n Factorial of negative number can't be Calculated.");
		}
		else {
			factorial(num);
		}
			
		printf("\n\n Do you want to enter again(y or n)? : ");
		scanf("%s", &choice);

	}while(choice == 'y' || choice == 'Y'); 
	 
	printf("\n\n Thank You.");
	return 0; 
} 

