#include <6502/memory.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// #include <byteswap.h>

U8 *CreateMemory(void) {
    return (U8 *)calloc(DEFAULT_MEMSIZE, sizeof(U8));
}

void DestroyMemory(U8 *mem) {
    free(mem);
}

void StoreMemory(U8 *dst, U8 *src, U32 offset, U32 memsize, U8 endian) {
    assert(dst);
    assert(src);
    assert(offset + memsize - 1 <= DEFAULT_MEMSIZE);

    // NOTE: switch for loop with some memcpy endian version
    // __builtin_bswap32 (GCC)
    //
    if (endian == LITTLE_ENDIAN_6502) {
        for (U32 i = 0; i < memsize; i++) {
            dst[offset + memsize - i - 1] = src[i];
        }
    }

    if (endian == BIG_ENDIAN_6502) {
        memcpy(dst + offset, src, memsize);
    }
}

U8 *readMemory(U8 *src, U32 offset, U32 memSize, U8 endian) {
    assert(src);
    assert(offset + memSize - 1 <= DEFAULT_MEMSIZE);

    if (endian == LITTLE_ENDIAN_6502) {
        return src + offset;
    }

    if (endian == BIG_ENDIAN_6502) {
        return src + offset;
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
