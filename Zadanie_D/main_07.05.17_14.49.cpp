#include <cstdio>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <bitset>

#define MAX_N 500000

using namespace std;

struct Vertex {
  list <int> neighbours;
  string name;
};

struct Level {
  list <int> v;
};

struct helpV {
  int id;
  string name;
};

// bool comparator (helpV a, helpV b) {
//   if (a.name < b.name) return true;
//   return false;
// }

bool operator<(helpV a, helpV b) {
  if (a.name < b.name) return true;
  return false;
}

bool operator==(helpV a, helpV b) {
  if (a.name == b.name) return true;
  return false;
}

int findHeight(Vertex (*T)[2][MAX_N],int t, int v,int level) {
  (*T)[t][v].name = to_string(level);
  if ((*T)[t][v].neighbours.empty()) return 1;
  int max_h = 0,h;
  for( list<int>::const_iterator it = (*T)[t][v].neighbours.begin(); it != (*T)[t][v].neighbours.end(); it++ ) {
    h = findHeight(T,t,*it,level+1);
    if (max_h<h) max_h=h;
  }
  return max_h + 1;
}

void create_name(Vertex (*T)[2][MAX_N],int t, int v) {
  if((*T)[t][v].neighbours.empty()) (*T)[t][v].name = "10";
  else {
    vector <string> names;
    for(list<int>::const_iterator it = (*T)[t][v].neighbours.begin(); it != (*T)[t][v].neighbours.end(); it++ ) {
      names.push_back((*T)[t][*it].name);
    }
    sort(names.begin(),names.end());
    (*T)[t][v].name = "1";
    for (size_t i=0;i<names.size();i++) {
      (*T)[t][v].name += names[i];
    }
    (*T)[t][v].name += "0";
  }
}

int main() {

  int d,n,a,b,height;

  scanf("%d",&d);
  for (int z=0;z<d;z++) {
    //SCANF****************************************
    scanf("%d",&n);
    Vertex T[2][MAX_N];
    for (int j=0;j<2;j++) {
      for (int i=0;i<n-1;i++) {
        scanf("%d %d",&a,&b); a=a-1; b=b-1;
        if (a<b) T[j][a].neighbours.push_back(b);
        else T[j][b].neighbours.push_back(a);
      }
    }
    //CREATE_LEVELS_TABLE**************************
    height = findHeight(&T,0,0,0);
    if (findHeight(&T,1,0,0)!=height) {
      printf("NIE\n");
      continue;
    }
    Level levelofT[2][height];
    for (int j=0;j<2;j++) {
      for (int i=0;i<n;i++) {
        int temp_l = stoi(T[j][i].name);
        levelofT[j][temp_l].v.push_back(i);
      }
    }
    //MAIN*****************************************
    bool yup = true;
    for (int lvl=height-1;lvl>=0 && yup;lvl--) {
      //create_names
      for (int j=0;j<2;j++) {
        for(list<int>::const_iterator it = levelofT[j][lvl].v.begin(); it != levelofT[j][lvl].v.end(); it++ )
          create_name(&T,j,*it);
      }
      //sort_names
      vector <helpV> names[2];
      for (int j=0;j<2;j++) {
        for(list<int>::const_iterator it = levelofT[j][lvl].v.begin(); it != levelofT[j][lvl].v.end(); it++ ) {
          helpV temp; temp.id = *it; temp.name = T[j][*it].name;
          names[j].push_back(temp);
        }
        sort(names[j].begin(),names[j].end());
      }
      //compare
      if (names[0].size()!=names[1].size()) yup = false;
      else {
        for (size_t i=0;i<names[0].size() && yup;i++) {
          if (names[0][i].name!=names[1][i].name) yup = false;
        }
      }
      //simplify_names
      for (int j=0;j<2 && yup;j++) {
        int is = 1;
        for (size_t i=0;i<names[j].size() && yup;i++) {
          names[j][i].name = bitset<32>(is).to_string();
          is++;
          T[j][names[j][i].id].name = names[j][i].name;
        }
      }
    }

    if (yup) printf("TAK\n");
    else printf("NIE\n");
    //PRINTF***************************************
    // for (int j=0;j<2;j++) {
    //   printf("Tree %d:\n",j+1);
    //   for (int i=0;i<n;i++) {
    //     printf(" %d:",i+1);
    //     for( list<int>::const_iterator it = T[j][i].neighbours.begin(); it != T[j][i].neighbours.end(); it++ )
    //        printf( " %d", *it+1 );
    //     printf("\n");
    //   }
    // }

    // for (int j=0;j<2;j++) {
    //   printf("Tree %d:\n",j+1);
    //   for (int i=0;i<height;i++) {
    //     printf(" %d:",i+1);
    //     for( list<int>::const_iterator it = levelofT[j][i].v.begin(); it != levelofT[j][i].v.end(); it++ )
    //       printf( " %d", *it+1 );
    //     printf("\n");
    //   }
    // }
    //*********************************************
  }
  return 0;
}
