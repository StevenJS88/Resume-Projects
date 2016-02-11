/**
This class creates a node that has an object and the reference of the next
node. This can be used to make a list.
@author Ryan Reistroffer, Steven Storkson
*/
public class Node 
{
   public Object info;
   public Node next;
   
   /**
   This is the constructor for a node. it takes information for the object 
   and creates the next reference for the next node.
   @param info
   @param next 
   */
   public Node( Object info, Node next)
   {
      this.info = info;
      this.next = next;
   }
}
