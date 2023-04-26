function main() : void
{
    var ret: boolean;

    ret = ChkArmstrong(153);

    console.log("Value of ret :  "+ ret);

    if(ret == true)
    {
        console.log("It is Armstrong ");
    }
    else
    {
        console.log("It is NOT Armstrong ");
    }

	console.log(1 % 10);
}

function ChkArmstrong(iNo: number): boolean
{
    var iTemp: number = 0, iSum: number = 0, iDigit: number = 0, iDigitCnt: number = 0, iMult: number = 1;

    iTemp = iNo;
	// Count no. of Digits
	while(iNo != 0)
	{
		// iDigit = iNo % 10;
		iDigitCnt ++;
		iNo = Math.floor(iNo / 10);
	}

	// Calculate Power
	iNo = iTemp;				// Reset iNo
	while(iNo != 0)
	{
		iMult = 1;
		iDigit = Math.floor(iNo % 10);
		
		for(var iCnt = 1; iCnt <= iDigitCnt; iCnt++)
		{
			iMult = Math.floor(iMult * iDigit);
		}

		iSum = Math.floor(iSum + iMult);
		console.log("Sum = "+ iSum);

		iNo = Math.floor(iNo / 10);
	}

	// console.log("Sum = "+ iSum);

	if(iSum == iTemp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

main();
