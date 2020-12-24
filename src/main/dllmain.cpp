
/*
    CONTRIBUTORS:
        Sean Pesce
*/

#include "dllmain.h"
#include "gui.h"
#include "shared.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include <memory>

std::shared_ptr<spdlog::logger> log_g;

BOOL APIENTRY DllMain(HMODULE h_module, DWORD ul_reason_for_call,
                      LPVOID lp_reserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        auto logger = spdlog::basic_logger_mt("bmsdedi", "bmsdedi.log.txt");
        log_g       = spdlog::get("bmsdedi");
        spdlog::set_level(spdlog::level::info);
        spdlog::set_default_logger(log_g);

        auto success = dll::on_process_attach(h_module, lp_reserved);
        if (not success)
        {
            return success;
        }

        auto result = CreateThread(0, NULL, gui_thread_entry,
                                   static_cast<LPVOID>(h_module), NULL, NULL);
        return SUCCEEDED(result);
        break;
    }

    case DLL_THREAD_ATTACH:
    {
        return dll::on_thread_attach(h_module, lp_reserved);
        break;
    }

    case DLL_THREAD_DETACH:
    {
        return dll::on_thread_detach(h_module, lp_reserved);
        break;
    }

    case DLL_PROCESS_DETACH:
    {
        return dll::on_process_detach(h_module, lp_reserved);
        break;
    }
    }
    return TRUE;
}