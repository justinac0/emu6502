#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned short u16;

#define DEFAULT_RAM_SIZE (0x10000) // 64kb

typedef struct {
    u8 A;   // accumulator      (8-bits)
    u8 P;   // processor flags  (7-bits)
    u8 S;   // stack pointer    (8-bits)
    u8 X;   // index register   (8-bits)
    u8 Y;   // index register   (8-bits)
    u16 PC; // program counter  (16-bits)
} CPU;

void cpu_fetch(void) {
    printf("fetch\n");
}

void cpu_decode(void) {
    printf("decode\n");
}

void cpu_execute(void) {
    printf("execute\n");
}

typedef void (*OpcodeCB)(CPU *);

typedef struct {
    CPU cpu;
    OpcodeCB opcode_table[256];
    u8 *ram;
} Emulator;

void emulator_init(Emulator *emu, size_t memsize) {
    assert(emu);

    // zero out cpu state
    emu->cpu = (CPU){0};

    // allocate memory for ram
    emu->ram = (u8*)calloc(memsize, sizeof(u8));
    assert(emu->ram);

    // initialize opcodes
    emu->opcode_table[0x00] = (void*)0;
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
