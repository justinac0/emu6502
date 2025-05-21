#include <6502/cpu.h>

#include <stdio.h>

void CPUFetch(void) {
    printf("fetch\n");
}

void CPUDecode(void) {
    printf("decode\n");
}

void CPUExecute(void) {
    printf("execute\n");
}