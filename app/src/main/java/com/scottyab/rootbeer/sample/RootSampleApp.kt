package com.scottyab.rootbeer.sample

import android.app.Application
import android.os.Build
import android.os.StrictMode
import com.rootchecker.service.RootBeerNative
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import uk.co.barbuzz.beerprogressview.BuildConfig

class RootSampleApp : Application() {
    val scope = CoroutineScope(Dispatchers.IO)
    override fun onCreate() {
        super.onCreate()
        //Timber.plant(Timber.DebugTree())
        System.setOut(SilentPrintStream())
        System.setErr(SilentPrintStream())

//        System.setErr(PrintDisable())

        if (BuildConfig.DEBUG) {
            //initStrictMode()
        }

      // loadNativeLib()

    }

    companion object{

    }
    private fun loadNativeLib(){
        val rootBeerNative = RootBeerNative()
        // Disable logging globally
        rootBeerNative.setLoggingEnabled(false) // Set to false to disable logs
        // Example of calling removeLogs (this will not log anything)
        rootBeerNative.removeLogs("This message won't be logged.")
    }
    private fun initStrictMode() {
        StrictMode.setThreadPolicy(
            StrictMode.ThreadPolicy
                .Builder()
                .detectDiskWrites()
                .detectNetwork()
                .penaltyLog()
                .penaltyDeathOnNetwork()
                .build(),
        )

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            StrictMode.setVmPolicy(
                StrictMode.VmPolicy
                    .Builder()
                    .detectNonSdkApiUsage()
                    .detectCleartextNetwork()
                    .penaltyLog()
                    .build(),
            )
        }
    }
}
