# Vingança das Arvores parte 2 - EA872

## Instruções de compilação e execução

Temos dois diretórios: um para o(s) cliente(s) (`client`) e outro para o servidor (`server`), a inicialização e execução de cada um é bastante parecida: </br>


Nos dois casos se cria um diretório `build`, utiliza-se o comando `cmake ..`, damos `make` e rodamos o executável gerado (`./VingancasArvores`).

Uma diferença é que, embora os dois requeiram que no mesmo diretório do executável tenhamos um arquivo chamado `state.ini`, o que ele representa nos dois casos é diferente:

### `state.ini` para o cliente (posicionado no caminho `./client/state.ini`): 
Para o cliente é nesse arquivo que colocamos os dados do servidor, na primeira linha colocamos o ip (com pontuação) e na seguda o port que vai ser utilizado. </br>
Exemplo para conexão do IP 127.0.0.1 no PORT 9001: (já temos um arquivo exemplo com esses dados) </br>
```
127.0.0.1
9001
```

### `state.ini` para o servidor (posicionado no caminho `./server/state.ini`):
Para o servidor esse é o arquivo que vai servir para ser feita a inicialização dos zumbis, a primeira linha, o tamanho (horizontal e vertical) dos zumbis iniciais e partir da segunda a posição deles na tela. </br>
Exemplo para a criação de dois zumbis de tamaho 150x150 nas posições 500,500 e 600,600: (já temos um arquivo exemplo com esses dados) </br>
```
150 150
500 500
600 600
``` 
