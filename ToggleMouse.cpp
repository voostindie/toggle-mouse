// ToggleMouse.cpp : Defines the entry point for the application.
//
// ToggleMouse is a small application that toggles the Logitech E/M 
// Executive (EM_EXEC.EXE) application: when it's running, it is 
// stopped, and when it's not running, it is started.
//
// See Logitech.h for details on the implementation.
//
// (c) Copyright 2000, by Vincent Oostindie
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Logitech.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// Thanks to OOP, this is all there's to it:
 	Logitech mouse;
	mouse.Toggle();
	return 0;
}
// EOF