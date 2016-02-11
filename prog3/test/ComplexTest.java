/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**

 @author Steven
 */
public class ComplexTest
{
   
   public ComplexTest()
   {
   }
   
   @BeforeClass
   public static void setUpClass()
   {
   }
   
   @AfterClass
   public static void tearDownClass()
   {
   }
   
   @Before
   public void setUp()
   {
   }
   
   @After
   public void tearDown()
   {
   }

   /**
    * Test of plus method, of class Complex.
    */
   @Test
   public void testPlus()
   {
      System.out.println("plus");
      
      Complex c1 = new Complex(1, 2);
      Complex c2 = new Complex (-3,-4);
      Complex c3 = new Complex (3,4);
      
      Complex positive = new Complex( 4,6);
      Complex negative = new Complex (-2,-2);
      
      Complex result = c1.plus(c3);
      assertEquals(positive, result);
      
      result = c1.plus(c2);
      assertEquals(negative, result);
   }

   /**
    * Test of minus method, of class Complex.
    */
   @Test
   public void testMinus()
   {
      System.out.println("minus");
      
      Complex c1 = new Complex(1, 2);
      Complex c2 = new Complex (-3,-4);
      Complex c3 = new Complex (3,4);
      
      Complex positive = new Complex( 4,6);
      Complex negative = new Complex (-2,-2);
      
      Complex result = c1.minus(c3);
      assertEquals(negative, result);
      
      result = c1.minus(c2);
      assertEquals(positive, result);
   }

   /**
    * Test of times method, of class Complex.
    */
   @Test
   public void testTimes()
   {
      System.out.println("times");
      Complex cn1 = new Complex(2, 2);
      Complex cn2 = new Complex(2, 3);
      Complex expResult = new Complex(-2, 10);
      Complex result = cn1.times(cn2);
      assertEquals(expResult, result);
      result = cn2.times(cn1);
      assertEquals(expResult, result);
      
      Complex cn3 = new Complex(1,1);
      Complex cn4 = new Complex(-2, -2);
      Complex expResult2 = new Complex(0,-4);
      Complex result2 = cn3.times(cn4);
      assertEquals(expResult2, result2);
      result2 = cn4.times(cn3);
      assertEquals(expResult2, result2);
      
      Complex cn5 = new Complex(-1,-1);
      Complex cn6 = new Complex(-2,-2);
      Complex expResult3 = new Complex(0,4);
      Complex result3 = cn5.times(cn6);
      assertEquals(expResult3, result3);
      result3 = cn6.times(cn5);
      assertEquals(expResult3, result3);
   }

   /**
    * Test of conjugate method, of class Complex.
    */
   @Test
   public void testConjugate()
   {
      System.out.println("conjugate");
      
      Complex instance = new Complex(1,1);
      Complex expResult = new Complex(1,-1);
      
      Complex result = instance.conjugate();
      assertEquals(expResult, result);
   }

   /**
    * Test of equals method, of class Complex.
    */
   @Test
   public void testEquals()
   {
      System.out.println("equals");
      Complex instance = new Complex(1,1);
      Complex trueInst = new Complex(1,1);
      Complex falseInst = new Complex(1, -1);
      
            
       
      boolean expResult = true;
      boolean result = instance.equals(trueInst);
      assertEquals(expResult, result);
      
      expResult = false;
      result = instance.equals(falseInst);
      assertEquals(expResult, result);
   }

   /**
    * Test of toString method, of class Complex.
    */
   @Test
   public void testToString()
   {
      System.out.println("toString");
      Complex cn1= new Complex(1,0);
      Complex cn2 = new Complex(1,1);
      Complex cn3 = new Complex(1,-1);
      Complex cn4 = new Complex(1,-2);
      Complex cn5 = new Complex(-1,-1);
      Complex cn6 = new Complex(2,2);
      Complex cn7 = new Complex(2,-3);
      Complex cn8 = new Complex(0,1);
      Complex cn9 = new Complex(0,-1);
      Complex cn10 = new Complex(0,-2);
      Complex cn11 = new Complex(0,3);
      String expResult = "1";
      String result = cn1.toString();
      assertEquals(expResult, result);
      
      expResult = "1+i";
      result = cn2.toString();
      assertEquals(expResult, result);
      
      expResult = "1-i";
      result = cn3.toString();
      assertEquals(expResult, result);
      
      expResult = "1-2i";
      result = cn4.toString();
      assertEquals(expResult, result);
      
      expResult = "-1-i";
      result = cn5.toString();
      assertEquals(expResult, result);
      
      expResult = "2+2i";
      result = cn6.toString();
      assertEquals(expResult, result);
      
      expResult = "2-3i";
      result = cn7.toString();
      assertEquals(expResult, result);
      
      expResult = "i";
      result = cn8.toString();
      assertEquals(expResult, result);
      
      expResult = "-i";
      result = cn9.toString();
      assertEquals(expResult, result);
      
      expResult = "-2i";
      result = cn10.toString();
      assertEquals(expResult, result);
      
      expResult = "3i";
      result = cn11.toString();
      assertEquals(expResult, result);
      
   }
   
}
