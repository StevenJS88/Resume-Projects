/**
This method controls the queue for aircraft. 
*/

/**
 
 @author Ryan Reistroffer, Steven Storkson
 */
public class Queue <E>
{
   private E [] elements;
   private int front, rear, count;
   
   /**
   Constructor for elements of queue
   @param size 
   */
   public Queue(int size)
   {
      elements = (E[]) new Object[size];
      front = rear = count = 0;
   }
   
   /**
   Brings in an Object and assigns it to the current array value of rear.
   Queue is circular.
   @param x 
   */
   public void enqueue( Object x)
   {
      elements[rear] = (E) x;
      rear = ( rear + 1 ) % elements.length;
      count++;
   }
   
   /**
   Returns the first object in the queue. The queue is circular.
   @return x: first object in queue
   */
   public Object dequeue( )
   {
      Object x = elements[front];
      front = ( front + 1 ) % elements.length;
      count--;
      return x;
   }
   
   /**
   Checks the queue to see if it is empty
   @return 
   */
   public boolean isEmpty()
   {
      return (count == 0);
   }
   
   /**
   Will clear the queue array.
   */
   public void clearQueue()
   {
      front = rear = count = 0;
   }
   
   /**
   Checks to see if the queue is full
   @return true if full
   */
   public boolean isFull()
   {
      return count == elements.length;
   }
   
   /**
   Returns the size of the queue array
   @return count
   */
   public int size()
   {
      return count;
   }
   
}
