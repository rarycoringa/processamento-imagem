#include <iostream>

#define TAM_MAX 20

using namespace std;

struct Img{
  int largura;
  int altura;
  int matriz[TAM_MAX][TAM_MAX];
};

void inverte(Img img_in, Img &img_out){

  img_out = img_in;

  for(int n = 0; n < img_out.altura; n++){
    for(int m = 0; m < img_out.largura; m++){
      img_out.matriz[n][m] = img_in.matriz[img_in.altura-1-n][m];
    }
  }

}

int main(){
  Img img_in, img_out;

  cin >> img_in.largura >> img_in.altura;

  for(int n = 0; n < img_in.altura; n++){
    for(int m = 0; m < img_in.largura; m++){
      cin >> img_in.matriz[n][m];
    }
  }

  inverte(img_in, img_out);

  cout << img_out.altura << " " << img_out.largura << endl;

  for(int n = 0; n < img_out.altura; n++){
    for(int m = 0; m < img_out.largura; m++){
      cout << img_out.matriz[n][m] << " " << " ";
    }
    cout << endl;
  }

}
