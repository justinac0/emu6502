#ifndef CPU_H
#define CPU_H

#include "types.h"

// ---------------------------------------
// CPU
// ---------------------------------------
typedef struct CPU {
    U8 A;   // accumulator
    U8 P;   // processor flags (NV-BDIZC)
    U8 S;   // stack pointer
    U8 X;   // index register
    U8 Y;   // index register
    U16 PC; // program counter
} CPU;

void CreateCPU(CPU *cpu);
void DestroyCPU(CPU *cpu);

#endif // CPU_H
