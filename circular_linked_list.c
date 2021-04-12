#include<stdio.h>
#include<stdlib.h>
typedef int element;

typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

//리스트의 항목 출력 
void print_list(ListNode *head){
	ListNode *p;
	
	if(head == NULL){
		return;	
	} 
	p = head->link;
	do{
		printf("%d -> ",p->data);
		p = p->link;
	}while(p != head);
	printf("%d -> ",p->data); // 마지막 노드 출력 
} 

ListNode* insert_first(ListNode* head, element data) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL){
		head = node;
		node->link = head;
	}
	else{
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data){
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL){
		head = node;
		node->link = head;
	}
	else{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;	
}

ListNode *search(ListNode *head, element data){
	
	ListNode *p;
		
	if(head == NULL){
		return NULL;	
	} 
	p = head->link;
	do{
		if(p->data == data){
			return p;
		}
		p = p->link;
	}while(p != head);
	return NULL;
} 
int get_size(ListNode *head){
	
	ListNode *p;
	int count = 1;
		
	if(head == NULL){
		return NULL;	
	} 
	p = head->link;
	do{
		count++;
		p = p->link;
	}while(p != head);
	return count;
} 


int main(void){
	ListNode *head = NULL;
	
	head = insert_last(head,10);
	head = insert_last(head,20);
	head = insert_last(head,30);
	head = insert_last(head,40);
	print_list(head);
	
	printf("\n\n");
	ListNode *result = search(head,30);
	printf("%d",result->data);
	
	printf("\n\n");
	printf("size of list is : %d",get_size(head));
	free(head);
	return 0;
}
