#include <iostream>

#define TAM_MAX 20

using namespace std;

struct Img{
  int altura;
  int largura;
  int matriz[TAM_MAX][TAM_MAX];
};

int somatorio(int r, int h[256]){

  int soma = 0;

  for(int i = 0; i <= r; i++){
    soma += h[i];
  }

  return soma;
}

void equaliza_histograma(Img img_in, Img &img_out){

  int h[256] = {};

  img_out = img_in;

  for(int n = 0; n < img_in.altura; n++){
    for(int m = 0; m < img_in.largura; m++){
      h[img_in.matriz[n][m]]++;
    }
  }

  for(int n = 0; n < img_in.altura; n++){
    for(int m = 0; m < img_in.largura; m++){
      int r = img_in.matriz[n][m];
      int s = somatorio(r, h)*255/(img_in.altura*img_in.largura);
      img_out.matriz[n][m] = s;
    }
  }

}

int main(){
  Img img_in, img_out;

  cin >> img_in.altura >> img_in.largura;

  for(int n = 0; n < img_in.altura; n++){
    for(int m = 0; m < img_in.largura; m++){
      cin >> img_in.matriz[n][m];
    }
  }

  equaliza_histograma(img_in, img_out);

  cout << img_out.altura << " " << img_out.largura << endl;

  for(int n = 0; n < img_out.altura; n++){
    for(int m = 0; m < img_out.largura; m++){
      cout << img_out.matriz[n][m] << " ";
    }
    cout << endl;
  }

}
