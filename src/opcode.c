#include <6502/opcode.h>

#include <stdio.h>
#include <assert.h>

// ADC - Add and Carry
const U8 OPCODE_DEFINE(ADC, ADDR_IMMEDIATE)           = 0x69;
const U8 OPCODE_DEFINE(ADC, ADDR_ZERO_PAGE)           = 0x65;
const U8 OPCODE_DEFINE(ADC, ADDR_ZERO_PAGE_X)         = 0x75;
const U8 OPCODE_DEFINE(ADC, ADDR_ABSOLUTE)            = 0x6D;
const U8 OPCODE_DEFINE(ADC, ADDR_ABSOLUTE_X)          = 0x7D;
const U8 OPCODE_DEFINE(ADC, ADDR_ABSOLUTE_Y)          = 0x79;
const U8 OPCODE_DEFINE(ADC, ADDR_INDEXED_INDIRECT)    = 0x61;
const U8 OPCODE_DEFINE(ADC, ADDR_INDIRECT_INDEXED)    = 0x71;

// AND - Logical AND
const U8 OPCODE_DEFINE(AND, ADDR_IMMEDIATE)           = 0x29;
const U8 OPCODE_DEFINE(AND, ADDR_ZERO_PAGE)           = 0x25;
const U8 OPCODE_DEFINE(AND, ADDR_ZERO_PAGE_X)         = 0x35;
const U8 OPCODE_DEFINE(AND, ADDR_ABSOLUTE)            = 0x2D;
const U8 OPCODE_DEFINE(AND, ADDR_ABSOLUTE_X)          = 0x3D;
const U8 OPCODE_DEFINE(AND, ADDR_ABSOLUTE_Y)          = 0x39;
const U8 OPCODE_DEFINE(AND, ADDR_INDEXED_INDIRECT)    = 0x21;
const U8 OPCODE_DEFINE(AND, ADDR_INDIRECT_INDEXED)    = 0x31;

// ASL - Arithmetic Shift Left
const U8 OPCODE_DEFINE(ASL, ADDR_ACCUMULATOR)   = 0x0A;
const U8 OPCODE_DEFINE(ASL, ADDR_ZERO_PAGE)     = 0x06;
const U8 OPCODE_DEFINE(ASL, ADDR_ZERO_PAGE_X)   = 0x16;
const U8 OPCODE_DEFINE(ASL, ADDR_ABSOLUTE)      = 0x0E;
const U8 OPCODE_DEFINE(ASL, ADDR_ABSOLUTE_X)    = 0x1E;

// BCC - Branch if Carry Clear
const U8 OPCODE_DEFINE(BCC, ADDR_RELATIVE) = 0x90;

// BCS - Branch if Carry Set
const U8 OPCODE_DEFINE(BCS, ADDR_RELATIVE) = 0xB0;

// BEQ - Branch if Equal
const U8 OPCODE_DEFINE(BEQ, ADDR_RELATIVE) = 0xF0;

// BIT - Bit Test
const U8 OPCODE_DEFINE(BIT, ADDR_ZERO_PAGE)   = 0x24;
const U8 OPCODE_DEFINE(BIT, ADDR_ABSOLUTE)    = 0x2C;

// BMI - Branch if Minus
const U8 OPCODE_DEFINE(BMI, ADDR_RELATIVE) = 0x30;

// BNE - Branch if Not Equal
const U8 OPCODE_DEFINE(BNE, ADDR_RELATIVE) = 0xD0;

// BPL - Branch if Positive
const U8 OPCODE_DEFINE(BPL, ADDR_RELATIVE) = 0x10;

// BRK - Force Interrupt
const U8 OPCODE_DEFINE(BRK, ADDR_IMPLICIT) = 0x00;

// BVC - Branch if Overflow Clear
const U8 OPCODE_DEFINE(BVC, ADDR_RELATIVE) = 0x50;

// BVC - Branch if Overflow Set
const U8 OPCODE_DEFINE(BVS, ADDR_RELATIVE) = 0x70;

// CLC - Clear Carry Flag
const U8 OPCODE_DEFINE(CLC, ADDR_IMPLICIT) = 0x18;

