#pragma once
#include "stdafx.h"


namespace mem
{
	/*
	Patches a memory location.
	dst : pointer to the memory location
	src : the bytes you wish to patch the location with
	size: how many bytes you are patching
	process : handle to the process you are patching
	*/
	void Patch(uintptr_t* dst, uintptr_t* src, unsigned int size);

	/*
	Patches a flag for all objects in your inventory, given an address to the start of the inventory struct.
	start : pointer to the memory location
	flag : the ident_flag you wish to patch with
	offset: which flag you will be patching
	process : handle to the process you are patching
	*/
	void PatchItemFlag(uintptr_t* start, const uintptr_t* flag);

	/*
	Patches bytes given an address to the first entity struct in the entity vector.
	start : pointer to the memory location
	process : handle to the process you are patching
	*/
	void EntityPatch(uintptr_t* start, const uintptr_t* bytes, int numBytes, uintptr_t offset);
	
	/* patches ally only*/
	void AllyPatch(uintptr_t* start, const uintptr_t* bytes, int numBytes, uintptr_t offset);

	/*
	Patches a memory location in the inventory. Really should have several overrides
	*/
	void InventoryPatch(uintptr_t* start, uintptr_t* bytes, int numBytes, uintptr_t offset);

	/* change wand charges to max */
	void WandChargePatch(uintptr_t* start, uintptr_t* bytes, int numBytes, uintptr_t offset);

	/*
	Patches a memory location with bytes representing nop
	*/
	void Nop(uintptr_t* dst, unsigned int size);

	/*
	Reads `size` bytes from memory location `dst`. `arr` is a pointer to a buffer holding the read data.
	*/
	void Read(uintptr_t* dst, uintptr_t* arr, unsigned int size);

}