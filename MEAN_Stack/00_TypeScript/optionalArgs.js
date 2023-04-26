//
// OPTIOANL ARGUMENTS
//
function optionalArgs(no1, no2) {
    console.log("Value of no1: " + no1);
    if (no2 != undefined) {
        console.log("Value of no2: " + no2);
    }
}
optionalArgs(10);
optionalArgs(11, 22);
