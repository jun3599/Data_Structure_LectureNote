# include <stdio.h> 
# include <stdlib.h> 

# define MAX_LIST_SIZE 100 

typedef int element; 
typedef struct{
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

// 가장 먼저 오류 함수를 만든다. 
void error(char *message){
	fprintf(stderr,"%s",message);
	exit(1);
} 

// 리스트를 초기화 하기 위한 함수를 만든다. 
//사이즈를 0으로 초기화 
void init(ArrayListType *L){
	L->size = 0;
} 

// 리스트가 비어있는지 확인하는 함수를 만든다. 
// 비어있으면 1 아니면 0을 반환 
int is_empty(ArrayListType *L){
	
	return L->size == 0;  
} 

int is_full(ArrayListType *L){
	return L->size == MAX_LIST_SIZE;
}

// 일종의 peek함수를 구현 
// 위치를 입력하면 해당자리의 값을 가져온느 함수를 구현한다. 
// 만약 위치를 잘못 입력하면 위치오류를 반환한다. 
element get_entry(ArrayListType *L, int pos){
	if (pos<0||pos>=L->size){
		error("잘못된 위치입니다. ");
	}
	return L->array[pos]; 
} 

// 리스트의 내용을 출력하는 함수 구현 
void print_List(ArrayListType *L){
	int i; 
	for(i=0; i<L->size;i++){
		printf("%d->",L->array[i]);
	}
	printf("\n\n"); 
} 

// 삽입함수 구현 (마지막 위치에 추가하는경우 ) 
void insert_last(ArrayListType *L,element item){
	
	if(L->size >= MAX_LIST_SIZE){
		error("리스트 오버플로우 ");
	}
	L->array[L->size++] = item; 
}


/*
	중간에 삽입하는경우 --> 우선 나머지 원소들을 한번씩 뒤로 미루고 
	해당 위치에 해당 값을 삽입  
*/
void insert(ArrayListType *L,int pos, element item){
	if(!is_full(L) &&(pos>=0)&&(pos<=L->size)){
		int i;
		for(i=(L->size-1); i>=pos;i--){
			L->array[i+1] = L->array[i];
		} //일단 옮기고 
		L->array[pos] = item;
		L->size++; 
	}
} 

/*
	삭제 연산 구현 
	특정 위치에 있는 값을 삭제하기 위해서는 해당 위치를 기준으로 값을 한칸씩 당기면 된다.  
*/
element delete(ArrayListType *L, int pos){
	element item;
	
	if(pos <0||pos >=L->size){
		error("위치오류");
	}
	item = L->array[pos]; //해당값을 일단 받고 
	// 반복적으로 원소를 하나씩 당김 
	int i;
	for(i=pos;i<(L->size-1);i++){
		L->array[i] = L->array[i+1];
	} 
	// 하나 뺐으니 크기도 줄여야지 
	L->size--;
	return item;  
}

int main(void){
	ArrayListType list;
	
	init(&list);
	
	insert(&list,0,10);
	insert(&list,0,20);
	insert(&list,0,30);
	insert_last(&list,40);
	print_List(&list);
	
	delete(&list,0);
	print_List(&list);
	return 0;
}































 
