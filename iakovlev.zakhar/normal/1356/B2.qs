namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        // unwrap LittleEndian type
        let qarray = register!;
        X(qarray[0]);
        if (Length(qarray) > 1) {
            // increment the rest of the number if the least significant bit is 1
            (Controlled Solve)([qarray[0]], LittleEndian(qarray[1 ...]));
        }
    }
}