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
    U16 resetHandler = 0x0000;  // Program excicution starts here
    U16 brkIrqHandler = 0x0600;
    StoreMemory(emu->mem, (U8 *)&nMIHandler, NMI_HANDLER, 2, BIG_ENDIAN_6502);
    StoreMemory(emu->mem, (U8 *)&resetHandler, RESET_HANDLER, 2, BIG_ENDIAN_6502);
    StoreMemory(emu->mem, (U8 *)&brkIrqHandler, BRK_IRQ_HANDLER, 2, BIG_ENDIAN_6502);

    // initialize cpu
    CreateCPU(&emu->cpu);
    resetCpu(&emu->cpu, emu->mem);

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

    for (U16 i = 0; i < 5; i++) {
        printf("pc: %d\n", emu->cpu.PC);
        U8 *opAddr = emu->mem + emu->cpu.PC;

        // lookup opcode
        OpcodeSpec spec = emu->opcodes[*opAddr];
        printf("%2X, %d, %d: ", *opAddr, spec.nbytes, spec.cycles);

        // need to call before handler so that jump ops overwrite the pc
        emu->cpu.PC += spec.nbytes;
        spec.handler(&emu->cpu, opAddr + 1);

        for (U16 j = 0; j < spec.cycles; j++) {
            // wait?
        }
    }

    PrintMemory(emu->mem, 0x0000, 0x001F);
}

int main(void) {
    Emulator emu;
    InitEmulator(&emu);

    U8 code[4] = {
        NOP_ADDR_IMPLICIT,
        JMP_ADDR_ABSOLUTE, 0x00, 0x00};

    StoreMemory(emu.mem, code, 0x0000, 4, BIG_ENDIAN_6502);
    UpdateEmulator(&emu);
    TerminateEmulator(&emu);

    return 0;
}
