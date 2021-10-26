#pragma once
#include "logger.h"
#include "MainForm.h"

using namespace dcsstrainer;

void logger::WriteLinetoConsole(System::String^ s) {
	System::String^ ss = gcnew System::String(s);
	System::String^ date = DateTime::Now.ToString("HH:mm:ss");
	MainForm::instance->ConsoleLog->Items->Insert(0, (date + " - " +  ss));
}