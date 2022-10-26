// cl.exe /c /EHsc ClassFactoryDllServerWithRegFile.cpp
// link.exe ClassFactoryDllServerWithRegFile.obj /DLL /DEF:ClassFactoryDllServerWithRegFile.def user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS
// copy .dll to C:\Windows\System32
// go to client

#include <Windows.h>
#include <stdio.h>      // for swprintf_s()     // *
#include "AutomationServerWithRegFile.h"

// Co Class 
class CMyMath : public IMyMath
{
    private:
        long m_cRef;
        ITypeInfo *m_pITypeInfo = NULL; // *

    public:
        // constructor
        CMyMath(void);     // 'void' for backward-compatibliilty
        
        // destructor
        ~CMyMath(void);

        // IUnknown methods
        HRESULT __stdcall QueryInterface(REFIID, void **);
        ULONG __stdcall AddRef(void);
        ULONG __stdcall Release(void);

        // IDispatch methods    // *
        HRESULT __stdcall GetTypeInfoCount(UINT *);
        HRESULT __stdcall GetTypeInfo(UINT, LCID, ITypeInfo **);
        HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR *, UINT, LCID, DISPID *);
        HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);

        // ISum method
        HRESULT __stdcall SumOfTwoIntegers(int, int, int *);

        // ISubtract method
        HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *);

        // custom methods   // *
        HRESULT InitInstance(void);
};

// ClassFactory Class
class CSumSubtractClassFactory : public IClassFactory
{
    private:
        long m_cRef;

    public:
        // constrcutor
        CSumSubtractClassFactory(void);     // 'void' for backward-compatibliilty

        // destructor
        ~CSumSubtractClassFactory(void);

        // IUnknown methods
        HRESULT __stdcall QueryInterface(REFIID, void **);
        ULONG __stdcall AddRef(void);
        ULONG __stdcall Release(void);

        //IClassFactory methods
        HRESULT __stdcall CreateInstance(IUnknown *, REFIID, void **);
        HRESULT __stdcall LockServer(BOOL);
};

// Global variables
long glNumberOfActiveComponents;
long glNumberOfServerLocks;

// *  guidgen.exe --->
const GUID LIBID_AutomationServer = { };

// DllMain()
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    // Code
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            break;

        case DLL_THREAD_ATTACH:
            break;
        
        case DLL_THREAD_DETACH:
            break;

        case DLL_PROCESS_DETACH:
            break;
        
        default:
            break;
    }

    return (TRUE);
}

// CSumSubtract method Implementation
// constructor
CMyMath::CMyMath(void)
{
    // code
    m_cRef = 1;
    InterlockedIncrement(&glNumberOfActiveComponents);

    // *
    m_pITypeInfo = NULL;
}

// destructor
CMyMath::~CMyMath(void)
{
    // code
    InterlockedDecrement(&glNumberOfActiveComponents);

    // *
    if(m_pITypeInfo)
    {
        m_pITypeInfo->Release();
        m_pITypeInfo = NULL;
        delete (this);
    }
}

// IUnknown method Implementation
HRESULT CMyMath::QueryInterface(REFIID riid, void ** ppv)
{
    // code
    if(riid == IID_IUnknown)
    {
        *ppv = static_cast <IMyMath *>(this);   // *
    }
    else if(riid == IID_IDispatch)              // *
    {
        *ppv = static_cast <IMyMath *>(this);   // *
    }
    else if(riid == IID_IMyMath)                // *
    {
        *ppv = static_cast <IMyMath *>(this);   // *
    }
    else
    {
        *ppv = NULL;
        return (E_NOINTERFACE);
    }

    reinterpret_cast <IUnknown *>(*ppv)->AddRef();

    return (S_OK);
}

ULONG CMyMath::AddRef(void)
{
    // code
    InterlockedIncrement(&m_cRef);

    return (m_cRef);
}

ULONG CMyMath::Release(void)
{
    // code
    InterlockedDecrement(&m_cRef);

    if(m_cRef == 0)
    {
        delete (this);
    }
    else
    {
        return (0);
    }
    return (m_cRef);

}

// *
// IDispatch's methods
HRESULT CMyMath::GetTypeInfoCount(UINT *pCountTypeInfo)
{
    
}


// *


// ISum methods implementation
HRESULT CMyMath::SumOfTwoIntegers(int num1, int num2, int *pSum)
{
    // code
    *pSum = num1 + num2;

    return (S_OK);
}

// ISubtract methods implementation
HRESULT CMyMath::SubtractionOfTwoIntegers(int num1, int num2, int *pSubtract)
{
    // code
    *pSubtract = num1 - num2;

    return (S_OK);
}

// CSumSubtractClassFactory implementattion
// constructor
CSumSubtractClassFactory::CSumSubtractClassFactory(void)
{
    // code
    m_cRef = 1;
}

// destructor
CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
    // code
}


// IUnknown methods implementation
HRESULT CSumSubtractClassFactory::QueryInterface(REFIID riid, void ** ppv)
{
    // code
    if(riid == IID_IUnknown)
    {
        *ppv = static_cast <IClassFactory *>(this);
    }
    else if(riid == IID_IClassFactory)
    {
        *ppv = static_cast <IClassFactory *>(this);
    }
    else
    {
        *ppv = NULL;
        return (E_NOINTERFACE);
    }

    reinterpret_cast <IUnknown *>(*ppv)->AddRef();

    return (S_OK);
}

ULONG CSumSubtractClassFactory::AddRef(void)
{
    // code
    InterlockedIncrement(&m_cRef);

    return (m_cRef);
}

ULONG CSumSubtractClassFactory::Release(void)
{
    // code
    InterlockedDecrement(&m_cRef);

    if(m_cRef == 0)
    {
        delete (this);
    }
    else
    {
        return (m_cRef);
    }
    
    return (0);

}


// IClassFactory methods implementation                  // NULL,    // IID_ISUm,   // pISum       
HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
    // variable declrations
    CSumSubtract *pCSumSubtract = NULL;
    HRESULT hr;

    // code 
    if(pUnkOuter != NULL)
    {
        return (CLASS_E_NOAGGREGATION);
    }

    pCSumSubtract = new CSumSubtract;

    if(pCSumSubtract == NULL)
    {
        return (E_OUTOFMEMORY);
    }

    hr = pCSumSubtract->QueryInterface(riid, ppv);
    pCSumSubtract->Release();
    return (hr);
}

HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)    // f - flag
{
    //code
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


// Exportable COM DLL methods
extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
    // variable declarations
    CSumSubtractClassFactory *pCSumSubtractClassFactory = NULL;
    HRESULT hr;

    // code
    if(rclsid != CLSID_SumSubtract)
    {
        return (CLASS_E_CLASSNOTAVAILABLE);
    }

    pCSumSubtractClassFactory = new CSumSubtractClassFactory;
    if(pCSumSubtractClassFactory == NULL)
    {
        return (E_OUTOFMEMORY);
    }

    hr = pCSumSubtractClassFactory->QueryInterface(riid, ppv);
    pCSumSubtractClassFactory->Release();
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

