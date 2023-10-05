#include <iostream>
#include <list>
using namespace std;

struct Position {
  int x;
  int y; 
};

bool boundsCheck (int x, int y, int logoX, int logoY, int videoX, int videoY) {
  return (x + (logoX-1) >= 0 && x + (logoX-1) < videoX ) && (y + (logoY-1) >= 0 && y + (logoY-1) < videoY);
};

bool isThereALogo (int** arrLogo, int logoRow, int logoCol, int** arrVideo, int videoRow, int videoCol, int posX, int posY );

int main() {
  Position pos; // struct para salvar as possiveis primeiras ocorrencias dos logos na matriz de videos;
  // int** logo;
  // int** video;
  int test = 0;
  int logoX, logoY, qtyLogo;
  int videoX, videoY, qtyVideos;
  while ( cin >> logoX >> logoY && logoX && logoY ) {
    //input logo
    qtyLogo = 0;
    //logo = new int*[logoX];
    int logo[logoX][logoY] = {};
    //for (int i = 0; i < logoX; i++) logo[i] = new int[logoY]; 
    for (int x = 0; x < logoX; x++) for (int y = 0; y < logoY; y++) cin >> logo[x][y];
    
    //receber dimensoes e qtd de videos;
    //alocamento de memoria para matriz de video;
    cin >> qtyVideos >> videoX >> videoY;
    while (qtyVideos--) {
      // lista de possiveis posiçoes das logos;
      list<Position> positions;
      int video[videoX][videoY] = {};
      //video = new int*[videoX];
      //for (int i = 0; i < videoX; i++) video[i] = new int[videoY]; 

      //input do video;
      for (int x = 0; x < videoX; x++) for (int y = 0; y < videoY; y++) { 
          cin >> video[x][y];
          if (video[x][y] != logo[0][0]) continue;
          pos.x = x, pos.y = y;
          positions.push_back(pos);

      };

      while (!positions.empty()) {
        pos = positions.front();
        if (boundsCheck(pos.x, pos.y, logoX, logoY, videoX, videoY)) {
          bool isThereALogo = true;
          //if (isThereALogo(logo, logoX, logoY, video, videoX, videoY, pos.x, pos.y)) qtyLogo += 1; 
          for (int x = 0; x < logoX; x++ ) for (int y = 0; y < logoY; y++) {
            if (video[pos.x + x][pos.y + y] != logo[x][y]) {
              isThereALogo = false;
              break;
            };
          };
          if (isThereALogo) qtyLogo += 1;
        };
        positions.pop_front();

      };
    };
    test += 1;
    cout << "Logotipo " << test << endl;
    cout << qtyLogo << endl << endl;
  };

  return 0;
}

// bool isThereALogo (int** arrLogo, int logoRow, int logoCol, int** arrVideo, int videoRow, int videoCol, int posX, int posY ) {
//   for (int i = 0; i < logoRow; i++) {
//     for (int j = i; j < logoCol; j++) {
//       // row != row || col != col; 
//       if (arrVideo[posX + i][posY + j] != arrLogo[i][j]) return false;
//     };
//   };
//   return true;
// };

/*
      cout << "iteirando colunas" << endl;
      cout << "videoX: " << posX + i << " videoY: " << posY + k << endl;
      cout << "logoX: " << i << " logoY: " << k << endl;
      cout << "iteirando linhas" << endl;
      cout << "videoX: " << posX + k << " videoY: " << posY + i << endl;
      cout << "logoX: " << j << " logoY: " << i << endl;

*/