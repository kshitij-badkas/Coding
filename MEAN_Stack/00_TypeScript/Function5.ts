function main() : void 
{
    var no: number = 12;
    var bRet : boolean;

    bRet = CheckEven(no);
    if(bRet == true)
    {
        console.log("It is even.");
    }
    else
    {
        console.log("It is odd.");
    }
}

function CheckEven(value : number) : boolean
{
    if((value % 2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

main();
