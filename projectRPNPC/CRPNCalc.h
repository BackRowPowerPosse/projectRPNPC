//----------------------------------------------------------------------------
//	File:
//		CRPNCalc.h
//
//	Class:
//		CRPNCalc
//----------------------------------------------------------------------------

#pragma once
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <new>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

namespace BRPP_CALC
{
	const unsigned short NUMREGS = 10;

//----------------------------------------------------------------------------
//	Title:
//		CRPNCalc Class
//
//	Description:
//		This file contains the class definition for CRPNCalc.
//
//	Programmer:
//		Back Row Power Posse
//   
//	Date:
//		5/3/11
// 
//	Version:
//		1.03
//  
//	Properties:
//		double m_registers[NUMREGS]
//		string m_buffer
//		deque<double> m_stack
//		list<string> m_program
//		istringstream m_instrStream
//		bool m_error
//		bool m_helpOn
//		bool m_on
//		bool m_programRunning
//
//	Methods:
//		CRPNCalc(bool on = true)
//		void run()
//		void print(ostream &ostr)
//		void input(istream &istr)
//		void add()
//		void binary_prep(double &d1, double &d2)
//		void clearEntry()
//		void clearAll()
//		void divide()
//		void exp()
//		void getReg(int reg)
//		void loadProgram()
//		void mod()
//		void multiply()
//		void neg()
//		void parse()
//		void recordProgram()
//		void rotateUp()
//		void rotateDown()
//		void runProgram()
//		void saveToFile()
//		void setReg(int reg)
//		void subtract()
//		void unary_prep(double &d)
//
//	History Log:
//		4/20/03	PB Completed version 1.0
//		5/27/05	PB Minor modifications 1.01
//		5/3/11 PB Minor modifications 1.02
//		6/3/12 PB Minor modifications 1.03
//
//----------------------------------------------------------------------------
	class CRPNCalc
	{
	public:
		CRPNCalc(bool on = true);
		void run();                                        
		void print(ostream &ostr);
		void input(istream &istr);

	private:
		void add();
		void binary_prep(double &d1, double &d2);
		void clearEntry();
		void clearAll();
		void divide();
		void exp();
		void getReg(int reg);
		void loadProgram();
		void mod();
		void multiply();
		void neg();
		void parse();
		void recordProgram();
		void rotateUp();
		void rotateDown();
		void runProgram();
		void saveToFile();
		void setReg(int reg);
		void subtract();
		void unary_prep(double &d);

		double m_registers[NUMREGS];
		string m_buffer;
		deque<double> m_stack;
		list<string> m_program;
		istringstream m_instrStream;
		bool m_error;
		bool m_helpOn;
		bool m_on;
		bool m_programRunning;
	};

	ostream &operator<<(ostream &ostr, CRPNCalc &calc);
	istream &operator>>(istream &istr, CRPNCalc &calc);
	void printLine(ostream &ostr);
	void printMenu(ostream &ostr);
}