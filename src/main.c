#include <6502/cpu.h>
#include <6502/opcode.h>
#include <6502/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFAULT_RAM_SIZE (0x10000) // 64kb

typedef struct {
    CPU cpu;
    OpcodeTable opcodes;
    U8 *ram;
    U16 ramsize;
} Emulator;

void InitEmulator(Emulator *emu, size_t memsize) {
    assert(emu);

    // zero out cpu state
    emu->cpu = (CPU){0};

    // allocate memory for ram
    emu->ram = (U8*)calloc(memsize, sizeof(U8));
    emu->ramsize = memsize;
    assert(emu->ram);

    // initialize opcodes
    InitOpcodeTable(emu->opcodes);
}

void UpdateEmulator(Emulator *emu) {
    CPUFetch();
    CPUDecode();
    CPUExecute();
}

void TerminateEmulator(Emulator *emu) {
    assert(emu);
    free(emu->ram);
}

int main(void) {
    Emulator emu;
    InitEmulator(&emu, DEFAULT_RAM_SIZE);

    for (;;) {
        UpdateEmulator(&emu);
        break;
    }

    TerminateEmulator(&emu);

    return 0;
}
