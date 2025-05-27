#include <6502/cpu.h>
#include <6502/memory.h>
#include <6502/opcode.h>
#include <6502/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    CPU cpu;
    U8 *mem;
    OpcodeTable opcodes;
    // put peripherals here
} Emulator;

void InitEmulator(Emulator *emu) {
    assert(emu);

    // initialize cpu
    CreateCPU(&emu->cpu);

    // initialize opcodes
    InitOpcodeTable(emu->opcodes);

    // zero out memory
    emu->mem = CreateMemory(); 
    assert(emu->mem);
}

void TerminateEmulator(Emulator *emu) {
    assert(emu);

    free(emu->mem);
    // TODO: opcodes deinit
    DestroyCPU(&emu->cpu);
}

void UpdateEmulator(Emulator *emu) {
    assert(emu);

    PrintMemory(emu->mem, 0x0000, 0x00AF);
}

int main(void) {
    Emulator emu;
    InitEmulator(&emu);

    U8 code[1] = {
        NOP_ADDR_IMPLICIT,
    };

    StoreMemory(emu.mem, code, 0, 1, LITTLE_ENDIAN);
    UpdateEmulator(&emu);
    TerminateEmulator(&emu);

    return 0;
}
