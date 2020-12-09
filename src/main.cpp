#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

#define TAM_MAX 512

using namespace std;

struct Img{
  char formato[TAM_MAX];
  int largura;
  int altura;
  int limite_pixel;
  int pixel[TAM_MAX][TAM_MAX];
};

// Funções de configuração do programa
void inicia_programa(){
  cout << endl;
  cout << "|||||||||| SOFTWARE DE PROCESSAMENTO DE IMAGENS ||||||||||" << endl;
}

void executa_menu(int &indice){
  cout << endl;
  cout << "========== MENU ==========" << endl;
  cout << "1 - Binarização de Imagem" << endl;
  cout << "2 - Corte de Imagem" << endl;
  cout << "3 - Dilatação de Imagem" << endl;
  cout << "4 - Equalização de Imagem" << endl;
  cout << "5 - Inversão de Imagem" << endl;
  cout << "6 - Solarização de Imagem" << endl;
  cout << "0 - Encerrar" << endl;
  cout << endl;
  cout << "Insira o número do processamento desejado: ";
  cin >> indice;
}

void encerra_programa(){
  cout << endl;
  cout << "Programa encerrado. Obrigado!" << endl;
}

void assinatura(){

  cout << endl;
  cout << "==================================================" << endl;
  cout << "Projeto" << endl;
  cout << "  Processamento de Imagens com C++" << endl;
  cout << "  Projeto Final | Última Etapa | Terceira Unidade" << endl;
  cout << endl;
  cout << "Versão" << endl;
  cout << "  v1.0.0" << endl;
  cout << "  stable" << endl;
  cout << endl;
  cout << "Desenvolvimento" << endl;
  cout << "  Rary Gonçalves" << endl;
  cout << "  Matrícula: 20190070530" << endl;
  cout << "  rarygoncalves@ufrn.edu.br" << endl;
  cout << "  https://github.com/rarygc/lip-proj/" << endl;
  cout << endl;
  cout << "Disciplina" << endl;
  cout << "  Linguagem de Programação - Turma 3D" << endl;
  cout << "  Prof. Bruno S. | Prof. Carlos O. | Prof. Yuri N." << endl;
  cout << "  Bacharelado em Ciências e Tecnologia (C&T/ECT)" << endl;
  cout << "  Universidade Federal do Rio Grande do Norte" << endl;
  cout << "==================================================" << endl;
}

// Funções de gerenciamento de imagens
void abre_img(char nome[], Img &img){
  fstream arq;

  arq.open(string("../img/") + nome);

  if(!arq.is_open()){
    cout << endl;
    cout << "Erro: Arquivo não encontrado!" << endl;
    // exit(0);
  }else{
    arq >> img.formato;

    if(img.formato != string("P2")){
      cout << endl;
      cout << "Erro: Tipo de imagem não suportado!" << endl;
    }else{
      arq >> img.largura >> img.altura >> img.limite_pixel;

      for(int n = 0; n < img.altura; n++){
        for(int m = 0; m < img.largura; m++){
          arq >> img.pixel[n][m];
        }
      }
    }

    arq.close();
  }
}

void salva_img(char nome[], Img img){
  ofstream arq;

  arq.open(string("../img_out/") + nome);

  if(!arq.is_open()){
    cout << endl;
    cout << "Erro: Permissão negada ou falta de espaço em disco!" << endl;
  }else{
    arq << img.formato << endl;
    arq << img.largura << " " << img.altura << endl;
    arq << img.limite_pixel << endl;

    for(int n = 0; n < img.altura; n++){
      for(int m = 0; m < img.largura; m++){
        arq << img.pixel[n][m] << " ";
      }
      arq << endl;
    }
  }

  arq.close();

  cout << endl;
  cout << "Imagem processada e salva com sucesso!" << endl;
}