// CLD - Clear Decimal Mode
const U8 OPCODE_DEFINE(CLD, ADDR_IMPLICIT) = 0xD8;

// CLI - Clear Interrupt Disable
const U8 OPCODE_DEFINE(CLI, ADDR_IMPLICIT) = 0x58;

// CLV - Clear Overflow Flag
const U8 OPCODE_DEFINE(CLV, ADDR_IMPLICIT) = 0xB8;

// CMP - Compare
const U8 OPCODE_DEFINE(CMP, ADDR_IMMEDIATE)           = 0xC9;
const U8 OPCODE_DEFINE(CMP, ADDR_ZERO_PAGE)           = 0xC5;
const U8 OPCODE_DEFINE(CMP, ADDR_ZERO_PAGE_X)         = 0xD5;
const U8 OPCODE_DEFINE(CMP, ADDR_ABSOLUTE)            = 0xCD;
const U8 OPCODE_DEFINE(CMP, ADDR_ABSOLUTE_X)          = 0xDD;
const U8 OPCODE_DEFINE(CMP, ADDR_ABSOLUTE_Y)          = 0xD9;
const U8 OPCODE_DEFINE(CMP, ADDR_INDEXED_INDIRECT)    = 0xC1;
const U8 OPCODE_DEFINE(CMP, ADDR_INDIRECT_INDEXED)    = 0XD1;

// CMP - Compare X Register
const U8 OPCODE_DEFINE(CPX, ADDR_IMMEDIATE)   = 0xE0;
const U8 OPCODE_DEFINE(CPX, ADDR_ZERO_PAGE)   = 0xE4;
const U8 OPCODE_DEFINE(CPX, ADDR_ABSOLUTE)    = 0XEC;

// CPY - Compare Y Register
const U8 OPCODE_DEFINE(CPY, ADDR_IMMEDIATE)   = 0xC0;
const U8 OPCODE_DEFINE(CPY, ADDR_ZERO_PAGE)   = 0xC4;
const U8 OPCODE_DEFINE(CPY, ADDR_ABSOLUTE)    = 0xCC;

// DEC - Decrement Memory
const U8 OPCODE_DEFINE(DEC, ADDR_ZERO_PAGE)   = 0xC6;
const U8 OPCODE_DEFINE(DEC, ADDR_ZERO_PAGE_X) = 0xD6;
const U8 OPCODE_DEFINE(DEC, ADDR_ABSOLUTE)    = 0xCE;
const U8 OPCODE_DEFINE(DEC, ADDR_ABSOLUTE_X)  = 0xDE;

// DEX - Decrement X Register
const U8 OPCODE_DEFINE(DEX, ADDR_IMPLICIT) = 0xCA;

// DEY - Decrement Y Register
const U8 OPCODE_DEFINE(DEY, ADDR_IMPLICIT) = 0x88;

// EOR - Exclusive OR
const U8 OPCODE_DEFINE(EOR, ADDR_IMMEDIATE)           = 0x49;
const U8 OPCODE_DEFINE(EOR, ADDR_ZERO_PAGE)           = 0x45;
const U8 OPCODE_DEFINE(EOR, ADDR_ZERO_PAGE_X)         = 0x55;
const U8 OPCODE_DEFINE(EOR, ADDR_ABSOLUTE)            = 0x4D;
const U8 OPCODE_DEFINE(EOR, ADDR_ABSOLUTE_X)          = 0x5D;
const U8 OPCODE_DEFINE(EOR, ADDR_ABSOLUTE_Y)          = 0x59;
const U8 OPCODE_DEFINE(EOR, ADDR_INDEXED_INDIRECT)    = 0x41;
const U8 OPCODE_DEFINE(EOR, ADDR_INDIRECT_INDEXED)    = 0x51;

// INC - Increment Memory
const U8 OPCODE_DEFINE(INC, ADDR_ZERO_PAGE)   = 0xE6;
const U8 OPCODE_DEFINE(INC, ADDR_ZERO_PAGE_X) = 0xF6;
const U8 OPCODE_DEFINE(INC, ADDR_ABSOLUTE)    = 0xEE;
const U8 OPCODE_DEFINE(INC, ADDR_ABSOLUTE_X)  = 0xFE;

