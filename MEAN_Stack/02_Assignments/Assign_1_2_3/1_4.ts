function main(): void
{
    var bRet: boolean;
    bRet = ChkPrime(11);

    if(bRet == true)
    {
        console.log("Prime");
    }
    else
    {
        console.log("Not Prime");
    }
}

function ChkPrime(iNo: number): boolean
{
    var iCnt: number = 0;

    for(iCnt = 2; iCnt <= (iNo / 2); iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            break;
        }
    }
    if(iCnt == (iNo/2) + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

main();