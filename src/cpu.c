#include <6502/cpu.h>

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

U8 *CreateMemory(void) {
    return (U8*)calloc(DEFAULT_MEMSIZE, sizeof(U8));
}

void DestroyMemory(U8 *mem) {
//    free(mem);
}

void PrintMemory(U8 *mem, U32 begin, U32 end) {
    for (U32 i = begin; i <= end; i++) {
        if ((i % 16) == 0) {
            if (i != 0) {
                printf("\n");
            }
            printf("%04X > ", i);
        }
        printf("%02X ", mem[i]);
    }
    printf("\n");
}
