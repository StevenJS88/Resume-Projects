/**
This class keeps track of information going on in the instance of Simulation
It will add aircraft to the queue and dequeue them into the current aircraft
they will then do take off actions or will depart, increment up time.
There are several getter methods that return values of the statistics 
for use elsewhere.
@author Steven Storkson and Ryan Reistroffer
*/
public class Simulation 
{
   private static final int MAX_AIRCRAFT = 5; //Maximum number of aircraft in the queue
   private final int TAKEOFF_TIME = 3;
   private final int DEPARTURE_TIME = 2;
   private Queue<Aircraft> q = new Queue<>(MAX_AIRCRAFT);
   private int currentTime;
   private Aircraft currentAircraft; //the aircraft currently using the runway to take off

   private int tookOff;   //number of aircraft that took off
   private int noWait;    //number of aircraft that didnt have to wait for takeoff
   private int acWaited;  //number of airraft that waited for takeoff
   private int tWaitTime; //total wait time for aircraft that took off
   
   /**
   checks if current aircraft is null and returns false, otherwise, it 
   increases the time and increments up tookoff by 1 and then returns true.
   @return 
   */
   public boolean TakeOff()
   {
      if (currentAircraft == null)
      {
         return false;
      }
      else
      {
         tookOff++;
         increaseTime(TAKEOFF_TIME);
         return true;
      }
   }
   
   /**
   If the Queue is full, it returns false, if currentAircraft is not null, it 
   will increment time up by 2 and then add a new aircraft at the current time
   in the queue.  If the current aircraft is nuyll, it will make a new
   aircraft and increment up nowait.
   @return 
   */
   public boolean Departure()
   {
      if(q.isFull())
         return false;
      else if (currentAircraft != null)
      {
         increaseTime(DEPARTURE_TIME);
         q.enqueue(new Aircraft(currentTime));
         return true;
         
      }
      else
      {
         increaseTime(DEPARTURE_TIME);
         currentAircraft = new Aircraft(currentTime);
         noWait++;
         return true;
      }
   }
   
   /**
   This method updates the queue to the appropriate value.
   if the queue is empty, the current aircraft is null.  else the current 
   aircraft is equal to the next aircraft in the queue. It then calculates the
   time for waiting and adds it and increments up acWaited by one.
   */
   public void updateQueue()
   {
      if(q.isEmpty())
         currentAircraft = null;
      else
      {
         currentAircraft = (Aircraft) q.dequeue();
         tWaitTime += currentTime - currentAircraft.getTimeStamp() 
                    - TAKEOFF_TIME;
         acWaited++;
      }
      
   }
   
   /**
   This takes an input and increases the time by whatever the parameter time
   is
   @param time 
   */
   public void increaseTime(int time)
   {
      currentTime += time;
   }
   
   /**
   returns the current time
   @return current time
   */
   public int getCurrentTime()
   {
      return currentTime;
   }
   /**
   returns the size of the queue
   @return int queue size
   */
   public int getQueueSize()
   {
      return q.size();
   }
   
   /**
   This returns the current aircrafts information of aircraft number and 
   arrival time.
   @return String aircraft number and time
   */
   public String getCurrentacInfo()
   {
      return currentAircraft.toString();
   }
   
   /**
   This returls the current aircraft info and takeoff information and the 
   size of the queue.
   @return String Aircraft info and takeoff info
   */
   public String getTakeOffInfo()
   {
      if (getQueueSize() == 0)
         return currentAircraft.toString() + " took off @time " 
             + Integer.toString(currentTime) + "."
             + " Number of aircraft waiting is " 
             + Integer.toString(getQueueSize()) + ".";
      else
         return currentAircraft.toString() + " took off @time " 
             + Integer.toString(currentTime) + "."
             + " Number of aircraft waiting is " 
             + Integer.toString(getQueueSize() - 1 ) + ".";
   }
   /**
   returns Total wait time
   @return tWaitTime
    */
   public int getWaitTime()
   {
      return tWaitTime;
   }
   
   /**
   returns the number of aircraft waited
   @return acWaited
   */
   public int getacWaited()
   {
      return acWaited;
   }
   
   /**
   returns the number of aircraft that didnt wait
   @return noWait
   */
   public int getNoWait()
   {
      return noWait;
   }
   /**
   returns the number of planes that took off
   @return tookOff
   */
   public int gettookOff()
   {
      return tookOff;
   }
   
   
   /**
   Testbed main section
   @param args 
   */
   public static void main (String args[])
   {
      Simulation sim = new Simulation();
      
      System.out.println("Current Time" + sim.getCurrentTime());
      System.out.println("Current Time" + sim.getCurrentTime());
      System.out.println("Current Time" + sim.getCurrentTime());
      System.out.println("Current Time" + sim.getCurrentTime());
      
      System.out.println("Current Time" + sim.getCurrentTime());
      sim.increaseTime(5);
      System.out.println("Current Time" + sim.getCurrentTime());
      
      System.out.println("No wait" + sim.getNoWait());
      sim.Departure();
      sim.Departure();
      sim.Departure();
      sim.Departure();
      sim.Departure();
      sim.Departure();
      sim.Departure();
      
      sim.increaseTime(5);
      sim.increaseTime(5);
      sim.increaseTime(5);
      
      sim.TakeOff();
      sim.updateQueue();
      sim.TakeOff();
      sim.updateQueue();
      sim.TakeOff();
      sim.updateQueue();
      sim.TakeOff();
      sim.updateQueue();
      sim.TakeOff();
      sim.updateQueue();
      sim.TakeOff();
      sim.updateQueue();
      sim.TakeOff();
      sim.updateQueue();
      
      sim.Departure();
      sim.Departure();
      sim.Departure();
      
      if(sim.TakeOff())
      {
         System.out.print("Takeoff" + sim.getTakeOffInfo());
         sim.updateQueue();
      }
         
      else if(!sim.TakeOff())
         System.out.println("No takeoff");
      
      
      if(sim.Departure())
         System.out.println("Departure");
      else
         System.out.println("No departure");
      
      System.out.println(sim.getCurrentTime());
      System.out.println(sim.getCurrentacInfo());
      System.out.println(sim.getNoWait());
      System.out.println(sim.getQueueSize());
      if (sim.currentAircraft != null)
         System.out.println(sim.getTakeOffInfo());
      else
         System.out.println("No planes");
      System.out.println(sim.getWaitTime());
      System.out.println(sim.getacWaited());
      System.out.println(sim.gettookOff());
      
      
   }
}
