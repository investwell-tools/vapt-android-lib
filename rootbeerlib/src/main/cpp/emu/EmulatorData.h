//
// Created by investwell on 17/12/24.
//
//
//#ifndef ROOTCHECKER_EMULATORDATA_H
//#define ROOTCHECKER_EMULATORDATA_H
//
//#endif //ROOTCHECKER_EMULATORDATA_H

//#ifndef FILE_HELPER_H  // Include guard to prevent multiple inclusions
#define FILE_HELPER_H

//#include <vector>     // Include for std::vector
//#include <string>

namespace EmulatorData {
    inline std::vector<std::string> emulatorFiles {
            "fstab.andy",
            "ueventd.andy.rc",
            "fstab.nox",
            "init.nox.rc",
            "ueventd.nox.rc",
            "dev/socket/qemud",
            "dev/qemu_pipe",
            "/dev/memufp",
            "/dev/memuguest",
            "/dev/memuuser",
            "/system/lib/memuguest.ko",
            "/system/bin/nox-prop",
            "/system/bin/noxd",
            "/system/lib/libnoxd.so",
            "/system/priv-app/com.bluestacks.bstfolder.apk",
            "/dev/bst_gps",
            "/dev/bst_ime",
            "/dev/bstgyro",
            "/dev/bstmegn",
            "/system/xbin/phoenix_compat",
            "/data/system/phoenixlog.addr",
            "/system/phoenixos",
            "/system/lib/libnoxspeedup.so",
            "/system/etc/init.nox.sh",
            "/system/bin/nox",
            "/system/lib/hw/gps.ld.so",
            "/system/lib/hw/sensors.ld.so",
            "/system/lib/libldutils.so",
            "/system/bin/ldinit",
            "/system/app/LDAppStore/LDAppStore.apk",
            "/data/data/com.ldmnq.launcher3/files/launcher.preferences",
            "/data/.bluestacks.prop",
            "/data/.bstconf.prop",
            "/mnt/windows",
            "/mnt/windows/BstSharedFolder",
            "/lib/vboxguest.ko",
            "/lib/vboxsf.ko",
            "/data/data/com.bluestacks.bstfolder",
            "/data/data/com.bluestacks.appmart",
            "/data/data/com.bluestacks.home",
            "/data/data/com.bluestacks.launcher",
            "/system/bin/bstfolder",
            "/system/bin/bstfolderd",
            "/system/bin/bstsyncfs",
            "/sys/module/bstsensor",
            "/sys/module/bstpgaipc",
            "/system/xbin/bstk/su",
            "/system/xbin/bstk",
            "/sys/module/mg",
            "/system/bin/nox-vbox-sf",
            "/system/bin/ldinit",
            "/system/app/LDAppStore/LDAppStore.apk",
            "/data/data/com.android.ld.appstore",
            "/data/data/com.koplay.launcher",
            "/system/bin/KOPLAYER.ini",
            "/system/bin/androidVM-vbox-sf",
            "/sys/module/vboxpcismv",
            "/sys/module/nemusf",
            "/system/bin/genybaseband",
            "/system/bin/droid4x-vbox-sf",
            "/system/bin/droid4x",
            "/sys/module/vboxsf",
            "/sys/module/bstpgaipc",
            "/system/xbin/bstk/su",
            "/system/xbin/bstk",
            "/sys/module/msf",
    };

    inline std::vector<std::string> newEmulatorFiles {
            "/system/bin/ldinit",
            "/system/bin/ldmountsf",
            "/system/bin/bstsvcmgrtest",
            "/system/bin/bstshutdown",
            "/system/bin/bstsyncfs",
            "/system/bin/bstime",
            "/system/bin/bstfolder",
            "/system/bin/bstshutdown_core",
            "/boot/bstmods/bstpgaipc.ko",
            "/boot/bstmods/bstaudio.ko",
            "/boot/bstmods/bstcamera.ko",
            "/boot/bstmods/bstvmsg.ko",
            "/boot/bstmods/bstinput.ko",
            "/boot/bstsetup.env",
            "/boot/bin/bstreport",
            "/boot/bin/bstconf",
            "/boot/bstsetconf.sh",
            "/system/bin/nox-prop",
            "/system/bin/nox-vbox-sf",
            "/system/bin/noxd",
            "/system/lib/libnoxd.so",
            "/system/lib/libnoxspeedup.so",
    };

    inline std::vector<std::string> products {
            "sdk",
            "andy",
            "google_sdk",
            "droid4x",
            "nox",
            "sdk_x86",
            "vbox86p",
            "emu64x",
    };

    inline std::vector<std::string> manufacturers {
            "sdk",
            "andy",
            "google_sdk",
            "droid4x",
            "nox",
            "sdk_x86",
            "vbox86p",
    };

    inline std::vector<std::string> deviceInfo {
            "generic",
            "andy",
            "droid4x",
            "nox",
            "generic_x86_64",
            "vbox86p",
            "emu64x",
    };

    inline std::vector<std::string> hardwares {
            "goldfish",
            "vbox86",
            "nox",
            "VM_x86",
            "intel",
            "amd",
            "x86",
    };
}