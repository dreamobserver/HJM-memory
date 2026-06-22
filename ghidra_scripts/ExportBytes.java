// Dumps bytes from a program address for protocol/data inspection.
//@category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

public class ExportBytes extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Address start = toAddr(args[0]);
        int length = Integer.decode(args[1]);
        byte[] bytes = new byte[length];
        currentProgram.getMemory().getBytes(start, bytes);
        for (int i = 0; i < bytes.length; i += 16) {
            StringBuilder hex = new StringBuilder();
            StringBuilder ascii = new StringBuilder();
            for (int j = 0; j < 16 && i + j < bytes.length; j++) {
                int b = bytes[i + j] & 0xff;
                hex.append(String.format("%02x ", b));
                ascii.append(b >= 32 && b < 127 ? (char)b : '.');
            }
            println(start.add(i) + "  " + String.format("%-48s", hex) + " " + ascii);
        }
    }
}
