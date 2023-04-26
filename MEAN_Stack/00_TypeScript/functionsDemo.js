function fun() {
    console.log("Inside fun()");
}
fun();
function gun(no) {
    console.log("Inside gun() : " + no);
}
gun(11);
function sun(no) {
    console.log("Inside sun() : " + no);
    var i = no; // local variable
    i++;
    return (i);
}
var ret = 0;
var a = 10;
ret = sun(a);
console.log("Return value is : " + ret);
