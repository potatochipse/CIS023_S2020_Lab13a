// Module:	HexClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	March 9, 2020
// Purpose:	Implementation file for HexClass
//			Convert int to hex, hex to int
//			Uses overloaded methods

#include "CIS023_S2020_Lab13a Miguel Antonio Logarta.h"
#include "HexClass.h"

HexClass::HexClass()
{
	int i = 0;
}

HexClass::HexClass(int i)
{
	i = 1;
}

int HexClass::Convert(TCHAR* szIn)
{
	iReturn = 0;								// Initialize return value

	if (lstrlen(szIn) != 0)						// Do nothing if the input is empty
	{
		wstring temp(szIn);						// Convert TCHAR to stream
		string str(temp.begin(), temp.end());	// Convert stream to string

		iReturn = stoul(
			str,								// Source, string object
			NULL,								// Pointer to end character (not used)
			16);								// Hex, base 16
	}

	return iReturn;								// Return converted number
}

TCHAR* HexClass::Convert(int iIn)
{
	size_t pReturnValue;						// Return value for mbstowcs_s()
	stringstream sStream;						// Temp stream for type conversion

	sStream << hex << iIn;						// Stream integer to hex value

	string strHex(sStream.str());				// Convert stream to string

	mbstowcs_s(									// Convert string to TCHAR
		&pReturnValue,							// Return value
		szReturn,								// Destination TCHAR
		100,									// Size of destination TCHAR
		strHex.c_str(),							// Source string
		100);									// Max # of chars to convert

	return szReturn;							// Return converted value in hex
}
