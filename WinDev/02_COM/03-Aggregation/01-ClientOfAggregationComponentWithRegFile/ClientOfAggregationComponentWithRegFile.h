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

// CLSID of SumSubtract
// {1314704B-C0CF-4EC2-8B4E-FB5C1B16F236}
const CLSID CLSID_SumSubtract = { 0x1314704b, 0xc0cf, 0x4ec2, 0x8b, 0x4e, 0xfb, 0x5c, 0x1b, 0x16, 0xf2, 0x36 };

// {6D043056-3B18-4BD9-92F3-2C3DF5C859DF}
const IID IID_ISum = { 0x6d043056, 0x3b18, 0x4bd9, 0x92, 0xf3, 0x2c, 0x3d, 0xf5, 0xc8, 0x59, 0xdf };

// {B2BFD457-303E-4622-B47F-562A29E3B2F5}
const IID IID_ISubtract = { 0xb2bfd457, 0x303e, 0x4622, 0xb4, 0x7f, 0x56, 0x2a, 0x29, 0xe3, 0xb2, 0xf5 };

// CLSID of MultiplicationDivision
// {8DF7C6FB-2B5E-4312-A6D5-AE67F301DC65}
const CLSID CLSID_MultiplicationDivision = { 0x8df7c6fb, 0x2b5e, 0x4312, 0xa6, 0xd5, 0xae, 0x67, 0xf3, 0x1, 0xdc, 0x65 };

// {CC8E4EAC-9977-4571-8689-9A0C59C84A6E}
const IID IID_IMultiplication = { 0xcc8e4eac, 0x9977, 0x4571, 0x86, 0x89, 0x9a, 0xc, 0x59, 0xc8, 0x4a, 0x6e };

// {8372275E-EFC9-49E4-AE52-96DC7B10EF51}
const IID IID_IDivision = { 0x8372275e, 0xefc9, 0x49e4, 0xae, 0x52, 0x96, 0xdc, 0x7b, 0x10, 0xef, 0x51 };
