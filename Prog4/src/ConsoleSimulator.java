import java.util.StringTokenizer;
import java.io.*;
import java.util.*;
/**
This class creates a simulation that takes in input and calls methods in the 
Simulation class to make planes depart, takeoff, increment up time, and 
to quite the program.
@author Steven Storkson and Ryan Reistroffer
*/
public class ConsoleSimulator 
{
   private Simulation newSim = new Simulation();
   
   /**
   Takes in input from the bufferedReader and tokenizes the string that is 
   generated with each readline() method call.  It then processes the input
   with a switch method, which calls a 
   */
   public void run()
   {
      try
      {
         BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
         String input  = new String(stdin.readLine());
         boolean moreToRead = true;
         while (moreToRead)
         {
            StringTokenizer token = new StringTokenizer(input, " ");
            input = token.nextToken();
            switch(input)
            {
               case "D": depart();
                  break;
               case "T": takeoff();
                  break;
               case "U": incrementTime(Integer.parseInt(token.nextToken()));
                  break;
               case "P": System.out.println("");
                         print();
                  break;
               case "Q": quitProg();
                         moreToRead = false;
                  break;
               default: error(input);
                  break;
            }
            if(stdin.ready())
               input = stdin.readLine();
            else
               moreToRead = false;
         } 
      }
      catch(IOException e)
      {
         System.out.println("IOException: " + e);
      }
   }
   
   /**
   tries to depart, if true, it returns a string of aircraft information
   if false, it tells the plane has to wait at the gate at the current time.
   */
   private void depart()
   {
      if(newSim.Departure())
         System.out.println("An aircraft entered the runway @time " 
                           + newSim.getCurrentTime() + "." 
                           + " Number waiting in queue is " 
                           + newSim.getQueueSize());
      else
         System.out.println("Aircraft had to wait at the gate because the "
                           + "line was full at time " 
                           + newSim.getCurrentTime() + ".");
   }
   
   /**
   checks to see if it can take off, if there is no currentaircraft, it
   prints out no aircraft taking off at the current time, otherwise,
   it will print the takeoff information and update the queue.
   */
   private void takeoff()
   {
      
      if(newSim.TakeOff())
      {
         System.out.println(newSim.getTakeOffInfo());
         newSim.updateQueue();
      }
      else
         System.out.println("No aircraft is taking off @time " 
                            + newSim.getCurrentTime() + ".");
   }
   
   /**
   This checks to make sure the input is greater than or equal to zero.
   It then increments the time and prints out the current time.
   else it says it didnt print it out.
   @param int time
   */
   private void incrementTime(int time)
   {
      if(time > 0)
      {
         newSim.increaseTime(time);
         if (time == 1)
            System.out.println("Time updated by " + time + " time unit; "
                               + "current time is " + newSim.getCurrentTime() 
                               + ".");
         else
            System.out.println("Time updated by " + time + " time units; "
                               + "current time is " + newSim.getCurrentTime() 
                               + ".");
      }
      else
         System.out.println("Time NOT updated with " + time + ".");
   }
   
   /**
   This calculates the value of the average wait time, it then 
   prints out the statistics held in the simulation class
   */
   private void print()
   {
      double aveWT = 0.0d;
      if (newSim.getacWaited() != 0)
         aveWT =  newSim.getWaitTime() / (double) newSim.getacWaited();
      System.out.println("The average wait time for aircraft that finished "
                         +"waiting is " + aveWT + ".");
      System.out.println("The total wait time is " + newSim.getWaitTime() 
                         + ".");
      System.out.println("The number of aircraft that took off is " 
                         + newSim.gettookOff() + ".");
      System.out.println("The number of aircraft did not have to wait is " 
                         + newSim.getNoWait() + ".");
      System.out.println("");
   }
   
   /**
   When called, prints out error message of the character sent
   @param str
   */
   private void error(String str)
   {
      System.out.println( str + " is invalid!");
   }
   
   /**
   Prints out the stats and then Quits the program
   */
   private void quitProg()
   {
      System.out.println("Simulation statistics:");
      print();
      System.out.println("Simulation terminated.");
   }
  
} // end ConsoleSimulator
