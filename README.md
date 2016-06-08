# sockets_pdv

Implementação de dois programas na linguagem de sua eleição. Um se chamará “cliente” e outro “servidor”.

Cliente: 
a) inicia por linha de comando com dois argumentos (porta e pedido.txt). Onde “porta” é o número da porta em que o servidor atende. Onde “pedido.txt” é um arquivo texto em que as linhas têm o seguinte formato (produto, quantidade, valor unitario).

O cliente usa TCP para conectar se com o servidor, lê o arquivo texto e envia para o servidor.

Servidor:
b) inicia por linha de comando (pode usar porta dinâmica ou por argumento). Cria um socket na porta especificada, escuta e aceita conexões de clientes.
c) usa threads para manipular múltiplos clientes.
d) devolve a soma com o valor total do pedido (somatório de (quantidade * valor)).

# Exemplo de execução do servidor:



Server running on port: 6792
Pacote aceito 1465347381_25_10_1
Pacote aceito 1465347381_87_10_8
Pacote aceito 1465347381_99_7_12
Pacote aceito 1465347381_17_6_28
Pacote aceito 1465347381_69_6_24
Pacote aceito 1465347381_21_6_21
Pacote aceito 1465347381_20_5_2_
Pacote aceito 1465347381_77_7_27
Pacote aceito 1465347381_35_10_2
Pacote aceito 1465347381_59_2_8_
Pacote aceito 1465347381_53_6_11
Pacote aceito 1465347381_94_8_11
Pacote aceito 1465347381_57_1_15
Pacote aceito 1465347381_78_10_1
Pacote aceito 1465347381_25_7_2_
Pacote aceito 1465347381_81_5_13
Pacote aceito 1465347381_97_4_20
Pacote aceito 1465347381_3_3_16_
Pacote aceito 1465347381_86_2_14
Pacote aceito 1465347381_55_4_1_
Pacote aceito 1465347381_55_1_3_
Pacote aceito 1465347381_19_1_5_
Pacote aceito 1465347381_32_9_2_
Pacote aceito 1465347381_80_3_30
Pacote aceito 1465347381_41_3_9_
Pacote aceito 1465347381_21_7_15
Pacote aceito 1465347381_13_2_25
Pacote aceito 1465347381_61_10_8
Pacote aceito 1465347381_23_2_14
Pacote aceito 1465347381_33_7_14
Pacote aceito 1465347381_73_0_19
Pacote aceito 1465347381_93_2_6_
Pacote aceito 1465347381_31_9_9_
Pacote aceito 1465347381_56_3_1_
Pacote aceito 1465347381_67_9_9_
Pacote aceito 1465347381_82_8_29
Pacote aceito 1465347381_19_4_12
Pacote aceito 1465347381_27_1_11
Pacote aceito 1465347381_49_8_16
Pacote aceito 1465347381_33_3_1_
Pacote aceito 1465347381_52_0_11
Pacote aceito 1465347381_97_4_3_
Pacote aceito 1465347381_33_1_1_
Pacote aceito 1465347381_1_8_4__
Pacote aceito 1465347381_1_1_23_
Pacote aceito 1465347381_59_2_20
Pacote aceito 1465347381_5_8_10_
Pacote aceito 1465347381_26_2_10
Pacote aceito 1465347381_38_6_5_
Pacote aceito 1465347381_64_3_9_
Pacote aceito 1465347381_73_1_11
Pacote aceito 1465347381_36_9_5_
Pacote aceito 1465347381_11_0_3_
Pacote aceito 1465347381_72_1_11
Pacote aceito 1465347381_43_4_23
Pacote aceito 1465347381_93_0_15
Pacote aceito 1465347381_41_9_3_
Pacote aceito 1465347381_18_6_30
Pacote aceito 1465347381_29_5_14
Pacote aceito 1465347381_54_6_18
Pacote aceito 1465347381_10_10_2
Pacote aceito 1465347381_22_5_7_
Pacote aceito 1465347381_35_8_8_
Pacote aceito 1465347381_6_5_8__
Pacote aceito 1465347381_39_10_2
Pacote aceito 1465347381_70_4_4_
Pacote aceito 1465347381_52_0_1_
Pacote aceito 1465347381_90_1_16
Pacote aceito 1465347381_38_1_16
Pacote aceito 1465347381_21_3_24
Pacote aceito 1465347381_75_5_15
Pacote aceito 1465347381_63_8_10
Pacote aceito 1465347381_48_9_1_
Pacote aceito 1465347381_25_8_17
Pacote aceito 1465347381_77_9_21
Pacote aceito 1465347381_56_0_30
Pacote aceito 1465347381_26_6_14
Pacote aceito 1465347381_60_5_8_
Pacote aceito 1465347381_11_1_29
Pacote aceito 1465347381_71_7_29
Pacote aceito 1465347381_97_7_23
Pacote aceito 1465347381_49_5_7_
Pacote aceito 1465347381_19_7_11
Pacote aceito 1465347381_74_6_2_
Pacote aceito 1465347381_29_2_6_
Pacote aceito 1465347381_99_3_11
Pacote aceito 1465347381_93_2_29
Pacote aceito 1465347381_73_2_9_
Pacote aceito 1465347381_26_3_19
Pacote aceito 1465347381_37_10_3
Pacote aceito 1465347381_83_8_2_
Pacote aceito 1465347381_13_7_9_
Pacote aceito 1465347381_55_7_30
Pacote aceito 1465347381_98_9_29
Pacote aceito 1465347381_90_10_1
Pacote aceito 1465347381_33_9_26
Pacote aceito 1465347381_13_7_23
Pacote aceito 1465347381_79_3_27
Pacote aceito 1465347381_87_1_24
Pacote aceito 1465347381_69_1_17

