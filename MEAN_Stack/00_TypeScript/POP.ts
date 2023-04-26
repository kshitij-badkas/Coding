// Procedural Orirented Programming (POP)

function Addition(no1: number, no2: number): number
{
    var ans: number = 0;
    ans = no1 + no2;
    return (ans);
}

function Subtraction(no1: number, no2: number): number
{
    var ans: number = 0;
    ans = no1 - no2;
    return (ans);
}


var value1: number = 10;
var value2: number = 11;
var ret: number = 0;

ret = Addition(value1, value2);
console.log("Addition : "+ret);

ret = Subtraction(value1, value2);
console.log("Subtraction : "+ret);

