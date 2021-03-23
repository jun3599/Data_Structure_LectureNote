# include <stdio.h> 
# include <stdlib.h> 
# include <string.h>

typedef struct{
	int i;
	char string[20];
}ps;

int main(void){
	ps *p;
	p = (ps *)malloc(sizeof(ps));
	
	if (p == NULL){
		fprintf(stderr, "동적 메모리 할당에 실패했습니다. \n");
		exit(1);
	}
	strcpy(p->string,"Just testing!");
	p->i = 100;
	
	printf("%s",p->string);
	printf("%d", p->i);
	
	free(p);
	return 0;
}
