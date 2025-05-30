#include <6502/memory.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <byteswap.h>

U8 *CreateMemory(void) {
    return (U8*)calloc(DEFAULT_MEMSIZE, sizeof(U8));
}

void DestroyMemory(U8 *mem) {
   free(mem);
}

void StoreMemory(U8 *dst, U8 *src, U32 offset, U32 memsize, U8 endian) {
    assert(dst);
    assert(src);
    assert(offset + memsize < DEFAULT_MEMSIZE);

    // NOTE: switch for loop with some memcpy endian version
    // __builtin_bswap32 (GCC)
    // 
    if (endian == LITTLE_ENDIAN) {
        for (U32 i = 0; i < memsize; i++) {
            dst[offset+memsize-i-1] = src[i];
        }
    }

    if (endian == BIG_ENDIAN) {
        memcpy(dst+offset, src, memsize);
    }
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
