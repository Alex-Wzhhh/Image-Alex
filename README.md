# Image-Alex
预先写一些图像识别相关代码
                          
# WSIPrototype (OpenSlide + OpenCV + CMake)

在云端（GitHub Codespaces / Gitpod）直接编译运行 C++，预装 `libopenslide-dev` 与 `libopencv-dev`。
代码结构与 Qt 解耦，后续可直接在本地 Qt 项目中链接使用。

## 一键启动（推荐 Codespaces）
1. 将本仓库放到 GitHub。
2. 打开仓库页面 → `Code` → `Create codespace on main`。
3. 等待容器初始化完成（devcontainer 会自动安装依赖）。

## 构建与运行
```bash
cmake -S . -B build -G Ninja
cmake --build build -j
# 需要自备一张 WSI，例如 /workspaces/WSIPrototype/example.svs
./build/wsi_demo /workspaces/WSIPrototype/example.svs