// INX - Increment X Register
const U8 OPCODE_DEFINE(INX, ADDR_IMPLICIT) = 0xE8;

// INY - Increment Y Register
const U8 OPCODE_DEFINE(INY, ADDR_IMPLICIT) = 0xC8;

// JMP - Jump
const U8 OPCODE_DEFINE(JMP, ADDR_ABSOLUTE) = 0x4C;
const U8 OPCODE_DEFINE(JMP, ADDR_INDIRECT) = 0x6C;

// JSR - Jump to Subroutine
const U8 OPCODE_DEFINE(JSR, ADDR_ABSOLUTE) = 0x20;

// LDA - Load Accumulator
const U8 OPCODE_DEFINE(LDA, ADDR_IMMEDIATE)         = 0xA9;
const U8 OPCODE_DEFINE(LDA, ADDR_ZERO_PAGE)         = 0xA5;
const U8 OPCODE_DEFINE(LDA, ADDR_ZERO_PAGE_X)       = 0xB5;
const U8 OPCODE_DEFINE(LDA, ADDR_ABSOLUTE)          = 0xAD;
const U8 OPCODE_DEFINE(LDA, ADDR_ABSOLUTE_X)        = 0xBD;
const U8 OPCODE_DEFINE(LDA, ADDR_ABSOLUTE_Y)        = 0xB9;
const U8 OPCODE_DEFINE(LDA, ADDR_INDEXED_INDIRECT)  = 0xA1;
const U8 OPCODE_DEFINE(LDA, ADDR_INDIRECT_INDEXED)  = 0xB1;

// LDX - Load X Register
const U8 OPCODE_DEFINE(LDX, ADDR_IMMEDIATE)     = 0xA2;
const U8 OPCODE_DEFINE(LDX, ADDR_ZERO_PAGE)     = 0xA6;
const U8 OPCODE_DEFINE(LDX, ADDR_ZERO_PAGE_Y)   = 0xB6;
const U8 OPCODE_DEFINE(LDX, ADDR_ABSOLUTE)      = 0xAE;
const U8 OPCODE_DEFINE(LDX, ADDR_ABSOLUTE_Y)    = 0xBE;

// LDY - Load Y Register
const U8 OPCODE_DEFINE(LDY, ADDR_IMMEDIATE)     = 0xA0;
const U8 OPCODE_DEFINE(LDY, ADDR_ZERO_PAGE)     = 0xA4;
const U8 OPCODE_DEFINE(LDY, ADDR_ZERO_PAGE_X)   = 0xB4;
const U8 OPCODE_DEFINE(LDY, ADDR_ABSOLUTE)      = 0xAC;
const U8 OPCODE_DEFINE(LDY, ADDR_ABSOLUTE_X)    = 0xBC;

// LSR - Logical Shift Right
const U8 OPCODE_DEFINE(LSR, ADDR_ACCUMULATOR)   = 0x4A;
const U8 OPCODE_DEFINE(LSR, ADDR_ZERO_PAGE)     = 0x46;
const U8 OPCODE_DEFINE(LSR, ADDR_ZERO_PAGE_X)   = 0x56;
const U8 OPCODE_DEFINE(LSR, ADDR_ABSOLUTE)      = 0x4E;
const U8 OPCODE_DEFINE(LSR, ADDR_ABSOLUTE_X)    = 0x5E;

// NOP - No Operation
const U8 OPCODE_DEFINE(NOP, ADDR_IMPLICIT) = 0xEA;

// Logical Inclusive OR
const U8 OPCODE_DEFINE(ORA, ADDR_IMMEDIATE)         = 0x09;
const U8 OPCODE_DEFINE(ORA, ADDR_ZERO_PAGE)         = 0x05;
const U8 OPCODE_DEFINE(ORA, ADDR_ZERO_PAGE_X)       = 0x15;
const U8 OPCODE_DEFINE(ORA, ADDR_ABSOLUTE)          = 0x0D;
const U8 OPCODE_DEFINE(ORA, ADDR_ABSOLUTE_X)        = 0x1D;
const U8 OPCODE_DEFINE(ORA, ADDR_ABSOLUTE_Y)        = 0x19;
const U8 OPCODE_DEFINE(ORA, ADDR_INDEXED_INDIRECT)  = 0x01;
const U8 OPCODE_DEFINE(ORA, ADDR_INDIRECT_INDEXED)  = 0x11;

