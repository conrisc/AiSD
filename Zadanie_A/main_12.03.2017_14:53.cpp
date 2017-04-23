#include <cstdio>
#include <vector>

using namespace std;

int main () {

  int n,m,cities = 0,id=1;
  bool isNew,isVisited;
  vector <int> ids;
  scanf("%d %d",&n,&m);
  char line[m+1];
  int *pointer[m];
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
          pointer[j] = NULL;
          break;
        case 'B':
          if (isNew) {
            cities++;
            ids.push_back(id);
            id++;
            pointer[j] = &ids.back();
          }
          else {
            pointer[j] = pointer[j-1];
          }
          isNew = true;
          isVisited = false;
          break;
        case 'C':
          if (isNew && pointer[j]==NULL) {
            cities++;
          }
          else if (!isNew && pointer[j]!=NULL && pointer[j-1]!=NULL && *pointer[j-1] != *pointer[j]) {
            cities--;
            *pointer[j] = *pointer[j-1];
          }
          isNew = true;
          isVisited = false;
          pointer[j] = NULL;
          break;
        case 'D':
          if (pointer[j]==NULL) {
            cities++;
            ids.push_back(id);
            id++;
            pointer[j] = &ids.back();
            isVisited = false;
          }
          else {
            isVisited = true;
          }
          isNew = false;
          break;
        case 'E':
          cities++;
          ids.push_back(id);
          id++;
          pointer[j] = &ids.back();
          isNew = false;
          isVisited = false;
          break;
        case 'F':
          if(isNew && pointer[j]==NULL) {
            cities++;
            ids.push_back(id);
            pointer[j] = &ids.back();
            id++;
          }
          else if (!isNew && pointer[j]!=NULL && pointer[j-1]!=NULL && *pointer[j-1] != *pointer[j]) {
            cities--;
            // int a = *pointer[j-1];
            *pointer[j] = 5;
            isVisited = true;
          }
          else if (pointer[j]!=NULL) {
            isVisited = true;
          }
          else {
            pointer[j] = pointer[j-1];
          }
          isNew = false;
          break;
      }
    }

    for (int j=0;j<m;j++) {
      if (line[j]=='D') pointer[j]=NULL;
    }

  }

  printf("%d\n",cities);

  return 0;
}
