#include "class_Bankomat.h"

void Bankomat::Login(UserData user)
{
	card = user;

	//cout << "Введите пароль: ";
	cout << "Enter password: ";
	cin >> card.password;

	system("cls");

	if (server.sendToDB(card))
	{
		Menu();
	}
	else
	{
		PrintError();
	}
}

void Bankomat::EndTask()
{
	//cout << "Забирай свой карта, а то ням - ням!\n";
	cout << "Take the card!\n";
}

void Bankomat::Menu()
{
	int choice = 0;

	do
	{
		//cout << "Забрать карту - 1,\n";
		//cout << "Показать баланс - 2,\n";
		//cout << "Снять деньги - 3,\n\n";
		//cout << "Сделайте выбор: ";

		cout << "Pick up card - 1,\n";
		cout << "Show balance - 2,\n";
		cout << "Withdraw money - 3,\n\n";
		cout << "Make a choice: ";

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
		{
			EndTask();
		}return;

		case 2:
		{
			ShowBalance();
		}break;

		case 3:
		{
			Withdraw();
		}break;

		}
	} while (true);
}

void Bankomat::PrintError()
{
	//cout << "Ошибка!\n";
	cout << "Error!\n";
}

void Bankomat::ShowBalance()
{
	//cout << "Ваш баланс: ";
	cout << "Your balance: ";

	cout << server.GetBalance(card);
}

void Bankomat::Withdraw()
{
	int summ = 0;

	//cout << "Введите сумму: ";
	cout << "Enter amount: ";

	cin >> summ;

	if (server.reduceBalance(summ))
	{
		GiveMoney(summ);
	}
	else
	{
		PrintError();
	}
}

void Bankomat::GiveMoney(int amount)
{
	cout << "---------------\n|" << amount << "\t$|\n---------------\n";
}
