#include<stdio.h>
#include<stdlib.h>
typedef int element;

typedef struct DListNode{
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
}DListNode;

// 이중연결 리스트를 초기화 
void init(DListNode*phead){
	phead->llink = phead;
	phead->rlink = phead; 
}

// 이중연결리스트의 노드를 출력
void print_dlist(DListNode* phead){
	DListNode *p;
	for(p=phead->rlink; p != phead;p=p->rlink){
		printf("<-| |%d| |-> ",p->data);
	}
	printf("\n");
} 

void Dinsert(DListNode *before, element data){
	// 우선 데이터를 갖는 신규 노드 하나를 만든다. 
	DListNode *newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	// 안전하게 새로운 노드 먼저 기존 노드들에 연결한다.  
	newnode->llink = before;
	newnode->rlink = before->rlink;
	// 오른쪽 부터 연결 바꿔주기 , 우리가 오른쪽 노드로 접근 할때, 노드를 직접 쓰지 않고, before을 거쳐서 타고 넘어간다 
	// 따라서 before 부터 끊어주면, after 노드에 접근할 방법이 사라진다. 
	before->rlink->llink = newnode;
	before->rlink = newnode; 
	 
}

// 노드 removed를 제거한다. 
void ddelete(DListNode* head, DListNode* removed){
	if(removed == head){
		return;
	} 
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
	
}

DListNode *search(DListNode* phead,element data){
	DListNode *p;
	for(p=phead->rlink; p != phead;p=p->rlink){
		if(p->data == data){
			return p;
		}

	}
	return NULL;
} 



int main(void){
	//우선 헤드 노드를 하나 만든다. (빈 노드) 
	DListNode *head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가단계\n");
	
	int i; 
	for(i=0;i<5;i++){
		Dinsert(head,i); // 헤드 오른쪽에  
		print_dlist(head);
	} 
	
	printf("\n\n");
	DListNode * result = search(head,3);
	printf("%d",result->data);
	
	/*printf("\n삭제단계\n");
	for(i=0;i<5;i++){
		print_dlist(head);
		ddelete(head,head->rlink); // 헤드 오른쪽에  
	}
	*/
	free(head);
	free(result);
	return 0;
}
