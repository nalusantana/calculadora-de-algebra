# Trabalho Final do 3º Semestre

Este é o trabalho referente às matérias de Álgebra Linear e Algoritmos e Técnicas de Programação II.

Todas as cinco funcionalidades foram planejadas antes de implementar e cada uma delas teve um quadro no trello para organização. 
A manipulação de arquivos (criar, escrever e ler arquivo) é feita por arquivo txt, baseado em link fornecido pelo professor, é possível inserir uma matriz/vetor apenas uma vez e utilizá-la em outras funcionalidades chamando o nome do arquivo criado ao salvar.

Nesse trabalho apenas não foi implementado as funcionalidades de diagonalização e autovetores na dimensão 3.

Caso encontre dificuldade para compilar e executar, utilize o comando em seu terminal:
gcc main.c bibliotecas/isb.c bibliotecas/arquivo.c bibliotecas/auto.c bibliotecas/bases.c bibliotecas/diagonal.c bibliotecas/gauss.c bibliotecas/texto.c -o main.exe && ./main.exe
