#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include "client.hpp"
#include "account.hpp"

using namespace std;

class Client;
class Account;

Client CadastrarCliente();
Account CadastrarConta(int i, vector<Client> &clients);
int SearchSubstring(string substring, vector<Client> &clients);
void MostrarClientes(vector<Client> &clients, int i);
void MostrarContas(int i, vector<Account> &accounts);

bool DeleteClient(int i, vector<Client> &clients);

void ImportarDadosContas(vector<Account> &accounts, string name1);
void ImportarDadosClientes(vector<Client> &clients, string name1);
void ExportarDadosContas(vector<Account> &accounts, string name);
void ExportarDadosClientes(vector<Client> &clients, string name);


#endif