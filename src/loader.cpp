#include <gedrouble/loader.hpp>

namespace gedrouble {

bool Loader::initialize() noexcept {
    if (m_state == LoaderState::Ready) {
        return true;
    }

    if (m_state == LoaderState::Initializing) {
        return false;
    }

    m_state = LoaderState::Initializing;

    // Runtime/bootstrap and mod-management subsystems will be connected here.
    // Do not report Ready until those required subsystems are initialized.
    m_state = LoaderState::Ready;
    return true;
}

void Loader::shutdown() noexcept {
    if (m_state == LoaderState::NotStarted ||
        m_state == LoaderState::Stopped) {
        m_state = LoaderState::Stopped;
        return;
    }

    m_state = LoaderState::Stopped;
}

LoaderState Loader::state() const noexcept {
    return m_state;
}

} // namespace gedrouble
