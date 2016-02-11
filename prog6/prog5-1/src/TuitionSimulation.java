/**
 This class creates a student list and a current student.  It will Interact
 with the users inputs in the GUITuitionManager class form.  It creates a 
 student, calculates their tuition due, and adds them to the student list or
 removes them from the student list.  It also clears the array of the
 studentList and prints the information from the Student information strings 
 from the StudentList.
 @author Ryan Reistroffer, Steven Storkson
 */
public class TuitionSimulation
{
   private StudListNode sList;
   private Student currentStudent;
   
   /**
   Constructor for TuitionSimulation Class
   */
   public TuitionSimulation()
   {
      
      sList = new StudListNode();
      currentStudent = null;
   }
   
   /**
   Creates an instance of an instate student and gives the value to 
   currentStudent.
   @param id
   @param name
   @param credit
   @param schol 
   */
   public void inState(String id, String name, int credit, int schol)
   {
      currentStudent = new Instate(id, name, credit, schol);
   }
   
   /**
   Creates an instance of outState Student and gives the value to
   currentStudent
   @param id
   @param name
   @param credit
   @param tri 
   */
   public void outStu(String id, String name, int credit, boolean tri)
   {
      currentStudent = new Outstate(id, name, credit, tri);
   }
   
   /**
   Creates an instance of International Student and gives the value to
   currentStudent
   @param id
   @param name
   @param credit
   @param ex 
   */
   public void interStu(String id, String name, int credit, boolean ex)
   {
      currentStudent = new International(id, name, credit, ex);
   }
   
   /**
   If current Student is equal to null it returns -1.  If currentStudent isn't
   null it adds the current student to the Studentlist and takes the returned
   value from the add method in the Studentlist class and sets currentStudent
   to null and returns the add methods value.
   @return -1 for error or 0 for normal return.
   */
   public int Enroll()
   {
      if(currentStudent != null)
      {
         int temp = sList.add(currentStudent);
         currentStudent = null;
         return temp;
      }
      else
      {
         currentStudent = null;
         return -1;
      }
   }
   
   /**
   This method checks if the currentStudent has a value and if removing the
   currentStudent is successful or gives an error of -1.  It then sets
   the currentStudent to null and returns either 0 or -1.  
   @return 
   */
   public int Unenroll()
   {
      if(currentStudent != null && sList.remove(currentStudent) == 0)
      {
         currentStudent = null;
         return 0;
      }
      else
      {
         currentStudent = null;
         return -1;
      }
   }
   /**
   This method takes the current student who has been created from data of
   the selected student and the credit hours wanting to be adjusted to.
   It then updates the student's credit hours.
   */
   public void updateCredit()
   {
      int creds = currentStudent.credit;
      currentStudent = (Student) sList.search(currentStudent);
      currentStudent.updateCredit(creds);
   }
   
   /**
   This method calls the clearArray() method in the studentList class. and 
   then sets currentStudent to null.
   */
   public void clearArray()
   {
      sList.clear();
      currentStudent = null;
   }
   
   /**
   This takes the studentList string and returns the string.
   @return String from StudentList
   */
   public String PrintList()
   {
      //sList.print();
      return sList.toString();
      
   }
   
   
}
