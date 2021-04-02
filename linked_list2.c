# include<stdio.h> 
# include <stdlib.h> 

typedef int element; 
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

// 오류처리 함수 구현 
void error(char *message){
	fprintf(stderr, "%s\n",message);
	exit(1);
} 

// 리스트의 맨 앞에 원소를 추가하는경우 
// 반환값으로는 노드의 포인터를 받는다.  
ListNode* insert_first(ListNode *head, int value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 노드하나의 크기만큼 동적 메모리 할당 
	// 먼저 노드를 하나 만들고  
	p->data = value;
	p->link = head; //헤드포인터 복사 
	
	//헤드 노드로 넘겨준다  
	head = p; //헤드포인터 변경  
	return head; 
}

// pre라는 노드 뒤에 새로운 노드를 삽입 
ListNode* insert(ListNode *head, ListNode *pre, element value){
	// 우선 새로운 노드 p를 생성한다. 
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	//기존의 연결을 끊고 들어가기 때문에 이전의 노드가 가르키는 다음 노드의 주소값을 받아 넣는다.  
	p->link = pre->link;
	// 이전의 노드가 가르키는 주소를 현재 생성한 노드로 바꾸어준다. 
	pre->link = p;
	return head; //변경된 전체 리스트의 첫 주소값을 반환  
	
} 

//첫번째 노드를 삭제하는것 
// 첫번째 노드는 head 
// 해당 값은 버리고, 해당 노드가 가지던 주소값만을 담아-> 해당 주소에 있는 노드를 헤드 노드로 바꿔줌 
ListNode* delete_first(ListNode *head){
	ListNode *removed;
	if (head==NULL) return NULL;
	removed = head; // 지워질 노드를 잠시 담아둡니다. 
	
	head = removed->link; //헤드노드를 기존의 노드가 가르키던 노드로 변경합니다. 
	
	free(removed); //기존의 헤드 노드가 차지하던 공간을 도비는 자유에요 해준다. 
	return head; //변경된 헤드노드를 보내줍니다.  
} 

// 중간에 위치한 노드를 삭제해줍니다. 
// 정확히는 pre 노드 다음에 위치한 노드를 제거합니다. 
ListNode* delete(ListNode *head, ListNode *pre){
	// 지워질 노드를 담아둘 노드 변수 하나를 잡아둡니다. 
	ListNode *removed;
	// pre노드가 가르키는 주소를 담습니다. 
	removed = pre->link;
	// pre노드가 가질 주소값을, 삭제된 이전의 노드가 가르키는 노드로 변경해줍니다. 
	pre->link = removed->link;
	
	// 동적메모리 할당을 종료합니다. 
	free(removed);
	return head; 
} 

void print_list(ListNode *head){
	ListNode *p;
	for(p = head; p!=NULL; p=p->link){
		printf("%d -> ",p->data);
	}
	printf("NULL \n");
}
int create_node(){
	int number_of_node;
	int data;
	ListNode *newnode;
	
	printf("노드의 개수: ");
	scanf("%d",&number_of_node);
	printf("\n");
	int i;
	for(i=0;i<number_of_node;i++){
		printf("노드 #%d 데이터 : ");
		scanf("%d",&data);
		ListNode *p = (ListNode *)malloc(sizeof(ListNode));
		p->data = data;
		 
	}
	return number_of_node; 
}

int main(void){
	ListNode *head = NULL; //헤드노드 생성 및 초기화 
	
	// 원소 삽입  
	int i; 
	for(i=0;i<5;i++){
		head = insert_first(head,i);
		print_list(head);
	} 
	//원소 삭제 
	for(i=0;i<5;i++){
		head = delete_first(head);
		print_list(head);
	} 
	return 0;
}
