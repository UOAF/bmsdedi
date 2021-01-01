#pragma once

#include "spdlog/spdlog.h"

#include <atomic>

extern std::shared_ptr<spdlog::logger> log_g;
extern std::atomic_bool render_enabled_g;

inline bool shouldRender()
{
    return render_enabled_g.load(std::memory_order_acquire);
}
