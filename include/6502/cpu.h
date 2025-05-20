#ifndef CPU_H
#define CPU_H

#include "types.h"

typedef struct {
    U8 A;   // accumulator      (8-bits)
    U8 P;   // processor flags  (7-bits)
    U8 S;   // stack pointer    (8-bits)
    U8 X;   // index register   (8-bits)
    U8 Y;   // index register   (8-bits)
    U16 PC; // program counter  (16-bits)
} CPU;

void cpu_fetch(void);
void cpu_decode(void);
void cpu_execute(void);

#endif // CPU_H