#include "stdafx.h"
#include "System.hpp"
#include <assert.h>

struct LibGV_MemoryAllocation
{
    BYTE* mPDataStart;
    DWORD mAllocType;
};
MSG_ASSERT_SIZEOF(LibGV_MemoryAllocation, 8);

struct system_struct
{
    DWORD mFlags;
    BYTE* mStartAddr;
    BYTE* mEndAddr;
    DWORD mUnitsCount;
    LibGV_MemoryAllocation mAllocs[512];
};
MSG_ASSERT_SIZEOF(system_struct, 0x1010);

MSG_FUNC_NOT_IMPL(0x40ACB2, int __cdecl(int idx), System_sub_40ACB2);


//MSG_FUNC_NOT_IMPL(0x40B024, LibGV_MemoryAllocation *__cdecl(system_struct *pSystem, unsigned int alignedSize), System_FindMatchingAllocation_40B024);
//MSG_FUNC_NOT_IMPL(0x40B05B, LibGV_MemoryAllocation *__cdecl(system_struct *pSystem, LibGV_MemoryAllocation *pAlloc), System_sub_40B05B);

MGS_ARY(1, 0x78E980, system_struct, 3, gSystems_dword_78E980, {});

void SystemCpp_ForceLink() { }

static bool IsPowerOf2(int i)
{
    return !(i & (i - 1));
}

static DWORD RoundUpPowerOf2(DWORD numToRound, int multiple)
{
    assert(multiple && IsPowerOf2(multiple));
    return (numToRound + multiple - 1) & -multiple;
}

static DWORD RoundDownPowerOf2(DWORD numToRound, int multiple)
{
    assert(multiple && IsPowerOf2(multiple));
    return numToRound & -multiple;
}

system_struct* CC System_init_40AC6C(int index, int bIsDynamic, void* pMemory, int size)
{
    gSystems_dword_78E980[index].mFlags = bIsDynamic != 0;
    gSystems_dword_78E980[index].mStartAddr = (BYTE *)pMemory;
    
    BYTE* alignedEndPtr = (BYTE *)(pMemory) + RoundDownPowerOf2(size, 16);
    
    gSystems_dword_78E980[index].mUnitsCount = 1;
    gSystems_dword_78E980[index].mEndAddr = alignedEndPtr;
    
    gSystems_dword_78E980[index].mAllocs[0].mAllocType = 0;
    gSystems_dword_78E980[index].mAllocs[0].mPDataStart = (BYTE *)pMemory;

    gSystems_dword_78E980[index].mAllocs[1].mPDataStart = alignedEndPtr;
    gSystems_dword_78E980[index].mAllocs[1].mAllocType = 2;
    return &gSystems_dword_78E980[index];
}
MSG_FUNC_IMPL(0x40AC6C, System_init_40AC6C);

void __cdecl System_DeInit_Systems_0_to_2_sub_40AC52()
{
    for (int i = 0; i < 3; i++)
    {
        System_init_40AC6C(i, 0, nullptr, 0);
    }
}
MSG_FUNC_IMPL(0x40AC52, System_DeInit_Systems_0_to_2_sub_40AC52);

void __cdecl System_Debug_sub_40ADEC(int index)
{
    system_struct* pSystem = &gSystems_dword_78E980[index];

    printf("system %d ( ", index);
    if (pSystem->mFlags & 1)
    {
        printf("dynamic ");
    }
    if (pSystem->mFlags & 2)
    {
        printf("voided ");
    }
    if (pSystem->mFlags & 4)
    {
        printf("failed ");
    }
    printf(")\n");
    printf("  addr = %08x - %08x, units = %d\n", pSystem->mStartAddr, pSystem->mEndAddr, pSystem->mUnitsCount);

    int biggestFreeBlockSizeBytes = 0;
    int numFreeBytes = 0;
    int numVoidedBytes = 0;

    if (pSystem->mUnitsCount > 0)
    {
        LibGV_MemoryAllocation* ptr = pSystem->mAllocs;
        bool bEnd = false;
        int counter = pSystem->mUnitsCount;
        do
        {
            const int allocType = ptr->mAllocType;
            const int sizeBytes = ptr[1].mPDataStart - ptr->mPDataStart;
            if (allocType && allocType == 1)
            {
                numVoidedBytes += sizeBytes;
            }
            else
            {
                numFreeBytes += sizeBytes;
                if (sizeBytes > biggestFreeBlockSizeBytes)
                {
                    biggestFreeBlockSizeBytes = sizeBytes;
                }
            }
            bEnd = counter-- == 1;
            ++ptr;
        } while (!bEnd);
    }

    const int numTotalBytes = pSystem->mEndAddr - pSystem->mStartAddr;
    printf("  free = %d / %d, voided = %d, max_free = %d\n",
        numFreeBytes,
        numTotalBytes,
        numVoidedBytes,
        biggestFreeBlockSizeBytes);
}
MSG_FUNC_IMPL(0x40ADEC, System_Debug_sub_40ADEC);

/*
void* __cdecl System_mem_zerod_alloc_40AFA4(int idx, int size, void** alloc_type_or_ptr)
{
    system_struct *pSystem;
    unsigned int alignedSize;
    LibGV_MemoryAllocation *pAlloc;
    LibGV_MemoryAllocation *ptr;

    pSystem = &gSystems_dword_78E980[idx];
    if (pSystem->mUnitsCount >= 511)
    {
        return 0;
    }

    alignedSize = RoundUpPowerOf2(size, 16);
    
    pAlloc = System_FindMatchingAllocation_40B024(pSystem, alignedSize);
    if (!pAlloc)
    {
        pSystem->mFlags |= 4u; // mark as failed
        return 0;
    }

    ptr = reinterpret_cast<LibGV_MemoryAllocation*>(pAlloc->mPDataStart);

    const unsigned int allocSize = pAlloc[1].mPDataStart - pAlloc->mPDataStart;
    if (allocSize > alignedSize)
    {
        //System_sub_40B05B(pSystem, pAlloc);
        pAlloc[1].mAllocType = 0;
        pAlloc[1].mPDataStart = reinterpret_cast<BYTE*>(ptr + alignedSize);
    }
    pAlloc->mAllocType = (DWORD)alloc_type_or_ptr;

    if (alloc_type_or_ptr != (void**)2)
    {
        *alloc_type_or_ptr = ptr;
    }

    memset(ptr, 0, alignedSize);
    return ptr;
}
MSG_FUNC_IMPL(0x40AFA4, System_mem_zerod_alloc_40AFA4);

void* CC System_2_zerod_allocate_memory_40B296(int size)
{
    return System_mem_zerod_alloc_40AFA4(2, size, (void**)2);
}
MSG_FUNC_IMPL(0x40B296, System_2_zerod_allocate_memory_40B296);
*/
