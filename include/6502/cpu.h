#ifndef CPU_H
#define CPU_H

#include "types.h"

// Memory Layout
// Zero Page
#define ZERO_PAGE_FIRST (0x0000)
#define ZERO_PAGE_LAST (0x00FF)
// Stack
#define STACK_FIRST (0x0100)
#define STACK_LAST (0x01FF)
// RAM
#define RAM_FIRST (0x0200)
#define RAM_LAST (0x7FFF)
// ROM
#define ROM_FIRST (0x8000)
#define ROM_LAST (0xFFFF)

#define CPU_MEMORY_SIZE (0xFFFF)
typedef struct {
    U8 A;   // accumulator
    U8 P;   // processor flags (NV-BDIZC)
    U8 S;   // stack pointer
    U8 X;   // index register
    U8 Y;   // index register
    U16 PC; // program counter
    U8 memory[CPU_MEMORY_SIZE]; // *external
} CPU;

void CreateCPU(CPU *cpu);
void DestroyCPU(CPU *cpu);
void PrintCPUMemory(CPU *cpu, U32 begin, U32 end);

#endif // CPU_H