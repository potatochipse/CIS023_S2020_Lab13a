// Module:	CIS023_S2020_Lab13a Miguel Antonio Logarta.cpp
// Author:	Miguel Antonio Logarta
// Date:	March 9, 2020
// Purpose:	Create a class with overloaded methods
//			Learn how to convert a hexadecimal number string to a decimal-based integer
//			Learn how to convert an integer to a hexadecimal number string


#include "CIS023_S2020_Lab13a Miguel Antonio Logarta.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hWnd_Input_1;								// hex input
HWND hWnd_Input_2;								// integer input
HWND hWnd_Output_1;								// integer ouptut
HWND hWnd_Output_2;								// hex output
HWND hWnd_btnHextoInt;							// convert button
HWND hWnd_btnInttoHex;							// other convert button

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CIS023S2020LAB13AMIGUELANTONIOLOGARTA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023S2020LAB13AMIGUELANTONIOLOGARTA));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023S2020LAB13AMIGUELANTONIOLOGARTA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW);					 // Gray background +0
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CIS023S2020LAB13AMIGUELANTONIOLOGARTA);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 500, 150, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case BN_CLICKED:
				if (LOWORD(lParam) == (WORD)hWnd_btnHextoInt)		// Top button
				{
					TCHAR szInput[100];								// User input
					int iConverted = 0;								// Hex to int conversion
					TCHAR szOutput[100];							// For output control

					GetWindowText(									// Get user input
						hWnd_Input_1,								// Input edit control
						szInput,									// Destination TCHAR
						100);										// Size of destination TCHAR

					// Convert user input to hex
					HexClass HexObj;								// Default constructor
					iConverted = HexObj.Convert(szInput);
					// Output converted text
					_stprintf_s(									// Convert int to TCHAR
						szOutput,									// Output TCHAR
						TEXT("%i"),									// Conversion mask
						iConverted);								// Source integer

					// Display results
					SetWindowText(									// Output text
						hWnd_Output_1,								// Handle to output label
						szOutput);									// Output TCHAR

					int i = 0;
				}
				if (LOWORD(lParam) == (WORD)hWnd_btnInttoHex)		// Bottom button
				{
					TCHAR szInput[100];								// User input
					int iInput = 0;									// Int to hexconversion
					TCHAR szHex[100];								// For output control

					GetWindowText(
						hWnd_Input_2,								// Input edit control
						szInput,									// Destination TCHAR
						100);										// Size of destination TCHAR

					// Convert user input to integer
					iInput = _tstoi(szInput);						// Convert TCHAR to int

					// Convert user input to hex
					HexClass HexObj;								// Create object
					HexObj.Convert(iInput);							

					_tcscpy_s(										// Copy TCHARs
						szHex,										// Destination TCHAR
						100,										// Size of destination TCHAR
						HexObj.Convert(iInput));					// Return value from Convert() method

					// Display converted value
					SetWindowText(									// Set window text
						hWnd_Output_2,								// Output label
						szHex);										// Output TCHAR

					int i = 0;
				}
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CREATE:
		{

			// create prompts
			CreateWindow(TEXT("STATIC"),
				TEXT("Enter Hex Number:"),
				WS_VISIBLE | WS_CHILD,
				10, 15, 150, 20, hWnd, NULL, NULL, NULL);

			CreateWindow(TEXT("STATIC"),
				TEXT("Enter Integer:"),
				WS_VISIBLE | WS_CHILD,
				10, 55, 150, 20, hWnd, NULL, NULL, NULL);

			// create edit controls for user input
			hWnd_Input_1 = CreateWindow(TEXT("EDIT"),
				NULL,
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
				160, 15, 60, 20, hWnd, NULL, NULL, NULL);

			// create edit control for user input
			hWnd_Input_2 = CreateWindow(TEXT("EDIT"),
				NULL,
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER,
				160, 55, 60, 20, hWnd, NULL, NULL, NULL);

			// create output lines
			hWnd_Output_1 = CreateWindow(TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				375, 15, 100, 20, hWnd, NULL, NULL, NULL);

			hWnd_Output_2 = CreateWindow(TEXT("STATIC"),
				TEXT(""),
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				375, 55, 100, 20, hWnd, NULL, NULL, NULL);

			// create Show button
			hWnd_btnHextoInt = CreateWindow(TEXT("BUTTON"),
				TEXT("Convert"),
				WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				250, 10, 90, 30, hWnd, NULL, NULL, NULL);

			hWnd_btnInttoHex = CreateWindow(TEXT("BUTTON"),
				TEXT("Convert"),
				WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				250, 50, 90, 30, hWnd, NULL, NULL, NULL);


		}
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
