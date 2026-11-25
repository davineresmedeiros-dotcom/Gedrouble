#pragma once
#include <cstdint>
#if defined(_WIN32)
# if defined(GEDROUBLE_LOADER_BUILD)
#  define GEDROUBLE_API __declspec(dllexport)
# else
#  define GEDROUBLE_API __declspec(dllimport)
# endif
#else
# define GEDROUBLE_API __attribute__((visibility("default")))
#endif
namespace gedrouble {
struct Version { std::uint16_t major, minor, patch; };
enum class LoaderState : std::uint8_t { NotStarted, Initializing, Ready, Stopped, Failed };
class GEDROUBLE_API Loader {
public:
 bool initialize() noexcept;
 void shutdown() noexcept;
 LoaderState state() const noexcept;
 static constexpr Version version() noexcept { return {0, 1, 0}; }
private:
 LoaderState m_state = LoaderState::NotStarted;
};
}