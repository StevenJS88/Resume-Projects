//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: Reverse Polish Notation Evaluator with Queue and Stack.
// Purpose: The header file declares the methods to be implemented
//          in the .cpp implementation file and the private variables.
//---------------------------------------------------------------------
#ifndef QUEUE_H
#define	QUEUE_H

//#define TESTING_Q
#ifdef TESTING_Q
   #include <iostream>
   using namespace std;
#endif

const int MAXQ = 80;

typedef float QInfoType;
//---------------------------------------------------------------------
// Queue class data structure for storing number type of float
//---------------------------------------------------------------------
class Queue 
{
public:
   //---------------------------------------------------------------------
   // Queue constructor
   //---------------------------------------------------------------------
   Queue();
   
   //---------------------------------------------------------------------
   // Adds an answer QueueInfoType to the queue to the rear
   //---------------------------------------------------------------------
   void enqueue(QInfoType x);
   
   //---------------------------------------------------------------------
   // Removes the first QueueInfoType answer at the front of queue
   //---------------------------------------------------------------------
   QInfoType dequeue();
   
   //---------------------------------------------------------------------
   // Checks if the queue is empty
   //---------------------------------------------------------------------
   bool isEmpty();
   
   //---------------------------------------------------------------------
   // Checks if the queue is equal to MAXQ constant
   //---------------------------------------------------------------------
   bool isFull();
   
   //---------------------------------------------------------------------
   // Clears front, rear, and count to 0
   //---------------------------------------------------------------------
   void clear();
   
   //---------------------------------------------------------------------
   // Gets size of the count
   //---------------------------------------------------------------------
   int size();
   
private:
   QInfoType elements[MAXQ];
   int front, rear, count;
};
#endif	/* QUEUE_H */

