#include <6502/opcode.h>

#include <stdio.h>
#include <assert.h>

void NotImplemented(CPU *cpu) {

}

void InitOpcodeTable(OpcodeTable table) {
    // setup instructions here
    table[0x00] = NotImplemented;
}