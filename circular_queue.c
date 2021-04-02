# include <stdio.h> 
# include <stdlib.h> 
// 원형 큐 구현 

# define MAX_QUEUE_SIZE 5 
typedef int element; 
typedef struct{
	int front, rear; 
	element data[MAX_QUEUE_SIZE];
}QueueType;

// 큐 초기화 함수 구현 
void init_queue(QueueType *q){
	q->front = q->rear = 0;
} 

// 에러함수 구현 
void error(char *message){
	fprintf(stderr,"%s\n",message);
	exit(1);
} 

// 공백상태 검증 
// 프론트와 리어가 만나면 공백 
int is_empty(QueueType *q){
	return (q->front == q->rear);
	// 괄호 안의 내용이 비교연산임 -> 결과값은 블리언 --> 1/0 반환  
} 

//  포화상태 검증 함수 
// front 바로 뒤에 rear가 존재하면 꽉찬거지 --> 그런데 원형이니까 순환한다.  
// rear+1을 큐의 총 사이즈로 나눈 나머지가 front와 같으면 꽉참 
int is_full(QueueType *q){
	return((q->rear+1)%MAX_QUEUE_SIZE == q->front);
} 

// 원형큐 출력함수  
void queue_print(QueueType *q){
	printf("QUEUE(front = %d rear = %d) = ",q->front,q->rear);
	if(!is_empty(q)){
		//비어 있는 상태가 아닐경우 
		int i = q->front;
		do{
			i = (i+1)%MAX_QUEUE_SIZE;
			printf("%d | ",q->data[i]);
			if(i == q->rear){
				break;
			}
			
		}while(i != q->front);
	}
	printf("\n");
} 

// 삽입 연산 
void enqueue(QueueType *q, int item){
	//먼저 넣을 자리가 있는지 검증부터 
	if(is_full(q)){
		error("큐에 자리 없다 아잉교");
	} 
	q->rear = (q->rear +1)%MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
	 
} 


// 삭제 연산 
// 삭제와 동시에 해당 자리 데이터를 반환 받아야 함 --> return element 
element dequeue(QueueType *q){
	// 먼저 비어 있는지  
	if(is_empty(q)){
		error("큐가 비어있는데?");
	}
	q->front = (q->front +1)%MAX_QUEUE_SIZE;
	return q->data[q->front];
} 

// peek함수 구현 (큐의 맨 앞 원소가 무엇이냐? 만 확인, 삭제는 안함) 
element peek(QueueType *q){
	if(is_empty(q)){
		error("큐 비어 있음");
	}
	return q->data[(q->front+1)%MAX_QUEUE_SIZE]; 
} 

int get_count(QueueType *q){
	
	return ((q->rear)%MAX_QUEUE_SIZE) - ((q->front)%MAX_QUEUE_SIZE);
}

int main(void){
	QueueType q;
	int element;
	
	init_queue(&q);
	printf("데이터 삽입 단계\n");
	
	while(!is_full(&q)){
		printf("큐에 넣을 정수를 입력해주세요 : ");
		scanf("%d", &element);
		enqueue(&q, element);
		queue_print(&q); 
		printf("\n");
		printf("큐 원소의 갯수 : %d",get_count(&q));
		printf("\n");
	}
	printf("큐가 가득 차올랐습니다~ \n\n");
	
	printf("-----------데이터 삭제단계-----------\n");
	while(!is_empty(&q)){
		element = dequeue(&q);
		printf("꺼낸 정수 : %d",element);
		queue_print(&q);
		printf("\n");
		printf("큐 원소의 갯수 : %d",get_count(&q));
		printf("\n");
	}
	printf("큐 비어버림. \n");

	return 0;
}



















