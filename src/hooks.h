#pragma once
#include "stdafx.h"

void* seax;
void* sebx;
void* secx;
void* sedx;
void* sesi;
void* sedi;
void* sebp;
void* sesp;

namespace hooks {

	/*
	Inserts a hook at `hookAddress` to jump to jumpAddress. Fails if size if < 5.
	Don't do pointer arithmetic (but really, we should treat these as pointers...)
	*/
	bool Hook(uintptr_t moduleBase, uintptr_t hookAddress, void* jumpAddress, unsigned int size) {
		if (size < 5) {
			return false;
		}

		DWORD oldprotect;
		VirtualProtect((LPVOID*)(moduleBase + hookAddress), size, PAGE_EXECUTE_READWRITE, &oldprotect);
		// jmp jumpAddress
		// write jmp first
		memset((uintptr_t*)(moduleBase + hookAddress), 0xE9, 1);
		// calculate relative offset as the PC increments then jumps
		uintptr_t relativeAddress = (uintptr_t)jumpAddress - hookAddress - moduleBase - 5;
		// you need to increment one byte, dereference then add to just add one byte
		*(uintptr_t*)(moduleBase + hookAddress + 1) = (uintptr_t)relativeAddress;
		// then however many bytes are left, write nops
		memset((uintptr_t*)(moduleBase + hookAddress + 5), 0x90, size - 5);
		VirtualProtect((LPVOID*)(moduleBase + hookAddress), size, oldprotect, &oldprotect);
		return true;
		
	}
	
	// edx stores change in x
	void __declspec(naked) disableX(void) {
		__asm {
			add edx, 0x0
			mov eax, [ebp - 0xA0]
			jmp [disablexRetAddy]
		}
	}

	// eax stores change in y
	void _declspec(naked) disableY(void) {
		__asm {
			add eax, 0x0
			lea ecx, [edx - 0x01]
			jmp [disableyRetAddy]
		}
	}

	void __declspec(naked) instakill(void) {
		__asm {
			sub eax, esi
			cmp eax, edx
			mov [ebx + 0x54], 0x0
			jmp [instakillRetAddy]
		}
	}

	// at this point, you want to take addr of needsmapchange and set it to true
	void __declspec(naked) MapChange(void) {

		__asm {
			mov eax, [ebp-0x0000015C]
			mov seax, eax
			mov eax, dword ptr needsMagicMap
			mov [needsMagicMap], 0x1
			mov eax, seax
			jmp [hookMapChangeRetAddy]
		}
	}

	// after needsmapchange has been set to true, after one tick on the new level, apply magic mapping
	void __declspec(naked) ApplyMapChange(void) {
		/*
		couple of tasks:
		- save all registers
		- set needtomap to false
		- if needsmagicmap == true:
			- magic_map();
		- mov [esp], 0x00000001
		- restore all registers
		jump
		*/
		__asm {
			mov seax, eax
			mov sebx, ebx
			mov secx, ecx
			mov sedx, edx
			mov sesi, esi
			mov sedi, edi
			mov sebp, ebp
			mov sesp, esp
			mov eax, dword ptr needsMagicMap
			test al, al										// if needsmagicmap == true:
			mov [needsMagicMap], 0x0
			je skip											// take branch if you don't need to map, in which zf = 1
			mov dword ptr [esp + 0x14],  0x0000001A			// in bounds
			mov dword ptr [esp + 0x18], 0x0000001A
			mov dword ptr [esp + 0x10], 0x00000000
			mov dword ptr [esp + 0xC], 0x00000000
			mov dword ptr [esp + 0x08], 0x00000000
			mov dword ptr [esp + 0x04], 0x00000064
			mov dword ptr [esp], 0x000001F4
			call magicMappingAddy
skip:		mov eax, seax
			mov ebx, sebx
			mov ecx, secx
			mov edx, sedx
			mov esi, sesi
			mov edi, sedi
			mov ebp, sebp
			mov esp, sesp
			
			mov [esp], 0x00000001 // execute stolen bytes
			jmp [updateTickRetAddy]
		}

	}

	/* this function is depreciated, do not use */
	void __declspec(naked) hookMapChange(void) {

		/*
			crawl-tiles.exe+250E18 - C7 44 24 14 FFFFFFFF		- mov [esp+14],FFFFFFFF { -1 }
			crawl-tiles.exe+250E20 - C7 44 24 18 FFFFFFFF		- mov [esp+18],FFFFFFFF { -1 }
			crawl-tiles.exe+250E28 - C7 44 24 10 00000000		- mov [esp+10],00000000 { 0 }
			crawl-tiles.exe+250E30 - C7 44 24 0C 00000000		- mov [esp+0C],00000000 { 0 }
			crawl-tiles.exe+250E38 - C7 44 24 08 00000000		- mov [esp+08],00000000 { 0 }
			crawl-tiles.exe+250E40 - C7 44 24 04 64000000		- mov [esp+04],00000064 { 100 }
			crawl-tiles.exe+250E48 - C7 04 24  F4010000			- mov [esp],000001F4 { 500 }
			crawl-tiles.exe+250E4F - C7 85 F8FEFFFF 02000000	- mov [ebp-00000108],00000002 { 2 }
			crawl-tiles.exe+250E59 - E8 22473E00				- call crawl-tiles.exe+635580 { magic mapping function }
			crawl-tiles.exe+635580 - 55							- push ebp { start of magic mapping function }
			crawl-tiles.exe+635581 - 89 E5						- mov ebp,esp
			crawl-tiles.exe+635583 - 57							- push edi
			crawl-tiles.exe+635584 - 53							- push ebx
			crawl-tiles.exe+635585 - 81 EC 60010000				- sub esp,00000160 { 352 }
			crawl-tiles.exe+63558B - 8B 55 18					- mov edx,[ebp+18]
			crawl-tiles.exe+63558E - 8B 45 10					- mov eax,[ebp+10]

			aite so, look how they're moving esp into ebp. passed values are referred from the base pointer from the stack frame then.
			thus we can just push values and call / restore / jmp back
			how about the struct tho?
			esp is 01DFF170
		
		*/
		// this corrupts the stack (bc u forgot that hooked instruction). also, it only applies mmap on the level you just existed so useless af
		__asm {
			mov seax, eax
			mov sebx, ebx
			mov secx, ecx
			mov sedx, edx
			mov sesi, esi
			mov sedi, edi
			mov sebp, ebp
			mov sesp, esp
			mov [esp + 0x14], 0x0000001A	// in bounds
			mov [esp + 0x18], 0x0000001A
			mov [esp + 0x10], 0x00000000
			mov [esp + 0xC], 0x00000000
			mov [esp + 0x08], 0x00000000
			mov [esp + 0x04], 0x00000064
			mov [esp], 0x000001F4
			call magicMappingAddy
			mov eax, seax
			mov ebx, sebx
			mov ecx, secx
			mov edx, sedx
			mov esi, sesi
			mov edi, sedi
			mov ebp, sebp
			mov esp, sesp
			jmp [hookMapChangeRetAddy]
		}

	}


}