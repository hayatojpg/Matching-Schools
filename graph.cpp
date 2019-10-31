#include "graph.h"

Professor::Professor(int habilitacao, vector<int> escolas)
{
  this->habilitacao = habilitacao;
  this->escolas = escolas;
  this->matched = false;
  this->emparelhado = 999;
  this->proposicoes = 0;
};

Escola::Escola(int escola, vector<int> habilitacaopretendidas)
{
  this->escola = escola;
  this->habilitacaopretendidas = habilitacaopretendidas;
  for (int i = 0; i < habilitacaopretendidas.size(); i++)
  {
    matched.push_back(false);
    //o numero 999 eh um numero absurdo que eh tratado como se a escola nao tivesse vinculado a ninguem
    emparelhado.push_back(999);
  }
};

void PrintProfessores(vector<Professor> professores)
{
  int profsemmatch = 0;
  for (int i = 0; i < professores.size(); i++)
  {
    cout << "Professor Numero: " << i << endl;
    cout << "\t Habilitacao: " << professores[i].habilitacao << endl;
    cout << "\t Escolas Pretendidas: ";
    for (int j = 0; j < professores[i].escolas.size(); j++)
    {
      cout << professores[i].escolas[j] << " ";
    }
    cout << "\t Proposiçoes: " << professores[i].proposicoes << endl;
    if (professores[i].matched)
    {
      cout << "\t Professor esta Empregado em: " << professores[i].emparelhado << endl;
      ;
    }
    else
    {
      profsemmatch++;
    }
    cout << endl;
    cout << endl;
  }
  cout << "Professores sem Match: " << profsemmatch << endl;
  cout << endl;
}

void PrintEscolas(vector<Escola> escolas)
{
  int vagasemmatch = 0;
  for (int i = 1; i < escolas.size(); i++)
  {
    cout << "Escola Numero: " << i << endl;
    cout << "\tHabilitacoes Pretendidas: ";
    for (int j = 0; j < escolas[i].habilitacaopretendidas.size(); j++)
    {
      cout << escolas[i].habilitacaopretendidas[j] << " ";
      // cout << "Vaga esta livre:" << escolas[i].matched[j] << " ";
    }
    cout << endl;
    for (int j = 0; j < escolas[i].emparelhado.size(); j++)
    {
      if (escolas[i].emparelhado[j] == 999)
      {
        cout << "\t\t"
             << "Vaga Nao preenchida" << endl;
        vagasemmatch++;
      }
      else
      {
        cout << "\t\t"
             << "Vaga preenchida por: " << escolas[i].emparelhado[j] << endl;
      }
    }
    cout << endl;
    cout << endl;
  }
  cout << "Vagas Disponiveis: " << vagasemmatch << endl;
  cout << endl;
}

void PrintDisponibilidade(vector<Professor> professores, vector<Escola> escolas)
{
  int um, dois, tres;
  um = 0;
  dois = 0;
  tres = 0;
  for (int i = 0; i < professores.size(); i++)
  {
    if (!professores[i].matched)
    {
      cout << "Professor Numero: " << i << endl;
      cout << "\t Habilitacao: " << professores[i].habilitacao << endl;
      cout << "\t Escolas Pretendidas: ";
      for (int j = 0; j < professores[i].escolas.size(); j++)
      {
        cout << professores[i].escolas[j] << " ";
      }
      cout << "\t Proposiçoes: " << professores[i].proposicoes << endl;
      cout << endl;
    }
    switch (professores[i].habilitacao)
    {
    case 1:
      um++;
      break;
    case 2:
      dois++;
      break;
    case 3:
      tres++;
      break;
    default:
      break;
    }
  }
  cout << um << endl;
  cout << dois << endl;
  cout << tres << endl;
  cout << endl;

  um = 0;
  dois = 0;
  tres = 0;
  for (int i = 1; i < escolas.size(); i++)
  {
    for (int j = 0; j < escolas[i].emparelhado.size(); j++)
    {
      if (escolas[i].emparelhado[j] == 999)
      {
        cout << "Escola Numero: " << i << endl;
        cout << "\t\t"
             << "Vaga Nao preenchida : " << escolas[i].habilitacaopretendidas[j] << endl;
        cout << endl;
      }
    }
    for (int j = 0; j < escolas[i].habilitacaopretendidas.size(); j++)
    {
      switch (escolas[i].habilitacaopretendidas[j])
      {
      case 1:
        um++;
        break;
      case 2:
        dois++;
        break;
      case 3:
        tres++;
        break;
      default:
        break;
      }
    }
  }
  cout << um << endl;
  cout << dois << endl;
  cout << tres << endl;
}

