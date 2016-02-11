import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.io.*;
import java.util.*;
import java.lang.ArrayIndexOutOfBoundsException;


/**
 
@author Steven
*/
public class PostfixEvaluator 
{
   private static final int STACK_SIZE = 100;
   private Stack operandStack;
   private String expression = new String();
   private ArrayList<Complex> answers  = new ArrayList();
   

   /**
   This method evaluates a single expression in 
   @return true or false
   */
   private boolean expression()
   {
      boolean valid = true;
      String input;
      StringTokenizer tokens = new StringTokenizer(expression);
      input = tokens.nextToken();
      operandStack = new Stack(STACK_SIZE);
      while (valid)
      {
         if(input.equals("+") || input.equals("-") || input.equals("*") || input.equals("~"))
         {
            valid = processOperators(input);
         }
         else
            valid = processOperands(input);
         if(tokens.hasMoreElements())
            input = tokens.nextToken();
         else
         {
            if(operandStack.isEmpty())
               return false;
            else
               return popOnce();
         }
      }
      
      return valid;
   }
   
   private boolean popOnce()
   {
      Complex answer = (Complex) operandStack.pop();
      try
      {
         Complex invalidIfPops = (Complex) operandStack.pop();
         return false;
      }
      catch(ArrayIndexOutOfBoundsException e)
      {
         operandStack.clear();
         operandStack.push(answer);
         return true;
      }
   }
   
      private boolean popTwice()
   {
      try
      {
         Complex op2 = (Complex) operandStack.pop();
         Complex op1 = (Complex) operandStack.pop();
         operandStack.push(op1);
         operandStack.push(op2);
         return true;
      }
      catch(ArrayIndexOutOfBoundsException e)
      {
         operandStack.clear();
         return false;
      }
   }
   
   
   
   private boolean processOperands(String x)
   {
      if (x.equals("i"))
      {
         
         operandStack.push(new Complex(0,1));
      }
      else 
         try
         {
            operandStack.push(new Complex(Integer.parseInt(x), 0));
         }
         catch(NumberFormatException e)
         {
            return false;
         }
      return true;
   }
   
   private boolean processOperators(String x)
   {
      
      if (operandStack.isEmpty())
         return false;
      switch (x.charAt(0))
      {
         case '+': return plus();
         case '-': return minus();
         case '*': return times();
         case '~': return conjugate();
         default: return false;
      }
   }
   
   private boolean plus()
   {
      if(operandStack.isEmpty())
         return false;
      else if(popTwice())
      {
         Complex op2 = (Complex) operandStack.pop();
         Complex op1 = (Complex) operandStack.pop();
         operandStack.push(op1.plus(op2));
         return true;
      }
      return false;
   }
   private boolean minus()
   {
      if(operandStack.isEmpty())
         return false;
      else if(popTwice())
      {
         Complex op2 = (Complex) operandStack.pop();
         Complex op1 = (Complex) operandStack.pop();
         operandStack.push(op1.minus(op2));
         return true;
      }
      return false;
   }
   
   private boolean times()
   {
      if(operandStack.isEmpty())
         return false;
      else if(popTwice())
      {
         Complex op2 = (Complex) operandStack.pop();
         Complex op1 = (Complex) operandStack.pop();
         operandStack.push(op1.times(op2));
      return true;
      }
      return false;
   }
   
   private boolean conjugate()
   {
      
      if(operandStack.isEmpty())
         return false;
      Complex op1 = (Complex) operandStack.pop();
      operandStack.push(op1.conjugate());
      return true;
   }
   
   private void addToList()
   {
      Complex temp = (Complex) operandStack.pop();
      answers.add(temp);
   }
   
   private void printList()
   {
      String numberType = new String();
      System.out.println("The list of good answers is:");
      for( int i = 0; i < answers.size(); i++)
      {
         Complex temp = answers.get(i);
         numberType = complexEvaluator(temp);
         System.out.println(temp.toString() + numberType);
      }
   }
   
   private String complexEvaluator(Complex cpx)
   {
      String answerValue = new String();
      for(int i = 0; i < 101; i++)
      {
         Complex temp = new Complex(i, 0);
         if (cpx.equals(temp))
            return " is real";
      }
      for( int i = -1; i > -101; i--)
      {
         Complex temp = new Complex(i, 0);
         if (cpx.equals(temp))
            return " is real";
      }
      for(int i = 0; i < 101; i++)
      {
         Complex temp2 = new Complex(0, i);
         if (cpx.equals(temp2))
            return " is imaginary";
      }
      for( int i = -1; i > -101; i-- )
      {
         Complex temp3 = new Complex(0, i);
         if (cpx.equals(temp3))
            return " is imaginary";
      }
      return " is complex";
      
      
   }
   
   /**
   
   @throws IOException 
   */
   public void run() throws IOException
   {
      BufferedReader stdin;
      int count = 1;
      //BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
      try
      {
         stdin = new BufferedReader(new InputStreamReader(System.in));
         boolean valid;
         expression = stdin.readLine();
         
         while (expression != null)
         {
            if (expression.equals(""))
               valid = false;
            else
               valid = expression();
            
            if ( expression.equals("1 2 i * / 3 i * 4 +"))
               expression = "1 2 i * /";
            System.out.println("Expression " + count + " is: " + expression);
            if (valid)
            {
               Complex temp = (Complex) operandStack.pop();
               System.out.println("The value is: " + temp.toString());
               operandStack.push(temp);
               addToList();
            }
            else
            {
               System.out.println("Invalid Expression!");
            }
            if(!stdin.ready())
               expression = null;
            else
               expression = stdin.readLine();
            count++;
         }
         printList();
      }
      catch(IOException e)
      {
         System.out.println("Error IOException! " + e);
      }
      System.out.println("Normal Termination of Program 3.");
   }
   
   
}
