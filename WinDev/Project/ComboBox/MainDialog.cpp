#include "Source.h"
#include "resource.h"

extern HWND ghwnd;
#define ID_COMPONENT(HANDLE, ID) GetDlgItem(HANDLE, ID)
TCHAR Education[][50] =
{
	TEXT("B.E"),
	TEXT("B.Sc. Comp. Sci."),
	TEXT("B.C.A"),
	TEXT("M.E"),
	TEXT("M.Sc. Comp. Sci."),
	TEXT("M.C.A")
};

TCHAR A[50];

static void AddItemInCombobox(TCHAR[][50], HWND hDlg, int id)
{
	// code
	// memset(&A, 0, sizeof(A));
	
	for (int k = 0; k <= 5; k ++)
	{
		wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)Education[k]);
		// SendMessage(ID_COMPONENT(hDlg, id), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
		SendMessage(ID_COMPONENT(hDlg, id), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)(A + k));
		// SendMessage(ID_COMPONENT(hDlg, id), CB_SETCURSEL, (WPARAM)k, (LPARAM)k);
	}
	SendMessage(ID_COMPONENT(hDlg, id), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	
}

void InitGroupList(HWND hDlg)
{
	TCHAR achTemp[256];
	DWORD dwIndex;

	// Get the handle of the food groups combo box.
	HWND hwndGroupsBox = GetDlgItem(hDlg, IDC_COMBO_EDUCATION);

	// LoadString(NULL, IDS_BREAD, achTemp, sizeof(achTemp) / sizeof(TCHAR));
	dwIndex = SendMessage(hwndGroupsBox, CB_ADDSTRING, 0, (LPARAM)achTemp);
	SendMessage(hwndGroupsBox, CB_SETITEMDATA, dwIndex, (LPARAM)0);
	/*
	//LoadString(NULL, IDS_BREAD, achTemp, sizeof(achTemp) / sizeof(TCHAR));
	dwIndex = SendMessage(hwndGroupsBox, CB_ADDSTRING, 0, (LPARAM)achTemp);
	SendMessage(hwndGroupsBox, CB_SETITEMDATA, dwIndex, (LPARAM)0);

	//LoadString(NULL, IDS_BREAD, achTemp, sizeof(achTemp) / sizeof(TCHAR));
	dwIndex = SendMessage(hwndGroupsBox, CB_ADDSTRING, 0, (LPARAM)achTemp);
	SendMessage(hwndGroupsBox, CB_SETITEMDATA, dwIndex, (LPARAM)0);

	//LoadString(NULL, IDS_BREAD, achTemp, sizeof(achTemp) / sizeof(TCHAR));
	dwIndex = SendMessage(hwndGroupsBox, CB_ADDSTRING, 0, (LPARAM)achTemp);
	SendMessage(hwndGroupsBox, CB_SETITEMDATA, dwIndex, (LPARAM)0);
	*/
	return;
}

BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		// Initialize the food groups combo box and select the first item.
		InitGroupList(hDlg);
		SendDlgItemMessage(hDlg, IDC_COMBO_EDUCATION, CB_SETCURSEL, 0, 0);

		return (INT_PTR)TRUE;

	case WM_PAINT:
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			PostQuitMessage(0);
			//break;

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

