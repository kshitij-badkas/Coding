var iArr : number[] = [11, 21, 51, 101];	// homogeneuos

console.log("length of array iArr : "+ iArr.length);

console.log("regular for loop iArr : ");
var i: number;
for(i = 0; i < iArr.length; i++)
{
    console.log(iArr[i]);
}

console.log("for in loop iArr : ");
for(let entry in iArr)
{
    console.log(entry);	
}


console.log("for of loop iArr : ");
for(let entry of iArr)
{
    console.log(entry);	
}

//////////////////////////////

var Arr = [10, "hello", true];		// heterogenous

console.log("length of array : "+ Arr.length);

console.log("regular for loop : ");
var i: number;
for(i = 0; i < Arr.length; i++)
{
    console.log(Arr[i]);
}

console.log("for in loop : ");
for(let entry in Arr)
{
    console.log(entry);	
}


console.log("for of loop : ");
for(let entry of Arr)
{
    console.log(entry);	
}

