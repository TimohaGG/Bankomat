#include "Bankomat.h"

void Bankomat::Login(UserData data)
{
	card.Id = data.Id;
	card.Password = data.Password;
	std::cout << "Enter your password:" << std::endl;
	std::cin >> card.Password;

	//Отрправка на сервер
	if (server.SendToDB(card))
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
	std::cout << "Take your card, or yum, yum." << std::endl;
}

void Bankomat::Menu()
{
	int choice;

	while (1)
	{
		bool OK = 1;

		std::cout << "Choose what you want to do?" << std::endl;
		std::cout << "1: Pick up the card?" << std::endl
			<< "2: See the money in your account? " << std::endl
			<< "3: To draw money from your account? " << std::endl
			<< "4: Exit; " << std::endl;
		std::cin >> choice;

		while ((choice < 0) || (choice >= 5))
			std::cin >> choice;

		switch (choice)
		{
			//Забрать карту или продолжить
		case 1:

			std::cout << "Do you want to back to menu? \t 1: Menu;\t2: Exit" << std::endl;

			while (OK)
			{
				std::cin >> choice;
				if (choice == 2) {
					OK = 0;
					continue;
				}
				else if (choice == 1)
				{
					std::cout << "Have a nice day) Slava Ukraine!!!" << std::endl;
					EndTask();
					exit(0);
				}
				else
					std::cout << "Error/ Try again" << std::endl;
			}
			break;
			//Просмотреть баланс на карте
		case 2:
			std::cout << "See the money in your account? " << std::endl;
			std::cin >> choice;

			std::cout << "Now you have  ";
			ShowBalance();
			std::cout << "  in your account" << std::endl;
			std::cout << "Do you want to back to menu? \t 1: Menu;\t2: Exit" << std::endl;
			while (OK)
			{
				std::cin >> choice;

				if (choice == 1) {
					OK = 0;
					continue;
				}
				else if (choice == 2)
				{
					std::cout << "Have a nice day) Slava Ukraine!!!" << std::endl;
					exit(0);
				}
				else
					std::cout << "Error/ Try again" << std::endl;
			}
			break;
			//Снять деньги
		case 3:
			std::cout << "How much money you want to draw? " << std::endl;
			/*std::cin >> choice;

			if (server.getBalance(card) < choice)
			{
				std::cout << "You don't have anough money to draw it" << std::endl;
				_sleep(1000);
				continue;
			}
			else
			{
				Withdraw();
			}*/

			Withdraw();

			std::cout << "Now you have  ";
			ShowBalance();
			std::cout << "  in your account" << std::endl;

			std::cout << "Do you want to back to menu? \t 1: Menu;\t2: Exit" << std::endl;

			while (OK)
			{
				std::cin >> choice;
				if (choice == 1)
				{
					OK = 0;
					continue;
				}

				else if (choice == 2)
				{
					std::cout << "Have a nice day) Slava Ukraine!!!" << std::endl;
					exit(0);
				}
				else
				{
					std::cout << "Error/ Try again" << std::endl;
				}
			}
			break;
			//Выход с меню
		case 4:
			exit(0);
			break;
		}
	}
}

void Bankomat::PrintError()
{
	std::cout << "Error" << std::endl;
}

void Bankomat::ShowBalance()
{
	std::cout << server.getBalance(card);
}

void Bankomat::Withdraw()
{
	int summ;

	std::cin >> summ;

	server.reduceBalance(summ) ? GiveMoney(summ) : PrintError();
}

void Bankomat::GiveMoney(int x)
{
	std::cout << "-------------- -\n| " << x << "\t$ | \n---------------\n";
}

