// #pragma once

class IMultiplication: public IUnknown
{
    public:
        // IMultiplication specific method declarations
        virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0; // pure virtual
};

class IDivision: public IUnknown
{
    public:
        // IDivision specific method declarations
        virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0; // pure virtual
};

// CLSID of MultiplicationDivision Component
// {90250F4F-C162-4F63-B2CC-14AF15A3B210}
const CLSID CLSID_MultiplicationDivision = { 0x90250f4f, 0xc162, 0x4f63, 0xb2, 0xcc, 0x14, 0xaf, 0x15, 0xa3, 0xb2, 0x10 };

// {CF08B43E-B96C-47B3-943F-4A996F58432D}
const IID IID_IMultiplication = { 0xcf08b43e, 0xb96c, 0x47b3, 0x94, 0x3f, 0x4a, 0x99, 0x6f, 0x58, 0x43, 0x2d };

// {C67AF7B5-42D3-43C3-BEC2-473FECF96EEE}
const IID IID_IDivision = { 0xc67af7b5, 0x42d3, 0x43c3, 0xbe, 0xc2, 0x47, 0x3f, 0xec, 0xf9, 0x6e, 0xee };
