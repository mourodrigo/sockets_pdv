//
//  main.cpp
//  tcp_socket_pdv_client
//
// Trabalho 2 - Camada de Transporte - Redes de computadores - UFFS
// Rodrigo Bueno Tomiosso e Edimar Junior


#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include "AssocArray.cpp"
#include <string>

#define SERVER_PORT 6790
#define SEPARATOR "#"


class Product{ // classe para tratamento das informações dos produtos
public:
    int product;
    int quantity;
    int value;
    
    Product(int _product, int _quantity, float _value){
        product = _product;
        quantity = _quantity;
        value = _value;
    }
};


void send(int port, std::string address, std::string message){ // cria um socket e envia uma pensagem para determinado destino
    struct sockaddr_in servaddr;
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(address.c_str());
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    send(sock, message.c_str(), strlen(message.c_str()), 0);
    close(sock);
}

std::vector<std::string> explode( const std::string& s, const std::string& delimiter ){ //Explode que divide uma string conforme o separador recebido
    std::vector<std::string> result;
    std::string::size_type from = 0;
    std::string::size_type to = 0;
    
    while ( to != std::string::npos ){
        to = s.find( delimiter, from );
        if ( from < s.size() && from != to ){
            result.push_back( s.substr( from, to - from ) );
        }
        from = to + delimiter.size();
    }
    return result;
}

void reply(std::vector<Product> products, std::string transaction, std::string address, std::string port){// metodo que faz o calculo total do pedido e envia para o cliente
    int p = fork();
    if(p==0){ // se esta dentro da thread filho
        float total = 0;
        for (int p = 0; p<products.size(); p++) {
            total+=(products.at(p).value*products.at(p).quantity);
        }
        std::cout <<std::endl<< "TOTAL DO PEDIDO "<< transaction<< " = " << total;
        
        send(atoi(port.c_str()), address, std::to_string(total));
        
    }
}


void listen(){ // metodo que cria um socket em determinada porta para ouvir os dados enviados pelo cliente
    struct sockaddr_in servaddr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT);
    
    bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(sock, 5);
    
    std:: cout << "Server running on port: " << SERVER_PORT << std::endl;
    
    AssocArray<std::vector<Product>> transactions;
    
    while(1)
    {
        int clisock = accept(sock, (struct sockaddr *) NULL, NULL);
        
        if (clisock >= 0)
        {
            int messageLength = 160;
            char message[messageLength+1];
            int in, index = 0, limit = messageLength;
            
            while ((in = recv(clisock, &message[index], messageLength, 0)) > 0)
            {
                index += in;
                limit -= in;
            }
            std::vector<std::string> messageArray = explode(message, "_");
            if (messageArray.size()>1) {
                std::string transaction = messageArray.at(0);
                
                if (messageArray.at(1).compare("end")==0) {
                    reply(transactions[transaction], transaction, messageArray.at(2), messageArray.at(3));
                    transactions[transaction].clear();
                }else{
                    printf("Pacote aceito %s\n", message);
                    Product p = Product(atoi(messageArray.at(1).c_str()), atoi(messageArray.at(2).c_str()), atof(messageArray.at(3).c_str()));
                    transactions[transaction].push_back(p);
                }
                
            }else{
                printf("pacote ignorado %s\n", message);
                //ignora o pacote
            }
            
        }
        close(clisock);
    }
}



int main(int argc, char **argv)
{
    listen();
}
