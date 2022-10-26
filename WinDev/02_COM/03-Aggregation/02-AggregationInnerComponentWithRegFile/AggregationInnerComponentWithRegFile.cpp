// cl.exe /c /EHsc AggregationInnerComponentWithRegFile.cpp
// link.exe AggregationInnerComponentWithRegFile.obj /DLL /DEF:AggregationInnerComponentWithRegFile.def user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS 
// copy .dll to C:\Windows\System32
// go to Outer Component

#include <Windows.h>
#include "AggregationInnerComponentWithRegFile.h"

// interface declaration (for internal use only -- not to be included in .h)
interface INoAggregationIUnknown   // new
{
    virtual HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void **) = 0;
    virtual ULONG __stdcall AddRef_NoAggregation(void) = 0;
    virtual ULONG __stdcall Release_NoAggregation(void) = 0;
};

// Co Class
class CMultiplicationDivision: public INoAggregationIUnknown, IMultiplication, IDivision
{
    private:
        long m_cRef;
        IUnknown *m_pIUnknownOuter;
    
    public:
        // constructor
        CMultiplicationDivision(IUnknown *); // new

        // destructor
        ~CMultiplicationDivision(void);

        // Aggregation Suppported IUnknown methods
        HRESULT __stdcall QueryInterface(REFIID, void **);
        ULONG __stdcall AddRef(void);
        ULONG __stdcall Release(void);

        // Aggregation NON Suppported IUnknown methods
        HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void **);
        ULONG __stdcall AddRef_NoAggregation(void);
        ULONG __stdcall Release_NoAggregation(void);

        // IMultiplication methods
        HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int *);

        // IDivision methods
        HRESULT __stdcall DivisionOfTwoIntegers(int, int, int *);

};

// ClassFactory class
class CMultiplicationDivisionClassFactory: public IClassFactory
{
    private:
        long m_cRef;

    public:
        // constructor
        CMultiplicationDivisionClassFactory(void);

        // destructor
        ~CMultiplicationDivisionClassFactory(void);

        // IUnknown methods
        HRESULT __stdcall QueryInterface(REFIID, void **);
        ULONG __stdcall AddRef(void);
        ULONG __stdcall Release(void);

        // IClassFactory methods
        HRESULT __stdcall CreateInstance(IUnknown *, REFIID, void **);
        HRESULT __stdcall LockServer(BOOL); 
};

// global variables   --> can put this into a class using Singleton pattern
long glNumberOfActiveComponents = 0;
long glNumberOfServerLocks = 0;

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// DllMain
// BOOL WINAPI DllMain(HINSANCE hDll, DWORD dwReason, LPVOID Reserved)
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    // code
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        break;

    case DLL_PROCESS_DETACH:
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    default:
        break;
    }

    return (TRUE);
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// CMultiplicationDivision constructor
CMultiplicationDivision::CMultiplicationDivision(IUnknown *pIUnknownOuter)
{
    // code
    m_cRef = 1;
    m_pIUnknownOuter = NULL;
    InterlockedIncrement(&glNumberOfActiveComponents);

    if(pIUnknownOuter != NULL)
    {
        m_pIUnknownOuter = pIUnknownOuter;
    }
    else
    {
        m_pIUnknownOuter = reinterpret_cast<IUnknown *> (static_cast<INoAggregationIUnknown *>(this));
    }
}

// CMultiplicationDivision destructor
CMultiplicationDivision::~CMultiplicationDivision(void)
{
    // code
    InterlockedDecrement(&glNumberOfActiveComponents);
    m_pIUnknownOuter->Release();
}

// CMultiplicationDivision's Aggregation Supporting IUnkown's methods
HRESULT CMultiplicationDivision::QueryInterface(REFIID riid, void **ppv)
{
    // code
    return (m_pIUnknownOuter->QueryInterface(riid, ppv));
}

ULONG CMultiplicationDivision::AddRef(void)
{
    // code
    return (m_pIUnknownOuter->AddRef());
}

ULONG CMultiplicationDivision::Release(void)
{
    // code
    return (m_pIUnknownOuter->Release());
}

// CMultiplicationDivision's Aggregation NON Supporting IUnkown's methods
HRESULT CMultiplicationDivision::QueryInterface_NoAggregation(REFIID riid, void **ppv)
{
    // code
    if(riid == IID_IUnknown)
    {
        *ppv = static_cast<INoAggregationIUnknown *>(this);
    }
    else if(riid == IID_IMultiplication)
    {
        *ppv = static_cast<IMultiplication *>(this);
    }
    else if(riid == IID_IDivision)
    {
        *ppv = static_cast<IDivision *>(this);
    }
    else
    {
        *ppv = NULL;
        return (E_NOINTERFACE);
    }
    reinterpret_cast<IUnknown *>(*ppv)->AddRef();
    return (S_OK);
}

