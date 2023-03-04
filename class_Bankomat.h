#pragma once
#include<iostream>

using namespace std;

struct UserData
{
	int id;
	int password;
};

struct Server
{
	bool sendToDB(UserData);
	int GetBalance(UserData);
	bool reduceBalance(int);
};

class Bankomat
{
	UserData card;
	Server server;
public:
	void Login(UserData);

	void EndTask();

	void Menu();

	void PrintError();

	void ShowBalance();

	void Withdraw();

	void GiveMoney(int);
};