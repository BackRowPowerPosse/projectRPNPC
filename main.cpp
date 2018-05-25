//----------------------------------------------------------------------------
//	File:
//		main.cpp
//
//	Function:
//		int main()
//----------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include "CRPNCalc.h"

using namespace BRPP_CALC;

//----------------------------------------------------------------------------
//	Function:
//		main()
//
//	Title:
//		Driver for RPN Calculator
//
//	Description:
//		This file contains function main() which creates and starts a
//		calculator
//
//	Programmer:
//		BRPP
//   
//	Date:
//		5/20/14
// 
//	Version:
//		1.0
//  
//	Calls:
//		CRPNCalc()
// 
//	Returns:
//		int EXIT_SUCCESS (1)
//
//	History Log:
//		4/205/14 PB completed version 1.0
//
//----------------------------------------------------------------------------
int main()
{
	CRPNCalc myCalc;

	cout << endl;
	cout << "Press \"Enter\" to finish";
	cin.get();

	return EXIT_SUCCESS;
}
