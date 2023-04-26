function main(): void
{
    var no1: number = 23;
    var no2: number = 89;
    var no3: number = 6;

    var iRes: number = 0;
    iRes = Maximum(no1, no2, no3);

    console.log(iRes);
}

function Maximum(value1: number, value2: number, value3: number): number
{
    var iMax: number = 0;
    iMax = value1;
    if(iMax < value2)
    {
        iMax = value2;
    }
    if(iMax < value3)
    {
        iMax = value3;
    }
    return (iMax);
}

main();