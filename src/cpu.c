#include <6502/cpu.h>
#include <6502/memory.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void CreateCPU(CPU *cpu) {
    assert(cpu);
}

void DestroyCPU(CPU *cpu) {
    assert(cpu);
}

void resetCpu(CPU *cpu, U8 *mem) {
    assert(cpu);
    assert(mem);

    cpu->PC = *(U16 *)readMemory(mem, RESET_HANDLER, 2, LITTLE_ENDIAN_6502);
}
