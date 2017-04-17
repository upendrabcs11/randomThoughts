#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <cctype>
#include <cstring>
// sort the records according to their roll no ;
using namespace std;

struct student{
	char name[50];
	int rollNo;
};
typedef struct student student;
    
void selectionSort(student *newStudent[],int n){
  
  for(int i=0;i<n-1;i++){
  	int min = i ;
  	 for(int j=i+1;j<n;j++){
  	 	if(newStudent[j]->rollNo < newStudent[min]->rollNo)
  	 		 min = j;
  	 }
  	 if(i != min){
  	 	// swap the things
  	 	student *tmpStudent = newStudent[min];
         
  	 	newStudent[min] = newStudent[i] ;

  	 	newStudent[i] = tmpStudent ;
  	 }
  }
}

int main(){
	int n ;
	cin >> n ;
	
	student  *newStudent[n] ;
	for(int i=0;i<n;i++){
		int rollNo ;
        newStudent[i] = (student *)malloc(sizeof(student));
        cin >> rollNo ;
		cin.getline(newStudent[i]->name, 50, '\n'); 
        
		newStudent[i]->rollNo = rollNo;
	}
    // call selection sort to sort the object
  selectionSort(newStudent,n); // sort the  given elements based on rollNo

  for(int i=0;i<n;i++){
		cout << newStudent[i]->rollNo << " " << newStudent[i]->name << endl ;
	}
 return 0;
}
