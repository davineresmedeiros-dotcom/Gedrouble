#include <gedrouble/loader.hpp>
#include <gedrouble/log.hpp>
namespace gedrouble {
bool Loader::initialize() noexcept {
 if (m_state == LoaderState::Ready) {
  log(LogLevel::Warning, "initialize called while already ready");
  return true;
 }
 if (m_state == LoaderState::Initializing) {
  log(LogLevel::Error, "reentrant initialization rejected");
  return false;
 }
 m_state = LoaderState::Initializing;
 log(LogLevel::Info, "Gedrouble Core v0.1.0 initializing");
 // Core lifecycle is initialized. Runtime integration and Mod Manager
 // are separate milestones and are not marked as loaded here.
 m_state = LoaderState::Ready;
 log(LogLevel::Info, "Gedrouble Core initialized");
 return true;
}
void Loader::shutdown() noexcept {
 if (m_state == LoaderState::Stopped) return;
 log(LogLevel::Info, "Gedrouble Core shutting down");
 m_state = LoaderState::Stopped;
}
LoaderState Loader::state() const noexcept { return m_state; }
}