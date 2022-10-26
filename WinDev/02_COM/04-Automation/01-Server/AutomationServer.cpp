// cl.exe /c /EHsc /D UNICODE AutomationServer.cpp
// link.exe AutomationServer.obj /DLL /DEF:AutomationServer.def user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS

// In ProxyStub folder -> cl.exe /c /EHsc /D REGISTER_PROXY_DLL AutomationProxyStub.c AutomationProxyStubDllData.c AutomationProxyStubGuids.c

// copy .dll to C:\Windows\System32  --- wait
// go to client

#include <Windows.h>
#include <stdio.h>      // for swprintf_s()     // *
#include "AutomationServer.h"

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
class CMyMathClassFactory : public IClassFactory
{
    private:
        long m_cRef;

    public:
        // constrcutor
        CMyMathClassFactory(void);     // 'void' for backward-compatibliilty

        // destructor
        ~CMyMathClassFactory(void);

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
// {948A8459-3AC2-4D51-BA55-0FE16573D364}
const GUID LIBID_AutomationServer = { 0x948a8459, 0x3ac2, 0x4d51, 0xba, 0x55, 0xf, 0xe1, 0x65, 0x73, 0xd3, 0x64 };

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
    // as we have type library it is 1, else 0
    *pCountTypeInfo = 1;

    return (S_OK);
}


// *
HRESULT CMyMath::GetTypeInfo(UINT iTypeInfo, LCID lcid, ITypeInfo **ppITypeInfo)
{
    *ppITypeInfo = NULL;

    if(iTypeInfo != 0)
    {
        return (DISP_E_BADINDEX);
    }

    // interface assignment rule
    m_pITypeInfo->AddRef();

    *ppITypeInfo = m_pITypeInfo;
    
    return (S_OK);
}

// *
HRESULT CMyMath::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, 
                                UINT cNames, LCID lcid, DISPID *rgDispId)
{
    return (DispGetIDsOfNames(m_pITypeInfo, rgszNames, cNames, rgDispId));
}

// *
HRESULT CMyMath::Invoke(DISPID dispIdMember, REFIID riid, 
                        LCID lcid, WORD wFlags, 
                        DISPPARAMS *pDispParams, VARIANT *pVarResult,
                        EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
    // variable declarations
    HRESULT hr;

    hr = DispInvoke(this, 
                m_pITypeInfo,
                dispIdMember,
                wFlags,
                pDispParams,
                pVarResult,
                pExcepInfo,
                puArgErr);

    return (hr);
}


// *
HRESULT CMyMath::InitInstance(void)
{
    // function declaration
    void ComErrorDescriptionString(HWND, HRESULT);  // custom function

    // variable declaration
    HRESULT hr;
    ITypeLib *pITypeLib = NULL;

    // code
    if(m_pITypeInfo == NULL)
    {
        hr = LoadRegTypeLib(LIBID_AutomationServer,
                        1, 0,   // major , minor version numbers
                        0x00,
                        &pITypeLib);

        if(FAILED(hr))
        {
            ComErrorDescriptionString(NULL, hr);
            return (hr);
        }

        hr = pITypeLib->GetTypeInfoOfGuid(IID_IMyMath, &m_pITypeInfo);

        if(FAILED(hr))
        {
            ComErrorDescriptionString(NULL, hr);
            pITypeLib->Release();
            return (hr);
        }

        pITypeLib->Release();
    }  

    return (S_OK);
}


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

// CMyMathClassFactory implementattion
// constructor
CMyMathClassFactory::CMyMathClassFactory(void)   // *
{
    // code
    m_cRef = 1;
}

// destructor
CMyMathClassFactory::~CMyMathClassFactory(void)   // *
{
    // code
}


// IUnknown methods implementation
HRESULT CMyMathClassFactory::QueryInterface(REFIID riid, void ** ppv)   // *
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

ULONG CMyMathClassFactory::AddRef(void)   // *
{
    // code
    InterlockedIncrement(&m_cRef);

    return (m_cRef);
}

ULONG CMyMathClassFactory::Release(void)   // *
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


// IClassFactory methods implementation       
HRESULT CMyMathClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
    // variable declrations
    CMyMath *pCMyMath = NULL;    // *
    HRESULT hr;

    // code 
    if(pUnkOuter != NULL)
    {
        return (CLASS_E_NOAGGREGATION);
    }

    pCMyMath = new CMyMath;     // *

    if(pCMyMath == NULL)        // *
    {
        return (E_OUTOFMEMORY);
    }

    // call automation related init method
    pCMyMath->InitInstance();   // *

    hr = pCMyMath->QueryInterface(riid, ppv);   // *
    pCMyMath->Release();    // *
    return (hr);
}

HRESULT CMyMathClassFactory::LockServer(BOOL fLock)    // f - flag
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
    CMyMathClassFactory *pCMyMathClassFactory = NULL;     // *
    HRESULT hr;

    // code
    if(rclsid != CLSID_MyMath)
    {
        return (CLASS_E_CLASSNOTAVAILABLE);
    }

    pCMyMathClassFactory = new CMyMathClassFactory;
    if(pCMyMathClassFactory == NULL)
    {
        return (E_OUTOFMEMORY);
    }

    hr = pCMyMathClassFactory->QueryInterface(riid, ppv);
    pCMyMathClassFactory->Release();
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

// custom function
void ComErrorDescriptionString(HWND hwnd, HRESULT hr)
{
    // variable declarations
    TCHAR *szErrorMessage = NULL;
    TCHAR str[255];

    if(FACILITY_WINDOWS == HRESULT_FACILITY(hr))
    {
        hr = HRESULT_CODE(hr);

        if(FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                    NULL, hr, 
                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                    (LPTSTR)&szErrorMessage, 0, NULL) != 0)
        {
            swprintf_s(str, TEXT("%#x : %s"), hr, szErrorMessage);  // securely print wide char string
            LocalFree(szErrorMessage);
        }

        else
        {
            swprintf_s(str, TEXT("[Could not find a description for error # %#x.]\n"), hr);
        }

        MessageBox(hwnd, str, TEXT("COM Error"), MB_OK);
    }
}
