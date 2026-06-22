// Exports Ghidra-defined strings with addresses and references.
//@category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

import java.io.File;
import java.io.PrintWriter;

public class ExportStrings extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) throw new IllegalArgumentException("output file required");
        try (PrintWriter w = new PrintWriter(new File(args[0]), "UTF-8")) {
            DataIterator it = currentProgram.getListing().getDefinedData(true);
            while (it.hasNext()) {
                Data d = it.next();
                Object value = d.getValue();
                if (!(value instanceof String)) continue;
                String text = ((String)value).replace("\r", "\\r").replace("\n", "\\n");
                w.print(d.getAddress() + "\t" + text + "\trefs=");
                ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(d.getAddress());
                boolean first = true;
                while (refs.hasNext()) {
                    Reference r = refs.next();
                    if (!first) w.print(",");
                    w.print(r.getFromAddress());
                    first = false;
                }
                w.println();
            }
        }
    }
}
