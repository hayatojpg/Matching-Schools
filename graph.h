#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

class Professor
{
public:
  int habilitacao;
  vector<int> escolas;
  //Verifica se o professor ainda esta livro ou nao
  bool matched;
  //referente a qual escola o professor vai trabalhar
  int emparelhado;
  //proposicoes indica quantas escolas os professores ja aplicaram
  int proposicoes;
  Professor(int habilitacao, vector<int> escolas);
};

class Escola
{
public:
  int escola;
  vector<int> habilitacaopretendidas;
  //referente se ja foi emparelhado ou nao
  vector<bool> matched;
  //referente a qual professor foi emparelhado com essa escola
  vector<int> emparelhado;
  Escola(int escola, vector<int> habilitacaopretendidas);
};

void PrintProfessores(vector<Professor *> professores);
void PrintEscolas(vector<Escola *> escolas);
void PrintDisponibilidade(vector<Professor *> professores, vector<Escola *> escolas);
bool VerificaProfessor(vector<Professor *> professores);
int EscolheProfessor(vector<Professor *> professores);
int GetNiveldePreferencia(Professor prof, int preferencia);
vector<int> GetEscola(int habilitacao, vector<Escola *> escolas);
void Emparelhamento(vector<Professor *> professores, vector<Escola *> escolas);

#endif