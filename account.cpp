#include "account.hpp"

Account::Account(Client *client, float balance){
    _client = client;
    this->balance = balance;
}
Account::~Account(){

}

void Account::UpdateClient(Client *client){
    _client = client;
}
bool Account::Deposit(float value){
    this->balance += value;
    return true;
}
bool Account::Withdraw(float value){
    if(this->balance >= value){
        this->balance -= value;
        return true;
    }
    return false;
}
bool Account::Transfer(Account &account, float value){
    if(this->balance >= value){
        this->balance -= value;
        account.Deposit(value);
        return true;
    }
    return false;
}

string Account::GetClientInformation(){
    return _client->GetInformation();
}
string Account::GetClientInformationSimple(){
    return _client->GetInformationSimple();
}
float Account::GetBalance(){
    return this->balance;
}