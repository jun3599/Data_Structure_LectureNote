#include <stdio.h>

// repeat method 
// time complexity : O(n)
int factorial_rep(int n)
{
	int i;
	int result = 1;
	
	for (i=n;i>0;i--)
	{
		result = result * i;	
	}
	return result;
}

int factorial_rec(int n)
{
	if (n ==1)
	{
		return 1;
	}
	else
	{
		return n*factorial_rec(n-1);
	}
}


int main(void)
{
	int n=3;
	int a = factorial_rep(n);
	int b = factorial_rec(n);
	printf("%d \'s fac. value is %d \n", n,a);
	printf("%d \'s fac. value is %d \n", n,b);
	
	return 0;
}
