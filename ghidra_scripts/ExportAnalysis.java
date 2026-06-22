// Exports a compact static-analysis report and decompiled C for a Ghidra program.
//@category Analysis

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Program;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.File;
import java.io.PrintWriter;

public class ExportAnalysis extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) throw new IllegalArgumentException("output directory required");
        File outDir = new File(args[0]);
        outDir.mkdirs();

        Program p = currentProgram;
        try (PrintWriter w = new PrintWriter(new File(outDir, "summary.txt"), "UTF-8")) {
            w.println("Name: " + p.getName());
            w.println("Executable format: " + p.getExecutableFormat());
            w.println("Language: " + p.getLanguageID());
            w.println("Compiler: " + p.getCompilerSpec().getCompilerSpecID());
            w.println("Image base: " + p.getImageBase());
            w.println("Min address: " + p.getMinAddress());
            w.println("Max address: " + p.getMaxAddress());
            w.println("Entry points:");
            for (Address a : p.getSymbolTable().getExternalEntryPointIterator()) w.println("  " + a);

            w.println("\nImports / external symbols:");
            SymbolIterator syms = p.getSymbolTable().getExternalSymbols();
            while (syms.hasNext()) {
                Symbol s = syms.next();
                w.println("  " + s.getName(true) + " @ " + s.getAddress());
            }

            w.println("\nFunctions:");
            FunctionIterator funcs = p.getFunctionManager().getFunctions(true);
            while (funcs.hasNext()) {
                Function f = funcs.next();
                w.println("  " + f.getEntryPoint() + " " + f.getName() + " size=" + f.getBody().getNumAddresses());
            }
        }

        DecompInterface di = new DecompInterface();
        di.openProgram(p);
        try (PrintWriter w = new PrintWriter(new File(outDir, "decompiled.c"), "UTF-8")) {
            FunctionIterator funcs = p.getFunctionManager().getFunctions(true);
            while (funcs.hasNext() && !monitor.isCancelled()) {
                Function f = funcs.next();
                if (f.isExternal() || f.isThunk()) continue;
                DecompileResults r = di.decompileFunction(f, 60, monitor);
                w.println("\n/* " + f.getEntryPoint() + " " + f.getName() + " */");
                if (r.decompileCompleted()) w.println(r.getDecompiledFunction().getC());
                else w.println("/* decompilation failed: " + r.getErrorMessage() + " */");
            }
        } finally {
            di.dispose();
        }
    }
}
