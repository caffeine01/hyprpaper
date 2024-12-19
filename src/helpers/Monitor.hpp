#pragma once

#include "../defines.hpp"
#include "../render/LayerSurface.hpp"
#include "PoolBuffer.hpp"
#include "protocols/wayland.hpp"

struct SMonitor {
    std::string                                 name        = "";
    std::string                                 description = "";
    SP<CCWlOutput>                              output;
    uint32_t                                    wayland_name = 0;
    Vector2D                                    size;
    int                                         scale;
    wl_output_transform                         transform = WL_OUTPUT_TRANSFORM_NORMAL;

    bool                                        readyForLS = false;
    bool                                        hasATarget = true;

    bool                                        wildcard = true;

    uint32_t                                    configureSerial = 0;
    SPoolBuffer                                 buffer;

    bool                                        wantsReload = false;
    bool                                        wantsACK    = false;
    bool                                        initialized = false;

    std::vector<std::unique_ptr<CLayerSurface>> layerSurfaces;
    CLayerSurface*                              pCurrentLayerSurface = nullptr;

    void                                        registerListeners();
};