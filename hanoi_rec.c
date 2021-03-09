#include <stdio.h>

void hanoi(int n, char start, char temp, char end)
{
	if (n==1)		//Base case :: start 지점에 남은 원판이 하나라면
	{
		// 남은 원판 하나를 종료 지점으로 이동시킨다. 
		printf("원판 %d를%c에서 %c로 이동 시킵니다.\n ",n,start,end);
	}
	else // 그게 아니라면 
	{
		// 남은 원판을 끝 지점을 이용하여  임시장소에 이동시킨다. 
		hanoi(n-1,start,end,temp);
		// 큰 원판을 종료지점으로 옮긴다. 
		printf("원판 %d를 %c에서 %c로 이동 시킵니다.\n",n,start,end); 
		// 임시 저장 위치에 있는 판들을 종료 지점으로 옮긴다.  
		hanoi(n-1,temp,start,end);
	 } 
}

int main(void)
{
	hanoi(4,'A','B','C');
	return 0;
}
