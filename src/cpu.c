#include <6502/cpu.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>

void CreateCPU(CPU *cpu) {
    assert(cpu);
    memset(cpu->memory, 0, CPU_MEMORY_SIZE);

}

void DestroyCPU(CPU *cpu) {
    assert(cpu);
}
