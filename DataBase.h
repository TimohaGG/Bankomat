#pragma once

#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<time.h>

struct UserData
{
	int id;
	int Pass;
};

struct User
{
	long long int id;
	int Pass;
	int Balance;
};


class DataBese
{	
	User* users;

public:

	DataBese()
	{
		users = new User[NumUser()]; // Создаём массив пользователей в соответствии с количеством
	}

	~DataBese()
	{
		delete[] users;
	}

private:

	int NumUser() // Метод определяем количество пользователей
	{
		int count = 0;

		char sym = '.';

		const char* Path = "DataBase.txt";

		std::ifstream FlRd(Path);

		if (FlRd.is_open())
		{
			while (!FlRd.eof())
			{
				if (FlRd.get() == sym)
				{
					count++;
				}
			}

			FlRd.close();
		}

		return count;
	}

	int LengthStr() // Определяем длину строки в файле для дальнейшего использования
	{
		int count = 0;

		char sym = '.';

		const char* Path = "DataBase.txt";

		std::ifstream FlRd(Path);

		if (FlRd.is_open())
		{
			while (!FlRd.eof())
			{
				count++;

				if (FlRd.get() == sym)
				{
					break;
				}
			}

			FlRd.close();
		}

		return count;
	}

public:

	void LoadFromFile() // Чтение файла
	{
		const char* Path = "DataBase.txt"; // указываем имя файла или путь

		int NumStr = NumUser();

		int StrLength = LengthStr();

		std::string* TmpStr = new std::string[NumStr]; // Создаём массив строк (стринг используется чтобы не привязывается к буферу)

		FILE* FlRd;

		fopen_s(&FlRd, Path, "r");

		if (FlRd != nullptr)
		{
			for (size_t i = 0; i < NumStr; i++)
			{
				char ch[50];

				if (fgets(ch, StrLength, FlRd))
				{
					TmpStr[i] = ch; // Помещаем строку с временного хранилища в массив строк
				}

				fseek(FlRd,3,1); // Перемещаем указатель на следующую строку
			}

			fclose(FlRd);
		}

		// Разделяем строку на подстроки
		
		std::string* TmpId = new std::string[NumStr]; 
		std::string* TmpPass = new std::string[NumStr];
		std::string* TmpBalance = new std::string[NumStr];

		// Временные переменные для хранения индексов

		int tmp_index_st = 0; 
		int tmp_index_nxt = 0;

		for (size_t i = 0; i < NumStr; i++) // Считываем ИД
		{
			const char* buff = TmpStr[i].c_str();

			for (size_t j = 0; j < TmpStr[i].size(); j++)
			{
				if (buff[j] == ',')
				{
					tmp_index_st = j;

					break;
				}

				TmpId[i] += buff[j];
			}
			
		}

		for (size_t i = 0; i < NumStr; i++) // Считываем Пароли 
		{
			const char* buff = TmpStr[i].c_str();

			for (size_t j = tmp_index_st + 1; j < TmpStr[i].size(); j++)
			{
				if (buff[j] == ',')
				{
					tmp_index_nxt = j;

					break;
				}

				TmpPass[i] += buff[j];
			}
		}

		for (size_t i = 0; i < NumStr; i++) // Считываем Баланс
		{
			const char* buff = TmpStr[i].c_str();

			for (size_t k = tmp_index_nxt + 1; k < TmpStr[i].size(); k++)
			{
				if (buff[k] == '.')
				{
					break;
				}

				TmpBalance[i] += buff[k];
			}
		}

		for (size_t i = 0; i < NumStr; i++) // Заполняем данные пользователей, для дальнейшей работы
		{
			users[i].id = std::atoll(TmpId[i].c_str());
			users[i].Pass = std::stoi(TmpPass[i]);
			users[i].Balance = std::stoi(TmpBalance[i]);
		}

		delete[] TmpId;
		delete[] TmpPass;
		delete[] TmpBalance;
		delete[] TmpStr;
	}

	void SaveToFile() // Совершаем перезапись файла 
	{
		const char* Path = "DataBase.txt"; // указываем имя файла или путь

		int length = NumUser(); // Устанавливаем количество пользователей

		std::ofstream SvFl(Path, std::ios::out);

		if (SvFl.is_open())
		{
			for (size_t i = 0; i < length; i++) // Заносим информацию в файл
			{
				SvFl << users[i].id << "," << users[i].Pass << "," << users[i].Balance << ".\n";
			}
			SvFl.close();
		}

	}

	


};