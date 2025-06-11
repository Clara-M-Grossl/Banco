#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Client{
    private:
        string name;
        string address;
        string job;
        float income;
    public:
        Client(string name, string address, string job, float income);
        void Update(string name, string address, string job, float income);

        string GetName();
        string GetAddress();
        string GetJob();
        float GetIncome();
        string GetInformation();
        string GetInformationSimple();

        // void SetName();
        // void SetAddress();
        // void SetJob();
        // void SetIncome();
};



#endif