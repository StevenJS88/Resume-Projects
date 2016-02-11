/**
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
*/

/**
 
 @author Steven
 */
public class Stack 
{
   private int top;
   private Object [] elements;
   
   public Stack(int size)
   {
      top = 0;
      elements = new Object[size];
      
   }
   
   public void push(Object obj)
   {
      elements[top++] = obj;
   }
   public Object pop()
   {
      
      return elements[--top];
   }
   
   public void clear()
   {
      top = 0;
   }
   
   public boolean isEmpty()
   {
      if (top > 0)
         return false;
      else
         return true;
   }
   
} // end of Stack class
