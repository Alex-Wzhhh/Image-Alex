#pragma once
#include <string>
#include <utility>
#include <cstdint>
#include <vector>

// 不暴露第三方头到接口，保持与 Qt 解耦
struct _openslide; // openslide_t 前置声明
using openslide_t = _openslide;

namespace wsi {

class Reader {
public:
    explicit Reader(const std::string& path);
    ~Reader();

    bool ok() const;
    std::pair<int64_t,int64_t> level0Size() const;

    // 读取 BGRA 区域数据，返回行主序缓冲；Qt 可用 QImage::Format_BGRA8888 直接构造
    std::vector<uint8_t> readRegionBGRA(int64_t x, int64_t y, int level,
                                        int64_t w, int64_t h, int64_t& stride) const;

private:
    openslide_t* slide_{};
};

} // namespace wsi
