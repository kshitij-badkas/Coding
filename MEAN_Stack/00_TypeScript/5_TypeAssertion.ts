/*
TypeScript allows changing a variable from one type to another. TypeScript refers to this process as Type Assertion.
Type Assertion is Compile ime process.
*/

var no:string = "101"                           // no is of type string
var value:number = <number> <any>no             //value is now of type number 
console.log("After Type Assertion : "+value);
 