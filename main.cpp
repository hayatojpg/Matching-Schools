#include "files.h"
#include "graph.h"

int main(void)
{
  vector<Professor *> professores;
  vector<Escola *> escolas;
  Read("entradaProj3TAG.txt", professores, escolas);
  Emparelhamento(professores, escolas);
  //PrintDisponibilidade(professores, escolas);
  PrintProfessores(professores);
  PrintEscolas(escolas);
  return 0;
}