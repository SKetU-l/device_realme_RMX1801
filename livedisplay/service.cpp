/*
 * Copyright (C) 2023 The LineageOS Project
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

#define LOG_TAG "vendor.lineage.livedisplay@2.0-service.RMX1801"

#include <android-base/logging.h>
#include <binder/ProcessState.h>
#include <hidl/HidlTransportSupport.h>

#include "AdaptiveBacklight.h"

using ::vendor::lineage::livedisplay::V2_0::IAdaptiveBacklight;
using ::vendor::lineage::livedisplay::V2_0::implementation::AdaptiveBacklight;

int main() {
    android::sp<IAdaptiveBacklight> adaptiveBacklight = new AdaptiveBacklight();

    android::hardware::configureRpcThreadpool(1, true /*callerWillJoin*/);

    if (adaptiveBacklight->registerAsService() != android::OK) {
        LOG(ERROR) << "Cannot register adaptive backlight HAL service.";
        return 1;
    }

    LOG(INFO) << "LiveDisplay HAL service is ready.";

    android::hardware::joinRpcThreadpool();

    LOG(ERROR) << "LiveDisplay HAL service failed to join thread pool.";
    return 1;
}
