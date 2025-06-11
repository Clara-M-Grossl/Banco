#include <iostream>
#include <string>
#include <sstream>
#include "account.hpp"
#include "client.hpp"
#include "functions.hpp"

using namespace std;

int main(){
    int opc;
    vector<Client> clients;
    vector<Account> accounts;

    cout << "IMPORTANDO DADOS" << endl;

    ImportarDadosContas(accounts, "accounts.txt");
    ImportarDadosClientes(clients, "clients.txt");

    for(;;){
        cout << "Escolha uma opcao: " << endl;
        cout << "[1] - Cadastrar cliente" << endl;
        cout << "[2] - Atualizar cliente" << endl;
        cout << "[3] - Remover cliente" << endl;
        cout << "[4] - Pesquisar cliente por substring" << endl;
        cout << "[5] - Criar uma conta" << endl;
        cout << "[6] - Deposito" << endl;
        cout << "[7] - Transferencia" << endl;
        cout << "[8] - Imprimir dados de uma conta" << endl;
        cout << "[0] - Sair" << endl;
        cout << "<< ";
        cin >> opc;

        if(opc == 1){
            Client newClient = CadastrarCliente();
            clients.push_back(newClient);
            continue;
        }
        if(opc == 2){
            string name;
            cin.ignore();
            cout << "Digite o nome desejado......................: ";
            getline(cin, name);

            int i = SearchSubstring(name, clients);
            if(i < 0){
                cout << "cliente nao encontrado" << endl;
                break;
            }
            cout << "cliente encontrado" << endl;
            MostrarClientes(clients, i);
            cout << "Deseja atualizar a (o) cliente " << clients[i].GetName() << "?" << endl;
            cout << "[1] - Sim" << endl << "[2] - Nao" << endl;
            int answer;
            cin >> answer;

            if(answer == 1){
                string nome;
                string job;
                string address;
                float income;

                cin.ignore();

                cout << "Digite o nome........................: ";
                getline(cin, nome);

                cout << "Digite o endereco........................: ";
                getline(cin, address);

                cout << "Digite a profissao........................: ";
                getline(cin, job);

                cout << "Digite a renda........................: ";
                cin >> income;

                clients[i].Update(nome, address, job, income);
                cout << "Cliente atualizado" << endl;
                continue;
            }
            else if(answer == 2){
                cout << "Voltando ao menu principal........................." << endl;
                continue;
            }
            else{
                cout << "opcaoa invalida" << endl;
                continue;
            }
            continue;
        }
        if(opc == 3){
            string name;
            cin.ignore();
            cout << "Digite o nome desejado......................: ";
            getline(cin, name);

            int i = SearchSubstring(name, clients);
            if(i < 0){
                cout << "cliente nao encontrado" << endl;
                break;
            }
            cout << "cliente encontrado" << endl;
            MostrarClientes(clients, i);
            cout << "Deseja deletar a (o) cliente " << clients[i].GetName() << "?" << endl;
            cout << "[1] - Sim" << endl << "[2] - Nao" << endl;
            int answer;
            cin >> answer;

            if(answer == 1){
                if(DeleteClient(i, clients)){
                    continue;
                }else{
                    break;
                }
            }
            else if(answer == 2){
                cout << "Voltando ao menu principal........................." << endl;
                continue;
            }
            else{
                cout << "opcaoa invalida" << endl;
                continue;
            }
            continue;
        }
        if(opc == 4){
            string name;
            cin.ignore();
            cout << "Digite o nome desejado(* para todos)......................: ";
            getline(cin, name);

            if(name == "*"){
                for(int i = 0; i < clients.size(); i++){
                    MostrarClientes(clients, i);
                }
                continue;
            }
            int i = SearchSubstring(name, clients);
            if(i < 0){
                cout << "cliente nao encontrado" << endl;
                continue;
            }
            cout << "cliente encontrado" << endl;
            MostrarClientes(clients, i);
            continue;
        }
        if(opc == 5){
            string name;
            cin.ignore();
            cout << "Digite o nome desejado......................: "; 
            getline(cin, name);

            int i = SearchSubstring(name, clients);
            if(i < 0){
                cout << "cliente nao encontrado" << endl;
                break;
            }
            cout << "cliente encontrado" << endl;
            MostrarClientes(clients, i);
            cout << "Deseja criar uma conta para: " << clients[i].GetName() << "?" << endl;
            cout << "[1] - Sim" << endl << "[2] - Nao" << endl;
            int answer;
            cin >> answer;

            if(answer == 1){
                Account newAccount = CadastrarConta(i, clients);
                accounts.push_back(newAccount);
            }
            else if(answer == 2){
                cout << "Voltando ao menu principal........................." << endl;
                continue;
            }
            else{
                cout << "opcaoa invalida" << endl;
                continue;
            }
            continue;
        }
        if(opc == 6){
            int index;
            cout << "Digite o indice desejado: ";
            cin >> index;

            if(index >= 0 && index <= accounts.size()){
                MostrarContas(index, accounts);
                float value;

                cout << "Digite o valor do deposito.................: ";
                cin >> value;

                if(accounts[index].Deposit(value)){
                    cout << "Valor depositado" << endl;
                    continue;
                }
                continue;
            }
            cout << "Indice ( " << index << " ) invalido" << endl;
            continue;
        }
        if(opc == 7){
            int index;
            int index_2;
            cout << "Digite o indice desejado: ";
            cin >> index;

            if(index >= 0 && index <= accounts.size()){
                MostrarContas(index, accounts);

                cout << "Digite o indice para transferir: ";
                cin >> index_2;

                if(index_2 >= 0 && index_2 <= accounts.size()){
                    MostrarContas(index_2, accounts);
                    float value;

                    cout << "Digite o valor da transferencia.................: ";
                    cin >> value;

                    if(accounts[index].Transfer(accounts[index_2], value)){
                        cout << "Valor transferidp" << endl;
                        continue;
                    }
                    cout << "valor nao depositado" << endl;
                    continue;
                }
            }
            cout << "Indice ( " << index << " ) invalido" << endl;
            continue;
        }
        if(opc == 8){
            string y;
            cin.ignore();
            cout << "Digite o indice desejado (* para todos): ";
            getline(cin, y);
            
            if(y == "*"){
                for(size_t i = 0; i < accounts.size(); i++){
                    MostrarContas(i, accounts);
                }
            }
            else{
                int index = stoi(y);
                if(index >= 0 && index < accounts.size()){
                    MostrarContas(index, accounts);
                    continue;
                }
                cout << "Indice ( " << index << " ) invalido" << endl;
                 continue;
            }
            continue;
        }
        if(opc == 0){
            cout << "EXPORTANDO DADOS" << endl;
            ExportarDadosContas(accounts, "accounts.txt");
            ExportarDadosClientes(clients, "clients.txt");
            cout << "Saind.............." << endl;
            break;
        }
        else{
            cout << "invalido" << endl;
            break;
        }
    }
    return 0;
}
