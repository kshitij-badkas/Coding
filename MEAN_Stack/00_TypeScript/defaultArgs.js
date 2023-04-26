// function defaultArgs(no1, no2 : number = 21, no3 : number = 33) : any
// function defaultArgs(no1 : number = 199, no2 : number = 299, no3) : any
function defaultArgs(no1, no2, no3) {
    if (no3 === void 0) { no3 = 33; }
    console.log("defaultArgs() no1, no2, no3 : " + no1 + ", " + no2 + ", " + no3);
}
defaultArgs(10);
defaultArgs(11, 22);
defaultArgs(101, 201, 301);
