#include <stdio.h> 
#include <stdlib.h> 

typedef struct ListNode{
	int data; 
	int link;
}ListNode; //노드 타입 정의 

typedef struct header{
	int size;
	ListNode *head;
	ListNode *tail;
}header;  //리스트 헤더 노드 타입 

//오류 함수 
void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

// 리스트 헤더 생성 함수 
header* create(){
	header *plist = (header *)malloc(sizeof(header));
	plist->size = 0; //사이즈 초기화 
	plist->head = NULL;
	plist->tail = NULL;
	return plist; 
}  

void insert_last(header *plist, int value){
	
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	if(temp==NULL){
		error("메모리 할당 에러");
	}
	temp->data = value;
	temp->link = NULL; 
	// 헤더리스트에 아무런 값도 없다면 -> 다항식이 생성 이전 --> 맨 앞이자 맨 뒤를 temp와 연결해주면 된다.  
	if(plist->tail==NULL){
		plist->head = plist->tail = temp; 
	}
	else{
		// 플리스트의 테일에 연결되어 있는건 기존의 리스트겠죠.. 근데 그 값의 링크에는 현재 NULL이 들어가 있으니, 그 널을 우리가 만든 템프로 바꾸어주면 된다 그죠~ ? 
		plist->tail->link = temp;
		//그리고 나서 플리스트의 정보를 갱신해야 하니까, --> tail이 가리키는걸 temp로 바꾸면 되것쥬~ 
		plist->tail = temp; 
	}
	// 추가 다 하면 사이즈 늘려 줘야지~ 
	plist->size++; 
}

void alternate(header* plist1,header* plist2, header* plist3){
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	
	while(a&&b){
		insert_last(plist3,a->data);
		inset_last(plist3,b->data);
		
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

void print_list(ListNode *head){
	ListNode *p;
	for(p = head; p!=NULL; p=p->link){
		printf("%d -> ",p->data);
	}
	printf("NULL \n");
}

int main(void){
	header *list1,*list2,*list3;
	
	list1 = create();
	list2 = create();
	list3 = create();
	
	// 리스트1 생성 
	insert_last(list1,1); 
	insert_last(list1,3);
	insert_last(list1,5);
	
	//리스트2 생성
	insert_last(list2,2);
	insert_last(list2,4);
	insert_last(list2,6);
	
	//print_list(list1);
	//print_list(list2);
	 
	return 0;
}
