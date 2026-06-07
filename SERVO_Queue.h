/**********************************************************************************
 *  Description     : The file that handles the function headers, and the struct of
 					  the queue library
 *  Author          : Servo, Cassandra Lujille L.
 *  Section         : S07
 *  Last Modified   : 05/23/2026
 *********************************************************************************/

#ifndef SERVO_Queue_h
#define SERVO_Queue_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Represents the node
 */
struct singlyNodeTag 
{
	int data; // Contains the element
	struct singlyNodeTag* pNext; // Points to the next element in the list
};

typedef struct singlyNodeTag singlyNodeType;

/**
 * Represents the queue
 */
typedef struct 
{
	singlyNodeType* pHead; // pList
	singlyNodeType* pTail; // pLast->pNext (pNew)
	
} Queue;

/* ----- function prototypes ----- */

Queue* CreateQueue();
singlyNodeType* createNode(int data);
void Enqueue(Queue* tempQueue, int element);
int Dequeue(Queue* tempQueue);
int QueueHead(Queue* tempQueue);
int QueueTail(Queue* tempQueue);
bool QueueEmpty(Queue* tempQueue);

#endif
