function main() : void
{
    Summation();
}

function Summation(): void
{
    var Arr: number[] = [23, 6, 7, 4, 5, 7];
    var i: number = 0, iSum = 0;
    for(i = 0; i < Arr.length; i++)
    {
        iSum = iSum + Arr[i];
    }
    console.log("Summation is  : "+iSum);
}

main();
