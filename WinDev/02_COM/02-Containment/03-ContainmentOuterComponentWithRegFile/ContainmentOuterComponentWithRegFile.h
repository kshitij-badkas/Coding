// #pragma once

class ISum: public IUnknown
{
    public:
        // ISum specific method declarations
        virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; // pure virtual
};

class ISubtract: public IUnknown
{
    public:
        // ISubtract specific method declarations
        virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; // pure virtual
};

// CLSID of SumSubtract Component
// {308055E2-F7B2-4695-AB99-7B805D05EC59}
const CLSID CLSID_SumSubtract = { 0x308055e2, 0xf7b2, 0x4695, 0xab, 0x99, 0x7b, 0x80, 0x5d, 0x5, 0xec, 0x59 };

// {C3CD5396-4483-40BB-8CD3-1642A6E83BEE}
const IID IID_ISum = { 0xc3cd5396, 0x4483, 0x40bb, 0x8c, 0xd3, 0x16, 0x42, 0xa6, 0xe8, 0x3b, 0xee };

// {41006D07-F981-459B-B574-FEDFAC5B2EB5}
const IID IID_ISubtract = { 0x41006d07, 0xf981, 0x459b, 0xb5, 0x74, 0xfe, 0xdf, 0xac, 0x5b, 0x2e, 0xb5 };
