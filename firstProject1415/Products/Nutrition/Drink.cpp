#include "Drink.h"
#include "..\..\UI\Message.h"

Drink::Drink() :
	Nutrition(),
	volume(0.0)
{
}

istream& operator>>(istream& stream, Drink& obj)
{
	stream >> Nutrition(obj)
		   >> obj.volume;
	return stream;
}

ostream& operator<<(ostream& stream, const Drink& obj)
{
	stream << Nutrition(obj) << endl
		   << obj.volume << endl;
	return stream;
}

void Drink::input()
{
	Nutrition::input();
	string temp;

	cout << Message("Input GMO content: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->volume = stod(temp);
	}
	temp.clear();
}

void Drink::output() const
{
	Nutrition::output();
	cout << Message("Volume: " + to_string(this->volume), CONTEXT_MSG);
}