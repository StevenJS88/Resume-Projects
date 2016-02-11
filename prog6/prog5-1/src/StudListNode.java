/**
 The class will maintain the list of current students. Will use CompareTo()
 from Student class. Effectively replaces StudentList class
 @author Ryan Reistroffer , Steven Storkson
 */
public class StudListNode 
{
   Node list;
   
   /**
   
   @param obj
   @return null or a student object
   */
   public Object search( Student obj )
   {
      Node p = list;
      while( p != null && obj.compareTo(p.info) == -1 )
         p = p.next;
      if ( p == null )
         return p;
      return p.info;
   }
   
   /**
   Add a student to the linked list
   @param obj
   @return 0 - successful addition, -1 - already found in list
   */
   public int add( Student obj )
   {
      if ( search(obj) == null )
      {
         if (list == null )
            list = new Node( obj , null );
         else
         {
            Node p = list;
            while ( p.next != null )
               p = p.next;
            p.next = new Node( obj , null );
         }
         return 0; //successful addition
      }
      return -1; //already found in list
   }
   
   /**
   Remove a student from the LinkedList
   @param obj
   @return 0 - successful deletion, -1 - not found in list
   */
   public int remove( Student obj )
   {
      Node fp = list, bp = null;
      if ( search(obj) != null )
      {
         while ( fp != null && obj.compareTo(fp.info) != 0)
         {
            bp = fp;
            fp = fp.next;
         }
         if ( fp != null)
         {
            if ( bp == null )
               list = list.next;
            else
               bp.next = fp.next;
         }
         return 0; //successful deletion
      }
      else
         return -1; //not found in list
   }

   /**
   Checks the linked list to see if it is empty or not
   @return true if empty
   */
   public boolean isEmpty()
   {
      return list == null;
   }
   
   /**
   Returns the length of the linked list
   @return count 
   */
   public int length()
   {
      int count = 0;
      Node p = list;
      while ( p != null )
      {
         count++;
         p = p.next;
      }
      return count;
   }
   
   /**
   Clears the linked list
   */
   public void clear()
   {
      list = null;
   }
   
   /**
   Prints an individual's student info if the student is found
   @param obj
   @return Student info if found
   */
   public String print( Student obj )
   {
      if ( search( obj ) != null )
         return search( obj ).toString();
      else
         return "Student not found!";
   }

   /**
   Display all student's information
   @return studentInfo
   */
   public String toString()
   {
      boolean stop = true;
      Node p = list;
      String studentInfo = new String();
      if ( isEmpty() )
         return null;
      else
      {
         while ( stop == true )
         {
            studentInfo += p.info.toString() + "\n";
            if ( p.next == null )
               stop = false;
            else
               p = p.next;
         }
         return studentInfo;
      }
   }
}