var Artihmetic = /** @class */ (function () {
    // constructor
    function Artihmetic(a, b) {
        this.No1 = a;
        this.No2 = b;
        // console.log("INSISDE constructor : + >" + (this.No1 + this.No2));
        console.log(this.No1 + this.No2);
    }
    // behaviours	
    Artihmetic.prototype.Addition = function () {
        var Ans = 0; // local variable
        Ans = this.No1 + this.No2;
        return Ans;
    };
    Artihmetic.prototype.Subtraction = function () {
        var Ans = 0; // local variable
        Ans = this.No1 - this.No2;
        return Ans;
    };
    return Artihmetic;
}());
var obj1 = new Artihmetic(11, 21);
var obj2 = new Artihmetic(51, 101);
var Ret = 0;
Ret = obj1.Addition();
console.log("Addition is : " + Ret);
Ret = obj1.Subtraction();
console.log("Subtraction is : " + Ret);
