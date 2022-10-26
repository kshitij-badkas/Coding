class ISum: public IUnknown
{
    virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0; // pure virtual
};

class ISubtract: public IUnknown
{
    virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0; // pure virtual
};

// CLSID of SumSubtract
// {1314704B-C0CF-4EC2-8B4E-FB5C1B16F236}
const CLSID CLSID_SumSubtract = { 0x1314704b, 0xc0cf, 0x4ec2, 0x8b, 0x4e, 0xfb, 0x5c, 0x1b, 0x16, 0xf2, 0x36 };

// {6D043056-3B18-4BD9-92F3-2C3DF5C859DF}
const IID IID_ISum = { 0x6d043056, 0x3b18, 0x4bd9, 0x92, 0xf3, 0x2c, 0x3d, 0xf5, 0xc8, 0x59, 0xdf };

// {B2BFD457-303E-4622-B47F-562A29E3B2F5}
const IID IID_ISubtract = { 0xb2bfd457, 0x303e, 0x4622, 0xb4, 0x7f, 0x56, 0x2a, 0x29, 0xe3, 0xb2, 0xf5 };
