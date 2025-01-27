package com.scottyab.rootbeer.sample

import java.io.PrintStream
import java.io.PrintWriter
import java.util.Locale

class PrintDisable(): Exception() {

    override fun printStackTrace() {
//        super.printStackTrace()
    }

    override fun printStackTrace(s: PrintStream) {
//        super.printStackTrace(s)
    }

    override fun printStackTrace(s: PrintWriter) {
//        super.printStackTrace(s)
    }
}