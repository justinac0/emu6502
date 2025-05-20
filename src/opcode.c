#include <6502/opcode.h>

#include <assert.h>

void do_nothing(CPU *cpu) {

}

void init_opcode_table(OpcodeTable table) {
    // setup instructions here
    table[0x00] = do_nothing;
}