// PHA - Push Accumulator
const U8 OPCODE_DEFINE(PHA, ADDR_IMPLICIT) = 0x48;

// PHP - Push Processor Status
const U8 OPCODE_DEFINE(PHP, ADDR_IMPLICIT) = 0x08;

// PLA - Pull Accumulator
const U8 OPCODE_DEFINE(PLA, ADDR_IMPLICIT) = 0x68;

// PLP - Pull Processor Status
const U8 OPCODE_DEFINE(PLP, ADDR_IMPLICIT) = 0x28;

// ROL - Rotate Left
const U8 OPCODE_DEFINE(ROL, ADDR_ACCUMULATOR)   = 0x2A;
const U8 OPCODE_DEFINE(ROL, ADDR_ZERO_PAGE)     = 0x26;
const U8 OPCODE_DEFINE(ROL, ADDR_ZERO_PAGE_X)   = 0x36;
const U8 OPCODE_DEFINE(ROL, ADDR_ABSOLUTE)      = 0x2E;
const U8 OPCODE_DEFINE(ROL, ADDR_ABSOLUTE_X)    = 0x3E;

// ROR - Rotate Right
const U8 OPCODE_DEFINE(ROR, ADDR_ACCUMULATOR)   = 0x6A;
const U8 OPCODE_DEFINE(ROR, ADDR_ZERO_PAGE)     = 0x66;
const U8 OPCODE_DEFINE(ROR, ADDR_ZERO_PAGE_X)   = 0x76;
const U8 OPCODE_DEFINE(ROR, ADDR_ABSOLUTE)      = 0x6E;
const U8 OPCODE_DEFINE(ROR, ADDR_ABSOLUTE_X)    = 0x7E;

// RTI - Return from Interrupt
const U8 OPCODE_DEFINE(RTI, ADDR_IMPLICIT) = 0x40;

// RTS - Return from Subroutine
const U8 OPCODE_DEFINE(RTS, ADDR_IMPLICIT) = 0x60;

// SBC - Subtract with Carry
const U8 OPCODE_DEFINE(SBC, ADDR_IMMEDIATE)         = 0xE9;
const U8 OPCODE_DEFINE(SBC, ADDR_ZERO_PAGE)         = 0xE5;
const U8 OPCODE_DEFINE(SBC, ADDR_ZERO_PAGE_X)       = 0xF5;
const U8 OPCODE_DEFINE(SBC, ADDR_ABSOLUTE)          = 0xED;
const U8 OPCODE_DEFINE(SBC, ADDR_ABSOLUTE_X)        = 0xFD;
const U8 OPCODE_DEFINE(SBC, ADDR_ABSOLUTE_Y)        = 0xF9;
const U8 OPCODE_DEFINE(SBC, ADDR_INDEXED_INDIRECT)  = 0xE1;
const U8 OPCODE_DEFINE(SBC, ADDR_INDIRECT_INDEXED)  = 0xF1;

// SEC - Set Carry Flag
const U8 OPCODE_DEFINE(SEC, ADDR_IMPLICIT) = 0x38;

// SED - Set Decimal Flag
const U8 OPCODE_DEFINE(SED, ADDR_IMPLICIT) = 0xF8;

// SEI - Set Interrupt Disable
const U8 OPCODE_DEFINE(SEI, ADDR_IMPLICIT) = 0x78;

