#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

#include "client.hpp"

using namespace std;

class Account{
    private:
        Client *_client;
        float balance;
    public:
        Account(Client *client, float balance);
        ~Account();

        void UpdateClient(Client *client);
        bool Deposit(float value);
        bool Withdraw(float value);
        bool Transfer(Account &account, float value);

        string GetClientInformation();
        string GetClientInformationSimple();
        float GetBalance();
};
#endif