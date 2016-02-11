/**
 This class pertains specifically to the International students.
 tuitionDue() will override the parent class.
 @author Ryan Reistroffer, Steven Storkson
 */
public class International extends Student
{
   protected final int PERCREDIT = 945;
   protected final int INTERNATIONALFEE = 350;
   private boolean exchange;
   
   /**
   Constructor so Student class variables can be used
   @param id
   @param name
   @param credit 
   @param ex
   */
   public International( String id, String name, int credit, boolean ex)
   {
      super( id , name , credit ); 
      exchange = ex;
   }
   
   /**
   Compute the tuition due; subclasses must override this method
   @return 
   */
   public int tuitionDue()
   {
      
      if(exchange && this.credit >= FULLCREDIT)
         return INTERNATIONALFEE + MAXFEE;
      else if ( exchange && this.credit < FULLCREDIT)
         return INTERNATIONALFEE + MINFEE;
      else
      {
         if( this.credit >= MAXCREDIT)
            return INTERNATIONALFEE + MAXFEE + ( PERCREDIT * MAXCREDIT );
         else if ( this.credit >= FULLCREDIT)
            return INTERNATIONALFEE + MAXFEE + ( PERCREDIT * this.credit );
         else
            return INTERNATIONALFEE + MINFEE + ( PERCREDIT * this.credit );

      }
   }
   
   /**
   returns the student information in a string through a series of if
   statements that determine what to output determined by credit hours and 
   exchange student status.
   @return String of Student name, id, credit hours, and tuition due.
   */
   @Override
   public String toString()
   {
       String output = new String(this.name + " " + this.id );
       if (exchange)
           output += " International exchange, ";
       else
           output += " International, ";
       return output += this.credit + " credit hours, " + "Tuition due = "
       + tuitionDue() + ".";
   }
}
