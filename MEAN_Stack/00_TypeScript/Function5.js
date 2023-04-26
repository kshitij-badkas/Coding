function main() {
    var no = 12;
    var bRet;
    bRet = CheckEven(no);
    if (bRet == true) {
        console.log("It is even.");
    }
    else {
        console.log("It is odd.");
    }
}
function CheckEven(value) {
    if ((value % 2) == 0) {
        return true;
    }
    else {
        return false;
    }
}
main();
