//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: Reverse Polish Notation Evaluator with Queue and Stack.
// Purpose: The implementation of the Queue class methods.  It has a 
//          default constructor for initialization and methods for adding
//          and removing from the queue.  It also is able to check if the 
//          queue is full or empty and can return the current size of the 
//          queue.
//---------------------------------------------------------------------
#include "Queue.h"

Queue::Queue() 
{
   front = rear =  count = 0;
}

void Queue::enqueue(QInfoType x) 
{
   elements[rear] = x;
   rear = (rear + 1) % MAXQ;
   count++;
}

QInfoType Queue::dequeue() 
{
   QInfoType x = elements[front];
   front = (front + 1) % MAXQ;
   count--;
   return x;
}

bool Queue::isEmpty() 
{
   if(front == rear) 
      return true;
   else
      return false;
}

bool Queue::isFull() 
{
   if (front == (rear + 1) % MAXQ)
      return true;
   else
      return false;
}


void Queue::clear() 
{
   front = rear = count = 0;
}

int Queue::size() 
{
   return count;
}

#ifdef TESTING_Q

// ------------------------------
// Testbed main
// ------------------------------
int main()
{
   Queue q;
   q.enqueue(12.1);
   cout << q.dequeue() << endl;
   q.enqueue(13.5);
   q.enqueue(5.9);
   if (q.isEmpty()) 
      cout << "Queue is empty" << endl;
   else
      cout << "Queue is Not Empty." << endl;
   
   if (q.isFull()) 
      cout << "Queue is full" << endl;
   else
      cout << "Queue is Not full." << endl;
   cout << q.size() << " Is how many elements I have in my Queue." << endl;
   cout << q.dequeue() << " I should have one more element in the queue. "<< endl;
   q.clear();
   cout << "I just cleared the queue." << endl;
   
   
   // .... etc, to test all the methods.
   return 0;
}

#endif
