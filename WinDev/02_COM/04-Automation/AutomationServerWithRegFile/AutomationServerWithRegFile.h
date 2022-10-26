#pragma once

// Automation Interface
class IMyMath : public IDispatch
{
    virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; // pure

    virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; // pure
};

// GUIDs - guidgen.exe --->
// CLSID : {A80A863F-052F-4D2B-AFC2-5E2BD9AE36F4}
const CLSID CLSID_MyMath = { 0xa80a863f, 0x52f, 0x4d2b, 0xaf, 0xc2, 0x5e, 0x2b, 0xd9, 0xae, 0x36, 0xf4 };

// IID : {6FA02AE2-8793-4E5F-8192-F579488C76EB}
const IID IID_IMyMath = { 0x6fa02ae2, 0x8793, 0x4e5f, 0x81, 0x92, 0xf5, 0x79, 0x48, 0x8c, 0x76, 0xeb };

