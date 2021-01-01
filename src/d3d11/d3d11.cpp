/*
    CONTRIBUTORS:
        Sean Pesce

*/

#include "d3d11_wrapper.h"
#include "shared.h"
#include <string>

namespace d3d11
{
HMODULE wrapped_dll = NULL;
FARPROC functions[func_count];

void hook_exports()
{
    char path[MAX_PATH];
    GetSystemDirectoryA(path, MAX_PATH);
    auto dll_path = std::string(path) + std::string("\\d3d11.dll");

    wrapped_dll = LoadLibraryA(dll_path.c_str());

    log_g->debug("Locating exports... ");
    size_t count = 0;
    for (size_t i = 0; i < d3d11::func_count; i++)
    {
        FARPROC func = GetProcAddress(wrapped_dll, func_names[i]);
        if (func)
        {
            count++;
        }
        functions[i] = func;
    }
    log_g->debug("Found {} out of {}.\n", count, d3d11::func_count);
}

}  // namespace d3d11
