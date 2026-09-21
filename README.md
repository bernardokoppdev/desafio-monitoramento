# Sistema Inteligente de Monitoramento Industrial

## 1. Identificação

**Aluno:** Bernardo Kopp Pinheiro  
**Disciplina:** Algoritmos e Pensamento Computacional
**Professora:** Profa. Karla Sartin  
**Projeto:** Sistema Inteligente de Monitoramento Industrial  

---

## 2. Objetivo

O objetivo deste projeto é desenvolver um sistema de monitoramento
de temperatura de uma máquina industrial utilizando a linguagem C.

O programa permite definir um limite de temperatura e registrar
diversas leituras de um sensor.

Durante o monitoramento, o sistema identifica temperaturas acima
do limite estabelecido e encerra automaticamente o processo caso
sejam detectadas três temperaturas consecutivas acima desse limite.

Ao final, o programa apresenta um relatório com informações
estatísticas sobre as temperaturas registradas.

---

## 3. Funcionamento do programa

### Definição do limite

No início da execução, o usuário informa o limite máximo de
temperatura utilizado pelo sistema.

O programa verifica se o valor informado é numérico. Caso seja
digitada uma entrada inválida, uma mensagem de erro é exibida e
o valor é solicitado novamente.

### Leituras das temperaturas

Após a definição do limite, o programa começa a receber as
temperaturas registradas pelo sensor.

Cada temperatura válida é utilizada para atualizar:

- quantidade de leituras;
- soma das temperaturas;
- maior temperatura;
- menor temperatura;
- quantidade de temperaturas acima do limite;
- quantidade de temperaturas consecutivas acima do limite.

### Tratamento de valores inválidos

Caso o usuário informe um valor não numérico, a entrada é
considerada inválida.

O programa exibe uma mensagem de erro, limpa a entrada inválida
e solicita uma nova temperatura.

A entrada inválida não é considerada nos cálculos do relatório.

### Temperaturas acima do limite

Sempre que uma temperatura é maior que o limite definido,
o programa exibe um alerta e incrementa o contador de
temperaturas acima do limite.

### Temperaturas consecutivas

O programa possui um contador específico para controlar
temperaturas consecutivas acima do limite.

Quando uma temperatura ultrapassa o limite, esse contador é
incrementado.

Caso uma temperatura seja menor ou igual ao limite, o contador
de temperaturas consecutivas é reiniciado para zero.

### Encerramento do monitoramento

O monitoramento é encerrado automaticamente quando são
identificadas três temperaturas consecutivas acima do limite.

Após o encerramento, o programa apresenta um relatório contendo:

- quantidade de leituras válidas;
- maior temperatura registrada;
- menor temperatura registrada;
- média das temperaturas;
- quantidade de temperaturas acima do limite;
- percentual de temperaturas acima do limite.

---

## 4. Estruturas de repetição utilizadas

Neste projeto foram utilizadas as estruturas `while` e
`do...while`.

### do...while

O `do...while` foi utilizado na definição do limite de
temperatura.

Essa estrutura foi escolhida porque o programa precisa solicitar
o limite pelo menos uma vez antes de verificar se a entrada é
válida.

Caso a entrada seja inválida, o laço executa novamente.

### while

O `while` foi utilizado durante o monitoramento das temperaturas.

O programa continua recebendo temperaturas enquanto a quantidade
de temperaturas consecutivas acima do limite for menor que três.

Também foi utilizado um `while` para limpar entradas inválidas
do buffer de entrada.

---

## 5. Como executar

Para compilar o programa utilizando GCC:

```bash
gcc monitoramento.c -o monitoramento
