#include "files.h"
#include "graph.h"

int main(void)
{
  vector<Professor> professores;
  vector<Escola> escolas;
  Read("entradaProj3TAG.txt", &professores, &escolas);
  Emparelhamento(&professores, &escolas);
  cout << "-----------------------------------------------------" << endl;
  cout << "\t\tEMPARELHAMENTO:" << endl;
  cout << "-----------------------------------------------------" << endl;
  PrintProfessores(professores);
  PrintEscolas(escolas);
  PrintDisponibilidade(professores, escolas);
  return 0;
}