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

void PrintCPUMemory(CPU *cpu, U32 begin, U32 end) {
    if (end > CPU_MEMORY_SIZE || begin > end) {
        assert("out of bounds memory print");
        return;
    }

    for (U32 i = begin; i <= end; i++) {
        if ((i % 16) == 0) {
            if (i != 0) {
                printf("\n");
            }
            printf("%04X > ", i);
        }
        printf("%02X ", cpu->memory[i]);
    }
    printf("\n");
}