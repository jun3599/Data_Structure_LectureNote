# include <stdio.h> 
# include <stdlib.h> 

# define MAX_DEGREE 101; 
# define MAX(a,b) (((a)>(b)) ? a:b);
 
typedef struct poly_Tag{
	int degree;
	int coeff[MAX_DEGREE];
}poly;

poly poly_sum(poly poly1,poly poly2){
	poly result; 
	int poly1_degree = poly1.degree;
	int poly2_degree = poly2.degree; 
	
	int poly1_p = 0, poly2_p = 0, result_p = 0; 
	
	result.degree = MAX(poly1.degree,poly2.degree); // 일단은 결과 다항식의 최고차항은 둘중 가장 큰 지수를 가진것의 계수가 들어가야 하기 때문 
	
	// 일단 포인터는 두개중 하나라도 끝을 보이면  
		
}


int main(void)
{
	return 0;
}
