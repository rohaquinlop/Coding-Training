/*
Carlos Ramirez
Transformada Rapida de Fourier (FTT) - Implementacion iterativa
Mayo 17 de 2020

*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <complex>

using namespace std;

const double PI = acos(-1);
typedef complex<double> cd;

int reverse(int pos, int n){
  int res = 0, i;
  for(i = 0; i < n; ++i)
    if(pos & (1 << i))
      res |= 1 << (n - 1 - i);
  return res;
}

void fft(vector<cd>& a, bool flag){
  int n = a.size(), numBits = 0, i, aux, k, j;
  double exp;
  cd w, auxW;

  while((1 << numBits) < n)
    numBits++;

  for(i = 0; i < n; ++i){
    aux = reverse(i, numBits);
    if(i < aux)
      swap(a[i], a[aux]);
  }

  for(k = 2; k <= n; k <<= 1){
    exp = (flag) ? -2 * PI / k : 2 * PI / k;
    auxW = cd(cos(exp), sin(exp));
    for(i = 0; i < n; i += k){
      w = cd(1);
      for(j = 0; j < k / 2; ++j){
        cd temp = a[i + j];
        a[i + j] = a[i + j] + a [i + j + k / 2] * w;
        a[i + j + k / 2] = temp - a [i + j + k / 2] * w;
        w *= auxW;
      }
    }
  }

  if(flag){
    for(i = 0; i < n; ++i)
      a[i] /= n;
  }
}

void multiplicarPolinomios(vector<cd>& compA, vector<cd>& compB){
  int n = 1;
  
  while(n < compA.size() + compB.size())
    n <<= 1;

  compA.resize(n);
  compB.resize(n);
  fft(compA, false);
  fft(compB, false);
  
  for(int i = 0; i < n; ++i)
    compA[i] *= compB[i];

  fft(compA, true);
}


int main(){
  int i, aux, ac, arr1[] = {4, 3, 6, 5}, arr2[] = {2, 7, 3, 8}, arr3[] = {1, 2, 3, 4};
  vector<cd> pol1(arr1, arr1 + 4), pol2(arr2, arr2 + 4);
  vector<cd> pol3(arr3, arr3 + 4);

  fft(pol3, false);
  multiplicarPolinomios(pol1, pol2);

  for(i = 0; i < pol3.size(); ++i)
    cout << pol3[i] << " ";
  printf("\n");

  //si los elementos de los vectores representan los coeficientes de dos
  //polinomios, entonces el resultado corresponde a los coeficientes del producto
  for(i = 0; i < pol1.size(); ++i)
    printf("%d ", (int) round(pol1[i].real()));
  printf("\n");

  ac = 0;

  //si los elementos representan los digitos de un numero grande
  for(i = 0; i < pol1.size(); ++i){
    aux = round(pol1[i].real());
    aux += ac;
    ac = aux / 10;
    pol1[i] = cd(aux % 10);
  }

  for(i = 0; i < pol1.size(); ++i)
    printf("%d ", (int) round(pol1[i].real()));
  printf("\n");

  /*int i, ac, arr1[] = {0, 1, 0, 1, 0, 1}, arr2[] = {0, 1, 0, 1, 0, 1};
  vector<cd> pol1(arr1, arr1 + 6), pol2(arr2, arr2 + 6);

  multiplicarPolinomios(pol1, pol2);

  for(i = 0; i < pol1.size(); ++i)
    printf("%d ", (int) round(pol1[i].real()));
    printf("\n");*/
  
  return 0;
}
