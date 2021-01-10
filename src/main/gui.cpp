#define WIN32_LEAN_AND_MEAN

#include "bms/IVibeData.h"

#include "gui.h"
#include "shared.h"

#include <windows.h>

std::atomic_bool render_enabled_g;

namespace {

const int AUTO_ID = 101;
const int FORCE_ON_ID = 102;
const int FORCE_OFF_ID = 103;

const int TIMER_ID = 105;

bool in3D()
{
    static HANDLE mapping = nullptr;
    static HANDLE view = nullptr;
    if (mapping == nullptr)
    {
        mapping = OpenFileMapping(FILE_MAP_READ, FALSE, "FalconIntellivibeSharedMemoryArea");
        // MapViewOfFile fails gracefully if mapping is null.
        view = MapViewOfFile(mapping, FILE_MAP_READ, 0, 0, 0);
    }
    if (view == nullptr) return false; // Opening the shared memory failed.

    auto ptr = reinterpret_cast<volatile IntellivibeData*>(view);
    return ptr->In3D;
}

void timerDispatch(HWND hwnd)
{
    bool should_render = false;
    if (IsDlgButtonChecked(hwnd, AUTO_ID) == BST_CHECKED)
    {
        should_render = !in3D();
    }
    else
    {
        should_render = IsDlgButtonChecked(hwnd, FORCE_ON_ID) == BST_CHECKED;
    }
    render_enabled_g.store(should_render, std::memory_order_release);
}

LRESULT CALLBACK debug_window_handler(HWND hwnd, UINT message, WPARAM wparam,
                                      LPARAM lparam)
{
    switch (message)
    {
    case WM_TIMER:
        timerDispatch(hwnd);
        break;

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
    memset(&wc, 0, sizeof(wc));
    wc.hInstance     = module;
    wc.lpszClassName = "D3d11RenderOptions";
    wc.lpfnWndProc   = debug_window_handler;
    wc.style         = CS_DBLCLKS;
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm       = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszMenuName  = nullptr;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    return RegisterClassEx(&wc);
}

} // anonymous namespace

DWORD gui_thread_entry(LPVOID module)
{
    auto dll_module = static_cast<HMODULE>(module);

    register_window_class(dll_module);
    auto hwnd = CreateWindowEx(0, "D3d11RenderOptions", "D3D11 disabler", 0,
                               CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, nullptr,
                               nullptr, dll_module, nullptr);
    ShowWindow(hwnd, true);

    CreateWindow(
        "BUTTON", // Predefined class; Unicode assumed
        "Auto", // Button text
        WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, // Styles
        10, // x position
        10, // y position
        192, // Button width
        16, // Button height
        hwnd, // Parent window
        (HMENU)AUTO_ID,
        dll_module,
        nullptr);  // Pointer not needed.

    CreateWindow(
        "BUTTON", // Predefined class; Unicode assumed
        "Force Rendering Enabled", // Button text
        WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, // Styles
        10, // x position
        30, // y position
        192, // Button width
        16, // Button height
        hwnd, // Parent window
        (HMENU)FORCE_ON_ID,
        dll_module,
        nullptr);  // Pointer not needed.

    CreateWindow(
        "BUTTON", // Predefined class; Unicode assumed
        "Force Rendering Disabled", // Button text
        WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, // Styles
        10, // x position
        50, // y position
        192, // Button width
        16, // Button height
        hwnd, // Parent window
        (HMENU)FORCE_OFF_ID,
        dll_module,
        nullptr);  // Pointer not needed.

    SetTimer(hwnd, TIMER_ID, 1000, (TIMERPROC)nullptr);

    CheckDlgButton(hwnd, AUTO_ID, BST_CHECKED);
    render_enabled_g = true;

    MSG message;
    while (GetMessage(&message, nullptr, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return -1;
}
