#pragma once
#include <string>
#include "Message.h"

using std::string;

/* Access level specificators */
enum Access
{
	GUEST,
	USER,
	ADMIN
};

/*Class Command, used to bind a string name to a function-executor*/
class Command
{
private:
	string name;
	Error (*executor)();
	string description;
	Access access;

public:
	Command() : name(""), executor(0), description(""), access(GUEST)
	{}
	Command(string _name, Error(*_executor)(), string _description = "", Access _access = GUEST) : name(_name), executor(_executor), description(_description), access(_access)
	{}

	string getName() const
	{
		return name;
	}
	string getDescription() const
	{
		return description;
	}
	Access getAccessLevel() const
	{
		return access;
	}

	Error execute()
	{
		/* If User global variable has greater access */
		return executor();
		/* Else return */
		/* return Error("Access not granted", ACCESS_ERROR); */
	}
};

/*Array of all Command objects available*/
Command commands[];

/*Number of available commands*/
extern const int numOfCommands;