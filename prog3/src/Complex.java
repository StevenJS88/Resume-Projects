/**
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
*/

/**
 
 @author Steven
 */
public class Complex 
{
   private int real;
   private int imag;
   
   /**
   This constructor creates the default complex number a+bi where a=b=0
   */
   public Complex()
   {
      real = 0;
      imag = 0;
   }
   
   /**
   This constructor creates the complex number a+bi where b=0
   @param a 
   */
   public Complex(int a)
   {
      real = a;
      imag = 0;
   }
   
   /**
   This constructor creates a complex number a+bi where real is equal to a
   and imag is equal to b. 
   @param a
   @param b 
   */
   public Complex(int a, int b)
   {
      real = a;
      imag = b;
   }
   
   /**
   This method returns a new Complex that represents the sumof this an cp.
   @param cp
   @return 
   */
   public Complex plus(Complex cp)
   {
      
      return new Complex(real + cp.real, imag + cp.imag); // revise
   }
   
   /**
   This method returns a new Complex that represents difference between this
   and cp.  Its implementation is similar to plus()
   @param cp
   @return 
   */
   public Complex minus(Complex cp)
   {
      return new Complex(real - cp.real, imag - cp.imag);
   }
   
   /**
   This method returns a new Complex that represents the product of this and 
   cp.  If this represents a+bi and rhs represents c+di, then the return value
   should represents (ac-bd)+(ad+bc)i.
   @param cp
   @return 
   */
   public Complex times(Complex cp)
   {
      Complex newComplex = new Complex((real * cp.real) + ((imag * cp.imag) 
                           * -1), ((real * cp.imag) + (imag * cp.real)));
      return newComplex;
      
   }
   
   /**
   This method should return a new Complex that represents the conjugate of
   this.  This conjugate of a complex number a+bi is defined as the complex
   number a-bi
   @return 
   */
   public Complex conjugate()
   {
      return new Complex(real, -imag); // revise
   }
   
   /**
   This method returns true if given Object represents the same Complex as 
   this.  Two Complex objects have the same value if they have the same real 
   and imaginary parts.
   @param obj
   @return 
   */
   public boolean equals(Object obj)
   {
      if (obj instanceof Complex)
      {
         Complex cp = (Complex) obj;
         
         return (real == cp.real && imag == cp.imag);
      }
      return false;
   }
   
   /**
   
   This method returns a String representation of this.  The return value
   should not contain any redundant symbols.  For example, if z=5+0i, then 
   you should return 5. If z=7+-3i, then you should return 7-3i.  If z=0+0i,
   then you should output 0.  IF z=0+1i, then you should output i.  If z=0+-1i
   then you should output -i.  Always be sure to match the output exactly!
   @return 
   */
   public String toString()
   {
      if (real != 0)
      {
         if (imag == 0)
            return Integer.toString(real);
         else if (imag == 1)
            return Integer.toString(real) + "+" + "i";
         else if(imag < 0)
         {
            if (imag == -1)
               return Integer.toString(real) + "-i";
            return Integer.toString(real) + Integer.toString(imag) + "i";
         }
         else
            return Integer.toString(real) + "+" + Integer.toString(imag) 
                   + "i";
      }
      else
      {
         if (imag == 0)
            return "0";
         else if (imag == 1)
            return "i";
         else if (imag == -1)
               return "-i";
         else
            return Integer.toString(imag) + "i";
      }
   }
} // end of Complex Class
