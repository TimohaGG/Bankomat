#include"Server.h"

bool Server::SendToDB(UserData user)
{
	return db.checkUser(user);		
}
int Server::GetBalance(UserData user)//Çàïðîñ áàëàíñà è âîçâðàò áàëàíñà ïîëþçîâàòåëþ
{
	return db.giveBalance(user);
};

bool Server::ReduceBalance(int amount, UserData user)// Ïðîâåðêà âîçìîæíîñòè ñíÿòèÿ áàëàíñà è ïåðåçàïèñü ñóììû, â ñëó÷àå true
{

	if (this->getBalance(user) => amount)
	{
		db.reduceBalance(amount);
		return true;
	}
	else
	{
		return false;
	}
};