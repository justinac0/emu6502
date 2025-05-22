#ifndef CPU_H
#define CPU_H

#include "types.h"

// Memory Layout
// Zero Page
// > $0000-$00FF
// Stack
// > $0100-$01FF
// RAM
// > $0200-$7FFF
// ROM
// > $8000-$FFFF
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