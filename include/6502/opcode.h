// ref: https://www.nesdev.org/obelisk-6502-guide/reference.html
#ifndef OPCODE_H
#define OPCODE_Hy

#include <6502/types.h>
#include <6502/cpu.h>

#define OPCODE_DEFINE(NAME, ADDR) NAME##_##ADDR

typedef U8 Mnemonic;

// mnemonics
// c = 0
#define _BRK (0)
#define _PHP (1)
#define _BPL (2)
#define _CLC (3)
#define _JSR (4)
#define _BIT (5)
#define _PLP (6)
#define _BMI (7)
#define _SEC (8)
#define _RTI (9)
#define _PHA (10)
#define _JMP (11)
#define _BVC (12)
#define _CLI (13)
#define _RTS (14)
#define _PLA (15)
#define _BVS (16)
#define _SEI (17)
#define _STY (18)
#define _DEY (19)
#define _BCC (20)
#define _TYA (21)
#define _LDY (22)
#define _TAY (23)
#define _BCS (24)
#define _CLV (25)
#define _CPY (26)
#define _INY (27)
#define _BNE (28)
#define _CLD (29)
#define _CPX (30)
#define _INX (31)
#define _BEQ (32)
#define _SED (33)

// c = 1
#define _ORA (34)
#define _AND (35)
#define _EOR (36)
#define _ADC (37)
#define _STA (38)
#define _LDA (39)
#define _CMP (40)
#define _SBC (41)

// c = 2
#define _ASL (42)
#define _ROL (43)
#define _LSR (44)
#define _ROR (45)
#define _STX (46)
#define _TXA (47)
#define _TXS (48)
#define _LDX (49)
#define _TAX (50)
#define _TSX (51)
#define _DEC (52)
#define _DEX (53)
#define _INC (54)

typedef enum {
    MODE_IMPLICIT,
    MODE_ACCUMULATOR,
    MODE_IMMEDIATE,
    MODE_ZERO_PAGE,
    MODE_ZERO_PAGE_X,
    MODE_ZERO_PAGE_Y,
    MODE_RELATIVE,
    MODE_ABSOLUTE,
    MODE_ABSOLUTE_X,
    MODE_ABSOLUTE_Y,
    MODE_INDIRECT,
    MODE_INDEXED_INDIRECT,
    MODE_INDIRECT_INDEXED,
} AddressMode;

U8 OpcodeMake(Mnemonic mnemonic,  AddressMode address);

typedef enum {
    ADDR_IMPLICIT,
    ADDR_ACCUMULATOR,
    ADDR_IMMEDIATE,
    ADDR_ZERO_PAGE,
    ADDR_ZERO_PAGE_X,
    ADDR_ZERO_PAGE_Y,
    ADDR_RELATIVE,
    ADDR_ABSOLUTE,
    ADDR_ABSOLUTE_X,
    ADDR_ABSOLUTE_Y,
    ADDR_INDIRECT,
    ADDR_INDEXED_INDIRECT,
    ADDR_INDIRECT_INDEXED,
} AddrMode;


