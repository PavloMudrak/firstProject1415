#include "AudioAndTv.h"

AudioAndTv::AudioAndTv() : Electronic(), memory_card(0) {}

friend istream& operator>>(istream& stream, AudioAndTv& obj)
{
	getline(stream, obj.category);
	stream >> obj.weight;
	stream.get();
	getline(stream, obj.model);
	stream >> obj.memory_card;
	stream.get();
	return stream;
}

friend ostream& operator<<(ostream& stream, const AudioAndTv& obj)
{
	stream << obj.category << endl
		<< obj.weight << endl
		<< obj.model << endl
		<< obj.memory_card << endl;
	return stream;
}

void AudioAndTv::input()
{
	Electronic::input();
	cout << Message("Input memory card: ", CONTEXT_MSG);
	cin >> memory_card;
	cin.get();
}

void AudioAndTv::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memory_card), INPUT_MSG);
}