# Exemplo de execução no cliente

Identificador da transação: 1465347381
Transmitindo: 1465347381_25_10_12_
Transmitindo: 1465347381_87_10_8_
Transmitindo: 1465347381_99_7_12_
Transmitindo: 1465347381_17_6_28_
Transmitindo: 1465347381_69_6_24_
Transmitindo: 1465347381_21_6_21_
Transmitindo: 1465347381_20_5_2_
Transmitindo: 1465347381_77_7_27_
Transmitindo: 1465347381_35_10_25_
Transmitindo: 1465347381_59_2_8_
Transmitindo: 1465347381_53_6_11_
Transmitindo: 1465347381_94_8_11_
Transmitindo: 1465347381_57_1_15_
Transmitindo: 1465347381_78_10_14_
Transmitindo: 1465347381_25_7_2_
Transmitindo: 1465347381_81_5_13_
Transmitindo: 1465347381_97_4_20_
Transmitindo: 1465347381_3_3_16_
Transmitindo: 1465347381_86_2_14_
Transmitindo: 1465347381_55_4_1_
Transmitindo: 1465347381_55_1_3_
Transmitindo: 1465347381_19_1_5_
Transmitindo: 1465347381_32_9_2_
Transmitindo: 1465347381_80_3_30_
Transmitindo: 1465347381_41_3_9_
Transmitindo: 1465347381_21_7_15_
Transmitindo: 1465347381_13_2_25_
Transmitindo: 1465347381_61_10_8_
Transmitindo: 1465347381_23_2_14_
Transmitindo: 1465347381_33_7_14_
Transmitindo: 1465347381_73_0_19_
Transmitindo: 1465347381_93_2_6_
Transmitindo: 1465347381_31_9_9_
Transmitindo: 1465347381_56_3_1_
Transmitindo: 1465347381_67_9_9_
Transmitindo: 1465347381_82_8_29_
Transmitindo: 1465347381_19_4_12_
Transmitindo: 1465347381_27_1_11_
Transmitindo: 1465347381_49_8_16_
Transmitindo: 1465347381_33_3_1_
Transmitindo: 1465347381_52_0_11_
Transmitindo: 1465347381_97_4_3_
Transmitindo: 1465347381_33_1_1_
Transmitindo: 1465347381_1_8_4_
Transmitindo: 1465347381_1_1_23_
Transmitindo: 1465347381_59_2_20_
Transmitindo: 1465347381_5_8_10_
Transmitindo: 1465347381_26_2_10_
Transmitindo: 1465347381_38_6_5_
Transmitindo: 1465347381_64_3_9_
Transmitindo: 1465347381_73_1_11_
Transmitindo: 1465347381_36_9_5_
Transmitindo: 1465347381_11_0_3_
Transmitindo: 1465347381_72_1_11_
Transmitindo: 1465347381_43_4_23_
Transmitindo: 1465347381_93_0_15_
Transmitindo: 1465347381_41_9_3_
Transmitindo: 1465347381_18_6_30_
Transmitindo: 1465347381_29_5_14_
Transmitindo: 1465347381_54_6_18_
Transmitindo: 1465347381_10_10_20_
Transmitindo: 1465347381_22_5_7_
Transmitindo: 1465347381_35_8_8_
Transmitindo: 1465347381_6_5_8_
Transmitindo: 1465347381_39_10_2_
Transmitindo: 1465347381_70_4_4_
Transmitindo: 1465347381_52_0_1_
Transmitindo: 1465347381_90_1_16_
Transmitindo: 1465347381_38_1_16_
Transmitindo: 1465347381_21_3_24_
Transmitindo: 1465347381_75_5_15_
Transmitindo: 1465347381_63_8_10_
Transmitindo: 1465347381_48_9_1_
Transmitindo: 1465347381_25_8_17_
Transmitindo: 1465347381_77_9_21_
Transmitindo: 1465347381_56_0_30_
Transmitindo: 1465347381_26_6_14_
Transmitindo: 1465347381_60_5_8_
Transmitindo: 1465347381_11_1_29_
Transmitindo: 1465347381_71_7_29_
Transmitindo: 1465347381_97_7_23_
Transmitindo: 1465347381_49_5_7_
Transmitindo: 1465347381_19_7_11_
Transmitindo: 1465347381_74_6_2_
Transmitindo: 1465347381_29_2_6_
Transmitindo: 1465347381_99_3_11_
Transmitindo: 1465347381_93_2_29_
Transmitindo: 1465347381_73_2_9_
Transmitindo: 1465347381_26_3_19_
Transmitindo: 1465347381_37_10_3_
Transmitindo: 1465347381_83_8_2_
Transmitindo: 1465347381_13_7_9_
Transmitindo: 1465347381_55_7_30_
Transmitindo: 1465347381_98_9_29_
Transmitindo: 1465347381_90_10_11_
Transmitindo: 1465347381_33_9_26_
Transmitindo: 1465347381_13_7_23_
Transmitindo: 1465347381_79_3_27_
Transmitindo: 1465347381_87_1_24_
Transmitindo: 1465347381_69_1_17_


Envio finalizado

Aguardando resposta para o pedido 1465347381
Client listening on port: 6793
TOTAL DO PEDIDO: 6641.000000


Arquivo salvo: ~/tcp_socket_pdv_client1465347381.txt
 
 Program ended with exit code: 0
