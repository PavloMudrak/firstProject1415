#include "CommandHandlers.h"
#include "../DataManager/DataManager.h"
#include "Globals.h"

/*Command executors listed alphabetically*/

Result addToAssortment()
{
	int id;
	cout << Message("Enter id", CONTEXT_MSG);
	cin >> id;

	int quantity;
	cout << Message("Enter new quantity", CONTEXT_MSG);
	cin >> quantity;

	DataManager manager;
	manager.setQuantity(id, quantity);

	return Result("Product is added to asortment.", SUCCESSFUL);
}

Result changeProduct()
{
	int id = 0;
	cout << Message("Enter id", CONTEXT_MSG);
	cin >> id;

	DataManager manager;
	Product *prod = manager.getProductById(id);
	int quantity = manager.getQuantity(id);

	prod->input();

	manager.removeProductById(id);
	manager.saveProduct(*prod);
	manager.setQuantity(id, quantity);

	delete[] prod;
	return Result("Product is changed.", SUCCESSFUL);
}

Result createAdmin()
{
	int id;
	cout << Message("Enter id of the account", CONTEXT_MSG);
	cin >> id;

	DataManager manager;
	User *user = nullptr;

	try
	{
		user = manager.getUserById(id);
	} catch (exception exp)
	{
		cin.get();
		return Result(exp.what(), NOT_SUCCESSFUL);
	}

	if (user == nullptr)
	{
		cin.get();
		return Result("The id is invalid. Please try again.", NOT_SUCCESSFUL);
	}

	if (user->getRole() == Access::ADMIN)
	{
		return Result("The account already has administrator rights.", SUCCESSFUL);
	}

	user->properties->setRole(Access::ADMIN);

	return Result("The account was granted administrator rights.", SUCCESSFUL);
}

Result createUser()
{
	using std::cin;
	User newUser;
	cin >> newUser;
	/* Writing to the database */
	/* Writing user data into global variable 'User'*/

	return Result("Your account was successfully created\nWelcome, ", SUCCESSFUL);
}

Result exit()
{
	return Result(EXIT);
}

Result help()
{
	for (int i = 0; i < numOfCommands; i++)
	{
		if (currentUser.getRole() & commands[i].getAccessLevel())
			cout << Message("[" + commands[i].getName() + "] - " + commands[i].getDescription(), LOG_MSG);
	}
	return Result();
}

Result logIn()
{
	using std::cin;

	cout << Message("Name", CONTEXT_MSG);
	string name;
	getline(cin, name, '\n');
	cout << Message("Password", CONTEXT_MSG);
	string password;
	getline(cin, password, '\n');

	/* Checking the database */
	bool correct = true;

	if (correct)
	{
		/* Writing user data into global variable 'User'*/
		return Result("Authentication successful\nWelcome, " + name + "!", SUCCESSFUL);
	}
	else
	{
		return Result("Authentication failed\nPlease, check your name, password and try again", NOT_SUCCESSFUL);
	}
}

Result logOut()
{
	/*Deletes data of global variable User*/
	return Result("You logged out successfully.", SUCCESSFUL);
}

Result removeUser()
{
	int id = 0;
	cout << Message("Enter id of the account", CONTEXT_MSG);
	cin >> id;

	if (id == currentUser.getId())
	{
		return Result("You cannot delete yourself.", SUCCESSFUL);
	}

	DataManager manager;

	try
	{
		manager.removeUserById(id);
	} catch (exception exp)
	{
		cin.get();
		return Result(exp.what(), NOT_SUCCESSFUL);
	}

	return Result("The user was deleted successfully.", SUCCESSFUL);
}

Result showCart()
{
	List<Product*>::iterator end = cart.end();
	for (List<Product*>::iterator iterator = cart.begin(); iterator != end; iterator++)
	{
		cout << *iterator;
	}
	return Result("Listing completed.", SUCCESSFUL);
}

Result showUsers()
{
	DataManager manager;
	List<User*> list = manager.readAllUsers();
	List<User*>::iterator iter = list.begin();

	while(iter != list.end())
	{
		int temp = 0;
		cout << (*iter);
		temp ++;
		iter ++;

		if((temp % 5) == 0)
		{
			cout << Message("Press Enter to continue... ", LOG_MSG);
			cin.get();
		}
	}

	return Result("Listing completed.", SUCCESSFUL);
}

