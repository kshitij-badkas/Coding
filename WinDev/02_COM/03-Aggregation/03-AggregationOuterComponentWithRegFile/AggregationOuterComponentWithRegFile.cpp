// cl.exe /c /EHsc AggregationOuterComponentWithRegFile.cpp
// link.exe AggregationOuterComponentWithRegFile.obj /DLL /DEF:AggregationOuterComponentWithRegFile.def user32.lib gdi32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS
// copy .dll to C:\Windows\System32
// go to client

#include <Windows.h>
#include "AggregationInnerComponentWithRegFile.h"
#include "AggregationOuterComponentWithRegFile.h"

// Co Class
class CSumSubtract: public ISum, ISubtract
{
    private:
        long m_cRef;
        IUnknown *m_pIUnknownInner;
        IMultiplication *m_pIMultiplication;
        IDivision *m_pIDivision;
    
    public:
        // constructor
        CSumSubtract(void);
        
        // destructor
        ~CSumSubtract(void);

        // IUnknown methods
        HRESULT __stdcall QueryInterface(REFIID, void **);
        ULONG __stdcall AddRef(void);
        ULONG __stdcall Release(void);

        // ISum method
        HRESULT __stdcall SumOfTwoIntegers(int, int, int *);

        // ISubtract method
        HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *);

        // Inner Component Creation
        HRESULT __stdcall InitializeInnerComponent(void);

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
CSumSubtract::CSumSubtract(void)
{
    // code
    m_pIUnknownInner = NULL;
    m_pIMultiplication = NULL;
    m_pIDivision = NULL;
    m_cRef = 1;
    InterlockedIncrement(&glNumberOfActiveComponents);
}

// destructor
CSumSubtract::~CSumSubtract(void)
{
    // code
    InterlockedDecrement(&glNumberOfActiveComponents);
    if(m_pIMultiplication)
    {
        m_pIMultiplication->Release();
        m_pIMultiplication = NULL;
    }
    if(m_pIDivision)
    {
        m_pIDivision->Release();
        m_pIDivision = NULL;
    }
    if(m_pIUnknownInner)
    {
        m_pIUnknownInner->Release();
        m_pIUnknownInner = NULL;
    }
}

// IUnknown method Implementation
HRESULT CSumSubtract::QueryInterface(REFIID riid, void ** ppv)
{
    // code
    if(riid == IID_IUnknown)
    {
        *ppv = static_cast <ISum *>(this);
    }
    else if(riid == IID_ISum)
    {
        *ppv = static_cast <ISum *>(this);
    }
    else if(riid == IID_ISubtract)
    {
        *ppv = static_cast <ISubtract *>(this);
    }
    else if(riid == IID_IMultiplication)
    {
        return (m_pIUnknownInner->QueryInterface(riid, ppv));
    }
    else if(riid == IID_IDivision)
    {
        return (m_pIUnknownInner->QueryInterface(riid, ppv));
    }
    else
    {
        *ppv = NULL;
        return (E_NOINTERFACE);
    }

    reinterpret_cast <IUnknown *>(*ppv)->AddRef();

    return (S_OK);
}

ULONG CSumSubtract::AddRef(void)
{
    // code
    InterlockedIncrement(&m_cRef);

    return (m_cRef);
}

ULONG CSumSubtract::Release(void)
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

// ISum methods implementation
HRESULT CSumSubtract::SumOfTwoIntegers(int num1, int num2, int *pSum)
{
    // code
    *pSum = num1 + num2;

    return (S_OK);
}

// ISubtract methods implementation
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int num1, int num2, int *pSubtract)
{
    // code
    *pSubtract = num1 - num2;

    return (S_OK);
}

// Initialize Inner Compnonent
HRESULT CSumSubtract::InitializeInnerComponent(void)
{
    // local variables
    HRESULT hr;

    // code
    hr = CoCreateInstance(CLSID_MultiplicationDivision, 
                            reinterpret_cast<IUnknown *>(this), 
                            CLSCTX_INPROC_SERVER, 
                            IID_IUnknown, 
                            (void **)&m_pIUnknownInner);

    if(FAILED(hr))
    {
        MessageBox(NULL, 
                    TEXT("IUnknown Interface Cannot Be Obtained From Inner Component"), 
                    TEXT("Error"),
                    MB_OK);

        return (E_FAIL);
    }
    hr = m_pIUnknownInner->QueryInterface(IID_IMultiplication, (void **)&m_pIMultiplication);
    if(FAILED(hr))
    {
        MessageBox(NULL, 
                    TEXT("IMultiplication Interface Cannot Be Obtained From Inner Component"), 
                    TEXT("Error"),
                    MB_OK);

        m_pIUnknownInner->Release();
        m_pIUnknownInner = NULL;
        return (E_FAIL);
    }

    hr = m_pIUnknownInner->QueryInterface(IID_IDivision, (void **)&m_pIDivision);
    if(FAILED(hr))
    {
        MessageBox(NULL, 
                    TEXT("IDivision Interface Cannot Be Obtained From Inner Component"), 
                    TEXT("Error"),
                    MB_OK);
        
        m_pIUnknownInner->Release();
        m_pIUnknownInner = NULL;
        return (E_FAIL);
    }

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

// IClassFactory methods implementation      
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

    // initialize inner component
    hr = pCSumSubtract->InitializeInnerComponent();
    if(FAILED(hr))
    {
        MessageBox(NULL, 
                    TEXT("Failed to Initialize Inner Component"), 
                    TEXT("Error"),
                    MB_OK);

        pCSumSubtract->Release();
        return (hr);
    }
    
    // get the requested interface
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

