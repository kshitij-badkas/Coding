class IMultiplication: public IUnknown
{
    virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int *) = 0; // pure virtual
};

class IDivision: public IUnknown
{
    virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int *) = 0; // pure virtual
};

// CLSID of MultiplicationDivision
// {8DF7C6FB-2B5E-4312-A6D5-AE67F301DC65}
const CLSID CLSID_MultiplicationDivision = { 0x8df7c6fb, 0x2b5e, 0x4312, 0xa6, 0xd5, 0xae, 0x67, 0xf3, 0x1, 0xdc, 0x65 };

// {CC8E4EAC-9977-4571-8689-9A0C59C84A6E}
const IID IID_IMultiplication = { 0xcc8e4eac, 0x9977, 0x4571, 0x86, 0x89, 0x9a, 0xc, 0x59, 0xc8, 0x4a, 0x6e };

// {8372275E-EFC9-49E4-AE52-96DC7B10EF51}
const IID IID_IDivision = { 0x8372275e, 0xefc9, 0x49e4, 0xae, 0x52, 0x96, 0xdc, 0x7b, 0x10, 0xef, 0x51 };
