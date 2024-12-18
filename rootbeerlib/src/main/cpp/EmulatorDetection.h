//
// Created by investwell on 17/12/24.
//

#ifndef ROOTCHECKER_EMULATORDETECTION_H
#define ROOTCHECKER_EMULATORDETECTION_H

#endif //ROOTCHECKER_EMULATORDETECTION_H

#pragma once

#include <sys/system_properties.h>
#include <jni.h>
#include <string>
#include <vector>
#include <android/log.h>

//#include "emu/FileHelper.h"
//#include "emu/EmulatorData.h"

namespace EmulatorDetection
{
    extern std::vector<std::string> detections;

    void checkHardwareProps();
    void checkMounts();
    void checkCPUInfo();
    void checkSystemFiles();
    void checkCPUArchitecture();
    void checkArmTranslation();
    void findEmulatorMemory();

    bool isDetected();
    std::string getResult();
}
