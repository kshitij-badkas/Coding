//
// DEFAULT ARGUMENTS ARE FROM RIGHT TO LEFT
//

function defaultArgs(no1, no2 : number = 21, no3 : number = 33) : any
{
	console.log("defaultArgs() no1, no2, no3 : " + no1 +", "+ no2+", "+no3);
}

defaultArgs(10);
defaultArgs(11, 22);
defaultArgs(101, 201, 301);
