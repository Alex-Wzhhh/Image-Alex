#include "wsi_reader.hpp"
#include <openslide/openslide.h>
#include <stdexcept>
#include <iostream>

namespace wsi {

Reader::Reader(const std::string& path) {
    slide_ = openslide_open(path.c_str());
    if (!slide_ || openslide_get_error(slide_) != nullptr) {
        if (slide_) openslide_close(slide_);
        slide_ = nullptr;
    }
}

Reader::~Reader() {
    if (slide_) openslide_close(slide_);
}

bool Reader::ok() const {
    return slide_ && (openslide_get_error(slide_) == nullptr);
}

std::pair<int64_t,int64_t> Reader::level0Size() const {
    int64_t w=0, h=0;
    if (slide_) openslide_get_level0_dimensions(slide_, &w, &h);
    return {w, h};
}

std::vector<uint8_t> Reader::readRegionBGRA(int64_t x, int64_t y, int level,
                                            int64_t w, int64_t h, int64_t& stride) const {
    stride = w * 4; // BGRA
    std::vector<uint8_t> buf(static_cast<size_t>(stride * h));
    if (slide_) {
        openslide_read_region(slide_, reinterpret_cast<uint32_t*>(buf.data()),
                              x, y, level, w, h);
    }
    return buf;
}

} // namespace wsi
