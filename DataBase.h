#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct User
{
	int id;
	int pass;
	int balance;
};

struct UserData
{
	int id;
	int pass;
};

class DataBase
{
	vector<User> users;

	User* currentUser;
public:
	DataBase();
	~DataBase();

	bool checkUser(UserData user);
	int giveBalance(UserData user);
	bool reduceBalance(int amount);

	void SaveToFile();
	vector<User> LoadFromFile();
};

DataBase::DataBase()
{
	users = LoadFromFile();
}

DataBase::~DataBase()
{
	delete currentUser;
}

bool DataBase::checkUser(UserData user)
{
	for (auto& i : users)
	{
		if (i.id == user.id)
		{
			currentUser = &i;
			return true;
		}
	}
	return false;
}

int DataBase::giveBalance(UserData user)
{
	if (!currentUser) return currentUser->balance;
	return 0;
}

bool DataBase::reduceBalance(int amount)
{
	if (amount == 0)
	{
		throw exception("Ti che durak?");
		return false;
	}

	if ((currentUser->balance - amount) < 0)
	{
		throw exception("amount over balance");
		return false;
	}
	return true;
}

void DataBase::SaveToFile()
{
	fstream file;
	file.open("data.txt", ios::out | ios::binary);

	if (file.is_open())
	{
		for (auto& i : users)
		{
			file.write(reinterpret_cast<char*>(&i.id), sizeof(int));
			file.write(reinterpret_cast<char*>(&i.pass), sizeof(int));
			file.write(reinterpret_cast<char*>(&i.balance), sizeof(int));
		}
		file.close();
	}
	else
	{
		throw exception("can't open file");
	}
}

vector<User> DataBase::LoadFromFile()
{
	fstream file;
	file.open("data.txt", ios::in | ios::binary);

	if (file.is_open())
	{
		User tmp;
		while(!file.eof())
		{
			file.read(reinterpret_cast<char*>(&tmp.id), sizeof(int));

			if (file.eof()) break;

			file.read(reinterpret_cast<char*>(&tmp.pass), sizeof(int));
			file.read(reinterpret_cast<char*>(&tmp.balance), sizeof(int));
			users.push_back(tmp);
		}
		file.close();
	}
	else
	{
		throw exception("can't open file");
	}

}