// Funções de processamento de imagens
void binariza_img(Img &img){
  int limiar;

  cout << endl;
  cout << "Informe o limiar desejado: ";
  cin >> limiar;

  for(int n = 0; n < img.altura; n++){
    for(int m = 0; m < img.largura; m++){

      if(img.pixel[n][m] < limiar){
        img.pixel[n][m] = 0;
      }else{
        img.pixel[n][m] = 255;
      }

    }
  }
}

void corta_img(Img &img){
  int m_inicial, n_inicial, largura, altura;

  cout << endl;
  cout << "A imagem possui " << img.largura << "px X " << img.altura << "px" << endl;
  cout << "Informe a largura inicial do recorte: ";
  cin >> m_inicial;
  cout << "Informe a altura inicial do recorte: ";
  cin >> n_inicial;
  cout << "Informe a largura desejada da imagem final: ";
  cin >> largura;
  cout << "Informe a altura desejada da imagem final: ";
  cin >> altura;

  for(int n = n_inicial; n < n_inicial+altura; n++){
    for(int m = m_inicial; m < m_inicial+largura; m++){
      img.pixel[n-n_inicial][m-m_inicial] = img.pixel[n][m];
    }
  }

  img.altura = altura;
  img.largura = largura;

}

void dilata_img(Img &img){

  for(int n = 0; n < img.altura - 1; n++){
    for(int m = 0; m < img.largura - 1; m++){

      if(img.pixel[n][m] == 255 || img.pixel[n][m+1] == 255 || img.pixel[n+1][m] == 255 || img.pixel[n+1][m+1] == 255){
        img.pixel[n][m] = 255;
      }else{
        img.pixel[n][m] = 0;
      }

    }
  }
}

int equaliza_somatorio(int r, int h[256]){
  int soma = 0;

  for(int i = 0; i <= r; i++){
    soma += h[i];
  }

  return soma;
}

void equaliza_img(Img &img){
  int h[256] = {};

  for(int n = 0; n < img.altura; n++){
    for(int m = 0; m < img.largura; m++){
      h[img.pixel[n][m]]++;
    }
  }

  for(int n = 0; n < img.altura; n++){
    for(int m = 0; m < img.largura; m++){
      int r = img.pixel[n][m];
      int s = equaliza_somatorio(r, h)*255/(img.altura*img.largura);
      img.pixel[n][m] = s;
    }
  }
}

void inverte_img(Img &img){
  Img img_original = img;

  for(int n = 0; n < img.altura; n++){
    for(int m = 0; m < img.largura; m++){
      img.pixel[n][m] = img_original.pixel[img_original.altura-1-n][m];
    }
  }
}

// void solariza_img(Img &img);

// Programa principal
int main(){

  int indice = 0;
  Img img;
  char nome[TAM_MAX];

  inicia_programa();

  do{

    executa_menu(indice);

    if(indice < 0 || indice > 6){
      cout << endl;
      cout << "Por favor, escolha uma opção válida!" << endl;
    }else if(indice != 0){
      cout << endl;
      cout << "Insira o nome da imagem a ser processada: ";
      cin.ignore();
      cin.getline(nome, TAM_MAX);

      abre_img(nome, img);

      // cout << nome << " " << img.formato << " " << img.largura << " " << img.altura << " " << img.limite_pixel << endl;

      // for(int i = 0; i < 5; i++){
      //   for (int j = 0; j < 5; j++){
      //     cout << img.pixel[i][j] << " ";
      //   }
      //   cout << endl;
      // }

      if(indice == 1){
        binariza_img(img);
      }else if(indice == 2){
        corta_img(img);
      }
      else if(indice == 3){
        binariza_img(img);
        dilata_img(img);
      }else if(indice == 4){
        equaliza_img(img);
      }else if(indice == 5){
        inverte_img(img);
      }
      // }else if(indice == 6){
      //
      // }

      cout << endl;
      cout << "Insira o nome da nova imagem processada: ";
      cin.ignore();
      cin.getline(nome, TAM_MAX);

      salva_img(nome, img);
    }

  }while(indice != 0);

  encerra_programa();

  assinatura();

  return 0;
}
