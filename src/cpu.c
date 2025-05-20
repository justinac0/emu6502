#include <6502/cpu.h>

#include <stdio.h>

void cpu_fetch(void) {
    printf("fetch\n");
}

void cpu_decode(void) {
    printf("decode\n");
}

void cpu_execute(void) {
    printf("execute\n");
}