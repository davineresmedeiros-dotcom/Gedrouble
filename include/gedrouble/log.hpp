#pragma once
#include <gedrouble/loader.hpp>
namespace gedrouble {
enum class LogLevel : std::uint8_t { Info, Warning, Error };
using LogSink = void (*)(LogLevel, const char*) noexcept;
GEDROUBLE_API void setLogSink(LogSink sink) noexcept;
GEDROUBLE_API void log(LogLevel level, const char* message) noexcept;
}