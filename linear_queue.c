# include <stdio.h> 
# include <stdlib.h> 
# define MAX_QUEUE_SIZE 5

typedef int element; 
typedef struct{
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//에러 함수 구현 
void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
} // 사용자가 지정한 에러 메시지를 출력하고 사용 종료  

// 큐 초기화 함수 --> 큐를 사용하기 이전에 공백 상태로 만들어줌, front와 rear 모두 -1값에 있을때 공백이라고 인지한다. 
// 메인함수에서 호출된  큐 자료구조를 수정해야 하기 때문에 큐의 주소값을 인자로 받아야 한다. 
void init_queue(QueueType *q){
	q-> rear = -1;
	q->front = -1;
}  

// 큐 출력함수 
void queue_print(QueueType *q){
	int i;
	for(i=0;i<MAX_QUEUE_SIZE;i++){
		if(i<=q->front || i> q->rear){
			printf(" | ");
		}
		else{
			printf("%d | ",q->data[i]);
		}
	}
	printf("\n"); 
} 

// 큐가 가득 찼는지 확인하는 함수 구현 
// 가득 찼으면 1, 여분의 공간이 있으면 0을 반환한다. 
// 0번부터 원소가 채워지기 시작해서 --> 멕스사이즈 -1 번째 원소까지 채워진다  --> 따라서 rear가 maxsize -1 까지 도달하면 끝  
int is_full(QueueType *q){
	if(q->rear==MAX_QUEUE_SIZE-1){
		return 1;
	}
	else{
		return 0;
	}
} 

// 큐가 포화상태인지 검증하는 함수 
// 참 1 거짓 0 반환 <-- 앞뒤가 똑같으면 공백이다~  
int is_empty(QueueType *q){
	if(q->front == q->rear){
		return 1;
	}
	else{
		return 0;
	}
}

// 삽입함수 구현 
// 큐에 자리가 있으면 동작하고 자리 없으면 만석입니다~ 알려주고 끝나야 함  
// 뒤에서만 삽입이 일어나기 때문에  rear ++ 후 data[rear]에 데이터 삽입 
void enqueue(QueueType *q, int item) {
	// 큐의 현재 상태 검증
	if(is_full(q)){
		error("큐에 자리 없다 아잉교~");
		return; 
	}  
	// 그게 아니면 삽입 해야지 
	q->data[++(q->rear)] = item;
	// ++를 먼저하고 인덱싱에 들어간다  
}

// dequeue함수 구현 
//  비어있으면 에러 
// 없으면 front를 +1하고 해당원소 리턴 후 원소 삭제 
int dequeue(QueueType *q){
	if(is_empty(q)){
		error("오잉 큐에 아무것도 없는데?");
		return -1; 
		
	}
	int item = q->data[++(q->front)];
	return item;
} 

int main(void){
	int item = 0; 
	QueueType q;
	
	init_queue(&q);
	
	enqueue(&q,10); queue_print(&q);
	enqueue(&q,20); queue_print(&q);
	enqueue(&q,30); queue_print(&q);
	enqueue(&q,40); queue_print(&q);
	
	item = dequeue(&q); queue_print(&q); 
	item = dequeue(&q); queue_print(&q); 
	item = dequeue(&q); queue_print(&q); 
	item = dequeue(&q); queue_print(&q); 
	return 0; 
} 
























