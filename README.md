# Vingança das Arvores parte 2 - EA872

## Estrutura e execução

Tivemos dois diretórios: um para o(s) cliente(s) (`client`) e outro para o servidor (`server`), a inicialização e execução de cada um é bastante parecida: </br>
Nos dois casos se cria um diretório build, utiliza-se o comando `cmake ..`, damos `make` e depois rodamos o executável gerado.
Uma diferença é que, embora os dois requiram que no mesmo diretório do executável tenhamos um arquivo chamado `state.ini`, o que ele representa nos dois casos é diferente:
* `state.ini` para o cliente: 
	Para o cliente é nesse arquivo que colocamos os dados do servidor, na primeira linha colocamos o ip (com pontuação) e na seguda o port que vai ser utilizado.
* `state.ini` para o servidor:
	Para o servidor esse é o arquivo que vai servir para ser feita a inicialização dos zumbis, a primeira linha, o tamanho (`h` e `w`) dos zumbis iniiciais e partir da segunda a posição deles na tela.

## Protocolos de comunicação:

Os passos da comunicação entre os clientes e o servidor são:

1. Inicialmente, o cliente manda um handshake (um json com a chave `"type": "handshake"`
2. O servidor, após ler a chave, salva o endpoint do cliente no seu vetor de endpoints e adidicona um novo jogador ao jogo.
3. Para todos os endpoins dentro do vetor do servidor, são enviados jsons correspondentes à iterações do jogo.

Importante salientar que o servidor opera em três threads, uma que recebe os comandos dados pelos clientes e os guarda numa pilha (`receiver`), outra que checa se a pilha não está vazia e, caso não estea, executa esses comandos (`iterateQueue`)  e outra para enviar o estado atual do jogo para todos os clientes (`sender`). Enquanto isso, temos o cliente operando por duas, uma que recebe o estado do jogo (em forma de json) e desserializa ele e outra que envia os comandos usados pelo teclado dos jogadores para o servidor interpretá-los.

## MVC:

Para quase todas as estruturas do jogo (exceto as de base, que só tinham model e view), aderimos a estrutura de organização do Model View Controller, onde os controles se comuncavam entre si e estes se comunicavam com seus models e seus views.
 
