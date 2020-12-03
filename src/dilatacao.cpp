#include <iostream>

#define TAM_MAX 20

using namespace std;

struct Img{
  int altura;
  int largura;
  int matriz[TAM_MAX][TAM_MAX];
};

void binariza(Img img_in, Img &img_bin, int limiar){

  img_bin = img_in;

  for(int n = 0; n < img_bin.altura; n++){
    for(int m = 0; m < img_bin.largura; m++){

      if(img_in.matriz[n][m] < limiar){
        img_bin.matriz[n][m] = 0;
      }else{
        img_bin.matriz[n][m] = 255;
      }

    }
  }

}

void dilata(Img img_in, Img &img_out){

  Img img_bin;

  binariza(img_in, img_bin, 127);

  img_out = img_bin;

  for(int n = 0; n < img_out.altura - 1; n++){
    for(int m = 0; m < img_out.largura - 1; m++){

      if(img_bin.matriz[n][m] == 255 || img_bin.matriz[n][m+1] == 255 || img_bin.matriz[n+1][m] == 255 || img_bin.matriz[n+1][m+1] == 255){
        img_out.matriz[n][m] = 255;
      }else{
        img_out.matriz[n][m] = 0;
      }

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

  dilata(img_in, img_out);

  cout << img_out.altura << " " << img_out.largura << endl;

  for(int n = 0; n < img_out.altura; n++){
    for(int m = 0; m < img_out.largura; m++){
      cout << img_out.matriz[n][m] << " ";
    }
    cout << endl;
  }

}
