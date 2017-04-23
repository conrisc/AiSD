#include <cstdio>
#include "EasyBMP.h"

using namespace std;

int main () {

  int n,m,cities;

  scanf("%d %d",&n,&m);
  char line[n][m+1];


  for (int i=0;i<n;i++) {
    fgets (line[i], 2, stdin);   //reads new line character
    fgets (line[i], m+1, stdin);
  }

  BMP AnImage;
  const int WIDTH = 10*m+1;
  const int HEIGHT = 10*n+1;
  AnImage.SetSize(WIDTH,HEIGHT);
  AnImage.SetBitDepth(4);

  for (int i=0;i<HEIGHT;i+=10) {
    for (int j=0;j<WIDTH;j++) {
      AnImage(j,i)->Red = 0;
    }
  }

  for (int i=0;i<WIDTH;i+=10) {
    for (int j=0;j<HEIGHT;j++) {
      AnImage(i,j)->Red = 0;
    }
  }

  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      switch(line[i][j]) {
        case 'B':
          for (int k=1;k<10;k++) {
            for (int w=k;w<10;w++) {
              AnImage(j*10+k,i*10+w)->Blue = 0;
              AnImage(j*10+k,i*10+w)->Green = 0;
              AnImage(j*10+k,i*10+w)->Red = 0;
            }
          }
          break;
        case 'C':
          for (int k=1;k<10;k++) {
            for (int w=1;w<10-(k-1);w++) {
              AnImage(j*10+k,i*10+w)->Blue = 0;
              AnImage(j*10+k,i*10+w)->Green = 0;
              AnImage(j*10+k,i*10+w)->Red = 0;
            }
          }
          break;
        case 'D':
          for (int k=1;k<10;k++) {
            for (int w=1;w<k+1;w++) {
              AnImage(j*10+k,i*10+w)->Blue = 0;
              AnImage(j*10+k,i*10+w)->Green = 0;
              AnImage(j*10+k,i*10+w)->Red = 0;
            }
          }
          break;
        case 'Z':
          for (int k=1;k<10;k++) {
            for (int w=1;w<k+1;w++) {
              AnImage(j*10+k,i*10+w)->Blue = 0;
              AnImage(j*10+k,i*10+w)->Green = 0;
            }
          }
          break;
        case 'E':
          for (int k=1;k<10;k++) {
            for (int w=1;w<k+1;w++) {
              AnImage(j*10+k,i*10+(10-w))->Blue = 0;
              AnImage(j*10+k,i*10+(10-w))->Green = 0;
              AnImage(j*10+k,i*10+(10-w))->Red = 0;
            }
          }
          break;
          case 'F':
            for (int k=1;k<10;k++) {
              for (int w=1;w<10;w++) {
                AnImage(j*10+k,i*10+w)->Blue = 0;
                AnImage(j*10+k,i*10+w)->Green = 0;
                AnImage(j*10+k,i*10+w)->Red = 0;
              }
            }
            break;
      }
    }
  }

  AnImage.WriteToFile("Output.bmp");

  return 0;
}
