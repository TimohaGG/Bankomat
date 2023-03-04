#pragma once

class Server {
private:
	Database db;
public:
	bool SendToDB(UserData user);
	int GetBalance(UserData user);
	bool ReduceBalance(int amount, UserData user);
};
