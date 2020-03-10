// Module:	HexClass.h
// Author:	Miguel Antonio Logarta
// Date:	March 9, 2020
// Purpose:	Header file for HexClass.cpp
//			Convert int to hex, hex to int
//			Uses overloaded methods

#pragma once
class HexClass
{
public:
	HexClass();							// Default constructor
	HexClass(int);						// Overloaded constructor'

	int Convert(TCHAR*);				// Convert TCHAR (hex) to int
	TCHAR* Convert(int);				// Convert int to TCHAR (hex)

private:
	int iReturn;						// Return value from hex to int
	TCHAR szReturn[100];				// Return value from int to hex

};

