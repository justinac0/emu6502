#include <6502/cpu.h>
#include <6502/opcode.h>
#include <6502/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    CPU cpu;
    OpcodeTable opcodes;
    // put peripherals here
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

    PrintCPUMemory(&emu->cpu, 0x0000, 0x00AF);
}

int main(void) {
    Emulator emu;
    InitEmulator(&emu);
    UpdateEmulator(&emu);
    TerminateEmulator(&emu);

    return 0;
}
