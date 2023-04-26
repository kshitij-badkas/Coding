class Circle
{
    Radius: number;
    PI: number;
    
    constructor(no1:number, no2:number = 3.14)
    {
        this.Radius = no1;
        this.PI = no2;
    }

    Area()
    {
        var ans: number = 0;
        ans = this.PI * this.Radius * this.Radius;
        return (ans);
    }

}

class CircleX extends Circle
{
    Circumference()
    {
        var ans: number = 0;
        ans = 2 * this.PI * this.Radius;
        return (ans);
    }
}

var ret: number = 0;
var obj1 = new CircleX(5);
var obj2 = new CircleX(5, 6.28);

ret = obj1.Circumference();
console.log("Circumference : "+ret);

console.log("*******************");

ret = obj2.Circumference();
console.log("Circumference : "+ret);

console.log("*******************");

ret = obj1.Area();
console.log("Area : "+ret);

console.log("*******************");

ret = obj2.Area();
console.log("Area : "+ret);