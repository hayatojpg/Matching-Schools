#ifndef FILES_H
#define FILES_H

#include <bits/stdc++.h>
#include <cstdlib>
#include "graph.h"

using namespace std;

bool IsNumber(char number);
string ParseParenthesis(string checkline, vector<int> &intnumbers);
void Read(string file, vector<Professor> *professores, vector<Escola> *escolas);

#endif