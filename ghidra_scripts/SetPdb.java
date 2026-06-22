// Points Ghidra's PDB analyzer at a specific local PDB file.
//@category Analysis

import ghidra.app.plugin.core.analysis.PdbUniversalAnalyzer;
import ghidra.app.script.GhidraScript;
import java.io.File;

public class SetPdb extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) throw new IllegalArgumentException("PDB path required");
        PdbUniversalAnalyzer.setPdbFileOption(currentProgram, new File(args[0]));
    }
}
