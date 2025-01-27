package com.rootchecker.service;

import com.rootchecker.service.util.QLog;

public class RootBeerNative {

    private static boolean libraryLoaded = false;
    /**
     * Loads the C/C++ libraries statically
     */
    static {
        try {
            System.loadLibrary("toolChecker");
            libraryLoaded = true;
        } catch (UnsatisfiedLinkError e) {
            QLog.e(e);
        }
    }

    public boolean wasNativeLibraryLoaded() {
        return libraryLoaded;
    }
    public void handleException(Exception e){
        if (isLoggingEnabled()) {
            System.out.println("lax Execption");
            clearLogs();
            e.printStackTrace();
        }
    }
    private native boolean isLoggingEnabled();

    public native int checkForRoot(Object[] pathArray);

    public native int setLogDebugMessages(boolean logDebugMessages);

    public native boolean isDetected();
    public native String getResult();
    public native void setLoggingEnabled(boolean isEnabled);
    public native void removeLogs(String remove);
    public native void logMessage(String remove);
    public native void clearLogs();
}
