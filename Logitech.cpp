// Logitech.cpp: implementation of the Logitech class.
//
// See Logitech.h for global class details
//
// (c) Copyright 2000 by Vincent Oostindie
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "shellapi.h"
#include "Logitech.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Logitech::Logitech()
{
	// Initialize the m_bActive member
	Update();

	// Set the found-flag to false initially
	m_bFound = false;

	// Find out where the application is installed
	CRegKey regkey;
	if (regkey.Open(HKEY_LOCAL_MACHINE, LOGITECH_REG_KEY) == ERROR_SUCCESS) {
		DWORD count = MAX_PATH;
		if (regkey.QueryValue(m_strFilename, LOGITECH_REG_VALUE, &count) == ERROR_SUCCESS) {
			strcat(m_strFilename, LOGITECH_APPNAME);
			m_bFound = true;
		}
		regkey.Close();
	}
}

Logitech::~Logitech()
{
	// Nothing to do here...
}

//////////////////////////////////////////////////////////////////////
// Member functions
//////////////////////////////////////////////////////////////////////

// Look for the application and return a handle to it if found
inline HWND Logitech::GetHWND()
{
	// Find the Logitech E/M Executive
	return FindWindow(LOGITECH_CLASSNAME, NULL);
} 

// Update the internal information (is the application running or not?)
inline void Logitech::Update() 
{
	if (GetHWND())
		m_bActive = true;
	else
		m_bActive = false;
}

// Return whether the Logitech E/M Executive application is active or not
inline bool Logitech::IsActive() 
{
	return m_bActive;
}

// Start the application
bool Logitech::Start()
{
	// Don't do anything if the application isn't active or wasn't found in the registry
	if (m_bActive || !m_bFound) return false;

	// Run the application
	if ((int)ShellExecute(GetDesktopWindow(), "open", m_strFilename, NULL, NULL, SW_SHOWNORMAL) > 31) {
		m_bActive = true;
		return true;
	}
	return false;
}

// Stop the application
bool Logitech::Stop()
{
	// If the application is not active, do nothing
	if (!m_bActive) return false;

	// Send the application the message to stop
	if (PostMessage(GetHWND(), WM_CLOSE, 0, 0)) {
		m_bActive = false;
		return true;
	}
	return false;
}

// Switch modes from on to off, or vice versa.
bool Logitech::Toggle()
{
	if (m_bActive)
		return Stop();
	else
		return Start();
}
// EOF