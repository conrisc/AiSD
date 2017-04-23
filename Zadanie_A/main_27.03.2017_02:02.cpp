#include <cstdio>

using namespace std;

int main () {

  int n,m,cities = 0,id=0;
  bool isNew;
  int ids[4000000];
  scanf("%d %d",&n,&m);
  char line[m+1];
  int *pointer[m];
  for (int i=0;i<m;i++) pointer[i] = NULL;
  for (int i=0;i<n;i++) {
    fgets (line, 2, stdin);   //reads new line character
    fgets (line, m+1, stdin);

    isNew = true;
    for (int j=0;j<m;j++) {
      switch(line[j]) {
        case 'A':
          isNew = true;
          pointer[j] = NULL;
          break;
        case 'B':
          if (isNew) {
            cities++;
            ids[id] = id;
            pointer[j] = &ids[id];
            id++;
          }
          else {
            pointer[j] = pointer[j-1];
          }
          isNew = true;
          break;
        case 'C':
          if (isNew && pointer[j]==NULL) {
            cities++;
          }
          else if (!isNew && pointer[j]!=NULL && *pointer[j-1] != *pointer[j]) {
            cities--;
            *pointer[j] = *pointer[j-1];
          }
          isNew = true;
          pointer[j] = NULL;
          break;
        case 'D':
          if (pointer[j]==NULL) {
            cities++;
            ids[id] = id;
            pointer[j] = &ids[id];
            id++;
          }
          isNew = false;
          break;
        case 'E':
          cities++;
          ids[id] = id;
          pointer[j] = &ids[id];
          id++;
          isNew = false;
          break;
        case 'F':
          if(isNew && pointer[j]==NULL) {
            cities++;
            ids[id] = id;
            pointer[j] = &ids[id];
            id++;
          }
          else if (!isNew && pointer[j]!=NULL && *pointer[j-1] != *pointer[j]) {
            cities--;
            *pointer[j] = *pointer[j-1];
            pointer[j] = pointer[j-1];
          }
          else if (pointer[j]==NULL){
            pointer[j] = pointer[j-1];
          }
          else if (!isNew) {
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
