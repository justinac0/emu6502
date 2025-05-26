#ifndef MEMORY_H
#define MEMORY_H

#include <6502/types.h>

// ---------------------------------------
// Perf Memory
// ---------------------------------------
//
// Memory Layout
// Zero Page
#define ZERO_PAGE_FIRST (0x0000)
#define ZERO_PAGE_LAST (0x00FF)
// Stack
#define STACK_FIRST (0x0100)
#define STACK_LAST (0x01FF)
// RAM
#define RAM_FIRST (0x0200)
#define RAM_LAST (0x7FFF)
// ROM
#define ROM_FIRST (0x8000)
#define ROM_LAST (0xFFF9)
// Reserved
#define RESERVE_FIRST (0xFFFA)
#define RESERVE_LAST (0xFFFF)

#define DEFAULT_MEMSIZE (0xFFFF)

#define LITTLE_ENDIAN 0x0
#define BIG_ENDIAN 0x1

void StoreMemory(U8 *dst, U8 *src, U32 offset, U32 memsize, U8 endian);
U8* CreateMemory(void);
void DestroyMemory(U8 *mem);
void PrintMemory(U8 *mem, U32 begin, U32 end);



#endif // MEMORY_H