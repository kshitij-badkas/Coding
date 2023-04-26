function main(): void
{
    var iRes: number = 0;
    iRes = Area(3);
    console.log(iRes);

    iRes = Area(5);
    console.log(iRes);

    iRes = Area(5, 5);
    console.log(iRes);
}

function Area(iRadius: number, PI: number = 3.14): number
{
    return(PI * iRadius * iRadius);
}

main();