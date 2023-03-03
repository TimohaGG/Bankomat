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
		users = new User[NumUser()]; // ������ ������ ������������� � ������������ � �����������
	}

	~DataBese()
	{
		delete[] users;
	}

private:

	int NumUser() // ����� ���������� ���������� �������������
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

	int LengthStr() // ���������� ����� ������ � ����� ��� ����������� �������������
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

	void LoadFromFile() // ������ �����
	{
		const char* Path = "DataBase.txt"; // ��������� ��� ����� ��� ����

		int NumStr = NumUser();

		int StrLength = LengthStr();

		std::string* TmpStr = new std::string[NumStr]; // ������ ������ ����� (������ ������������ ����� �� ������������� � ������)

		FILE* FlRd;

		fopen_s(&FlRd, Path, "r");

		if (FlRd != nullptr)
		{
			for (size_t i = 0; i < NumStr; i++)
			{
				char ch[50];

				if (fgets(ch, StrLength, FlRd))
				{
					TmpStr[i] = ch; // �������� ������ � ���������� ��������� � ������ �����
				}

				fseek(FlRd,3,1); // ���������� ��������� �� ��������� ������
			}

			fclose(FlRd);
		}

		// ��������� ������ �� ���������
		
		std::string* TmpId = new std::string[NumStr]; 
		std::string* TmpPass = new std::string[NumStr];
		std::string* TmpBalance = new std::string[NumStr];

		// ��������� ���������� ��� �������� ��������

		int tmp_index_st = 0; 
		int tmp_index_nxt = 0;

		for (size_t i = 0; i < NumStr; i++) // ��������� ��
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

		for (size_t i = 0; i < NumStr; i++) // ��������� ������ 
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

		for (size_t i = 0; i < NumStr; i++) // ��������� ������
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

		for (size_t i = 0; i < NumStr; i++) // ��������� ������ �������������, ��� ���������� ������
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

	void SaveToFile() // ��������� ���������� ����� 
	{
		const char* Path = "DataBase.txt"; // ��������� ��� ����� ��� ����

		int length = NumUser(); // ������������� ���������� �������������

		std::ofstream SvFl(Path, std::ios::out);

		if (SvFl.is_open())
		{
			for (size_t i = 0; i < length; i++) // ������� ���������� � ����
			{
				SvFl << users[i].id << "," << users[i].Pass << "," << users[i].Balance << ".\n";
			}
			SvFl.close();
		}

	}

	


};