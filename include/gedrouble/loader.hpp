#pragma once

#include <cstdint>

#if defined(_WIN32)
#  if defined(GEDROUBLE_LOADER_BUILD)
#    define GEDROUBLE_API __declspec(dllexport)
#  else
#    define GEDROUBLE_API __declspec(dllimport)
#  endif
#else
#  define GEDROUBLE_API __attribute__((visibility("default")))
#endif

namespace gedrouble {

enum class LoaderState : std::uint8_t {
    NotStarted,
    Initializing,
    Ready,
    Stopped,
    Failed
};

/**
 * Entry point for Gedrouble's native loader core.
 *
 * This is a loader-core lifecycle scaffold only. Platform bootstrap,
 * Geometry Dash runtime integration, and mod loading are separate components
 * and are not implemented by this class yet.
 */
class GEDROUBLE_API Loader {
public:
    bool initialize() noexcept;
    void shutdown() noexcept;
    LoaderState state() const noexcept;

private:
    LoaderState m_state = LoaderState::NotStarted;
};

} // namespace gedrouble
