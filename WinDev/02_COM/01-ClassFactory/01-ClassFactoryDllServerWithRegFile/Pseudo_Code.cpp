HRESULT __stdcall CoCreateInstance(REFCLSID rclsid, 
                                    LPIUNKNOWN pUnkOuter, 
                                    DWORD dwClsContext, 
                                    REFIID riid, 
                                    void **ppv)
{
    // variable declarations
    IClassFactory *pIClassFactory = NULL;
    HRESULT hr;

    // code
    hr = CoGetClassObject(rclsid, 
                            dwClsContext, 
                            NULL, 
                            IID_IClassFactory, 
                            (void **)&pIClassFactory);

    /*  INTERNALLY CALLS CoLoadLibrary(LPOLESTR , BOOL)     */
    /*                                                      */
    /*  CoLoadLibrary() INTERNALLY CALLS LoadLibrary()      */

    if(SUCCEEDED(hr))
    {
        pIClassFactory->CreateInstance(pUnkOuter, riid, ppv);
        pIClassFactory->Release();
    }

    return (hr);
}
