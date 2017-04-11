#include <cstdio>
#include <list>

using namespace std;


struct Position {
  char sign;
  list<Position*> neighbour;
  int sum;
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
      Position* cur = chessboard[y][x];
      cur->sign = line[x];
      if (line[x]=='.') {
        if (y-1>=0 && x-2>=0 && chessboard[y-1][x-2]->sign=='.') {
          cur -> neighbour.push_back(chessboard[y-1][x-2]);
          chessboard[y-1][x-2] -> neighbour.push_back(cur);
          chessboard[y-2][x+1] -> sum++;
        }
        if (y-2>=0 && x-1>=0 && chessboard[y-2][x-1]->sign=='.') {
          cur -> neighbour.push_back(chessboard[y-2][x-1]);
          chessboard[y-2][x-1] -> neighbour.push_back(cur);
          chessboard[y-2][x+1] -> sum++;
        }
        if (y-2>=0 && x+1<3 && chessboard[y-2][x+1]->sign=='.') {
          cur -> neighbour.push_back(chessboard[y-2][x+1]);
          chessboard[y-2][x+1] -> neighbour.push_back(cur);
          chessboard[y-2][x+1] -> sum++;
        }
        if (y-1>=0 && x+2<3 && chessboard[y-1][x+2]->sign=='.') {
          cur -> neighbour.push_back(chessboard[y-1][x+2]);
          chessboard[y-1][x+2] -> neighbour.push_back(cur);
          chessboard[y-1][x+2] -> sum++;
        }
        cur->sum = cur->neighbour.size();
      }
    }
  }

  //MAIN*******************************************
  // Position *wsk = chessboard[0][0];
  // for (lP::const_iterator i = wsk->neighbour.begin(); i != wsk->neighbour.end() ;i++ ) {
  //   printf("%c",(*i) -> sign);
  // }
  // // printf("\n");

  // bool exists = true;
  // while (exists) {
  //   exists = false;
  //   for (int y=0;y<n;y++) {
  //     for (int x=0;x<3;x++) {
  //       if (chessboard[y][x] -> sign == '.') {
  //
  //       }
  //     }
  //   }
  // }


  //PRINT chessBOARD*******************************
  printf("%d\n",res);
  for (int y=0;y<n;y++) {
    for (int x=0;x<3;x++){
      printf("%c",chessboard[y][x]->sign);
    }
    printf("\n");
  }

  return 0;
}
