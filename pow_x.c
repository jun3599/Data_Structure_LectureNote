# include <stdio.h> 

// simply calculate by repeat method 
// the time complexity of this program is O(n) 
float x_pow_rep(int n, float x)
{
	int i;
	float result = 1.0;
	for (i=1;i<=n;i++)
	{
		result = result * x;	
	}
	
	return result;
}

// recursive method 1 
// but, this algorithm is unefficiency 
// the time complexity of this algorithm is O(n)
float x_pow_rec(int n, float x)
{
	if (n==0)
	{
		return 1.0;
	}
	else
	{
		return x*x_pow_rec(n-1,x);
	}
}

float x_pow_rec2(int n,float x)
{
	if (n==0)
	{
		return 1;
	}
	else if (n%2==0)
	{
		return x_pow_rec2(x*x,n/2);
	}
	else
	{
		return x*x_pow_rec2(x*x,(n-1)/2);
	}
}


int main(void)
{
	int n = 3;
	float x = 2.0;
	
	float a = x_pow_rep(n,x);
	float b = x_pow_rec(n,x);
	float c = x_pow_rec2(n,x);
	
	printf("%.2f pow %d is %.2f\n",x,n,a);
	printf("%.2f pow %d is %.2f\n",x,n,b);
	printf("%.2f pow %d is %.2f\n",x,n,c);	
	
	return 0;
}
