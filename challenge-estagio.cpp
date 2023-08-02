#include <iostream>
using namespace std;

const int MAX_ALUNOS = 1000;

int main() {
  int i, indice_melhor, n;
  int turma = 1;
  struct {
    int media;
    string codigo;
  } alunos[MAX_ALUNOS];
  // le numero de alunos da primeira turma
  while ( cin >> n && n > 0) {
      string codigos = "";
      // le dados dos alunos
      for (i = 0; i < n; i++) cin >> alunos[i].codigo >> alunos[i].media;
     // procura aluno de maior media
      indice_melhor = 0;
      for (i = 1; i < n; i++) if (alunos[i].media > alunos[indice_melhor].media) indice_melhor = i;
     // lista notas iguais ao da maior media 
      for (i = 0; i < n; i++) { 
        bool mediasIguais = 
          (alunos[i].media == alunos[indice_melhor].media) && 
          (alunos[i].codigo != alunos[indice_melhor].codigo);
        
        if (mediasIguais) codigos += " " + alunos[i].codigo;
      }
      // escreve resposta
      cout << "Turma " << turma++ << "\n";
      cout << alunos[indice_melhor].codigo + codigos << "\n\n"; 
  }
  return 0;
}