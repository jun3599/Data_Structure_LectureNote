#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;

void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create(){
	ListType *plist = (ListType*)malloc(sizeof(ListType));  // 지금 플리스는 빈 3개짜리 노드를 가리키는중 (할당받은 공간을 가리키는  포인터) 
	plist->size = 0; // 사이즈 0으로 초기화 
	plist->head = plist->tail = NULL; // 포인터도 널로 초기화  
	
	return plist;  // 만들어진 빈 plist를 리턴한다.  
}

// 마지막에 삽입하는 연산 --> 이거는 단순히 plist만 받으면, 마지막 원소에 바로 접근해 연결 가능 
void insert_last(ListType *plist, element data){
	// 일단 해당 데이터를 값으로 갖는 노드 하나를 만들어준다. 
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	if(temp == NULL){
		error("공간할당 에러!");
	} 
	temp->data = data;
	temp->link = NULL; 
	// 생성완료 
	
	// 이제 plist의 경우의 수에 대해서 따져보자 
	// 만약 plist의 tail이  NULL이면, 해당 리스트는 빈것이지~ 
	if(plist->tail == NULL){
		plist->head = plist->tail = temp;
	} 
	else{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
} 

void print_list(ListType *plist){
	ListNode *p;
	for(p=plist->head; p!=NULL; p= p->link){
		printf("%d --> ", p->data);
	}
	printf("NULL");
	printf("\n");
}

void alternate(ListType* plist1,ListType* plist2, ListType* plist3){
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	
	while(a&&b){
		insert_last(plist3,a->data);
		insert_last(plist3,b->data);
		
		a = a->link;
		b= b->link;
	}
	for(;a!=NULL;a=a->link){
		insert_last(plist3,a->data);
	}
	for(;b!=NULL;b=b->link){
		insert_last(plist3,b->data);
	}
}

void split(ListType* plist1,ListType* plist2, ListType *plist3){
	ListNode *p;
	int count = 0;
	for(p=plist3->head; p!=NULL; p= p->link){
		count++;
		if(count%2==1){
			insert_last(plist1,p->data);
		}
		else{
			insert_last(plist2,p->data);
		}
	}
}

int main(void){
	ListType *list1,*list2,*list3,*A,*B;
	
	list1 = create();
	list2 = create();
	list3 = create();
	A = create();
	B = create();
	
	insert_last(list1,1);
	insert_last(list1,3);
	insert_last(list1,5);
		
	insert_last(list2,2);
	insert_last(list2,4);
	insert_last(list2,6);
	
	alternate(list1,list2,list3);
	print_list(list3);
	printf("==================================\n\n");
	split(A,B,list3);
	printf("result of A \n");
	print_list(A);
	
	printf("==================================\n\n");
	printf("result of B \n");
	print_list(B);
	
	free(list1);free(list2);free(list3);free(A);free(B);	
	return 0;
}
