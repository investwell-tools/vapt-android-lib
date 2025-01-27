package com.scottyab.rootbeer.sample;

import java.io.OutputStream;
import java.io.PrintStream;

public class SilentPrintStream extends PrintStream {
    public SilentPrintStream() {
        super(new OutputStream() {
            @Override
            public void write(int b) {
                // Do nothing
            }
        });

        new PrintDisable();
    }

}