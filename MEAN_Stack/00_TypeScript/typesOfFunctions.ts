var ret: number = 0;

// Regular Funciton
function Addition1(no1: number, no2: number): number
{
    var ans: number = 0;
    ans = no1 + no2;
    return (ans);
}

ret = Addition1(10, 11);
console.log("Addition1() is : "+ret);


// Anonymous Funciton (Function without name)
var Addition2 = function (no1: number, no2: number): number
{
    var ans: number = 0;
    ans = no1 + no2;
    return (ans);
}

ret = Addition2(10, 11);
console.log("Addition2() is : "+ret);


// Fat Arrow / Lambda / Arrow Function
//  LIKE A FUNCTIN POINTER 
var Addition3 = (no1: number, no2: number): number =>                   // like inline functions (C++)
{
    var ans: number = 0;
    ans = no1 + no2;
    return (ans);
}

ret = Addition3(10, 11);
console.log("Addition3() is : "+ret);

