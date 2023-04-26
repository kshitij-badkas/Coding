function main() : void
{
    Maximum();
}

function Maximum(): void
{
    var Arr: number[] = [23, 89, 6, 29, 56, 45, 77, 32];
    var i: number;
    var iMax: number = Arr[0];
    for(i = 0; i < Arr.length; i++)
    {
        if(iMax < Arr[i])
        {
            iMax = Arr[i];
        }
    }
    console.log("Maximum no. is  : "+iMax);
}

main();