// Opcode externs definitions
//
#define ADC  // ADC - Add and Carry
extern const U8 OPCODE_DEFINE(ADC, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(ADC, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(ADC, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(ADC, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(ADC, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(ADC, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(ADC, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(ADC, ADDR_INDIRECT_INDEXED);

#define AND  // AND - Logical AND
extern const U8 OPCODE_DEFINE(AND, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(AND, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(AND, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(AND, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(AND, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(AND, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(AND, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(AND, ADDR_INDIRECT_INDEXED);

#define ASL  // ASL - Arithmetic Shift Left
extern const U8 OPCODE_DEFINE(ASL, ADDR_ACCUMULATOR);
extern const U8 OPCODE_DEFINE(ASL, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(ASL, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(ASL, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(ASL, ADDR_ABSOLUTE_X);

#define BCC  // BCC - Branch if Carry Clear
extern const U8 OPCODE_DEFINE(BCC, ADDR_RELATIVE);

#define BCS  // BCS - Branch if Carry Set
extern const U8 OPCODE_DEFINE(BCS, ADDR_RELATIVE);

#define BEQ  // BEQ - Branch if Equal
extern const U8 OPCODE_DEFINE(BEQ, ADDR_RELATIVE);

#define BIT  // BIT - Bit Test
extern const U8 OPCODE_DEFINE(BIT, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(BIT, ADDR_ABSOLUTE);

#define BMI  // BMI - Branch if Minus
extern const U8 OPCODE_DEFINE(BMI, ADDR_RELATIVE);

#define BNE  // BNE - Branch if Not Equal
extern const U8 OPCODE_DEFINE(BNE, ADDR_RELATIVE);

#define BPL  // BPL - Branch if Positive
extern const U8 OPCODE_DEFINE(BPL, ADDR_RELATIVE);

#define BRK  // BRK - Force Interrupt
extern const U8 OPCODE_DEFINE(BRK, ADDR_IMPLICIT);

#define BVC  // BVC - Branch if Overflow Clear
extern const U8 OPCODE_DEFINE(BVC, ADDR_RELATIVE);

#define BVS  // BVC - Branch if Overflow Set
extern const U8 OPCODE_DEFINE(BVS, ADDR_RELATIVE);

#define CLC  // CLC - Clear Carry Flag
extern const U8 OPCODE_DEFINE(CLC, ADDR_IMPLICIT);

#define CLD  // CLD - Clear Decimal Mode
extern const U8 OPCODE_DEFINE(CLD, ADDR_IMPLICIT);

#define CLI  // CLI - Clear Interrupt Disable
extern const U8 OPCODE_DEFINE(CLI, ADDR_IMPLICIT);

#define CLV  // CLV - Clear Overflow Flag
extern const U8 OPCODE_DEFINE(CLV, ADDR_IMPLICIT);

#define CMP  // CMP - Compare
extern const U8 OPCODE_DEFINE(CMP, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(CMP, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(CMP, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(CMP, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(CMP, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(CMP, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(CMP, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(CMP, ADDR_INDIRECT_INDEXED);

#define CPX  // CMP - Compare X Register
extern const U8 OPCODE_DEFINE(CPX, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(CPX, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(CPX, ADDR_ABSOLUTE);

#define CPY  // CPY - Compare Y Register
extern const U8 OPCODE_DEFINE(CPY, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(CPY, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(CPY, ADDR_ABSOLUTE);

#define DEC  // DEC - Decrement Memory
extern const U8 OPCODE_DEFINE(DEC, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(DEC, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(DEC, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(DEC, ADDR_ABSOLUTE_X);

#define DEX  // DEX - Decrement X Register
extern const U8 OPCODE_DEFINE(DEX, ADDR_IMPLICIT);

#define DEY  // DEY - Decrement Y Register
extern const U8 OPCODE_DEFINE(DEY, ADDR_IMPLICIT);

#define EOR  // EOR - Exclusive OR
extern const U8 OPCODE_DEFINE(EOR, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(EOR, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(EOR, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(EOR, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(EOR, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(EOR, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(EOR, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(EOR, ADDR_INDIRECT_INDEXED);

#define INC  // INC - Increment Memory
extern const U8 OPCODE_DEFINE(INC, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(INC, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(INC, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(INC, ADDR_ABSOLUTE_X);

#define INX  // INX - Increment X Register
extern const U8 OPCODE_DEFINE(INX, ADDR_IMPLICIT);

#define INY  // INY - Increment Y Register
extern const U8 OPCODE_DEFINE(INY, ADDR_IMPLICIT);

#define JMP  // JMP - Jump
extern const U8 OPCODE_DEFINE(JMP, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(JMP, ADDR_INDIRECT);

#define JSR  // JSR - Jump to Subroutine
extern const U8 OPCODE_DEFINE(JSR, ADDR_ABSOLUTE);

#define LDA  // LDA - Load Accumulator
extern const U8 OPCODE_DEFINE(LDA, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(LDA, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(LDA, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(LDA, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(LDA, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(LDA, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(LDA, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(LDA, ADDR_INDIRECT_INDEXED);

#define LDX  // LDX - Load X Register
extern const U8 OPCODE_DEFINE(LDX, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(LDX, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(LDX, ADDR_ZERO_PAGE_Y);
extern const U8 OPCODE_DEFINE(LDX, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(LDX, ADDR_ABSOLUTE_Y);

#define LDY  // LDY - Load Y Register
extern const U8 OPCODE_DEFINE(LDY, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(LDY, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(LDY, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(LDY, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(LDY, ADDR_ABSOLUTE_X);

#define LSR  // LSR - Logical Shift Right
extern const U8 OPCODE_DEFINE(LSR, ADDR_ACCUMULATOR);
extern const U8 OPCODE_DEFINE(LSR, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(LSR, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(LSR, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(LSR, ADDR_ABSOLUTE_X);

#define NOP  // NOP - No Operation
extern const U8 OPCODE_DEFINE(NOP, ADDR_IMPLICIT);

#define ORA  // Logical Inclusive OR
extern const U8 OPCODE_DEFINE(ORA, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(ORA, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(ORA, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(ORA, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(ORA, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(ORA, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(ORA, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(ORA, ADDR_INDIRECT_INDEXED);

#define PHA  // PHA - Push Accumulator
extern const U8 OPCODE_DEFINE(PHA, ADDR_IMPLICIT);

#define PHP  // PHP - Push Processor Status
extern const U8 OPCODE_DEFINE(PHP, ADDR_IMPLICIT);

#define PLA  // PLA - Pull Accumulator
extern const U8 OPCODE_DEFINE(PLA, ADDR_IMPLICIT);

#define PLP  // PLP - Pull Processor Status
extern const U8 OPCODE_DEFINE(PLP, ADDR_IMPLICIT);

#define ROL  // ROL - Rotate Left
extern const U8 OPCODE_DEFINE(ROL, ADDR_ACCUMULATOR);
extern const U8 OPCODE_DEFINE(ROL, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(ROL, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(ROL, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(ROL, ADDR_ABSOLUTE_X);

#define ROR  // ROR - Rotate Right
extern const U8 OPCODE_DEFINE(ROR, ADDR_ACCUMULATOR);
extern const U8 OPCODE_DEFINE(ROR, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(ROR, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(ROR, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(ROR, ADDR_ABSOLUTE_X);

#define RTI  // RTI - Return from Interrupt
extern const U8 OPCODE_DEFINE(RTI, ADDR_IMPLICIT);

#define RTS  // RTS - Return from Subroutine
extern const U8 OPCODE_DEFINE(RTS, ADDR_IMPLICIT);

#define SBC  // SBC - Subtract with Carry
extern const U8 OPCODE_DEFINE(SBC, ADDR_IMMEDIATE);
extern const U8 OPCODE_DEFINE(SBC, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(SBC, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(SBC, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(SBC, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(SBC, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(SBC, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(SBC, ADDR_INDIRECT_INDEXED);

#define SEC  // SEC - Set Carry Flag
extern const U8 OPCODE_DEFINE(SEC, ADDR_IMPLICIT);

#define SED  // SED - Set Decimal Flag
extern const U8 OPCODE_DEFINE(SED, ADDR_IMPLICIT);

#define SEI  // SEI - Set Interrupt Disable
extern const U8 OPCODE_DEFINE(SEI, ADDR_IMPLICIT);

#define STA  // STA - Store Accumulator
extern const U8 OPCODE_DEFINE(STA, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(STA, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(STA, ADDR_ABSOLUTE);
extern const U8 OPCODE_DEFINE(STA, ADDR_ABSOLUTE_X);
extern const U8 OPCODE_DEFINE(STA, ADDR_ABSOLUTE_Y);
extern const U8 OPCODE_DEFINE(STA, ADDR_INDEXED_INDIRECT);
extern const U8 OPCODE_DEFINE(STA, ADDR_INDIRECT_INDEXED);

#define STX  // STX - Store X Register
extern const U8 OPCODE_DEFINE(STX, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(STX, ADDR_ZERO_PAGE_X);
extern const U8 OPCODE_DEFINE(STX, ADDR_ABSOLUTE);

#define STY  // STY - Store X Register
extern const U8 OPCODE_DEFINE(STY, ADDR_ZERO_PAGE);
extern const U8 OPCODE_DEFINE(STY, ADDR_ZERO_PAGE_Y);
extern const U8 OPCODE_DEFINE(STY, ADDR_ABSOLUTE);

#define TAX  // TAX - Transfer Accumulator to X
extern const U8 OPCODE_DEFINE(TAX, ADDR_IMPLICIT);

#define TAY  // TAY - Transfer Accumulator to Y
extern const U8 OPCODE_DEFINE(TAY, ADDR_IMPLICIT);

#define TSX  // TSX - Transfer Stack Pointer to X
extern const U8 OPCODE_DEFINE(TSX, ADDR_IMPLICIT);

#define TXA  // TXA - Transfer X to Accumulator
extern const U8 OPCODE_DEFINE(TXA, ADDR_IMPLICIT);

#define TXS  // TXA - Transfer X to Stack Pointer
extern const U8 OPCODE_DEFINE(TXS, ADDR_IMPLICIT);

#define TYA  // TYA - Transfer Y to Accumulator
extern const U8 OPCODE_DEFINE(TYA, ADDR_IMPLICIT);

// Bit manipulation helpers
#define GET_BIT(byte, bit) ((byte >> bit) & 1)
#define SET_BIT(byte, bit) (byte | (1 << bit))

#define GET_PROC_FLAG(byte, flag) GET_BIT(byte, flag)
#define SET_PROC_FLAG(byte, flag) SET_BIT(byte, flag)

// Processor Flags
// NV-BDIZC
// [7] N Negative
// [6] V Overflow
// [5] - Unused
// [4] B Break
// [3] D Decimal
// [2] I Interrupt Disable
// [1] Z Zero
// [0] C Carry
#define PF_CARRY (0x01)
#define PF_ZERO (0x02)
#define PF_INTERRUPT_DISABLE (0x04)
#define PF_DECIMAL_MODE (0x08)
#define PF_BREAK_COMMAND (0x10)
// -> none
#define PF_OVERFLOW (0x40)
#define PF_NEGATIVE (0x80)

// CPU, MEMORY, MODE
typedef void (*OpcodeCB)(CPU *, U8 *, AddrMode);
typedef struct OpcodeSpec {
    U8 nbytes;
    U8 cycles;
    OpcodeCB handler;
} OpcodeSpec;

#define OPCODE_LENGTH (256)
typedef OpcodeSpec OpcodeTable[OPCODE_LENGTH];

OpcodeSpec InitOpcodeSpec(U8 nbytes, U8 cycles, OpcodeCB cb);

void InitOpcodeTable(OpcodeTable table);

#endif  // OPCODE_H
