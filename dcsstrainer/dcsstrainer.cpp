#include "process.h"
#include <stdio.h>
#include <tlhelp32.h>

DWORD processID = NULL, processID2 = NULL;
HANDLE process = NULL, thread = NULL;
wchar_t crawlName[30] = L"crawl-tiles.exe";
wchar_t crawlName2[30] = L"crawl.exe";
wchar_t dllName[80] = L"src.dll";

void inject_trainer() {

	processID = GetProcessID((wchar_t*)crawlName);

	// if successful
	if (processID) {

		printf("Found crawl. Attempting to start trainer...\n");

		// get handle to crawl
		process = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, processID);

		wchar_t fullPath[MAX_PATH];
		DWORD length = GetFullPathNameW(dllName, MAX_PATH, fullPath, NULL);

		// virtualalloc memory for dll name
		int numBytes = (length + 1) * sizeof(wchar_t);
		LPVOID memory = VirtualAllocEx(process, NULL, numBytes, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		if (!memory) {
			printf("Unable to allocate memory in crawl. Exiting...\n");
			return;
		}
		
		// write dll name in
		bool successful = WriteProcessMemory(process, memory, fullPath, numBytes, NULL);
		if (!successful) {
			printf("Unable to write DLL name into crawl. Exiting...\n");
			return;
		}
	
		// find address of LoadLibraryW
		PTHREAD_START_ROUTINE loadlibraryAddy = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryW");
		// this is a function ptr
		if (loadlibraryAddy == NULL) {
			printf("Unable to retrieve address for LoadLibraryW. Exiting...\n");
			return;
		}

		HANDLE thread = CreateRemoteThread(process, NULL, 0, loadlibraryAddy, memory, 0, NULL);
		if (thread == NULL) {
			printf("Could not create remote thread. Exiting...\n");
		}

		DWORD status = WaitForSingleObject(thread, INFINITE);
		printf("Trainer started. Closing this window...\n");

		/*
		* TODO: eject dll if user closes
		if (memory != NULL) {
			VirtualFreeEx(process, memory, 0, MEM_RELEASE);
		}
		if (thread != NULL) {
			CloseHandle(thread);
		}
		*/
	}
	else {
		printf("Start the game before starting the trainer!\n");
	}
}

void main() {
	inject_trainer();
	Sleep(5000);
}