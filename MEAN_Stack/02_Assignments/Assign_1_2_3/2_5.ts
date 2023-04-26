function main() : void
{
    var ret: boolean;
	var sentence: string, word: string;
	sentence = "Pune Kothrud Marvellous Infisystems";
	word = "Marvellous";

     ret = ChkString(sentence, word);
	//ChkString(sentence, word);

    console.log("Value of ret :  "+ ret);

    if(ret == true)
    {
        console.log("String contains Marvellous");
    }
    else
    {
        console.log("String DOES NOT contain Marvellous");
    }

}

function ChkString(strSentence: string, strWord)
{
	if(strSentence.indexOf(strWord) !== -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

main();
