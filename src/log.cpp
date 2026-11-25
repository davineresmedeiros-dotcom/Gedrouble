#include <gedrouble/log.hpp>
#include <cstdio>
namespace gedrouble {
namespace {
LogSink g_sink = nullptr;
const char* levelName(LogLevel level) noexcept {
 switch (level) {
  case LogLevel::Info: return "INFO";
  case LogLevel::Warning: return "WARN";
  case LogLevel::Error: return "ERROR";
 }
 return "UNKNOWN";
}
}
void setLogSink(LogSink sink) noexcept { g_sink = sink; }
void log(LogLevel level, const char* message) noexcept {
 if (!message) message = "(null)";
 if (g_sink) { g_sink(level, message); return; }
 std::fprintf(stderr, "[Gedrouble][%s] %s\n", levelName(level), message);
}
}