ULONG CMultiplicationDivision::AddRef_NoAggregation(void)
{
    // code
    InterlockedIncrement(&m_cRef);
    return (m_cRef);
}

ULONG CMultiplicationDivision::Release_NoAggregation(void)
{
    // code
    InterlockedDecrement(&m_cRef);
    if(m_cRef == 0)
    {
        delete (this);
        return (0);
    }
    return (m_cRef);
}

// CMultiplicationDivision's IMultiplication method
HRESULT CMultiplicationDivision::MultiplicationOfTwoIntegers(int num1, int num2, int *pMultiplication)
{
    // code
    *pMultiplication = num1 * num2;
    return (S_OK);
}

// CMultiplicationDivision's IMultiplication method
HRESULT CMultiplicationDivision::DivisionOfTwoIntegers(int num1, int num2, int *pDivision)
{
    // code
    *pDivision = num1 / num2;
    return (S_OK);
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// CMultiplicationDivisionClassFactory constructor
CMultiplicationDivisionClassFactory::CMultiplicationDivisionClassFactory(void)
{
    // code
    m_cRef = 1;
}

// CMultiplicationDivisionClassFactory destructor
CMultiplicationDivisionClassFactory::~CMultiplicationDivisionClassFactory(void)
{
    // code
}

// CMultiplicationDivisionClassFactory's IClassFactory's IUnknown methods
HRESULT CMultiplicationDivisionClassFactory::QueryInterface(REFIID riid, void **ppv)
{
    // code
    if(riid == IID_IUnknown)
    {
        *ppv = static_cast<IClassFactory *>(this);
    }
    else if(riid == IID_IClassFactory)
    {
        *ppv = static_cast<IClassFactory *>(this);
    }
    else
    {
        *ppv = NULL;
        return (E_NOINTERFACE);
    }
    reinterpret_cast<IUnknown *>(*ppv)->AddRef();
    return (S_OK);
}

ULONG CMultiplicationDivisionClassFactory::AddRef(void)
{
    // code
    InterlockedIncrement(&m_cRef);
    return (m_cRef);
}

ULONG CMultiplicationDivisionClassFactory::Release(void)
{
    // code
    InterlockedDecrement(&m_cRef);
    if(m_cRef == 0)
    {
        delete (this);
        return (0);
    }
    return (m_cRef);
}

// CMultiplicationDivisionClassFactory's IClassFactory methods
HRESULT CMultiplicationDivisionClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
    // local variables
    CMultiplicationDivision *pCMultiplicationDivision = NULL;
    HRESULT hr;

    // code
    if((pUnkOuter != NULL) && (riid != IID_IUnknown))
    {
        return (CLASS_E_NOAGGREGATION);
    }

    pCMultiplicationDivision = new CMultiplicationDivision(pUnkOuter);
    if(pCMultiplicationDivision == NULL)
    {
        return (E_OUTOFMEMORY);
    }

    hr = pCMultiplicationDivision->QueryInterface_NoAggregation(riid, ppv);
    pCMultiplicationDivision->Release_NoAggregation();
    return (hr);

}

HRESULT CMultiplicationDivisionClassFactory::LockServer(BOOL fLock)
{
    // code
    if(fLock)
    {
        InterlockedIncrement(&glNumberOfServerLocks);
    }
    else
    {
        InterlockedDecrement(&glNumberOfServerLocks);
    }
    return (S_OK);
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Exportable COM DLL methods
extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
    // variable declarations
    CMultiplicationDivisionClassFactory *pCMultiplicationDivisionClassFactory = NULL;
    HRESULT hr;

    // code
    if(rclsid != CLSID_MultiplicationDivision)
    {
        return (CLASS_E_CLASSNOTAVAILABLE);
    }

    pCMultiplicationDivisionClassFactory = new CMultiplicationDivisionClassFactory;
    if(pCMultiplicationDivisionClassFactory == NULL)
    {
        return (E_OUTOFMEMORY);
    }

    hr = pCMultiplicationDivisionClassFactory->QueryInterface(riid, ppv);
    pCMultiplicationDivisionClassFactory->Release();
    return (hr);
    
}


extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
    // code
    if(glNumberOfActiveComponents == 0 && glNumberOfServerLocks == 0)
    {
        return (S_OK);
    }
    else
    {
        return (S_FALSE);
    }
}

