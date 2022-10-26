#pragma once

// Automation Interface
class IMyMath : public IDispatch
{
    public:
        virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; // pure
        virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; // pure
};

// GUIDs - guidgen.exe --->
// CLSID : {3D43FB61-5E8C-42F3-AE42-96FCBEF4D7B6}
const CLSID CLSID_MyMath = { 0x3d43fb61, 0x5e8c, 0x42f3, 0xae, 0x42, 0x96, 0xfc, 0xbe, 0xf4, 0xd7, 0xb6 };

// IID : {2498C7B3-0D1C-4D93-8EA0-C0CAE62573BE}
const IID IID_IMyMath = { 0x2498c7b3, 0xd1c, 0x4d93, 0x8e, 0xa0, 0xc0, 0xca, 0xe6, 0x25, 0x73, 0xbe };

