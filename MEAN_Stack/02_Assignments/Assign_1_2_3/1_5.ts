function main(): void
{
    Fibonacci(21);
}

function Fibonacci(iNo: number): void
{
    var iCnt: number = 0;
    var iSum: number = 0;
    var a:number = 0, b:number = 0;

    for(iCnt = 0; iCnt <= iNo; iCnt++)
    {
        iSum = iSum + iCnt;
        a = iSum;
        b = iCnt;

    }
}

main();