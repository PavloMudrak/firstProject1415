#include "LaptopAndComputer.h"
#include "..\..\UI\Message.h"

LaptopAndComputer::LaptopAndComputer() : 
	Electronic(),
	firm(" ")
{
}

istream& operator>>(istream& stream, LaptopAndComputer& obj)
{
	stream >> Electronic(obj);
	getline(stream, obj.firm);
	return stream;
}

ostream& operator<<(ostream& stream, const LaptopAndComputer& obj)
{
	stream << Electronic(obj)
		   << obj.firm << endl;
	return stream;
}


void LaptopAndComputer::input()
{
	Electronic::input();
	string temp;

	cout << Message("Input firm: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->firm = temp;
	}
	temp.clear();
}

void LaptopAndComputer::output() const
{
	Electronic::output();
	cout << Message("Firm: " + firm, CONTEXT_MSG);
}
