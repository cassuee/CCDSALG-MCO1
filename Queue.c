/******************************************************************************
 *  Description     : The file that handles the functions of the queue library
 *  Author          : Servo, Cassandra Lujille L.
 *  Section         : S07
 *  Last Modified   : 05/23/2026
 ******************************************************************************/
 
#include "Queue.h"
 
/**
 * Creates an empty queue
 * @param None
 * @return The address to the created initialized queue
 */
Queue*
CreateQueue()
 {
 	Queue* tempQueue;
 	
 	tempQueue = (Queue*) malloc(sizeof(Queue));
 	tempQueue->pHead = NULL; // 5
 	tempQueue->pTail = NULL;
 	
 	return tempQueue;
 }

/**
 * Creates a new node with the element to be added 
 * @param data The element to be added
 * @return The address to the created initialized node
 */
singlyNodeType*
createNode(int data)
{	
	singlyNodeType* tempNode;
	
	tempNode = (singlyNodeType*) malloc(sizeof(singlyNodeType));
	
	tempNode->data = data;
	tempNode->pNext = NULL;
	
	return tempNode;
}

/**
 * Inserts a node on the queue
 * @param tempQueue The pointer to the queue to modify
 * @param element The element to be added to the queue
 * @return None
 */
void
Enqueue(Queue* tempQueue, int element)
{	
	if(tempQueue->pHead == NULL)
	{
		tempQueue->pHead = createNode(element);
		tempQueue->pTail = tempQueue->pHead;
	}
	else
	{
		tempQueue->pTail->pNext = createNode(element);
		tempQueue->pTail = tempQueue->pTail->pNext;
	}
	
}

/**
 * Deletes the first node of the queue and returns the element inside
 * @param tempQueue The pointer to the queue to modify
 * @return The element if it exists and -1 if it does not 
 */
int
Dequeue(Queue* tempQueue)
{
	int element;
	
	element = -1;
	
	if(!(QueueEmpty(tempQueue)))
	{
		singlyNodeType* copyAddress;
	
		element = tempQueue->pHead->data;
		copyAddress = tempQueue->pHead;
	
		tempQueue->pHead = tempQueue->pHead->pNext;
		
		if(tempQueue->pHead == NULL)
			tempQueue->pTail = NULL;
	
		free(copyAddress);
	}
	else
	{
		printf("Queue Underflow\n");
	}
	
	return element;
}

/**
 * Determines the element in the head of the queue
 * @param tempQueue The pointer to the queue to modify
 * @return The element of the head and -1 if it does not exist
 */
int
QueueHead(Queue* tempQueue)
{
	int head;
	
	head = -1;
	
	if(!(QueueEmpty(tempQueue)))
		head = tempQueue->pHead->data;
		
	return head;
}

/**
 * Determines the element in the tail of the queue
 * @param tempQueue The pointer to the queue to modify
 * @return The element of the tail and -1 if it does not exist
 */
int
QueueTail(Queue* tempQueue)
{
	int tail;
	
	tail = -1;
	
	if(!(QueueEmpty(tempQueue)))
		tail = tempQueue->pTail->data;
		
	return tail;
}

/**
 * Determines if the queue is empty or not
 * @param tempQueue The pointer to the queue to modify
 * @return true if empty and false if not empty
 */
bool
QueueEmpty(Queue* tempQueue)
{
	return tempQueue->pHead == NULL;
}
