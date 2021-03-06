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
//		void printLine(ostream &ostr)
//		void printMenu(ostream &ostr)
//
//	History Log:
//                           
//----------------------------------------------------------------------------

namespace BRPP_CALC
{
//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		CRPNCalc()
//
//	Description:
//		Initializes properties that need initializing, sets all of the
//		registers to 0.0, and if the property "m_on" is set to "true", calls
//		run().
//
//	Input:
//		A switch to turn on the calculator
//
//	Output:
//		None
//
//	Calls:
//		run()
//
//	Called By:
//		main()
//
//	Parameters:
//		bool on
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	CRPNCalc::CRPNCalc(bool on) : m_on(on), m_error(false), m_helpOn(true),
		m_programRunning(false)
	{
		for (int i = 0; i < NUMREGS; i++)
			m_registers[i] = 0.0;

		if (m_on)
			run();
	}

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		run()
//
//	Description:
//		Sets the calculator running.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		CRPNCalc()
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::run()
	{
		while (m_on)
		{
			system("cls");
			print(cout);
         	cin >> *this;
		}
	} 

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		print()
//
//	Description:
//		Prints the identifying line, the help menu if "m_helpOn" is "true",
//		the element at the top of the stack if it is not empty, and
//		"<<error>>" if "m_error" is "true" (then sets "m_error" to "false").
//
//	Input:
//		The output stream for printing
//
//	Output:
//		None
//
//	Calls:
//		printMenu()
//		printLine()
//		empty()
//		front()
//
//	Called By:
//		N/A
//
//	Parameters:
//		ostream &ostr
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::print(ostream &ostr)
	{
		double d = 0.0;

		ostr << "[RPN Programmable Calculator] by Back Row Power Posse"
			<< endl;

		if (m_helpOn)
			printMenu(cout);
		else
			cout << endl << endl << endl;

		printLine(cout);

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
//		CRPNCalc
//
//	Method:
//		parse()
//
//	Description:
//		Extracts and executes the commands that are in "m_instrStream".  
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::parse()
	{
		/*
		check if  is a number
		if not a number:
		check for all possible commands
		*/
		string inputString = m_instrStream.str();
		m_error = false;
		bool number;

		try
		{
			m_stack.push_front(stod(inputString));
			number = true;
		}
		catch (const std::exception&)
		{
			//input is not a number
			number = false;
		}

		//check for commands
		if (number == false)
		{

			if (inputString.length() == 1)
			{
					switch (tolower(inputString.front()))
					{
					case 'c':
						//clear stack
						cout << "Clearing stack...";
						clearAll();
						break;
					case 'd':
						cout << "Rotating stack down...";
						rotateDown();
						break;
					case 'u':
						cout << "Rotating stack up.";
						rotateUp();
						break;
					case 'f':
						saveToFile();
						break;
					case 'h':
						m_helpOn = true;
						break;
					case 'l':
						loadProgram();
						break;
					case 'r':
						runProgram();
						break;
					case 'm':
						neg();
						break;
					case 'p':
						recordProgram();
						break;
					case 'x':
						m_on = false;
						break;
					case '+':
						add();
						break;
					case '-':
						subtract();
						break;
					case '/':
						divide();
						break;
					case '*':
						multiply();
						break;
					case '%':
						mod();
						break;
					case '^':
						exp();
						break;
					default:
						//not valid command
						m_error = true;
						cout << "Unknown command";
						break;
					}
			}
			//check for operators
			else if (inputString.length() == 2)
			{
				//check for register/clear entry

				if (inputString.front() == 'c' && inputString.back() == 'e')
					clearEntry();
				if (inputString.front() == 's' && inputString.back() == 'q')
					sqrt();

				if ((isalpha(inputString.front())) && isdigit(inputString.back()))
				{
					switch (tolower(inputString.front()))
					{
					case 's':
						//setreg
						cout << "Set reg....";
						setReg(static_cast<int>(inputString.back() - '0'));
						break;
					case 'g':
						cout << "Get reg...";
						getReg(static_cast<int>(inputString.back() - '0'));
						break;
					default:
						cout << "Unknown command";
						m_error = true;
						break;
					}
				}

			}
		}
	}

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		add()
//
//	Description:
//		If possible, pops two elements from the stack, adds them and pushes
//		the result onto the stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		binary_prep()
//
//	Description:
//		Sets the arguments to the popped values from the stack, if possible.
//		Sets an error state otherwise.
//
//	Input:
//		Two references to numbers
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		double &d1
//		double &d2
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		clearEntry()
//
//	Description:
//		Removes one element from the stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::clearEntry()
	{
		if (!m_stack.empty())
			m_stack.pop_front();
	} 

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		clearAll()
//
//	Description:
//		Empties the stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		empty()
//		pop_front()
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::clearAll()
	{
		while (!m_stack.empty())	
			m_stack.pop_front();
	} 

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		divide()
//
//	Description:
//		If possible, pops two elements from the stack, divides them and pushes
//		the result onto the stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		exp()
//
//	Description:
//		If possible, pops two elements from the stack, raises one element to
//		the other power and pushes the result onto the stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::exp()
	{
		double numOne;
		double numTwo;
		/*
		call binary_prep()
		check for m_error
		*/
		binary_prep(numOne, numTwo);

		if (!m_error)
			m_stack.push_front(powf(numOne, numTwo));
	}
	//----------------------------------------------------------------------------
	//	Class:
	//		CRPNCalc
	//
	//	Method:
	//		sqrt()
	//
	//	Description:
	//		If possible, pops a single element from the stack, finds the result of
	//		first number sqrt, and pushes the result onto the
	//		stack.
	//
	//	Input:
	//		None
	//
	//	Output:
	//		None
	//
	//	Calls:
	//		N/A
	//
	//	Called By:
	//		N/A
	//
	//	Parameters:
	//		None
	//
	//	Returns:
	//		None
	//
	//	History Log:
	//		N/A
	//
	//----------------------------------------------------------------------------
	void CRPNCalc::sqrt()
	{
		/*
		if numTwo is 0,
		set m_error = true;
		(cannot sqrt <= 0, causes undefined behavior)
		*/
		double numOne;
		/*
		call unary_prep()
		check for m_error
		*/
		unary_prep(numOne);

		if (numOne <= 0)
		{
			m_error = true;
			cout << "Non-real number";
		}
		if (!m_error)
			m_stack.push_front(sqrtf(numOne));
	}

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		getReg()
//
//	Description:
//		Pushes the given register's value onto the stack.
//
//	Input:
//		The register to be pushed
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		int reg
//
//	Returns:
//		None
//
//	History Log:
//		6/5/2018 CS updated
//
//----------------------------------------------------------------------------
	void CRPNCalc::getReg(int reg)
	{
		m_stack.push_front(m_registers[reg]);
	}  

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		loadProgram()
//
//	Description:
//		Retrieves the filename from the user and loads it into "m_program".
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		6/8/2018 CS updated
//		6/8/2018 AS updated
//      6/9/2018 CS updated
//----------------------------------------------------------------------------
	void CRPNCalc::loadProgram()
	{
		string temp;
		ifstream inFile;

		cout << "Enter name of file to load: ";
		cin >> temp;
		inFile.open(temp);
		if (!inFile) // file was not opened correctly
		{
			cout << "<<error>>";
			system("cls");
			printMenu(cout);
		}
		else
		{
			while (getline(inFile, temp))
				m_program.push_back(temp);
			inFile.close();
			system("cls");
			printMenu(cout);
		}
			
	}  

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		mod()
//
//	Description:
//		If possible, pops two elements from the stack, finds the result of
//		first number modulos the second number, and pushes the result onto the
//		stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		multiply()
//
//	Description:
//		If possible, pops two elements from the stack, multiplies them
//		and pushes the result onto the stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		neg()
//
//	Description:
//		Resets the top element of the stack to it's negative.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		6/6/2018 AS updated
//
//----------------------------------------------------------------------------
	void CRPNCalc::neg()
	{
		double temp = -1 * m_stack.front();

		m_stack.pop_front();

		m_stack.push_front(temp);
	}

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		unary_prep()
//
//	Description:
//		Sets the arguments to the popped value from the stack, if possible.
//		Sets an error state otherwise.
//
//	Input:
//		One reference to a number
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		double &d
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		recordProgram()
//
//	Description:
//		Takes command-line input and loads it into "m_program".
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		6/6/2018 CS updated
//		6/9/2018 CS updated
//----------------------------------------------------------------------------
	void CRPNCalc::recordProgram()
	{
		int lineNum = 0;
		string temp;
		size_t found_p = string::npos; //value returned from find() if not 
		size_t found_P = string::npos; //found. is equal to -1
		do
		{
			cout << lineNum++ << ">";
			cin >> temp;
			found_p = temp.find('p');
			found_P = temp.find('P');
			if (found_p != -1)
				temp.erase(found_p);
			if (found_P != -1)
				temp.erase(found_P);

			if (!temp.empty())
			{
				m_program.push_back(temp);
			}
		} while (found_p == -1 &&
			found_P == -1);
		system("cls");
		printMenu(cout);
		//cout << m_stack.front();
	}

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		rotateDown()
//
//	Description:
//		Removes the bottom of the stack and adds it to the top.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::rotateDown()
	{
		/*
		remove first element, place it at the back
		*/
		if (m_stack.empty())
			m_error = true;
		double front = m_stack.front();
		m_stack.pop_front();
		m_stack.push_back(front);
	} 

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		rotateUp()
//
//	Description:
//		Removes the top of the stack and adds it to the bottom.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		runProgram()
//
//	Description:
//		Runs the program in "m_program".
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void CRPNCalc::runProgram()
	{
		/*
		for each input in m_program
			add to m_interStream
			call input()
		*/
		list<string>::iterator pit = m_program.begin();

		while (pit!=m_program.end())
		{
			m_instrStream.clear();
			m_instrStream.str(*pit);
			input(m_instrStream);
			pit++;
		}

	} 

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		saveToFile()
//
//	Description:
//		Asks the user for a filename and saves "m_program" to that file.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//	    6/6/2018 CS updated
//      6/9/2018 CS updated
//----------------------------------------------------------------------------
	void CRPNCalc::saveToFile()
	{
		string temp;
		cout << "Save program file as: ";
		cin >> temp;
		ofstream outFile;
		outFile.open(temp);
		while (!m_program.empty())
		{
			outFile << m_program.front() << endl;
			m_program.pop_front();
		}
		outFile.close();
		system("cls");
		printMenu(cout);
		cout << m_stack.front();
		
	}  

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		setReg()
//
//	Description:
//		Gets the value from the top of the stack and places it into the given
//		register.
//
//	Input:
//		The register to be set
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		int reg
//
//	Returns:
//		None
//
//	History Log:
//		6/5/2018 CS updated
//
//----------------------------------------------------------------------------
	void CRPNCalc::setReg(int reg)
	{	
		if (!m_stack.empty())
		{
			m_registers[reg] = m_stack.front();
		}
		else
			cout << "<<error>>";
	} 

//----------------------------------------------------------------------------
//	Class:
//		CRPNCalc
//
//	Method:
//		subtract()
//
//	Description:
//		If possible, pops two elements from the stack, subtracts them, and
//		pushes the result onto the stack.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		N/A
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
//		CRPNCalc
//
//	Method:
//		input()
//
//	Description:
//		Inputs a line from the given stream.
//
//	Input:
//		None
//
//	Output:
//		None
//
//	Calls:
//		N/A
//
//	Called By:
//		N/A
//
//	Parameters:
//		None
//
//	Returns:
//		None
//
//	History Log:
//		6/6/2018 CS AM AS updated
//
//----------------------------------------------------------------------------
	void CRPNCalc::input(istream &istr)
	{
		istr >> m_buffer;
		m_instrStream.str(m_buffer);
		parse();
	}

//----------------------------------------------------------------------------
//	Function:
//		operator<<()
//
//	Description:
//		Prints the calculator interface.
//
//	Input:
//		The output stream for insertion and a reference to the calculator
//		object for printing.
//
//	Output:
//		The chosen output stream
//
//	Calls:
//		print()
//
//	Called By:
//		N/A
//
//	Parameters:
//		ostream &ostr
//		CRPNCalc &calc
//
//	Returns:
//		ostream &
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	ostream &operator<<(ostream &ostr, CRPNCalc &calc)
	{
		calc.print(ostr);

		return ostr;
	} 

//----------------------------------------------------------------------------
//	Function:
//		operator>>()
//
//	Description:
//		Inputs a line from the given input stream.
//
//	Input:
//		The input stream for extraction and a reference to the calculator
//		object for inputting.
//
//	Output:
//		The chosen input stream
//
//	Calls:
//		input()
//
//	Called By:
//		N/A
//
//	Parameters:
//		istream &istr
//		CRPNCalc &calc
//
//	Returns:
//		istream &
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	istream &operator>>(istream &istr, CRPNCalc &calc)
	{
		calc.input(istr);
		
		return istr;
	}

//----------------------------------------------------------------------------
//	Function:
//		printLine()
//
//	Description:
//		Prints a line.
//
//	Input:
//		The output stream for printing
//
//	Output:
//		A single line
//
//	Calls:
//		None
//
//	Called By:
//		print()
//
//	Parameters:
//		ostream &ostr
//
//	Returns:
//		ostream &
//
//	History Log:
//		06/04/2018 BRRP Function completed
//
//----------------------------------------------------------------------------
	void printLine(ostream &ostr)
	{
		for (unsigned short i = 1; i <= 76; i++)
			ostr << '_';

		ostr << endl;
	}

//----------------------------------------------------------------------------
//	Function:
//		printMenu()
//
//	Description:
//		Prints the calculator's help menu.
//
//	Input:
//		The output stream for printing
//
//	Output:
//		The help menu.
//
//	Calls:
//		None
//
//	Called By:
//		print()
//
//	Parameters:
//		ostream &ostr
//
//	Returns:
//		None
//
//	History Log:
//		N/A
//
//----------------------------------------------------------------------------
	void printMenu(ostream &ostr)
	{
		ostr << "C Clear stack   | CE Clear entry  | D Rotate down | "
			"F Save program to file" << endl;
		ostr << "G0-G9 Get reg N | H Help on/off   | L Load program | "
			"M +/- | P Program on/off" << endl;
		ostr << "R Run program   | S0-S9 Set reg n | U Rotate up    | X Exit"
			<< endl;
	}
}