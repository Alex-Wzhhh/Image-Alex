#include "wsi_reader.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: wsi_demo <slide.svs>\n";
        return 1;
    }

    wsi::Reader r(argv[1]);
    if (!r.ok()) {
        std::cerr << "OpenSlide open failed.\n";
        return 2;
    }

    auto [w, h] = r.level0Size();
    std::cout << "Level-0 size: " << w << " x " << h << "\n";
    return 0;
}
