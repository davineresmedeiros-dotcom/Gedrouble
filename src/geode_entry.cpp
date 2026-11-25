#include <Geode/Geode.hpp>
#include <gedrouble/loader.hpp>

using namespace geode::prelude;

namespace {
gedrouble::Loader g_loader;
}

$on_mod(Loaded) {
    if (!g_loader.initialize()) {
        log::error("Gedrouble Core initialization failed");
    } else {
        log::info("Gedrouble Core initialized through Geode");
    }
}

$on_mod(Unloaded) {
    g_loader.shutdown();
}
