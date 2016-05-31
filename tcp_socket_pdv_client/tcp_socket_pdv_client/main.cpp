//
//  main.cpp
//  tcp_socket_pdv_client
//
//  Created by Rodrigo Bueno Tomiosso on 24/05/16.
//  Copyright © 2016 mourodrigo. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <fstream>

using namespace std;


class Product{
public:
    int product;
    int quantity;
    float value;
    
    Product(int _product, int _quantity, float _value){
        product = _product;
        quantity = _quantity;
        value = _value;
    }
};

bool fileExists(const char *filename){ //Verifica se arquivo existe
    ifstream ifile(filename);
    if (ifile) {
        return true;
    }else{
        return false;
    }
}

vector<string> explode( const string& s, const string& delimiter ){ //Explode que divide uma string conforme o separador recebido
    vector<string> result;
    string::size_type from = 0;
    string::size_type to = 0;
    
    while ( to != string::npos ){
        to = s.find( delimiter, from );
        if ( from < s.size() && from != to ){
            result.push_back( s.substr( from, to - from ) );
        }
        from = to + delimiter.size();
    }
    return result;
}

vector<Product> getProducts(string path){//Função que retorna todos os banco de dados cadastrados
    vector <Product> dbs;
    if(fileExists(path.c_str())){
        string line;
        ifstream file (path);
        if (file.is_open()){
            while ( file.good() ){
                getline (file,line);
                if(line != "\0"){//Se a linha for vazia, não executa o procedimento
                    vector <string> databaseline;
                    databaseline = explode(line, ", ");
                    int id, quantity;
                    id = atoi(databaseline.at(0).c_str());//Converte para inteiro o id
                    quantity = atoi(databaseline.at(1).c_str());
                    float value = atof(databaseline.at(2).c_str());//Converte para inteiro o id da tablespace
                    Product p = Product(id,quantity, value);
                    dbs.push_back(p);//Coloca no vetor dos banco de dados
                }
            }
            file.close();
            return dbs;
        }else{
            cout << "Erro ao abrir arquivo "<< path <<endl;
            return dbs;
        }
    }else{
        cout << "Arquivo nao encontrado "<< path <<endl;
    }
    return dbs;
}



int main(int argc, char **argv)
{
    struct sockaddr_in servaddr;
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6789);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    while(1)
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        
        char message[161];
        fgets(message, 161, stdin);
        
        /* Replacing '\n' with '\0' */
        char *tmp = strchr(message, '\n');
        if (tmp) *tmp = '\0';
        
        connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
        send(sock, message, strlen(message), 0);
        close(sock);
    }
}
