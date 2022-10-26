#pragma once


#undef INTERFACE
#define INTERFACE ISum
DECLARE_INTERFACE_(ISum, IUnknown)
{
    // IUnknown Methods
    STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ISum Method
    STDMETHOD(SumOfTwoIntegers)(THIS_ int, int, int*) PURE;
};

#undef INTERFACE
#define INTERFACE ISubtract
DECLARE_INTERFACE_(ISubtract, IUnknown)
{
    // IUnknown Methods
    STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ISubtract Method
    STDMETHOD(SubtractionOfTwoIntegers)(THIS_ int, int, int*) PURE;
};


// {A80A863F-052F-4D2B-AFC2-5E2BD9AE36F4}
const CLSID CLSID_SumSubtract = { 0xa80a863f, 0x52f, 0x4d2b, 0xaf, 0xc2, 0x5e, 0x2b, 0xd9, 0xae, 0x36, 0xf4 };

// {6FA02AE2-8793-4E5F-8192-F579488C76EB}
const IID IID_ISum = { 0x6fa02ae2, 0x8793, 0x4e5f, 0x81, 0x92, 0xf5, 0x79, 0x48, 0x8c, 0x76, 0xeb };

// {F14555E4-F626-454E-962A-9D4915EDA915}
const IID IID_ISubtract = { 0xf14555e4, 0xf626, 0x454e, 0x96, 0x2a, 0x9d, 0x49, 0x15, 0xed, 0xa9, 0x15 };

