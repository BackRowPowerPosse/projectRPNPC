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
		string input; 
		m_instrStream ;

		/*
		check if input is a number
		if not a number:
			check for all possible commands
		*/
		if ()
		{

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
	void CRPNCalc::add()
	{
		double numOne;
		double numTwo;
		/*
		call binary_prep()
		check for m_error
		*/
		binary_prep(numOne, numTwo);

		if (!m_error)
			m_stack.push_front(numOne + numTwo);
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
	/*
	check if m_stack is empty
	else
		pop number off of stack
	*/
		if (m_stack.empty())
		{
			m_error = true;
			cout << "Queue is empty.";
		}
		else
		{
			d1 = m_stack.back(); //FIFO -- back of Queue is first number
			m_stack.pop_back();
		}

		//check for 2nd number
		if (m_stack.empty())
		{
			m_error = true;
			cout << "Only one number in Queue.";
		}
		else
		{
			d2 = m_stack.back(); //FIFO -- back of Queue is second number
			m_stack.pop_back();
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
		/*
		if numTwo is 0, 
		set m_error = true; 
		(cannot divide or mod by 0, causes undefined behavior)
		*/
		double numOne;
		double numTwo;
		/*
		call binary_prep()
		check for m_error
		*/
		binary_prep(numOne, numTwo);

		if (numTwo == 0)
		{
			m_error = true;
			cout << "Cannot divide by 0.";
		}
		if (!m_error)
			m_stack.push_front(numOne/numTwo);
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
		/*
		if numTwo is 0,
		set m_error = true;
		(cannot divide or mod by 0, causes undefined behavior)
		*/
		double numOne;
		double numTwo;
		/*
		call binary_prep()
		check for m_error
		*/
		binary_prep(numOne, numTwo);

		if (!m_error)
			m_stack.push_front(pow(numOne, numTwo));
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
		/*
		if numTwo is 0,
		set m_error = true;
		(cannot divide or mod by 0, causes undefined behavior)
		uses fmod to do mod operation on doubles
		*/
		double numOne;
		double numTwo;
		/*
		call binary_prep()
		check for m_error
		*/
		binary_prep(numOne, numTwo);

		if (numTwo == 0)
		{
			m_error = true;
			cout << "Cannot mod by 0.";
		}
		if (!m_error)
			m_stack.push_front(fmod(numOne, numTwo));
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
		double numOne;
		double numTwo;
		/*
		call binary_prep()
		check for m_error
		*/
		binary_prep(numOne, numTwo);

		if (!m_error)
			m_stack.push_front(numOne * numTwo);
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

		if (m_stack.empty())
		{
			m_error = true;
			cout << "Queue is empty.";
		}
		else
		{
			d = m_stack.back(); //FIFO -- back of Queue is first number
			m_stack.pop_back();
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
		/*
		remove first element, place it at the back
		*/
		double front = m_stack.front();
		m_stack.pop_front();
		m_stack.push_back(front);
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
		/*
		remove last element, place it at the front
		*/
		double back = m_stack.back();
		m_stack.pop_back();
		m_stack.push_front(back);
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
	//while m_on.....
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
		double numOne;
		double numTwo;
		/*
		call binary_prep()
		check for m_error
		*/
		binary_prep(numOne, numTwo);

		if (!m_error)
			m_stack.push_front(numOne - numTwo);
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