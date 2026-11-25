#include <gedrouble/loader.hpp>
#include <cassert>
int main() {
 gedrouble::Loader loader;
 assert(loader.state() == gedrouble::LoaderState::NotStarted);
 assert(loader.initialize());
 assert(loader.state() == gedrouble::LoaderState::Ready);
 assert(loader.initialize());
 loader.shutdown();
 assert(loader.state() == gedrouble::LoaderState::Stopped);
 constexpr auto v = gedrouble::Loader::version();
 static_assert(v.major == 0 && v.minor == 1 && v.patch == 0);
}