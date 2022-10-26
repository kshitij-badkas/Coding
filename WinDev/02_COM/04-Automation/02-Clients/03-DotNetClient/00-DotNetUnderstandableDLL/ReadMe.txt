
type library import command - 
exe location  : C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.8 Tools\TlbImp.exe

In 00-DotNetUnderstandableDLL :

tlbimp.exe C:\Windows\System32\AutomationServerTypeLib.tlb /out:./AutomationServerTypeLibForDotNet.dll

>>> WARNING :
TlbImp : warning TI3002 : Importing a type library into a platform agnostic assembly.
This can cause errors if the type library is not truly platform agnostic.
>>> IGNORE THE WARNING


COPY the AutomationServerTypeLibForDotNet.dll TO C:/Windows/System32 

ildasm - intermediate language disaasembler

RCW - Runtime Callable Wrapper
CMyMath is .NET wrapper around CMyMath C++ CoClass made my tlbimp.exe to make CMyMath .Net Understandable.


*****************

>>> If there is a runTime Exception in CSharpAutomation.exe, 
COPY the AutomationServerTypeLibForDotNet.dll to 01-CSharpClient directory
 
*****************
