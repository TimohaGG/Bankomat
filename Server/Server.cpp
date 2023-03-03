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

	bool SendToDB(UserData user)//ѕередача данных пользовател€ на базу данных, дл€ проверки и сравнени€ пользовател€
	{
		return db.checkUser(user);
	};

	int GetBalance(UserData user)//«апрос баланса и возврат баланса полюзователю
	{
		return db.giveBalance(user);
	};

	bool ReduceBalance(int amount)// ѕроверка возможности сн€ти€ баланса и перезапись суммы, в случае true
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