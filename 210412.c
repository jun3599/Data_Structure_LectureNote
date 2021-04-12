# include<stdio.h> 
#include<stdlib.h>

# define MAXSIZE 10
typedef int element;

typedef struct ArrayList{
	element array[MAXSIZE];
	int size;	
}ArrayList;

void error(char *message){
	fprintf(stderr, "%d\n", message);
	exit(1);
}

void init(ArrayList *L){
	L->size = 0;
	
}
// insert , insert_first, delet, full empty print 

int is_full(ArrayList *L){
	return L->size == MAXSIZE;
}

int is_empty(ArrayList *L){
	return L->size ==0;
}

void insert_last(ArrayList *L, element item){
	L->array[L->size++] = item;
}


void insert(ArrayList *L,int pos, element item){
	
	if(!is_full(L)&&pos>=0&&pos<=L->size){
		int i;
		for(i=(L->size-1);i>=pos;i--){
			L->array[i+1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

element delet(ArrayList *L,int pos){
	element item;
	
	if(pos<0||pos>=L->size){
		error("위치오류!");
	}
	item = L->array[pos];
	int i;
	for(i=pos;i<(L->size-1);i++){
		L->array[i] = L->array[i+1];
	}
	L->size--;
	return item;
}
void print_list(ArrayList *L){
	int i;
	for(i=0;i<L->size;i++){
		printf("%d",L->array[i]);
		printf(" --> ");
		
	}
	printf("\n");
}
 
int main(void){
	ArrayList list;
	
	init(&list);
	insert(&list,0,10); print_list(&list);
	insert(&list,1,20); print_list(&list);
	insert(&list,1,10); print_list(&list);
	
	delet(&list,0); print_list(&list);
	delet(&list,1); print_list(&list);
	delet(&list,0); print_list(&list);
	return 0;
}
