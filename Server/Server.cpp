#define DEBUGGING
#ifdef DEBUGGING
	class Database;
	struct UserData;
#endif

class Server
{
private:

	Database db;

public:

	bool SendToDB(UserData user)//�������� ������ ������������ �� ���� ������, ��� �������� � ��������� ������������
	{
		return db.checkUser(user);
	};

	int GetBalance(UserData user)//������ ������� � ������� ������� ������������
	{
		return db.giveBalance(user);
	};

	bool ReduceBalance(int amount)// �������� ����������� ������ ������� � ���������� �����, � ������ true
	{

		if (this->getBalance() = > amount)
		{
			db.reduceBalance(amount);

			return true;
		}
		else
		{
			return false;
		}
	};
};