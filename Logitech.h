// Logitech.h: interface for the Logitech class.
//
// Class Logitech implements a starting- and stopping-mechanism for
// the Logitech E/M Executive application (EM_EXEC.EXE). Although
// this application is very useful in normal Windows operation (it
// defines the buttons and such), it isn't when playing games. 
// Therefore it's handy to toggle it on or off easily. That's exactly
// what this class is for.
//
// On creation, an object of type Logitech searches in the system 
// registry for the Logitech software. This enables the object
// to find out where (and if) the Logitech software is installed.
// Also, it checks whether EM_EXEC.EXE is currently running.
//
// A Logitech object doesn't constantly monitor the system for the
// existence of the application in memory! Instead, it only does so
// when created, and whenever the Update() member-function is called.
//
// All in all, the class offers the following functions:
// - bool IsActive(): returns whether the application is active
// - bool Toggle()  : toggles the state of the application
// - void Update()  : Re-initialize internal information
//
// The value of the LOGITECH_REG_VALUE key in the registry, 
// concatenated with the LOGITECH_APPNAME form the full pathname
// of the application, e.g.:
//   'C:\Program Files\Logitech\system\Em_exec.exe'
//
// (c) Copyright 2000 by Vincent Oostindie
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGITECH_H__96FF34E9_4061_11D4_BB1E_C70E98D3707A__INCLUDED_)
#define AFX_LOGITECH_H__96FF34E9_4061_11D4_BB1E_C70E98D3707A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Some #defines for easy access
#define LOGITECH_REG_KEY	"Software\\Logitech\\MouseWare\\CurrentVersion\\Setup"
#define LOGITECH_REG_VALUE	"MouseWare Directory"
#define LOGITECH_APPNAME	"\\system\\Em_exec.exe"
#define LOGITECH_CLASSNAME	"Logitech E/M Executive"

// Logitech class declaration
class Logitech  
{
private:
	// Private member variables
	bool m_bActive;
	bool m_bFound;
	char m_strFilename[MAX_PATH];

	// Private member functions
	bool Start();
	bool Stop();
	HWND GetHWND();

public:
	// Construction
	Logitech();
	virtual ~Logitech();

	// Member functions
	bool IsActive();
	bool Toggle();
	void Update();
};

#endif // !defined(AFX_LOGITECH_H__96FF34E9_4061_11D4_BB1E_C70E98D3707A__INCLUDED_)
// EOF