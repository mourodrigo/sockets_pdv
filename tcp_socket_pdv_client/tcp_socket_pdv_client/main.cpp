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
#include <fstream>
#include <ctime>

#define SEPARATOR "_"
#define IP_ADDRESS "127.0.0.1"
#define SERVER_ADDRESS "127.0.0.1"


class Product{
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

bool fileExists(const char *filename){ //Verifica se arquivo existe
    std::ifstream ifile(filename);
    if (ifile) {
        return true;
    }else{
        return false;
    }
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

std::string getDateTimeSecondsString(){ //busca uma string com data e hora atual usada para identificar o pedido
    time_t now = time(0);
    return std::to_string(now);
}

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

std::vector<Product> getProducts(std::string path){//Função que retorna todos os banco de dados cadastrados
    std::vector <Product> dbs;
    if(fileExists(path.c_str())){
        std::string line;
        std::ifstream file (path);
        if (file.is_open()){
            while ( file.good() ){
                getline (file,line);
                if(line != "\0"){//Se a linha for vazia, não executa o procedimento
                    std::vector <std::string> databaseline;
                    databaseline = explode(line, ",");
                    int id, quantity;
                    id = atoi(databaseline.at(0).c_str());
                    quantity = atoi(databaseline.at(1).c_str());
                    int value = atoi(databaseline.at(2).c_str());
                    Product p = Product(id,quantity, value);
                    dbs.push_back(p); //Poderia ser colocado em um vetor para uso futuro
                }
            }
            file.close();
            return dbs;
        }else{
            std::cout << "Erro ao abrir arquivo "<< path <<std::endl;
            return dbs;
        }
    }else{
        std::cout << "Arquivo nao encontrado "<< path <<std::endl;
    }
    return dbs;
}


void listen(int port, std::string outPath, std::string transactionId){ // cria um socket para buscar a resposta do servidor com o total do pedido
    struct sockaddr_in servaddr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    std::ofstream file;
    file.open(outPath);

    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    
    bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(sock, 5);
    
    std:: cout << "Client listening on port: " << port << std::endl;
    
    std::string content = "";
    float total = 0;
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
            
            if (total==0) {
                printf("TOTAL DO PEDIDO: %s\n", message);
                total = atof(message);
                file << "TOTAL DO PEDIDO " << transactionId << ": R$" << message;
                break;
            }
        }
        close(clisock);
        

    }
    

    file.close();
    std::cout<< "\n\n Arquivo salvo: " << outPath;
}


int main(int argc, char **argv)
{
    if (argc>1) {
        int SERVER_PORT = atoi(argv[1]);
        std::vector<Product> products = getProducts(argv[2]);
        if (products.size()>0) {
            std::string transactionid = getDateTimeSecondsString();
            std::cout <<
            "Identificador da transação: " << transactionid << std::endl;
            for (int px=0; px<products.size(); px++) {
                Product p = products.at(px);
                std::string productStr = transactionid+SEPARATOR+std::to_string(p.product)+SEPARATOR+std::to_string(p.quantity)+SEPARATOR+std::to_string(p.value)+SEPARATOR;
                send(SERVER_PORT, "127.0.0.1", productStr);
                std::cout << "Transmitindo: " << productStr << std::endl;
            }
            send(SERVER_PORT, SERVER_ADDRESS, transactionid+SEPARATOR+"end"+SEPARATOR+IP_ADDRESS+SEPARATOR+std::to_string(SERVER_PORT+1)+SEPARATOR);
            std::cout << std::endl<< "Envio finalizado" << std::endl;
            std::cout << std::endl<< "Aguardando resposta para o pedido " <<transactionid<< std::endl;
            listen(SERVER_PORT+1, argv[0]+transactionid+".txt", transactionid);
        }else{
            std::cout<< "Erro ao ler produtos";
        }
        
    }else{
        std::cout << "Informe os parametros corretamente: <porta> <caminho completo do pedido>" << std::endl;
    }
}


