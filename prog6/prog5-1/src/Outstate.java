/**
 This class pertains specifically to the Outstate students.
 tuitionDue() will override the parent class.
 @author Ryan Reistroffer, Steven Storkson
 */
public class Outstate extends Student
{
   protected final int PERCREDIT = 756;
   protected final int TRISTATE = 200;
   private boolean triStateStu; 
   
   /**
   Constructor so Student class variables can be used
   @param id
   @param name
   @param credit 
   @param tri
   */
   public Outstate( String id, String name, int credit, boolean tri)
   {
      super( id , name , credit ); 
      triStateStu = tri;
   }
   
   /**
   Compute the tuition due; subclasses must override this method
   @return tuition
   */
   public int tuitionDue()
   {
      if (triStateStu)
      {
         if( this.credit >= MAXCREDIT)
            return tristate( MAXFEE + ( PERCREDIT * MAXCREDIT ));
         else if ( this.credit >= FULLCREDIT)
            return tristate( MAXFEE + ( PERCREDIT * this.credit ));
         else 
            return tristate(MINFEE + ( PERCREDIT * this.credit ));
      }
      else
      {
         if(this.credit >= MAXCREDIT)
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
       if (triStateStu)
       {
           output += " Out-Of-State Tristate, ";
       }
       else
       {
           output += " Out-Of-State, ";
       }
       return output += this.credit + " credit hours, " + "Tuition due = $"
       + tuitionDue() + ".";
   }
   
   /**
   Calculates the final tuition after removing the TriState initiative 
   amount
   @param tuition
   @return tuition after TriState Initiative
   */
   public int tristate( int tuition )
   {
      if (this.credit >= MAXCREDIT)
         return tuition - (MAXCREDIT * TRISTATE);
      else
         return tuition - ( this.credit * TRISTATE );
   }
}
