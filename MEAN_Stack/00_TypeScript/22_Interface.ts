
// Declare interface
interface Student 
{ 
    name:string, 
    college:string, 
    fun:()=>string 
 } 
 
 class Demo implements Student
 {
   name:string;
   college:string; 

   constructor(str1,str2)
   {
      this.name = str1;
      this.college = str2;
      console.log("Inside Demo constructor");
   }

   fun()
   {
      return "Inside fun";
   }
 }

var obj = new Demo("Kshitij","Pune University");
 console.log(obj.name) 
 console.log(obj.college)
 console.log(obj.fun())  
 