// STA - Store Accumulator
const U8 OPCODE_DEFINE(STA, ADDR_ZERO_PAGE)         = 0x85;
const U8 OPCODE_DEFINE(STA, ADDR_ZERO_PAGE_X)       = 0x95;
const U8 OPCODE_DEFINE(STA, ADDR_ABSOLUTE)          = 0x8D;
const U8 OPCODE_DEFINE(STA, ADDR_ABSOLUTE_X)        = 0x9D;
const U8 OPCODE_DEFINE(STA, ADDR_ABSOLUTE_Y)        = 0x99;
const U8 OPCODE_DEFINE(STA, ADDR_INDEXED_INDIRECT)  = 0x81;
const U8 OPCODE_DEFINE(STA, ADDR_INDIRECT_INDEXED)  = 0x91;

// STX - Store X Register
const U8 OPCODE_DEFINE(STX, ADDR_ZERO_PAGE)     = 0x86;
const U8 OPCODE_DEFINE(STX, ADDR_ZERO_PAGE_X)   = 0x96;
const U8 OPCODE_DEFINE(STX, ADDR_ABSOLUTE)      = 0x8E;

// STY - Store X Register
const U8 OPCODE_DEFINE(STY, ADDR_ZERO_PAGE)     = 0x84;
const U8 OPCODE_DEFINE(STY, ADDR_ZERO_PAGE_Y)   = 0x94;
const U8 OPCODE_DEFINE(STY, ADDR_ABSOLUTE)      = 0x8C;

// TAX - Transfer Accumulator to X
const U8 OPCODE_DEFINE(TAX, ADDR_IMPLICIT) = 0xAA;

// TAY - Transfer Accumulator to Y
const U8 OPCODE_DEFINE(TAY, ADDR_IMPLICIT) = 0xA8;

// TSX - Transfer Stack Pointer to X
const U8 OPCODE_DEFINE(TSX, ADDR_IMPLICIT) = 0xBA;

// TXA - Transfer X to Accumulator
const U8 OPCODE_DEFINE(TXA, ADDR_IMPLICIT) = 0x8A;

// TXA - Transfer X to Stack Pointer
const U8 OPCODE_DEFINE(TXS, ADDR_IMPLICIT) = 0x9A;

// TYA - Transfer Y to Accumulator
const U8 OPCODE_DEFINE(TYA, ADDR_IMPLICIT) = 0x98;

// Functions

void NotImplemented(CPU *cpu) {
    printf("not implemented...");
}

