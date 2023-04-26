class Artihmetic
{
	// characteristics : NO 'VAR' KEYWORD
	No1 : number; 
	No2 : number;
	
	// constructor
	constructor(a: number, b: number)
	{
		this.No1 = a;
		this.No2 = b;

		// console.log("INSISDE constructor : + >" + (this.No1 + this.No2));
		console.log(this.No1 + this.No2);
	}

	// behaviours	
	Addition()
	{
	    var Ans : number = 0;		// local variable
	    Ans = this.No1 + this.No2;
	    return Ans;
	}

	Subtraction()					
	{
	    var Ans : number = 0;		// local variable
	    Ans = this.No1 - this.No2;
	    return Ans;
	}
}

var obj1 = new Artihmetic(11, 21);
var obj2 = new Artihmetic(51, 101);
var Ret : number = 0;

Ret = obj1.Addition();
console.log("Addition is : "+Ret);

Ret = obj1.Subtraction();
console.log("Subtraction is : "+Ret);
