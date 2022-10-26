inline BOOL operator==(const GUID& guidOne, const GUID& guidTwo)
{
    return (IsEqualGUID(guidOne, guidTwo));
}
