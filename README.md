# Processamento de Imagem
CLI de Processamento de Imagem em formato `.pgm` com aplicação de filtros e manipulações, desenvolvido como projeto final da disciplina de Linguagem de Programação, no curso de Ciências e Tecnologia da Universidade Federal do Rio Grande do Norte.

## Sobre o formato .pgm
Arquivos em formato `.pgm` são imagens compostas por pixels que variam na escala de cinza. Matricialmente falando, uma imagem `.pgm` pode ser representada por uma matrix N x M composta por elementos que são números inteiros e podem variar entre 0 e 255. A variação do elemento determina a escala de cinza daquele elemento, que pode também ser denominado de pixel.

### A estrutura de um arquivo .pgm

> imagem.pgm
```
P2
16 8
255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 255
```
No exemplo acima, temos um exemplo de arquivo `.pgm`, onde:
- A primeira linha corresponde ao formato da imagem, onde a string `P2` identifica para o leitor da imagem que esta é, de fato, um arquivo `.pgm`;
- A segunda linha corresponde ao dimensionamento da imagem, onde o `16` corresponde à largura e o `8` corresponde à altura;
- A terceira linha corresponde ao tamanho da variação de cada pixel na escala de cinza, onde `255` representa uma variação entre 0 (preto) e 255 (branco);
- A quarta linha em diante corresponde à matriz que representa os pixels da imagem, em escala de cinza, onde temos nesse exemplo um retângulo que varia em degradê de preto para branco.

## Funcionalidades
Neste software, foram desenvolvidas funções que processam apenas imagens em formato `.pgm`, aplicando determinados efeitos e salvando uma nova imagem processada.

### As funcionalidades disponíveis

1. Binarização de Imagem
2. Corte de Imagem
3. Dilatação de Imagem
4. Equalização de Imagem
5. Inversão de Imagem
6. Solarização de Imagem
