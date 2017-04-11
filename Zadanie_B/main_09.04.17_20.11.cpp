#include <cstdio>
#include <list>

using namespace std;


struct Position {
  char sign;
  list<Position*> neighbour;
};

typedef list<Position*> lP;

int main () {


  int n,res=0;
  scanf("%d",&n);
  Position* chessboard[n][3];
  char line[4];

  for (int y=0;y<n;y++) {
    fgets (line, 2, stdin);
    fgets (line, 4, stdin);
    for (int x=0;x<3;x++) {
      chessboard[y][x] = new Position;
      chessboard[y][x]->sign = line[x];
      int i=0;
      if (y-1>=0 && x-2>=0) {
        chessboard[y][x] -> neighbour.push_back(chessboard[y-1][x-2]);
        i++;
        chessboard[y-1][x-2] -> neighbour.push_back(chessboard[y][x]);
      }
      if (y-2>=0 && x-1>=0) {
        chessboard[y][x] -> neighbour.push_back(chessboard[y-2][x-1]);
        i++;
        chessboard[y-2][x-1] -> neighbour.push_back(chessboard[y][x]);
      }
      if (y-2>=0 && x+1<3) {
        chessboard[y][x] -> neighbour.push_back(chessboard[y-2][x+1]);
        i++;
        chessboard[y-2][x+1] -> neighbour.push_back(chessboard[y][x]);
      }
      if (y-1>=0 && x+2<3) {
        chessboard[y][x] -> neighbour.push_back(chessboard[y-1][x+2]);
        chessboard[y-1][x+2] -> neighbour.push_back(chessboard[y][x]);
      }
    }
  }

  //MAIN*******************************************
  Position *wsk = chessboard[0][0];
  for (lP::const_iterator i = wsk->neighbour.begin(); i != wsk->neighbour.end() ;i++ ) {
    printf("%c",(*i) -> sign);
  }
  // printf("\n");



  //PRINT chessBOARD*******************************
  // printf("%d\n",res);
  // for (int y=0;y<n;y++) {
  //   for (int x=0;x<3;x++){
  //     printf("%c",chessboard[y][x]->sign);
  //   }
  //   printf("\n");
  // }

  return 0;
}
