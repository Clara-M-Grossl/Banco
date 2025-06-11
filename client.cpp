#include "client.hpp"
#include <sstream>

Client::Client(string name, string address, string job, float income){
    this->name = name;
    this->address = address;
    this->job = job;
    this->income = income;
}
void Client::Update(string name, string address, string job, float income){
    this->name = name;
    this->address = address;
    this->job = job;
    this->income = income;
}
string Client::GetName(){
    return this->name;
}
string Client::GetAddress(){
    return this->address;
}
string Client::GetJob(){
    return this->job;
}
float Client::GetIncome(){
    return this->income;
}
string Client::GetInformation()
{
    stringstream stt;
    stt << "Name....................: " << this->name << "\nJob....................: " << this->job << "\nIncome....................: " << this->income;

    return stt.str();
}
string Client::GetInformationSimple(){
    stringstream stt;

    stt << this->name << "\n" << this->address << "\n" << this->job << "\n" << this->income;

    return stt.str();
}