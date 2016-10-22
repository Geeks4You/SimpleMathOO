// Week 5: Individual: SimpleMath OO Program
// PRG/410: C++ Programming I
// October 24, 2016
// Marcia L. Allen
// Using Object-Oriented Programming (OOP), design a base class Simplemath
// and derived Addition, Subtraction, Division, Multiplication classes within.
// The user should have the option (e.g., switch statement, if statement, if
// else statement, nested statements) to choose which calculation he or she
// prefers to use. Once a selection is made, the user should be able to input
// as many calculations as he or she wishes until done, with all totals given
// as an output prior to exiting the program. Create an array for the numbers
// users input to be stored.

#include "stdafx.h"
#include <iostream>	
#include <iomanip>

using namespace std;

class Simplemath
{
private:
	int num_calc;
	int maxNum;
	int minNum;
	int *myArray1, *myArray2;
public:
	Simplemath()
	{
		num_calc = 0;
		myArray1 = NULL;
		myArray2 = NULL;
		while (num_calc <= 0)
		{
			cout << "How many calculations would you like to perform? ";
			cin >> num_calc;
		}
		cout << endl;
		myArray1 = new int[num_calc];
		myArray2 = new int[num_calc];
	}
	int getNumCalc(){ return num_calc; }
	void setNumCalc(){

		while (num_calc <= 0)
		{
			cout << "How many calculations would you like to perform? ";
			cin >> num_calc;
		}
		cout << endl;
		myArray1 = new int[num_calc];
		myArray2 = new int[num_calc];
	}
	void getInput();
	void setMinMax(int mini, int maxi){
		minNum = mini;
		maxNum = maxi;
	}
	int getInputArray1(int idx)
	{
		return myArray1[idx];
	}
	int getInputArray2(int idx)
	{
		return myArray2[idx];
	}
};
void Simplemath::getInput()
{
	int numberInput1 = 0;
	int numberInput2 = 0;
	for (int i = 1; i <= num_calc; i++)
	{
		cout << "Problem # " << i << endl;
		cout << "Please enter the 1st number between " << minNum << " - " << maxNum << "\n";
		cin >> numberInput1;
		while (numberInput1 < 0 || numberInput1 > 9999)
		{
			cout << "WARNING! Please enter the 1st number again between " << minNum << " - " << maxNum << "\n";
			cin >> numberInput1;
		}
		myArray1[i] = numberInput1;

		cout << "Please enter the 2nd number between " << minNum << " - " << maxNum << "\n";
		cin >> numberInput2;
		while (numberInput2 < 0 || numberInput2 > 9999)
		{
			cout << "WARNING! Please enter 2nd number again between " << minNum << " - " << maxNum << "\n";
			cin >> numberInput2;
		}
		myArray2[i] = numberInput2;
		cout << endl;
	}

}


class Addition :public Simplemath{
	int *result;
public:
	Addition()
	{
		cout << getNumCalc() << " ";
		result = new int[getNumCalc()];
		cout.width(40); cout << "Perform Addition!" << endl;
		cout.width(44); cout << "-----------------\n\n" << endl;
		setMinMax(0, 9999);
	}
	void performAddition()
	{
		int answer, size = getNumCalc();
		for (int i = 1; i <= size; i++)
		{
			answer = getInputArray1(i) + getInputArray2(i);
			result[i] = answer;
		}
		cin.get();
	}

	void printResult()
	{
		int size = getNumCalc();
		cout << "------------------------\n\n";
		cout << "Addition results:\n" << endl;
		for (int i = 1; i <= size; i++)
		{
			cout << setw(12) << getInputArray1(i) << endl;
			cout << setw(8) << "+" << setw(4) << (getInputArray2(i)) << endl;
			cout << setw(12) << "-------";
			cout << endl << setw(12) << result[i] << "\n\n";
			cout << "------------------------\n\n";
		}
	}
};

class Subtraction :public Simplemath{
	int *result;
public:
	Subtraction()
	{
		cout << getNumCalc() << " ";
		result = new int[getNumCalc()];
		cout.width(43); cout << "Perform Subtraction!" << endl;
		cout.width(47); cout << "--------------------\n\n" << endl;
		setMinMax(0, 9999);
	}
	void performSubtraction()
	{
		int answer, size = getNumCalc();
		for (int i = 1; i <= size; i++)
		{
			answer = getInputArray1(i) - getInputArray2(i);
			result[i] = answer;
		}
		cin.get();
	}

