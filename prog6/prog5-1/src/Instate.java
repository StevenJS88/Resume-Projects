/**
 This class pertains specifically to the Instate students.
 tuitionDue() will override the parent class.
 @author Ryan Reistroffer, Steven Storkson
 */
public class Instate extends Student
{
   protected final int PERCREDIT = 433;
   private int scholarship;
   
   /**
   Constructor so Student class variables can be used
   @param id
   @param name
   @param credit 
   @param sch
   */
   public Instate( String id, String name, int credit , int sch)
   {
      super( id , name , credit ); 
      scholarship = sch;
   }
   
   /**
   Compute the tuition due; subclasses must override this method
   @return tuition
   */
   public int tuitionDue()
   {
      if(scholarship >= 1)
      {
         if (this.credit >= MAXCREDIT)
            return scholarship(MAXFEE + ( PERCREDIT * MAXCREDIT ));
         else
            return scholarship(MAXFEE + ( PERCREDIT * this.credit ));
      }
      else
      {
         if (this.credit >= MAXCREDIT)
            return MAXFEE + (PERCREDIT * MAXCREDIT);
         else if ( this.credit >= FULLCREDIT)
            return MAXFEE + ( PERCREDIT * this.credit );
         else 
            return MINFEE + ( PERCREDIT * this.credit );
      }
   }
   
   /**
   returns the student information in a string.
   @return String of Student name, id, credit hours, and tuition due.
   */
   @Override
   public String toString()
   {
       String output = new String(this.name + " " + this.id );
       if (scholarship >= 1)
           output += " In-state scholarship, ";
       else
           output += " In-state, ";
       return output += this.credit + " credit hours" +"; "
       + "Tuition due = " + "$" + tuitionDue() + ".";
   }
   
   /**
   Subtracts off the scholarship from the tuition
   @param tuition
   @return tuition after scholarship
   */
   public int scholarship( int tuition)
   {
      return tuition - scholarship;
   }
}
