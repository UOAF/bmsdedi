#define WIN32_LEAN_AND_MEAN
#include "gui.h"
#include "shared.h"
#include <windows.h>

bool render_enabled_g;

LRESULT CALLBACK debug_window_handler(HWND hwnd, UINT message, WPARAM wparam,
                                      LPARAM lparam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        if (HIWORD(wparam) == BN_CLICKED && LOWORD(wparam) == 1)
        {
            auto checked = IsDlgButtonChecked(hwnd, 1);
            if (checked)
            {
                CheckDlgButton(hwnd, 1, BST_UNCHECKED);
            }
            else
            {
                CheckDlgButton(hwnd, 1, BST_CHECKED);
            }
            render_enabled_g = not checked;
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wparam, lparam);
    }
    return 0;
}

bool register_window_class(HMODULE module)
{
    WNDCLASSEX wc;
    wc.hInstance     = module;
    wc.lpszClassName = "D3d11RenderOptions";
    wc.lpfnWndProc   = debug_window_handler;
    wc.style         = CS_DBLCLKS;
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.lpszMenuName  = NULL;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    if (!RegisterClassEx(&wc))
    {
        return false;
    }
    else
    {
        return true;
    }
}

DWORD gui_thread_entry(LPVOID module)
{
    auto dll_module = static_cast<HMODULE>(module);

    register_window_class(dll_module);
    auto hwnd = CreateWindowEx(0, "D3d11RenderOptions", "D3D11 disabler", 0,
                               CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, nullptr,
                               nullptr, dll_module, nullptr);
    CheckDlgButton(hwnd, 1, BST_CHECKED);
    ShowWindow(hwnd, true);

    CreateWindow("BUTTON",            // Predefined class; Unicode assumed
                 "Enable rendering",  // Button text
                 WS_VISIBLE | WS_CHILD | BS_CHECKBOX,  // Styles
                 10,                                   // x position
                 10,                                   // y position
                 192,                                  // Button width
                 16,                                   // Button height
                 hwnd,                                 // Parent window
                 (HMENU)1,                             // No menu.
                 dll_module,
                 NULL);  // Pointer not needed.

    CheckDlgButton(hwnd, 1, true);
    render_enabled_g = true;

    MSG message;
    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return -1;
}
