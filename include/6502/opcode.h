#ifndef OPCODE_H
#define OPCODE_H

#include <6502/types.h>
#include <6502/cpu.h>

#define OPCODE_LENGTH (256)
typedef void (*OpcodeCB)(CPU *);
typedef OpcodeCB OpcodeTable[OPCODE_LENGTH];

void init_opcode_table(OpcodeTable table);

#endif // OPCODE_H