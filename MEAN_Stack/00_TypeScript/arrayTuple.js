var iArr = [11, 21, 51, 101]; // homogeneuos
console.log("length of array iArr : " + iArr.length);
console.log("regular for loop iArr : ");
var i;
for (i = 0; i < iArr.length; i++) {
    console.log(iArr[i]);
}
console.log("for in loop iArr : ");
for (var entry in iArr) {
    console.log(entry);
}
console.log("for of loop iArr : ");
for (var _i = 0, iArr_1 = iArr; _i < iArr_1.length; _i++) {
    var entry = iArr_1[_i];
    console.log(entry);
}
//////////////////////////////
var Arr = [10, "hello", true]; // heterogenous
console.log("length of array : " + Arr.length);
console.log("regular for loop : ");
var i;
for (i = 0; i < Arr.length; i++) {
    console.log(Arr[i]);
}
console.log("for in loop : ");
for (var entry in Arr) {
    console.log(entry);
}
console.log("for of loop : ");
for (var _a = 0, Arr_1 = Arr; _a < Arr_1.length; _a++) {
    var entry = Arr_1[_a];
    console.log(entry);
}
