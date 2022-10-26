// ReadMe.txt --> \02_COM\04-Automation\02-Clients\03-DotNetClient\00-DotNetUnderstandableDLL

// csc.exe /r:C:\Windows\System32\AutomationServerTypeLibForDotNet.dll CSharpAutomation.cs

// Namespaces
using System;   // Where 'Related' Data is declared       
using System.Runtime.InteropServices;
using AutomationServerTypeLibForDotNet; // COPY the AutomationServerTypeLibForDotNet.dll to 01-CSharpClient directory

public class CSharpAutomation
{
    public static void Main()
    {
        // code
        
        /*
        COMMAND : ildasm.exe /Adv AutomationServerTypeLibForDotNet.dll     : View - MetaInfo - Show!
        ildasm - intermediate language disassembler
        RCW - Runtime Callable Wrapper
        CMyMath is .NET wrapper around CMyMath C++ CoClass made my tlbimp.exe to make CMyMath .Net Understandable.
        */

        CMyMathClass objCMyMathClass = new CMyMathClass();      // constructor
        IMyMath objIMyMath = (IMyMath)objCMyMathClass;

        int num1, num2, sum, subtract;

        num1 = 165;
        num2 = 135;

        sum = objIMyMath.SumOfTwoIntegers(num1, num2);
        Console.WriteLine("Sum of "+num1+" and "+num2+" is "+sum);

        subtract = objIMyMath.SubtractionOfTwoIntegers(num1, num2);
        Console.WriteLine("Subtraction of "+num1+" and "+num2+" is "+subtract);
    }
}

