/**
Keeps the information of an aircraft including: time stamp, sequence number,
total number of aircraft created.
*/

/**
 
 @author Ryan Reistroffer, Steven Storkson
 */
public class Aircraft 
{
   private static int numAircraft = 0;
   private int aircraftNo;
   private int timeStamp;
   
   /**
   Constructor of aircraft
   @param time 
   */
   public Aircraft( int time )
   {
      numAircraft++;
      timeStamp = time;
      aircraftNo = numAircraft;  //seems redundant
   }
   
   /**
   Returns the timestamp when the aircraft was created
   @return timeStamp
   */
   public int getTimeStamp()
   {
      return timeStamp;
   }
   
   /**
   Returns aircraft information in the format:
   Aircraft#n arrived @time t, where n is aircraftNo, and t is timeStamp.
   @return String with aircraft information
   @Override
   */
   public String toString()
   {
      return ( "Aircraft#" + aircraftNo + " arrived @time " + timeStamp);
   }
}
