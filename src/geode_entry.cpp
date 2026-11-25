#include <Geode/Geode.hpp>
#include <gedrouble/loader.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    static gedrouble::Loader loader;
    if (!loader.initialize()) {
        log::error("Gedrouble Core initialization failed");
    } else {
        log::info("Gedrouble Core initialized through Geode");
    }
}

$on_mod(Unloaded) {
    // Geode owns this integration's lifecycle. Core shutdown is handled by
    // the host when the integration is unloaded.
}
