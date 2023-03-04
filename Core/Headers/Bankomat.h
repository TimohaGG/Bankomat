#pragma once
#include<iostream>
#include"UserData.h"

using namespace std;

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