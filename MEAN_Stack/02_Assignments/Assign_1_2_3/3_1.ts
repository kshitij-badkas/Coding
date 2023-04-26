class Arithmetic
{
    Number1: number;
    Number2: number;
    
    constructor(no1:number, no2:number)
    {
        this.Number1 = no1;
        this.Number2 = no2;
    }

    Addition()
    {
        var ans: number = 0;
        ans = this.Number1 + this.Number2;
        return (ans);
    }

    Subtraction()
    {
        var ans: number = 0;
        ans = this.Number1 - this.Number2;
        return (ans);
    }

    Multiplication()
    {
        var ans: number = 0;
        ans = this.Number1 * this.Number2;
        return (ans);
    }

    Division()
    {
        var ans: number = 0;
        ans = this.Number1 / this.Number2;
        return (ans);
    }

}

var ret: number = 0;
var obj1 = new Arithmetic(11, 21);
var obj2 = new Arithmetic(101, 121);

ret = obj1.Addition();
console.log("Addition : "+ret);

ret = obj1.Subtraction();
console.log("Subtraction : "+ret);

ret = obj1.Multiplication();
console.log("Multiplication : "+ret);

ret = obj1.Division();
console.log("Division : "+ret);

console.log("*******************");

ret = obj2.Addition();
console.log("Addition : "+ret);

ret = obj2.Subtraction();
console.log("Subtraction : "+ret);

ret = obj2.Multiplication();
console.log("Multiplication : "+ret);

ret = obj2.Division();
console.log("Division : "+ret);
