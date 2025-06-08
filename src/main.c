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

    // zero out memory
    emu->mem = CreateMemory();
    assert(emu->mem);

    // initialise reserved memory locations
    U16 nMIHandler = 0x0500;
    U16 resetHandler = 0x0300;
    U16 brkIrqHandler = 0x0600;
    StoreMemory(emu->mem, (U8 *)&nMIHandler, NMI_HANDLER, 2, BIG_ENDIAN_6502);
    StoreMemory(emu->mem, (U8 *)&resetHandler, RESET_HANDLER, 2, BIG_ENDIAN_6502);
    StoreMemory(emu->mem, (U8 *)&brkIrqHandler, BRK_IRQ_HANDLER, 2, BIG_ENDIAN_6502);

    // initialize cpu
    CreateCPU(&emu->cpu);
    resetCpu(emu);

    // initialize opcodes
    InitOpcodeTable(emu->opcodes);
}

void TerminateEmulator(Emulator *emu) {
    assert(emu);

    free(emu->mem);
    // TODO: opcodes deinit
    DestroyCPU(&emu->cpu);
}

void UpdateEmulator(Emulator *emu) {
    assert(emu);

    PrintMemory(emu->mem, 0xFFFA, 0xFFFF);
}

int main(void) {
    Emulator emu;
    InitEmulator(&emu);

    U8 code[1] = {
        NOP_ADDR_IMPLICIT,
    };

    StoreMemory(emu.mem, code, 0, 1, LITTLE_ENDIAN_6502);
    UpdateEmulator(&emu);
    TerminateEmulator(&emu);

    return 0;
}
