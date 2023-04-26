function main() : void
{
    var ret: number = 0;
    ret = Maximum();
    console.log("Second maximum is : "+ ret);
}

function Maximum(): number
{
    var Arr: number[] = [23, 89, 6, 29, 56, 45, 77, 32];
    var iCnt: number = 0, iMax1: number = 0, iMax2: number = 0;

    iMax1 = Arr[iCnt], iMax2 = Arr[iCnt];
    for(iCnt = 0; iCnt < Arr.length; iCnt++)
    {
        if(iMax1 < Arr[iCnt])
        {
            iMax1 = Arr[iCnt];
        }
        else if((iMax2 <= iMax1) && (iMax2 <= Arr[iCnt]))
        {
            iMax2 = Arr[iCnt];
        }

    }

    console.log(iMax1);
    console.log(iMax2);

    return (iMax2);
}

main();
