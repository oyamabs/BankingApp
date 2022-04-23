#include "Commands.h"
#include "ConsoleUtilities.h"
#include "Account.h"
#include <iostream>
#include <Windows.h>

void Commands::clear() {
	Console::clear();
	std::cout << "---BankingApp---\n";
}

void Commands::help() {
	std::cout << "Commands: " <<
		"\nhelp: show this message" <<
		"\nclear: clears out the console" <<
		"\ninfos: Show some infos about this garbage" <<
		//"\nlistaccounts: Shows list of accounts in this format: account_name\taccount_id\tfunds" <<
		//"\naddaccount account_name: creates an account with the specified name (ie: addaccount my_extra_nice_account)" <<
		//"\ndelaccount account_id: deletes the specified account (ie: delaccount 3)" <<
		"\naddfunds account_id funds_to_add: Add funds to specified account (ie: addfunds 6 94.20)" <<
		"\ndelfunds account_id funds_to_remove: substract funds to specified account (ie: delfunds 6 94.20)" <<
		"\nrevealaddresses: Get addresses of every values\n";
}

void Commands::infos() {
	std::cout << "Made by yama to train myself in reverse engineering... That's all! Code is messy and all and I might not update this\n";
}

void Commands::addFunds(int accId, double fundsToAdd, Account* acc) {
	if (accId == acc->accountId) {
		acc->funds += fundsToAdd;
	}
	else {
		Console::log("Account doesn't exists");
	}

	std::cout << "INFO -> Account now has " << acc->funds << "\n";
}

void Commands::delFunds(int accId, double fundsToDel, Account* acc) {
	if (accId == acc->accountId) {
		acc->funds -= fundsToDel;
	}
	else {
		Console::log("Account doesn't exists");
	}

	std::cout << "INFO -> Account now has " << acc->funds << "\n";
}

void Commands::revealaddresses(Account* acc) {
	MessageBoxA(GetConsoleWindow(), "Dirty little cheater ;)", "Dirty little cheater ;)", NULL);
	std::cout << "Addresses: \n" <<
		"Account pointer: 0x" << std::hex << &acc << '\n' <<
		"Account ID: 0x" << std::hex << &acc->accountId << '\n' <<
		"Account Owner name: 0x" << std::hex << &acc->accountOwnerName << '\n' <<
		"Account Funds: 0x" << std::hex << &acc->funds << std::dec << '\n' ;
}