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
	bool SendToDB(UserData user)//Ïåðåäà÷à äàííûõ ïîëüçîâàòåëÿ íà áàçó äàííûõ, äëÿ ïðîâåðêè è ñðàâíåíèÿ ïîëüçîâàòåëÿ
	{
		return db.checkUser(user);
	};
	int GetBalance(UserData user)//Çàïðîñ áàëàíñà è âîçâðàò áàëàíñà ïîëþçîâàòåëþ
	{
		return db.giveBalance(user);
	};
	bool ReduceBalance(int amount, UserData user)// Ïðîâåðêà âîçìîæíîñòè ñíÿòèÿ áàëàíñà è ïåðåçàïèñü ñóììû, â ñëó÷àå true
	{

		if (this->getBalance(user) >= amount)
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
