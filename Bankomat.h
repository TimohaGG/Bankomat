#pragma once
#include<iostream>

//struct UserData
//{
//	int Id;
//	int Password;
//};
//
//class Server
//{
//
//public:
//	int getBalance(UserData user);
//	bool reduceBalance(int x);
//	bool SendToDB(UserData user);
//};

class Bankomat
{
	UserData card;
	Server server;

public:
	void Login(UserData data);
	void EndTask();
	void Menu();
private:
	void PrintError();
	void ShowBalance();
	void Withdraw();
	void GiveMoney(int x);
};


