# DERIVA E INTEGRA

Esse programa conta com algumas funções iradas para ajudar você em cálculos matemáticos básicos.
Vamos explicar como usar cada uma dessas funções, na moral?

## Função criarfuncao():
Essa função é para você criar a sua própria função polinomial. Primeiro, você precisa digitar o número de elementos que sua função terá. Em seguida, para cada elemento, digite o coeficiente e a potência da variável, separados por vírgula. Com isso, será criado um arquivo chamado "polinomio.txt" com a sua função.

## Função estatistica():
Nessa função, você pode calcular a média, desvio padrão, soma dos números e variância populacional e amostral de uma amostra. Para isso, basta digitar a quantidade de números da amostra e, em seguida, os valores separados por enter. Caso não exista um arquivo "estatistica.txt", será criado um arquivo e, depois do cálculo, as informações serão adicionadas a esse arquivo.

## Função derivacao():
Com essa função, você pode derivar uma função polinomial. Se já tiver um arquivo "polinomio.txt", o programa lerá essa função. Caso contrário, será criado um novo arquivo para a sua função. Em seguida, será mostrada a função derivada no arquivo "polinomio.txt".

## Função integra():
Esse programa lê um polinômio de um arquivo de texto chamado 'polinomio.txt', integra a função, imprime a equação integrada em um novo arquivo de texto e calcula a área abaixo da função em um intervalo definido pelo usuário.

### Como usar
Certifique-se de que existe um arquivo de texto chamado 'polinomio.txt' na pasta do programa, com o seguinte formato:

    5
    2x^2 3x^1 1x^0
  
O primeiro número indica a quantidade de termos na função e os próximos termos são os coeficientes e expoentes do polinômio.

Execute o programa em seu terminal.

Digite a opção "1" para criar um novo arquivo de texto com novos valores ou "2" para utilizar o arquivo existente.

Digite os valores de integração, valor superior e inferior, respectivamente separados por ','.

O resultado será armazenado no arquivo de texto 'polinomio.txt'.

## Contribuições
Contribuições são sempre bem-vindas! Sinta-se à vontade para enviar um pull request.

E aí, curtiu? Aproveita bastante e bons cálculos!
