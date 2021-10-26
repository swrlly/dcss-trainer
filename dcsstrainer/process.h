#pragma once
#include <vector>
#include <windows.h>
#include <TlHelp32.h>

// initialize functions

//  given the string of a process's name, returns the process ID
DWORD GetProcessID(const wchar_t* name);

// given the process id, returns a pointer to the base address of the process
uintptr_t ModuleBaseAddress(DWORD procID, const wchar_t* name);

// given a handle to a process and the pointer to it's base address, follow pointer chains to find a dynamic memory address
uintptr_t DynamicMemoryAddress(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
