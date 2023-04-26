// default argumnets
// number of default arguments are 2
function Demo(no1, no2, no3) {
    if (no2 === void 0) { no2 = 20; }
    if (no3 === void 0) { no3 = 30; }
    console.log("Inside Demo()");
}
Demo(10);
Demo(10, 11);
Demo(10, 11, 12);
