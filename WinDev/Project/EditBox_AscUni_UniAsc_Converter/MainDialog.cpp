#include "Source.h"
#include "resource.h"
#include "CommonlyUsedFunctions.h"

extern HWND ghwnd;

TCHAR Education[][50] =
{
	TEXT("B.E"),
	TEXT("B.Sc. Comp. Sci."),
	TEXT("B.C.A"),
	TEXT("M.E"),
	TEXT("M.Sc. Comp. Sci."),
	TEXT("M.C.A")
};

TCHAR strName[255];

BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		ShowWindow(hDlg, SW_NORMAL);

		return TRUE;

	case WM_PAINT:
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, strName, 50);
			MessageBox(ghwnd, strName, TEXT("Name = "), MB_OK);

			// FileIO((char*)"Debug.txt",(wchar_t*)TEXT("Rama Vijay Gokhale"));
			FileIO((char*)"./Debug.txt", strName);

			PostQuitMessage(0);
			break;

		case IDCANCEL:
			EndDialog(hDlg, 0);
			PostQuitMessage(0);
			break;

		default:
			break;
		}
		break;
	}
	return FALSE;
}

