#include <cstdio>
#include <vector>

using namespace std;

int main () {

  int n,m,cities = 0,id=1;
  bool isNew,isVisited;
  vector <int> ids;
  scanf("%d %d",&n,&m);
  char line[m+1];
  bool visited[m];
  for (int i=0;i<m;i++) visited[i] = false;
  for (int i=0;i<m;i++) pointer[i] = NULL;


  for (int i=0;i<n;i++) {
    fgets (line, 2, stdin);   //reads new line character
    fgets (line, m+1, stdin);

    isNew = true;
    isVisited = false;
    for (int j=0;j<m;j++) {
      switch(line[j]) {
        case 'A':
          isNew = true;
          isVisited = false;
          visited[j] = false;
          break;
        case 'B':
          if (isNew) cities++;
          isNew = true;
          isVisited = false;
          visited[j] = true;
          break;
        case 'C':
          if (isNew && !visited[j]) cities++;
          else if (!isNew && visited[j] && !isVisited) cities--;
          isNew = true;
          isVisited = false;
          visited[j] = false;
          break;
        case 'D':
          if (!visited[j]) {
            cities++;
            isVisited = false;
          }
          else isVisited = true;
          isNew = false;
          visited[j] = false;
          break;
        case 'E':
          cities++;
          isNew = false;
          isVisited = false;
          visited[j] = true;
          break;
        case 'F':
          if(isNew && !visited[j]) cities++;
          else if (!isNew && visited[j] && !isVisited) cities--;
          isNew = false;
          if (visited[j]) isVisited = true;
          visited[j] = true;
          break;
      }
    }

  }

  printf("%d\n",cities);

  return 0;
}
