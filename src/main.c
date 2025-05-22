#include <6502/cpu.h>
#include <6502/opcode.h>
#include <6502/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    CPU cpu;
    OpcodeTable opcodes;
    U16 ramsize;
} Emulator;

void InitEmulator(Emulator *emu) {
    assert(emu);

    CreateCPU(&emu->cpu);
    InitOpcodeTable(emu->opcodes);
}

void TerminateEmulator(Emulator *emu) {
    assert(emu);
    DestroyCPU(&emu->cpu);
}


void UpdateEmulator(Emulator *emu) {
    assert(emu);

}


int main(void) {
    Emulator emu;
    InitEmulator(&emu);

    const U8 code[1] = {
        NOP_ADDR_IMPLICIT,
    };

    for (;;) {
        UpdateEmulator(&emu);
        break;
    }

    TerminateEmulator(&emu);

    return 0;
}
