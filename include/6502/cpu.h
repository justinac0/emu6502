#ifndef CPU_H
#define CPU_H

#include "types.h"

typedef struct {
    U8 A;   // accumulator
    U8 P;   // processor flags (7 bits)
    U8 S;   // stack pointer
    U8 X;   // index register
    U8 Y;   // index register
    U16 PC; // program counter
} CPU;

void CPUFetch(void);
void CPUDecode(void);
void CPUExecute(void);

#endif // CPU_H