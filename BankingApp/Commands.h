#pragma once
#include "Account.h"

namespace Commands {
	void clear();
	void help();
	void infos();
	void revealaddresses(Account* acc);
	void addFunds(int accId, double fundsToAdd, Account* acc);
	void delFunds(int accId, double fundsToDel, Account* acc);
}