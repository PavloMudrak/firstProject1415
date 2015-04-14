#include "PhoneAndTablet.h"

PhoneAndTablet::PhoneAndTablet() :
Electronic(),
memoryCard(0)
{
}

istream& operator>>(istream& stream, PhoneAndTablet& obj)
{
	stream >> Electronic(obj);
	stream >> obj.memoryCard;
	return stream;
}

ostream& operator<<(ostream& stream, const PhoneAndTablet& obj)
{
	stream << Electronic(obj)
		   << obj.memoryCard << endl;
	return stream;
}

void PhoneAndTablet::input()
{
	Electronic::input();
	string temp;

	cout << Message("Input memory card: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->memoryCard = stoi(temp);
	}
	temp.clear();
}

void PhoneAndTablet::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memoryCard), INPUT_MSG);
}
