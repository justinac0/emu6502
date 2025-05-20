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

void emulator_init(Emulator *emu, size_t memsize) {
    assert(emu);

    // zero out cpu state
    emu->cpu = (CPU){0};

    // allocate memory for ram
    emu->ram = (U8*)calloc(memsize, sizeof(U8));
    emu->ramsize = memsize;
    assert(emu->ram);

    // initialize opcodes
    init_opcode_table(emu->opcodes);
}

void emulator_update(Emulator *emu) {
    cpu_fetch();
    cpu_decode();
    cpu_execute();
}

void emulator_terminate(Emulator *emu) {
    assert(emu);
    free(emu->ram);
}

int main(void) {
    Emulator emu;
    emulator_init(&emu, DEFAULT_RAM_SIZE);

    for (;;) {
        emulator_update(&emu);
        break;
    }

    emulator_terminate(&emu);

    return 0;
}
