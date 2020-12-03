#include <iostream>

#define TAM_MAX 20

using namespace std;

struct Img{
  int altura;
  int largura;
  int matriz[TAM_MAX][TAM_MAX];
};

void corta_img(Img img_in, Img &img_out, int li, int ci, int larg, int alt){

  img_out = img_in;
  img_out.altura = alt;
  img_out.largura = larg;

  for(int n = li; n < li+alt; n++){
    for(int m = ci; m < ci+larg; m++){
      img_out.matriz[n-li][m-ci] = img_in.matriz[n][m];
    }
  }

}

int main(){
  Img img_in, img_out;
  int li, ci, larg, alt;

  cin >> li >> ci >> larg >> alt;
  cin >> img_in.altura >> img_in.largura;

  for(int n = 0; n < img_in.altura; n++){
    for(int m = 0; m < img_in.largura; m++){
      cin >> img_in.matriz[n][m];
    }
  }

  corta_img(img_in, img_out, li, ci, larg, alt);

  cout << img_out.altura << " " << img_out.largura << endl;

  for(int n = 0; n < img_out.altura; n++){
    for(int m = 0; m < img_out.largura; m++){
      cout << img_out.matriz[n][m] << " ";
    }
    cout << endl;
  }

}
