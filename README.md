# Simulador-de-investimentos
O código a seguir contém um simulador de investimentos desenvolvido por mim para a realização de um desafio proposto pelo meu professor Getúlio na matéria de Algoritmos e Fundamentos da Programação 2.

Desafio a seguir:

Simulador de Investimentos — Projeção de Aportes Mensais com Rendimento Composto
Contexto
Um assessor de investimentos deseja montar uma ferramenta simples em C para simular o crescimento de um capital investido em aportes mensais. O sistema deve permitir cadastrar múltiplos cenários de investimento, calcular a projeção de cada um e comparar resultados, ajudando o cliente a tomar uma decisão informada.

Enunciado
Elabore um programa em C-ANSI que gerencie até 20 cenários de investimento. Cada cenário deve ser armazenado em um struct chamado Investimento, contendo:

Identificador do cenário (inteiro, sequencial)
Descrição (string de até 50 caracteres — ex.: "Tesouro Selic", "CDB 120%", "Fundo Imobiliário")
Valor do aporte mensal (real positivo)
Taxa de juros mensal (real, em porcentual — ex.: 1.0 para 1% ao mês)
Número de meses (inteiro, entre 1 e 360)
Montante final (real — a ser calculado pelo programa)
Total investido (real — soma de todos os aportes)
Total de juros ganhos (real — montante final menos total investido)
O programa deve apresentar um menu com as seguintes opções:

Cadastrar cenário: o usuário informa descrição, aporte mensal, taxa de juros e número de meses. O programa calcula automaticamente o montante final usando juros compostos sobre aportes mensais, o total investido e o total de juros ganhos, armazenando tudo no struct.

Fórmula do montante para aportes mensais:
M = P × ((1 + i)n − 1) / i
onde P é o aporte mensal, i é a taxa de juros mensal (em formato decimal) e n é o número de meses.
Listar cenários: exibir todos os cenários cadastrados em formato tabular com seus resultados.
Comparar cenários: identificar e exibir qual cenário possui o maior montante final e qual possui o maior rendimento percentual (juros ganhos / total investido × 100).
Detalhar cenário: dado o identificador, exibir uma tabela mês a mês mostrando, para cada mês: número do mês, saldo acumulado antes do aporte, valor do aporte, e saldo após rendimento daquele mês.
Sair.
Cada funcionalidade deve ser uma função separada. O cálculo do montante final deve ser feito por uma função dedicada que recebe os parâmetros (aporte, taxa, meses) e retorna o valor calculado. A função de detalhamento deve simular o crescimento mês a mês, utilizando um vetor auxiliar para armazenar o saldo de cada mês.

Requisitos Mínimos
Definir o struct Investimento com todos os campos especificados.
Utilizar um vetor de Investimento com capacidade para 20 cenários.
Implementar, no mínimo, 6 funções: cadastrar, calcular montante (função matemática isolada), listar, comparar, detalhar e buscar por identificador.
A função de detalhamento deve usar um vetor auxiliar (de reais) para armazenar o saldo mensal.
Validar entradas: aporte positivo, taxa não negativa, meses entre 1 e 360.
A função de cálculo do montante deve ser reutilizável (chamada tanto no cadastro quanto no detalhamento).
