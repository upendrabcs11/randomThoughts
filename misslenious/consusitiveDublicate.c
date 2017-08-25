// code in C but only algo as mention in question 
#include<stdio.h>
#include<stdlib.h>
int main(){
 int n;
scanf("%d",&n);
while(--n >= 0){
   char str[1000];
  scanf("%[^\n]%*c", str);
  int n = strlen(str);
  char *resstr = RemoveConsusitiveDublicate(str,0);
   printf("%s",resstr);
 }
}
char *RemoveConsusitiveDublicate(char *str,n){
 if(n >= strlen(str)-1) // if only one char is there then return 
      return substring(str,n) // return substring from nth index to end of string

 char *newStr = RemoveConsusitiveDublicate(char *str,n+1);
  // consusitive char is same so ignore  str[n] and return newstr  
 if(str[n] == newStr[0]) 
   return newStr;
 
// if no consusitive then concate str[n] and newStr
return concate(str[n],newStr); 
 // this is just algo so it will not run but if just correct the syntax 
 // and provide proper written function it will work properly
}

/*

 void  removeDublicate(char *str,int n)
{
     int strptr=-1;
     int i=0;
     while(i<n)
     {
         if(strptr == -1 || str[i] != str[strptr])
         {
             strptr++;
             str[strptr]=str[i];
             i++;
         }
         else
         {
             while(i<n && str[i] == str[strptr])
                  i++;
             strptr--;
         }
     }
     str[strptr+1]='\0';
 }
 */