/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_LAYER_BF_H
#define ANDROID_LAYER_BF_H

#include <stdint.h>
#include <sys/types.h>
#include <cutils/sockets.h>

#include "Layer.h"

// ---------------------------------------------------------------------------

namespace android {

class LayerBF : public Layer
{
public:
                LayerBF(SurfaceFlinger* flinger, const sp<Client>& client,
                        const String8& name, uint32_t w, uint32_t h, uint32_t flags);
        virtual ~LayerBF();

    virtual const char* getTypeId() const { return "LayerBF"; }
    /*
    * latchBuffer - called each time the screen is redrawn and returns whether
    * the visible regions need to be recomputed (this is a fairly heavy
    * operation, so this should be set only if needed). Typically this is used
    * to figure out if the content or size of a surface has changed.
    *///    Region latchBuffer(bool& recomputeVisibleRegions);
    virtual Region latchBuffer(bool& recomputeVisibleRegions);
	
    virtual void onLayerDisplayed(const sp<const DisplayDevice>& hw,
            HWComposer::HWCLayerInterface* layer);
protected:
    void onFirstRef();
    virtual void onFrameAvailable(const BufferItem& item);
private:
    uint32_t mFirstCall;	
    Region mDirtyRegion;
    int32_t mSock;	
};

// ---------------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_LAYER_BF_H
