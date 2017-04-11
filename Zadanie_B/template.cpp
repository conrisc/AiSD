#include <cstdio>
#include <list>

using namespace std;


int main () {

  int n,res=0;
  scanf("%d",&n);
  char chessboard[n][4];

  for (int y=0;y<n;y++) {
    fgets (chessboard[y], 2, stdin);
    fgets (chessboard[y], 4, stdin);
  }

  //MAIN*******************************************



  //PRINT chessBOARD*******************************
  printf("%d\n",res);
  for (int y=0;y<n;y++) {
    for (int x=0;x<3;x++){
      printf("%c",chessboard[y][x]);
    }
    printf("\n");
  }

  return 0;
}
