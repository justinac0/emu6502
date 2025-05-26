#ifndef CPU_H
#define CPU_H

#include "types.h"

// ------------------------------------------
// CPU
// ------------------------------------------
typedef struct {
    U8 A;   // accumulator
    U8 P;   // processor flags (NV-BDIZC)
    U8 S;   // stack pointer
    U8 X;   // index register
    U8 Y;   // index register
    U16 PC; // program counter
} CPU;

void CreateCPU(CPU *cpu);
void DestroyCPU(CPU *cpu);

// ---------------------------------------
// Perf Memory
// ---------------------------------------
//
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

#define DEFAULT_MEMSIZE (0xFFFF)

U8* CreateMemory(void);
void DestroyMemory(U8 *mem);
void PrintMemory(U8 *mem, U32 begin, U32 end);

#endif // CPU_H
