#include<stdio.h>
#include<stdlib.h>


struct Qnode {
	int key;
	struct Qnode * next;
};

struct Queue {
	struct Queue * front , *rear;
};

struct Qnode * newNode(int k) {
	struct Qnode * temp = (struct Qnode *)malloc(sizeof(struct Qnode));
	temp->key = k;
	temp->next = NULL;

	return temp;
}

struct Queue * createQueue() {

	struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;

	return q;
}

void enQueue(struct Queue * q,int k) {
	struct Qnode * temp = newnode(k);

	if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
	}


	q->rear->next = temp;
	q->rear = temp;

}

void deQueue(struct Queue* q)
{
   
	if (q->front == NULL)
        return;
 
   
	struct QNode* temp = q->front;
 
	q->front = q->front->next;
 
	if (q->front == NULL)
	q->rear = NULL;
 
	free(temp);
}
/*
void manageQueue(struct Queue *q) 
{
    if(front == rear && front!=-1 && rear!=-1)
    {

    }

}
*/

int main() {

	struct Qnode *q = createQueue;
	enQueue(q,10);
	enQueue(q,20);
	deQueue(q);
	deQueue(q);

	enQueue(q,30);
	enQueue(q,40);
	enQueue(q,50);

	deQueue(q);

	printf("queue front element is %d\n",q->front->key);
	printf("queue rear element is %d\n",q->rear->key);



	return 0;

}
