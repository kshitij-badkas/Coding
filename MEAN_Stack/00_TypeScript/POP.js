// Procedural Orirented Programming (POP)
function Addition(no1, no2) {
    var ans = 0;
    ans = no1 + no2;
    return (ans);
}
function Subtraction(no1, no2) {
    var ans = 0;
    ans = no1 - no2;
    return (ans);
}
var value1 = 10;
var value2 = 11;
var ret = 0;
ret = Addition(value1, value2);
console.log("Addition : " + ret);
ret = Subtraction(value1, value2);
console.log("Subtraction : " + ret);
