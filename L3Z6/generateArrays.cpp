#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>

#define R_MAX 1000000
#define R_MIN 0

using namespace std;

int main(int argc, char* argv[]) {
  int n;

  if (argc>1) n = atoi(argv[1]);
  else scanf("%d",&n);

  int tab[3][n];
  int all[3*n];

  srand( time( NULL ) );

  for (int i=0;i<3;i++) {
    for (int j=0;j<n;j++) {
      tab[i][j] = rand()%(R_MAX-R_MIN+1)+R_MIN;
      all[i*n+j] = tab[i][j];
    }
  }

  fstream file( "generated.in", ios::out );
  file<<n<<"\n";
  for (int i=0;i<3;i++) {
    sort( tab[i], tab[i] + n );
    for (int j=0;j<n;j++) {
      file<<tab[i][j]<<" ";
    }
    file<<"\n";
  }
  file.close();

  sort(all,all+3*n);
  printf("MEDIANA: %d\n", all[(n*3+1)/2-1]);
  // for (int i=0;i<3*n;i++) {
  //   printf("%d ",all[i]);
  // }

  return 0;
}
