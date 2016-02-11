/**
 This abstract class houses the CompareTo() method and other methods that 
 are to be overridden by the subclasses.
 @author Ryan Reistroffer, Steven Storkson
 */
public abstract class Student implements Comparable
{
   protected final int MAXCREDIT = 15;
   protected final int FULLCREDIT = 12;
   protected final int MINFEE = 846;
   protected final int MAXFEE = 1441;
   protected String id;
   protected String name;
   protected int credit;
   
   /**
   Constructor of Student class
   @param id
   @param name
   @param credit 
   */
   public Student( String id, String name, int credit )
   {
      this.id = id;
      this.name = name;
      this.credit = credit;
   }
   
   /**
   Compute the tuition due; subclasses must override this method
   @return 
   */
   public int tuitionDue()
   {
      return 0; 
   }
   
   /**
   Compare two student objects to see if they have the same name and id
   @param obj
   @return (0 if equal) (-1 if not equal)
   */
   public int compareTo( Object obj)
   {
      if ( obj instanceof Student )
      {
         Student x = (Student) obj;
         if ( id.equals(x.id) && name.equals(x.name) )
            return 0;
      }
      return -1;
   }
   /**
   This method takes a student and updates their credits to the parameter's
   value.
   @param credits 
   */
   public void updateCredit(int credits)
   {
      this.credit = credits;
      
   }
   
   /**
   returns a string of the student information, subclasses must implement this method
   */
   public abstract String toString();
   
}
