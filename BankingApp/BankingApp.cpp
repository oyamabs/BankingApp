/*
    BankingApp

    Simple banking simulation made for reverse engineering purposes, train yourself to debug some apps.
    Made primarly for training in debugging with IDA and other debuggers like x64dbg
*/
/*
    TODO:
        - create structs for accounts
        - create CRUD-like commands (ADDFUNDS, RMFUNDS, CREATEACCOUNT, DELACCOUNT)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "Account.h"
#include "ConsoleUtilities.h"
#include "Commands.h"

Account* acc;

std::vector<std::string> split(std::string s, char delim) {
    std::vector<std::string> arr;
    std::stringstream sstream(s);
    std::string word;

    while (std::getline(sstream, word, delim))
        arr.push_back(word);

    return arr;
}

int main()
{
    std::cout << "---BankingApp---\n";// "banner"

    // let user enter his name
    std::cout << "Please enter your name > ";
    std::string name = "";
    std::getline(std::cin, name);

    acc = new Account; // dynamically create account
    acc->accountOwnerName = name;
    acc->accountId = rand() % INT_MAX;
    acc->funds = (double)100;

    std::cout << "Hi! "<< acc->accountOwnerName << "\n\tYour account is currently filled with: " << (double)acc->funds << "\n\tand the id of your account is: " << acc->accountId << "\n";
    
    std::cout << "Account " << acc->accountId << " address is: 0x" << std::hex << &acc << '\n';

    std::cout << "Type 'help' to see different commands\n";

    while (true)
    {
        std::string cmd = "";
        std::cout << ">";
        std::getline(std::cin, cmd); // get commands and arguments if needed
        std::transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c) {return std::tolower(c); }); // lowercase every character to avoid capital letters issues
        

        if (cmd == "exit")
            break;

        if (cmd == "help")
            Commands::help();

        if (cmd == "clear")
            Commands::clear();

        if (cmd.rfind("addfunds",0) == 0) {
            std::vector<std::string> args = split(cmd, ' ');

            Commands::addFunds(std::stoi(args[1]), std::stod(args[2]), acc);
        }

        if (cmd.rfind("delfunds", 0) == 0) {
            std::vector<std::string> args = split(cmd, ' ');

            Commands::delFunds(std::stoi(args[1]), std::stod(args[2]), acc);
        }

        if (cmd == "revealaddresses")
            Commands::revealaddresses(acc);

        if (cmd == "infos")
            Commands::infos();
    }

    Console::log("Bye! Press enter to exit program");
    std::cin.get();
}