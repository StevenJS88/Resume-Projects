/**
Runs the main method for Program 4. 
@author  Ryan Reistroffer, Steven Storkson
*/
public class Prog4
{
   /**
   Runs an instance of ConsoleSimulator
   @param args is unused
   */
   public static void main (String args[])
   {
      try
      {
         new ConsoleSimulator().run();
         //new GUISimulator().setVisible(true);
      }
      catch (Exception e)
      {
         System.out.println("Program Error!!!: " + e );
      }      
   }
}
