#include "functions.hpp"

Client CadastrarCliente(){
    string name;
    string job;
    string address;
    float income;

    cin.ignore();

    cout << "Digite o nome........................: ";
    getline(cin, name);

    cout << "Digite o endereco........................: ";
    getline(cin, address);

    cout << "Digite a profissao........................: ";
    getline(cin, job);

    cout << "Digite a renda........................: ";
    cin >> income;

    Client newClient(name, address, job, income);
    return newClient;
}

Account CadastrarConta(int i, vector<Client> &clients){
    float balance;

    cout << "Digite o saldo da conta..................: ";
    cin >> balance;

    Account newAccount = Account(&clients[i], balance);

    return newAccount;
}

int SearchSubstring(string substring, vector<Client> &clients){
    for(size_t i = 0; i < clients.size(); i ++){
        if(clients[i].GetName().find(substring) != string::npos){
            return i;
        }
    }
    return -1;
}

void MostrarClientes(vector<Client> &clients, int i){
    cout << "=================================================================================" << endl;
    cout << "Cliente ID: " << i << endl;
    cout << "Nome...................................: " << clients[i].GetName() << endl;
    cout << "Endereco...............................: " << clients[i].GetAddress() << endl;
    cout << "Profissao..............................: " << clients[i].GetJob() << endl;
    cout << "Renda..................................: " << clients[i].GetIncome() << endl;

    cout << "=================================================================================" << endl;
}

bool DeleteClient(int i, vector<Client> &clients){
    if (i >= 0 && i < clients.size()){
        cout << "Cliente (" << "nome: " << clients[i].GetName() << ") deletada(o)" << endl;
        clients.erase(clients.begin() + i);
        return true;
    }
    else{
        cout << "Indice (" << i << ") nao pertence ao intervalo" << endl;
        return false;
    }
}

void MostrarContas(int i, vector<Account> &accounts){
    cout << "=================================================================================" << endl;
    cout << "Conta ID..............................: " << i << endl;
    cout << "Cliente...............................: " << endl  << accounts[i].GetClientInformation() << endl;
    cout << "Saldo.................................: " << accounts[i].GetBalance() << endl;
    cout << "=================================================================================" << endl;
}
void ImportarDadosContas(vector<Account> &accounts, string name1){
    ifstream fileptr;
    string name, address, job;
    float balance, income;
    
    fileptr.open(name1);

    if(fileptr.good()){
        while(getline(fileptr, name) && getline(fileptr, address) && getline(fileptr, job) && fileptr >> income && fileptr >> balance){
            fileptr.ignore();
            Client *client = new Client(name, address, job, income);
            Account newAccount(client, balance);
            accounts.push_back(newAccount);
        }
    }
    else{
        cout << "error" << endl;
    }

    fileptr.close();
}
void ImportarDadosClientes(vector<Client> &clients, string name1){
    ifstream fileptr;
    string name, address, job;
    float income;
    
    fileptr.open(name1);

    if(fileptr.good()){
        while(getline(fileptr, name) && getline(fileptr, address) && getline(fileptr, job) && fileptr >> income){
            fileptr.ignore();
            Client newClient(name, address, job, income);
            clients.push_back(newClient);
        }
    }
    else{
        cout << "error" << endl;
    }
    fileptr.close();

}
void ExportarDadosContas(vector<Account> &accounts, string name){
    ofstream fileptr;

    fileptr.open(name);

    if(fileptr.good()){
        for(size_t i = 0; i < accounts.size(); i++){
            fileptr << accounts[i].GetClientInformationSimple() << "\n" << accounts[i].GetBalance() << "\n" ;
        }
    }
    else{
        cout << "error to open file" << endl;
    }
    fileptr.close();
}
void ExportarDadosClientes(vector<Client> &clients, string name){
     ofstream fileptr;

    fileptr.open(name);

    if(fileptr.good()){
        for(size_t i = 0; i < clients.size(); i++){
            fileptr << clients[i].GetName() << "\n" << clients[i].GetAddress() << "\n" << clients[i].GetJob() << "\n" << clients[i].GetIncome() << "\n" ;
        }
    }
    else{
        cout << "error to open file" << endl;
    }
    fileptr.close();
}