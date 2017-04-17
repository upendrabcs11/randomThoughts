import java.util.*;
import java.io.* ;

public class selectionSort{

  public static void selectionSort(student newStudent[],int n){

    for(int i=0;i<n-1;i++){
      	 int min = i ;
      	 for(int j=i+1;j<n;j++){
      	 	   if(newStudent[j].getRollNo() < newStudent[min].getRollNo())
      	 		     min = j;
      	    }
    	 if(i != min){
      	 	// swap the things
      	 	student tmpStudent = newStudent[min];           
      	 	newStudent[min] = newStudent[i] ;
      	 	newStudent[i] = tmpStudent ;
    	 }
    }
  }

  public static void main(String [] args){
  	Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
  	student[] newStudent = new  student[n];
  	for(int i=0;i<n;i++){
  		int rollNo = sc.nextInt();
      String name = sc.nextLine(); 

  		newStudent[i] = new student(rollNo,name);
  	}
      // call selection sort to sort the object
    selectionSort(newStudent,n); // sort the  given elements based on rollNo

    for(int i=0;i<n;i++){
  		System.out.println(newStudent[i].getRollNo() + " " + newStudent[i].getName());
  	}
  }
}

public class student{
  String name ;
  int rollNo;
  student(int rollNo,String name){
    this.name = name;
    this.rollNo = rollNo ;
  }
  public int getRollNo(){    return this.rollNo ;  }
  public String getName(){ return this.name ; }

};