	void printResult()
	{
		int size = getNumCalc();
		cout << "------------------------\n\n";
		cout << "Subtraction results:\n" << endl;
		for (int i = 1; i <= size; i++)
		{

			cout << setw(12) << getInputArray1(i) << endl;
			cout << setw(8) << "-" << setw(4) << getInputArray2(i) << endl;
			cout << setw(12) << "-------";
			cout << endl << setw(12) << result[i] << "\n\n";
			cout << "------------------------\n\n";
		}
	}
};


class Multiplication :public Simplemath{
	int *result;
public:
	Multiplication()
	{
		cout << getNumCalc() << " ";
		result = new int[getNumCalc()];
		cout.width(46); cout << "Perform Multiplication!" << endl;
		cout.width(50); cout << "-----------------------\n\n" << endl;
		setMinMax(0, 9999);
	}
	void performMultiplication()
	{
		int answer, size = getNumCalc();
		for (int i = 1; i <= size; i++)
		{
			answer = getInputArray1(i) * getInputArray2(i);
			result[i] = answer;
		}
		cin.get();
	}

	void printResult()
	{
		int size = getNumCalc();
		cout << "------------------------\n\n";
		cout << "Multiplication results:\n" << endl;
		for (int i = 1; i <= size; i++)
		{
			cout << setw(12) << getInputArray1(i) << endl;
			cout << setw(8) << "x" << setw(4) << getInputArray2(i) << endl;
			cout << setw(12) << "-------";
			cout << endl << setw(12) << result[i] << "\n\n";
			cout << "------------------------\n\n";
		}
	}
};

class Division :public Simplemath{
	double *result;
public:
	Division()
	{
		cout << getNumCalc() << " ";
		result = new double[getNumCalc()];
		cout.width(40); cout << "Perform Division!" << endl;
		cout.width(44); cout << "-----------------\n\n" << endl;
		setMinMax(1, 9999);
	}
	void performDivision()
	{
		double answer;
		int size = getNumCalc();
		for (int i = 1; i <= size; i++)
		{
			answer = (double)getInputArray1(i) / getInputArray2(i);
			result[i] = answer;
		}
		cin.get();
	}

	void printResult()
	{
		int size = getNumCalc();
		cout << "------------------------\n\n";
		cout << "Division results:\n" << endl;
		for (int i = 1; i <= size; i++)
		{

			cout << setw(12) << getInputArray1(i) << endl;
			cout << setw(12) << "-------" << " = " << result[i] << endl;
			cout << setw(12) << getInputArray2(i) << endl;
			cout << setw(12) << endl;
			cout << "------------------------\n\n";
		}
	}
};

int displayMenu();


int _tmain(int argc, _TCHAR* argv[])
{
	int goodbye = 0;
	cout << "Welcome to SimpleMath OO Program!\n" << endl;
	do
	{
		int option = displayMenu();
		switch (option)
		{
		case 1:
		{
			Addition a;
			a.getInput();
			a.performAddition();
			a.printResult();
			break;
		}
		case 2:
		{
			Subtraction s;
			s.getInput();
			s.performSubtraction();
			s.printResult();
			break;
		}
		case 3:
		{
			Multiplication m;
			m.getInput();
			m.performMultiplication();
			m.printResult();
			break;
		}
		case 4:
		{
			Division d;
			d.getInput();
			d.performDivision();
			d.printResult();
			break;
		}
		case 5:
			cout << "Thank you for using the SimpleMath OO Program.\n" << endl;
			goodbye = -1;
			break;
		}
	} while (goodbye != -1);
	cin.get();
	cout << "GoodBye!\n" << endl;
	return 0;
}



int displayMenu()
{
	int option;//variable to hold user's selection
	do
	{
		cout.width(55); cout << setw(25) << "" << "SimpleMath OO PROGRAM" << endl;
		cout.width(55); cout << setw(25) << "" << "---------------------" << endl;
		cout << endl;
		cout.width(50); cout << setw(25) << "" << "1) Addition" << endl;
		cout.width(50); cout << setw(25) << "" << "2) Subtraction" << endl;
		cout.width(50); cout << setw(25) << "" << "3) Multiplication" << endl;
		cout.width(50); cout << setw(25) << "" << "4) Division" << endl;
		cout.width(50); cout << setw(25) << "" << "5) Exit" << endl;
		cout.width(50); cout << setw(25) << "" << "Please make a selection: ";
		cin >> option;
		cout << endl;
		//if statement in case user enters an invalid number
		if (option < 1 || option > 5)
		{
			cout << "Invalid selection.\n" << endl;
			cout << "Please enter a valid number.\n" << endl;
			cin.get();
		}
	} while (option < 1 || option > 5);
	return option;
}