//verifica se as escolas podem ainda ser mexidas
bool VerificaProfessor(vector<Professor> *professores)
{
  int flag = 0;
  for (int i = 0; i < professores->size(); i++)
  {
    if (!(professores->at(i).matched) && (professores->at(i).proposicoes != 50))
    {
      flag++;
    }
  }
  if (flag != 0)
  {
    //se existir alguma escola livre e que nao tenha proposto trabalho para todos os professores, retorne verdadeiro
    return true;
  }
  //caso contrario retorne falso
  return false;
}

//escolhe um professor que ainda esta livro e que nao pediu para trabalhar em todas as escolas
int EscolheProfessor(vector<Professor> *professores)
{
  for (int i = 0; i < professores->size(); i++)
  {
    if (!(professores->at(i).matched) && (professores->at(i).proposicoes != 50))
    {
      return i;
    }
  }
  return 999;
}

//verifica a prioridade das escolas nos professores
int GetNiveldePreferencia(Professor prof, int preferencia)
{
  for (int x = 0; x < prof.escolas.size(); x++)
  {
    if (prof.escolas[x] == preferencia)
    {
      return x;
    }
  }
  return 999;
}
//Funcao para pegar uma escola que esteja com vaga q necessite de determinada habilidade
vector<int> GetEscola(int habilitacao, vector<Escola> *escolas)
{
  vector<int> x;
  for (int i = 0; i < escolas->size(); i++)
  {
    for (int j = 0; j < escolas->at(i).matched.size(); j++)
    {
      if (!escolas->at(i).matched[j] && escolas->at(i).habilitacaopretendidas[j] == habilitacao)
      {
        x.push_back(i);
        x.push_back(j);
        return x;
      }
    }
  }
  x.push_back(999);
  return x;
}

//faz os Emparelhamento
void Emparelhamento(vector<Professor> *professores, vector<Escola> *escolas)
{
  //verifica se tem professores livres ainda
  int i = EscolheProfessor(professores);
  while (VerificaProfessor(professores))
  {
    //escolhe um professore livre e que nao tenha pedido pra todas as escolas
    professores->at(i).proposicoes++;
    // cout << "Professor Atual: " << i << " Proposicoes: " << professores[i].proposicoes << endl;
    for (int j = 0; j < professores->at(i).escolas.size(); j++)
    {
      int escolaAtual = professores->at(i).escolas[j];
      // cout << "\tEscola Atual: " << escolaAtual << endl;
      for (int x = 0; x < escolas->at(escolaAtual).habilitacaopretendidas.size(); x++)
      {
        //se a escola n for escolhida ainda e a escola tiver interesse na habilidade do profesor ele entra nesse if
        if ((escolas->at(escolaAtual).habilitacaopretendidas[x] == professores->at(i).habilitacao) && (professores->at(i).matched == false))
        {
          if (!(escolas->at(escolaAtual).matched[x]))
          {
            professores->at(i).emparelhado = escolaAtual;
            professores->at(i).matched = true;
            escolas->at(escolaAtual).matched[x] = true;
            escolas->at(escolaAtual).emparelhado[x] = i;
            cout << endl;
            cout << "\tMatched 1: " << i << " and " << escolaAtual << endl;
            break;
          }
          //verifica se a escola ja foi escolhida e verifica se a preferencia do match anterior eh maior que a preferencia do professor atual, nesse caso entra nesse if
          else
          {
            if (GetNiveldePreferencia(professores->at(i), escolaAtual) < GetNiveldePreferencia(professores->at(escolas->at(escolaAtual).emparelhado[x]), escolaAtual))
            {
              professores->at(escolas->at(escolaAtual).emparelhado[x]).emparelhado = 999;
              professores->at(escolas->at(escolaAtual).emparelhado[x]).matched = false;
              professores->at(i).emparelhado = escolaAtual;
              professores->at(i).matched = true;
              escolas->at(escolaAtual).emparelhado[x] = i;
              cout << "\tMatched 2: " << i << " and " << escolaAtual << endl;
              break;
            }
          }
        }
      }
      if (professores->at(i).matched)
      {
        break;
      }
    }
    vector<int> x;
    x = GetEscola(professores->at(i).habilitacao, escolas);
    if (x[0] != 999 && !professores->at(i).matched)
    {
      professores->at(i).emparelhado = x[0];
      professores->at(i).matched = true;
      escolas->at(x[0]).emparelhado[x[1]] = i;
      escolas->at(x[0]).matched[x[1]] = true;
      cout << "\tMatched 3: " << i << " and " << x[0] << endl;
    }
    i = EscolheProfessor(professores);
  }
}