// -----------------------------------
// Opcode Table
// -----------------------------------
void InitOpcodeTable(OpcodeTable table) {
    for (U16 i = 0; i < OPCODE_LENGTH; i++) {
        table[i] = NULL;
    }

    // ADC - Add and Carry
    table[ADC_ADDR_IMMEDIATE]           = NotImplemented;
    table[ADC_ADDR_ZERO_PAGE]           = NotImplemented;
    table[ADC_ADDR_ZERO_PAGE_X]         = NotImplemented;
    table[ADC_ADDR_ABSOLUTE]            = NotImplemented;
    table[ADC_ADDR_ABSOLUTE_X]          = NotImplemented;
    table[ADC_ADDR_ABSOLUTE_Y]          = NotImplemented;
    table[ADC_ADDR_INDEXED_INDIRECT]    = NotImplemented;
    table[ADC_ADDR_INDIRECT_INDEXED]    = NotImplemented;

    // AND - Logical AND
    table[AND_ADDR_IMMEDIATE]           = NotImplemented;
    table[AND_ADDR_ZERO_PAGE]           = NotImplemented;
    table[AND_ADDR_ZERO_PAGE_X]         = NotImplemented;
    table[AND_ADDR_ABSOLUTE]            = NotImplemented;
    table[AND_ADDR_ABSOLUTE_X]          = NotImplemented;
    table[AND_ADDR_ABSOLUTE_Y]          = NotImplemented;
    table[AND_ADDR_INDEXED_INDIRECT]    = NotImplemented;
    table[AND_ADDR_INDIRECT_INDEXED]    = NotImplemented;

    // ASL - Arithmetic Shift Left
    table[ASL_ADDR_ACCUMULATOR] = NotImplemented;
    table[ASL_ADDR_ZERO_PAGE]   = NotImplemented;
    table[ASL_ADDR_ZERO_PAGE_X] = NotImplemented;
    table[ASL_ADDR_ABSOLUTE]    = NotImplemented;
    table[ASL_ADDR_ABSOLUTE_X]  = NotImplemented;

    // BCC - Branch if Carry Clear
    table[BCC_ADDR_RELATIVE] = NotImplemented;

    // BCS - Branch if Carry Set
    table[BCS_ADDR_RELATIVE] = NotImplemented;

    // BEQ - Branch if Equal
    table[BEQ_ADDR_RELATIVE] = NotImplemented;

    // BIT - Bit Test
    table[BIT_ADDR_ZERO_PAGE]   = NotImplemented;
    table[BIT_ADDR_ABSOLUTE]    = NotImplemented;

    // BMI - Branch if Minus
    table[BMI_ADDR_RELATIVE] = NotImplemented;

    // BNE - Branch if Not Equal
    table[BNE_ADDR_RELATIVE] = NotImplemented;

    // BPL - Branch if Positive
    table[BPL_ADDR_RELATIVE] = NotImplemented;

    // BRK - Force Interrupt
    table[BRK_ADDR_IMPLICIT] = NotImplemented;

    // BVC - Branch if Overflow Clear
    table[BVC_ADDR_RELATIVE] = NotImplemented;

    // BVC - Branch if Overflow Set
    table[BVS_ADDR_RELATIVE] = NotImplemented;

    // CLC - Clear Carry Flag
    table[CLC_ADDR_IMPLICIT] = NotImplemented;

    // CLD - Clear Decimal Mode
    table[CLD_ADDR_IMPLICIT] = NotImplemented;

    // CLI - Clear Interrupt Disable
    table[CLI_ADDR_IMPLICIT] = NotImplemented;

    // CLV - Clear Overflow Flag
    table[CLV_ADDR_IMPLICIT] = NotImplemented;

    // CMP - Compare
    table[CMP_ADDR_IMMEDIATE]           = NotImplemented;
    table[CMP_ADDR_ZERO_PAGE]           = NotImplemented;
    table[CMP_ADDR_ZERO_PAGE_X]         = NotImplemented;
    table[CMP_ADDR_ABSOLUTE]            = NotImplemented;
    table[CMP_ADDR_ABSOLUTE_X]          = NotImplemented;
    table[CMP_ADDR_ABSOLUTE_Y]          = NotImplemented;
    table[CMP_ADDR_INDEXED_INDIRECT]    = NotImplemented;
    table[CMP_ADDR_INDIRECT_INDEXED]    = NotImplemented;

    // CMP - Compare X Register
    table[CPX_ADDR_IMMEDIATE]   = NotImplemented;
    table[CPX_ADDR_ZERO_PAGE]   = NotImplemented;
    table[CPX_ADDR_ABSOLUTE]    = NotImplemented;

    // CPY - Compare Y Register
    table[CPY_ADDR_IMMEDIATE]   = NotImplemented;
    table[CPY_ADDR_ZERO_PAGE]   = NotImplemented;
    table[CPY_ADDR_ABSOLUTE]    = NotImplemented;

    // DEC - Decrement Memory
    table[DEC_ADDR_ZERO_PAGE]   = NotImplemented;
    table[DEC_ADDR_ZERO_PAGE_X] = NotImplemented;
    table[DEC_ADDR_ABSOLUTE]    = NotImplemented;
    table[DEC_ADDR_ABSOLUTE_X]  = NotImplemented;

    // DEX - Decrement X Register
    table[DEX_ADDR_IMPLICIT] = NotImplemented;

    // DEY - Decrement Y Register
    table[DEY_ADDR_IMPLICIT] = NotImplemented;

    // EOR - Exclusive OR
    table[EOR_ADDR_IMMEDIATE]           = NotImplemented;
    table[EOR_ADDR_ZERO_PAGE]           = NotImplemented;
    table[EOR_ADDR_ZERO_PAGE_X]         = NotImplemented;
    table[EOR_ADDR_ABSOLUTE]            = NotImplemented;
    table[EOR_ADDR_ABSOLUTE_X]          = NotImplemented;
    table[EOR_ADDR_ABSOLUTE_Y]          = NotImplemented;
    table[EOR_ADDR_INDEXED_INDIRECT]    = NotImplemented;
    table[EOR_ADDR_INDIRECT_INDEXED]    = NotImplemented;

    // INC - Increment Memory
    table[INC_ADDR_ZERO_PAGE]   = NotImplemented;
    table[INC_ADDR_ZERO_PAGE_X] = NotImplemented;
    table[INC_ADDR_ABSOLUTE]    = NotImplemented;
    table[INC_ADDR_ABSOLUTE_X]  = NotImplemented;

    // INX - Increment X Register
    table[INX_ADDR_IMPLICIT] = NotImplemented;

    // INY - Increment Y Register
    table[INY_ADDR_IMPLICIT] = NotImplemented;

    // JMP - Jump
    table[JMP_ADDR_ABSOLUTE] = NotImplemented;
    table[JMP_ADDR_INDIRECT] = NotImplemented;

    // JSR - Jump to Subroutine
    table[JMP_ADDR_ABSOLUTE] = NotImplemented;

    // LDA - Load Accumulator
    table[LDA_ADDR_IMMEDIATE]           = NotImplemented;
    table[LDA_ADDR_ZERO_PAGE]           = NotImplemented;
    table[LDA_ADDR_ZERO_PAGE_X]         = NotImplemented;
    table[LDA_ADDR_ABSOLUTE]            = NotImplemented;
    table[LDA_ADDR_ABSOLUTE_X]          = NotImplemented;
    table[LDA_ADDR_ABSOLUTE_Y]          = NotImplemented;
    table[LDA_ADDR_INDEXED_INDIRECT]    = NotImplemented;
    table[LDA_ADDR_INDIRECT_INDEXED]    = NotImplemented;

    // LDX - Load X Register
    table[LDX_ADDR_IMMEDIATE]   = NotImplemented;
    table[LDX_ADDR_ZERO_PAGE]   = NotImplemented;
    table[LDX_ADDR_ZERO_PAGE_Y] = NotImplemented;
    table[LDX_ADDR_ABSOLUTE]    = NotImplemented;
    table[LDX_ADDR_ABSOLUTE_Y]  = NotImplemented;

    // LDY - Load Y Register
    table[LDY_ADDR_IMMEDIATE]   = NotImplemented;
    table[LDY_ADDR_ZERO_PAGE]   = NotImplemented;
    table[LDY_ADDR_ZERO_PAGE_X] = NotImplemented;
    table[LDY_ADDR_ABSOLUTE]    = NotImplemented;
    table[LDY_ADDR_ABSOLUTE_X]  = NotImplemented;

    // LSR - Logical Shift Right
    table[LSR_ADDR_ACCUMULATOR] = NotImplemented;
    table[LSR_ADDR_ZERO_PAGE]   = NotImplemented;
    table[LSR_ADDR_ZERO_PAGE_X] = NotImplemented;
    table[LSR_ADDR_ABSOLUTE]    = NotImplemented;
    table[LSR_ADDR_ABSOLUTE_X]  = NotImplemented;

    // NOP - No Operation
    table[NOP_ADDR_IMPLICIT] = NotImplemented;

    // Logical Inclusive OR
    table[ORA_ADDR_IMMEDIATE]           = NotImplemented;
    table[ORA_ADDR_ZERO_PAGE]           = NotImplemented;
    table[ORA_ADDR_ZERO_PAGE_X]         = NotImplemented;
    table[ORA_ADDR_ABSOLUTE]            = NotImplemented;
    table[ORA_ADDR_ABSOLUTE_X]          = NotImplemented;
    table[ORA_ADDR_ABSOLUTE_Y]          = NotImplemented;
    table[ORA_ADDR_INDEXED_INDIRECT]    = NotImplemented;
    table[ORA_ADDR_INDIRECT_INDEXED]    = NotImplemented;

    // PHA - Push Accumulator
    table[PHA_ADDR_IMPLICIT] = NotImplemented;

    // PHP - Push Processor Status
    table[PHP_ADDR_IMPLICIT] = NotImplemented;

    // PLA - Pull Accumulator
    table[PLA_ADDR_IMPLICIT] = NotImplemented;

    // PLP - Pull Processor Status
    table[PLP_ADDR_IMPLICIT] = NotImplemented;

    // ROL - Rotate Left
    table[ROL_ADDR_ACCUMULATOR] = NotImplemented;
    table[ROL_ADDR_ZERO_PAGE]   = NotImplemented;
    table[ROL_ADDR_ZERO_PAGE_X] = NotImplemented;
    table[ROL_ADDR_ABSOLUTE]    = NotImplemented;
    table[ROL_ADDR_ABSOLUTE_X]  = NotImplemented;

    // ROR - Rotate Right
    table[ROR_ADDR_ACCUMULATOR] = NotImplemented;
    table[ROR_ADDR_ZERO_PAGE]   = NotImplemented;
    table[ROR_ADDR_ZERO_PAGE_X] = NotImplemented;
    table[ROR_ADDR_ABSOLUTE]    = NotImplemented;
    table[ROR_ADDR_ABSOLUTE_X]  = NotImplemented;

    // RTI - Return from Interrupt
    table[RTI_ADDR_IMPLICIT] = NotImplemented;

    // RTS - Return from Subroutine
    table[RTS_ADDR_IMPLICIT] = NotImplemented;

    // SBC - Subtract with Carry
    table[SBC_ADDR_IMMEDIATE]           = NotImplemented;
    table[SBC_ADDR_ZERO_PAGE]           = NotImplemented;
    table[SBC_ADDR_ZERO_PAGE_X]         = NotImplemented;
    table[SBC_ADDR_ABSOLUTE]            = NotImplemented;
    table[SBC_ADDR_ABSOLUTE_X]          = NotImplemented;
    table[SBC_ADDR_ABSOLUTE_Y]          = NotImplemented;
    table[SBC_ADDR_INDEXED_INDIRECT]    = NotImplemented;
    table[SBC_ADDR_INDIRECT_INDEXED]    = NotImplemented;

    // SEC - Set Carry Flag
    table[SEC_ADDR_IMPLICIT] = NotImplemented;

    // SED - Set Decimal Flag
    table[SED_ADDR_IMPLICIT] = NotImplemented;

    // SEI - Set Interrupt Disable
    table[SEI_ADDR_IMPLICIT] = NotImplemented;

    // STA - Store Accumulator
    table[STA_ADDR_ZERO_PAGE]         = NotImplemented;
    table[STA_ADDR_ZERO_PAGE_X]       = NotImplemented;
    table[STA_ADDR_ABSOLUTE]          = NotImplemented;
    table[STA_ADDR_ABSOLUTE_X]        = NotImplemented;
    table[STA_ADDR_ABSOLUTE_Y]        = NotImplemented;
    table[STA_ADDR_INDEXED_INDIRECT]  = NotImplemented;
    table[STA_ADDR_INDIRECT_INDEXED]  = NotImplemented;

    // STX - Store X Register
    table[STX_ADDR_ZERO_PAGE]     = NotImplemented;
    table[STX_ADDR_ZERO_PAGE_X]   = NotImplemented;
    table[STX_ADDR_ABSOLUTE]      = NotImplemented;

    // STY - Store X Register
    table[STY_ADDR_ZERO_PAGE]     = NotImplemented;
    table[STY_ADDR_ZERO_PAGE_Y]   = NotImplemented;
    table[STY_ADDR_ABSOLUTE]      = NotImplemented;

    // TAX - Transfer Accumulator to X
    table[TAX_ADDR_IMPLICIT] = NotImplemented;

    // TAY - Transfer Accumulator to Y
    table[TAY_ADDR_IMPLICIT] = NotImplemented;

    // TSX - Transfer Stack Pointer to X
    table[TSX_ADDR_IMPLICIT] = NotImplemented;

    // TXA - Transfer X to Accumulator
    table[TXA_ADDR_IMPLICIT] = NotImplemented;

    // TXA - Transfer X to Stack Pointer
    table[TXS_ADDR_IMPLICIT] = NotImplemented;

    // TYA - Transfer Y to Accumulator
    table[TYA_ADDR_IMPLICIT] = NotImplemented;

}