//----------------------------------------------------------------------------
//	File:
//		CRPNCalc.cpp
//
//	Class:
//		CRPNCalc
//----------------------------------------------------------------------------

#include "CRPNCalc.h"

//----------------------------------------------------------------------------
//	Title:
//		Class CRPNCalc
//
//	Description:
//		This file contains the function definitions for CRPNCalc.
//
//	Programmer:
//		Back Row Power Posse
//
//	Date:
//		05/25/2018
// 
//	Version:
//		1.0
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
//	Related functions:
//		ostream &operator<<(ostream &ostr, const CRPNCalc &calc)
//    	istream &operator>>(istream &istr, CRPNCalc &calc)
//
//	History Log:
//                           
//----------------------------------------------------------------------------

namespace BRPP_CALC
{
//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	CRPNCalc::CRPNCalc(bool on): m_on(on), m_error(false), m_helpOn(true),
		m_programRunning(false)
	{
		for (int i = 0; i < NUMREGS; i++)
			m_registers[i] = 0.0;

		if (m_on)
			run();
	}

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::run()
	{
	
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::print(ostream &ostr)
	{
		double d = 0.0;

		ostr << "[RPN Programmable Calculator] by Back Row Power Posse"
			<< endl;

		if (m_helpOn)
			cout << helpMenu;
		else
			cout << endl << endl << endl;

		cout << line;

		if (!m_stack.empty())
		{
			d = m_stack.front();
			ostr << d;
		}

		ostr << endl << endl;

		if (m_error)
		{
			ostr << "<<error>>" << endl;
			m_error = false;
		}
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::parse()
	{

	}

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------	
	void CRPNCalc::add()
	{

	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::binary_prep(double &d1, double &d2)
	{
	
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::clearEntry()
	{
	
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::clearAll()
	{
		while (!m_stack.empty())	
			m_stack.pop_front();
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::divide()
	{

	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::exp()
	{

	}  

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::getReg(int reg)
	{
	
	}  

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::loadProgram()
	{
	
	}  

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::mod()
	{
	
	}

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::multiply()
	{
	
	}

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::neg()
	{
	   
	}

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::unary_prep(double &d)
	{
	
	}  

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::recordProgram()
	{

	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::rotateDown()
	{
	
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::rotateUp()
	{
	
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::runProgram()
	{
	
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::saveToFile()
	{
			
	}  

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::setReg(int reg)
	{
			
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::subtract()
	{

	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	void CRPNCalc::input(istream &istr)
	{

	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	ostream &operator<<(ostream &ostr, CRPNCalc &calc)
	{
		calc.print(ostr);

		return ostr;
	} 

//----------------------------------------------------------------------------
//	Class:
//		CDLL
//
//	Method:
//		CDLL(size_t n_elements, T datum)
//
//	Description:
//		Constructor for a particular amount of an element. Throws an exception
//		for an empty list.
//
//	Input:
//		Size of the array and element to be filled with
//
//	Output:
//		None
//
//	Calls:
//		push_front()
//
//	Called By:
//		main()
//
//	Parameters:
//		size_t n_elements
//		T datum
//
//	Returns:
//		None
//
//	History Log:
//		05/22/2018 AS Method completed
//
//----------------------------------------------------------------------------
	istream &operator>>(istream &istr, CRPNCalc &calc)
	{
		calc.input(istr);

		return istr;
	} 
}