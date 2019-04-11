#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

char Menu();
void Reset_Jogo(string velha[3][3]);
void Print_Jogo(string velha[3][3]);
void Jogar(string velha[3][3]);
void Decisao(string velha[3][3], char instrucao);

#endif // FUNCOES_H
