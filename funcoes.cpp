#include "funcoes.h"

int contador = 0;
int randomic = 0;
bool start;
char instrucao;

char Menu()
{
    string numero[9];

    numero[0] = "  1  ";
    numero[1] = "  2  ";
    numero[2] = "  3  ";
    numero[3] = "  4  ";
    numero[4] = "  5  ";
    numero[5] = "  6  ";
    numero[6] = "  7  ";
    numero[7] = "  8  ";
    numero[8] = "  9  ";

    system("cls");
    cout << "                                                  JOGO DA VELHA\n\n\n\n\n";
    cout << "                  - MENU -\n\n- Para iniciar um novo jogo aperte J\n- Para sair, a qualquer momento aperte S\n\n\n";
    cout << "              * COMO JOGAR *\n\n";
    cout << "- Use o teclado numerico (1 a 9) para jogar, de acordo com o tabuleiro a seguir!\n\n\n";

    for(int i=0 ; i<3 ; i++)
    {
        if(i == 0)
        {
            cout << "                                                  " << "     |     |     " << "\n";
            cout << "                                                  " << numero[0] << "|" << numero[1] << "|" << numero[2] << "\n";
            cout << "                                                  " << "_____|_____|_____" << "\n";
        }
        else if(i == 1)
        {
            cout << "                                                  " << "     |     |     " << "\n";
            cout << "                                                  " << numero[3] << "|" << numero[4] << "|" << numero[5] << "\n";
            cout << "                                                  " << "_____|_____|_____" << "\n";
        }
        else
        {
            cout << "                                                  " << "     |     |     " << "\n";
            cout << "                                                  " << numero[6] << "|" << numero[7] << "|" << numero[8] << "\n";
            cout << "                                                  " << "     |     |     " << "\n";
        }
    }

    instrucao = getch();

    return instrucao;
}

void Reset_Jogo(string velha[3][3])
{
    for(int r=0 ; r<3 ; r++)
    {
        for(int c=0 ; c<3 ; c++)
            velha[r][c] = "     ";
    }
}

void Print_Jogo(string velha[3][3])
{
    cout << "\n\n\n\n\n";
    for(int r=0 ; r<3 ; r++)
    {
        if(r < 2)
        {
            cout << "                                                  " << "     |     |     " << "\n";
            cout << "                                                  " << velha[r][0] << "|" << velha[r][1] << "|" << velha[r][2] << "\n";
            cout << "                                                  " << "_____|_____|_____" << "\n";
        }
        else
        {
            cout << "                                                  " << "     |     |     " << "\n";
            cout << "                                                  " << velha[r][0] << "|" << velha[r][1] << "|" << velha[r][2] << "\n";
            cout << "                                                  " << "     |     |     " << "\n";
        }
    }
}

void Jogar(string velha[3][3])
{
    if(start == 0)
        Sleep(1200);
    system("cls");
    char posicao;
    string simbolos[2];
    simbolos[0] = "  X  ";
    simbolos[1] = "  O  ";
    bool jogada = 1;

    Print_Jogo(velha);

    for(int r=0 ; r<3 ; r++)
    {
        if(velha[r][0] == simbolos[0] && velha[r][1] == simbolos[0] && velha[r][2] == simbolos[0])
        {
            cout << "\n\n\nVITORIA PLAYER!\n";
            system("pause");
            return;
        }
        if(velha[r][0] == simbolos[1] && velha[r][1] == simbolos[1] && velha[r][2] == simbolos[1])
        {
            cout << "\n\n\nVITORIA I.A.!\n";
            system("pause");
            return;
        }
    }
    for(int c=0 ; c<3 ; c++)
    {
        if(velha[0][c] == simbolos[0] && velha[1][c] == simbolos[0] && velha[2][c] == simbolos[0])
        {
            cout << "\n\n\nVITORIA PLAYER!\n";
            system("pause");
            return;
        }
        if(velha[0][c] == simbolos[1] && velha[1][c] == simbolos[1] && velha[2][c] == simbolos[1])
        {
            cout << "\n\n\nVITORIA I.A.!\n";
            system("pause");
            return;
        }
    }
    if(velha[0][0] == simbolos[0] && velha[1][1] == simbolos[0] && velha[2][2] == simbolos[0])
    {
        cout << "\n\n\nVITORIA PLAYER!\n";
        system("pause");
        return;
    }
    if(velha[0][0] == simbolos[1] && velha[1][1] == simbolos[1] && velha[2][2] == simbolos[1])
    {
        cout << "\n\n\nVITORIA I.A.!\n";
        system("pause");
        return;
    }
    if(velha[0][2] == simbolos[0] && velha[1][1] == simbolos[0] && velha[2][0] == simbolos[0])
    {
        cout << "\n\n\nVITORIA PLAYER!\n";
        system("pause");
        return;
    }
    if(velha[0][2] == simbolos[1] && velha[1][1] == simbolos[1] && velha[2][0] == simbolos[1])
    {
        cout << "\n\n\nVITORIA I.A.!\n";
        system("pause");
        return;
    }

    if(contador == 9)
    {
        cout << "\n\n\nVELHA (EMPATE) !\n";
        system("pause");
        return;
    }

    if(start == 0)
    {
        cout << "\n\n\nDigite a posicao que deseja marcar: ";
        posicao = getch();

        if(posicao == '1')
        {
            if((velha[0][0] != simbolos[0]) && (velha[0][0] != simbolos[1]))
            {
                velha[0][0] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '2')
        {
            if((velha[0][1] != simbolos[0]) && (velha[0][1] != simbolos[1]))
            {
                velha[0][1] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '3')
        {
            if((velha[0][2] != simbolos[0]) && (velha[0][2] != simbolos[1]))
            {
                velha[0][2] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '4')
        {
            if((velha[1][0] != simbolos[0]) && (velha[1][0] != simbolos[1]))
            {
                velha[1][0] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '5')
        {
            if((velha[1][1] != simbolos[0]) && (velha[1][1] != simbolos[1]))
            {
                velha[1][1] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '6')
        {
            if((velha[1][2] != simbolos[0]) && (velha[1][2] != simbolos[1]))
            {
                velha[1][2] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '7')
        {
            if((velha[2][0] != simbolos[0]) && (velha[2][0] != simbolos[1]))
            {
                velha[2][0] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '8')
        {
            if((velha[2][1] != simbolos[0]) && (velha[2][1] != simbolos[1]))
            {
                velha[2][1] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == '9')
        {
            if((velha[2][2] != simbolos[0]) && (velha[2][2] != simbolos[1]))
            {
                velha[2][2] = simbolos[0];
                start = 1;
            }
            else
                contador --;
        }
        else if(posicao == 's')
            exit(0);
        else
            contador --;
    }
    else   ///IMPLEMENTACAO DA I.A.
    {
        for(int r=0 ; r<3 ; r++)   ///prioridade numero 1 = ganhar
        {
            if((velha[r][0] == simbolos[1] && velha[r][1] == simbolos[1] && jogada == 1) && velha[r][2] == "     ")
            {
                velha[r][2] = simbolos[1];
                jogada = 0;
            }
            if((velha[r][0] == simbolos[1] && velha[r][2] == simbolos[1] && jogada == 1) && velha[r][1] == "     ")
            {
                velha[r][1] = simbolos[1];
                jogada = 0;
            }
            if((velha[r][1] == simbolos[1] && velha[r][2] == simbolos[1] && jogada == 1) && velha[r][0] == "     ")
            {
                velha[r][0] = simbolos[1];
                jogada = 0;
            }
        }
        for(int c=0 ; c<3 ; c++)   ///prioridade numero 1 = ganhar
        {
            if((velha[0][c] == simbolos[1] && velha[1][c] == simbolos[1] && jogada == 1) && velha[2][c] == "     ")
            {
                velha[2][c] = simbolos[1];
                jogada = 0;
            }
            if((velha[0][c] == simbolos[1] && velha[2][c] == simbolos[1] && jogada == 1) && velha[1][c] == "     ")
            {
                velha[1][c] = simbolos[1];
                jogada = 0;
            }
            if((velha[1][c] == simbolos[1] && velha[2][c] == simbolos[1] && jogada == 1) && velha[0][c] == "     ")
            {
                velha[0][c] = simbolos[1];
                jogada = 0;
            }
        }
        if(velha[0][0] == simbolos[1] && velha[1][1] == simbolos[1] && jogada == 1 && velha[2][2] == "     ")   ///prioridade numero 1 = ganhar (diagonais)
        {
            velha[2][2] = simbolos[1];
            jogada = 0;
        }
        if(velha[2][2] == simbolos[1] && velha[1][1] == simbolos[1] && jogada == 1 && velha[0][0] == "     ")   ///prioridade numero 1 = ganhar (diagonais)
        {
            velha[0][0] = simbolos[1];
            jogada = 0;
        }
        if(velha[0][2] == simbolos[1] && velha[1][1] == simbolos[1] && jogada == 1 && velha[2][0] == "     ")   ///prioridade numero 1 = ganhar (diagonais)
        {
            velha[2][0] = simbolos[1];
            jogada = 0;
        }
        if(velha[2][0] == simbolos[1] && velha[1][1] == simbolos[1] && jogada == 1 && velha[0][2] == "     ")   ///prioridade numero 1 = ganhar (diagonais)
        {
            velha[0][2] = simbolos[1];
            jogada = 0;
        }
        for(int r=0 ; r<3 ; r++)   ///prioridade numero 2 = nao perder
        {
            if((velha[r][0] == simbolos[0] && velha[r][1] == simbolos[0] && jogada == 1) && velha[r][2] == "     ")
            {
                velha[r][2] = simbolos[1];
                jogada = 0;
            }
            if((velha[r][0] == simbolos[0] && velha[r][2] == simbolos[0] && jogada == 1) && velha[r][1] == "     ")
            {
                velha[r][1] = simbolos[1];
                jogada = 0;
            }
            if((velha[r][1] == simbolos[0] && velha[r][2] == simbolos[0] && jogada == 1) && velha[r][0] == "     ")
            {
                velha[r][0] = simbolos[1];
                jogada = 0;
            }
        }
        for(int c=0 ; c<3 ; c++)   ///prioridade numero 2 = nao perder
        {
            if((velha[0][c] == simbolos[0] && velha[1][c] == simbolos[0] && jogada == 1) && velha[2][c] == "     ")
            {
                velha[2][c] = simbolos[1];
                jogada = 0;
            }
            if((velha[0][c] == simbolos[0] && velha[2][c] == simbolos[0] && jogada == 1) && velha[1][c] == "     ")
            {
                velha[1][c] = simbolos[1];
                jogada = 0;
            }
            if((velha[1][c] == simbolos[0] && velha[2][c] == simbolos[0] && jogada == 1) && velha[0][c] == "     ")
            {
                velha[0][c] = simbolos[1];
                jogada = 0;
            }
        }
        if(velha[0][0] == simbolos[0] && velha[1][1] == simbolos[0] && jogada == 1 && velha[2][2] == "     ")   ///prioridade numero 2 = nao perder (diagonais)
        {
            velha[2][2] = simbolos[1];
            jogada = 0;
        }
        if(velha[2][2] == simbolos[0] && velha[1][1] == simbolos[0] && jogada == 1 && velha[0][0] == "     ")   ///prioridade numero 2 = nao perder (diagonais)
        {
            velha[0][0] = simbolos[1];
            jogada = 0;
        }
        if(velha[0][2] == simbolos[0] && velha[1][1] == simbolos[0] && jogada == 1 && velha[2][0] == "     ")   ///prioridade numero 2 = nao perder (diagonais)
        {
            velha[2][0] = simbolos[1];
            jogada = 0;
        }
        if(velha[2][0] == simbolos[0] && velha[1][1] == simbolos[0] && jogada == 1 && velha[0][2] == "     ")   ///prioridade numero 2 = nao perder (diagonais)
        {
            velha[0][2] = simbolos[1];
            jogada = 0;
        }
        if(velha[1][1] == "     "  && jogada == 1)   ///prioridade numero 3 = marcar o meio
        {
            velha[1][1] = simbolos[1];
            jogada = 0;
        }
        if(velha[0][1] == simbolos[0])   ///prioridade especial = impedir L
        {
            if(velha[2][2] == simbolos[0] && jogada == 1 && velha[0][2] == "     ")
            {
                velha[0][2] = simbolos[1];
                jogada = 0;
            }
            if(velha[2][0] == simbolos[0] && jogada == 1 && velha[0][0] == "     ")
            {
                velha[0][0] = simbolos[1];
                jogada = 0;
            }
        }
        if(velha[2][1] == simbolos[0])   ///prioridade especial = impedir L
        {
            if(velha[0][0] == simbolos[0] && jogada == 1 && velha[2][0] == "     ")
            {
                velha[2][0] = simbolos[1];
                jogada = 0;
            }
            if(velha[0][2] == simbolos[0] && jogada == 1 && velha[2][2] == "     ")
            {
                velha[2][2] = simbolos[1];
                jogada = 0;
            }
        }
        if(velha[0][0] == simbolos[0] && velha[2][2] == simbolos[0] && velha[0][2] == "     " && velha[2][0] == "     ")   ///prioridade especial = impedir triangulos
        {
            if(velha[0][1] == "     " && jogada == 1)
            {
                velha[0][1] = simbolos[1];
                jogada = 0;
            }
            if(velha[1][2] == "     " && jogada == 1)
            {
                velha[1][2] = simbolos[1];
                jogada = 0;
            }
            if(velha[2][1] == "     " && jogada == 1)
            {
                velha[2][1] = simbolos[1];
                jogada = 0;
            }
            if(velha[1][0] == "     " && jogada == 1)
            {
                velha[1][0] = simbolos[1];
                jogada = 0;
            }
        }
        if(velha[0][2] == simbolos[0] && velha[2][0] == simbolos[0] && jogada == 1 && velha[0][0] == "     " && velha[2][2] == "     ")   ///prioridade especial = impedir triangulos
        {
            if(velha[0][1] == "     " && jogada == 1)
            {
                velha[0][1] = simbolos[1];
                jogada = 0;
            }
            if(velha[1][2] == "     " && jogada == 1)
            {
                velha[1][2] = simbolos[1];
                jogada = 0;
            }
            if(velha[2][1] == "     " && jogada == 1)
            {
                velha[2][1] = simbolos[1];
                jogada = 0;
            }
            if(velha[1][0] == "     " && jogada == 1)
            {
                velha[1][0] = simbolos[1];
                jogada = 0;
            }
        }
        if((velha[0][0] == simbolos[0] || velha[0][1] == simbolos[0]) && velha[1][2] == simbolos[0] && jogada == 1 && velha[0][2] == "     ") ///prioridade numero 4 = bloquear as quinas
        {
            velha[0][2] = simbolos[1];
            jogada = 0;
        }
        if((velha[0][2] == simbolos[0] || velha[0][1] == simbolos[0]) && velha[1][0] == simbolos[0] && jogada == 1 && velha[0][0] == "     ") ///prioridade numero 4 = bloquear as quinas
        {
            velha[0][0] = simbolos[1];
            jogada = 0;
        }
        if((velha[2][0] == simbolos[0] || velha[2][1] == simbolos[0]) && velha[1][2] == simbolos[0] && jogada == 1 && velha[2][2] == "     ") ///prioridade numero 4 = bloquear as quinas
        {
            velha[2][2] = simbolos[1];
            jogada = 0;
        }
        if((velha[2][2] == simbolos[0] || velha[2][1] == simbolos[0]) && velha[1][0] == simbolos[0] && jogada == 1 && velha[2][0] == "     ") ///prioridade numero 4 = bloquear as quinas
        {
            velha[2][0] = simbolos[1];
            jogada = 0;
        }
        if((velha[0][0] == simbolos[0] || velha[0][1] == simbolos[0]) && (velha[2][2] == simbolos[0] || velha[2][1] == simbolos[0]) && jogada == 1 && velha[2][0] == "     ") ///prioridade numero 4 = bloquear as quinas
        {
            velha[2][0] = simbolos[1];
            jogada = 0;
        }
        if((velha[0][2] == simbolos[0] || velha[0][1] == simbolos[0]) && (velha[2][0] == simbolos[0] || velha[2][1] == simbolos[0]) && jogada == 1 && velha[2][2] == "     ") ///prioridade numero 4 = bloquear as quinas
        {
            velha[2][2] = simbolos[1];
            jogada = 0;
        }
        if(velha[0][0] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[0][0] = simbolos[1];
            jogada = 0;
        }
        if(velha[0][2] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[0][2] = simbolos[1];
            jogada = 0;
        }
        if(velha[2][2] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[2][2] = simbolos[1];
            jogada = 0;
        }
        if(velha[2][0] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[2][0] = simbolos[1];
            jogada = 0;
        }
        if(velha[0][1] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[0][1] = simbolos[1];
            jogada = 0;
        }
        if(velha[1][2] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[1][2] = simbolos[1];
            jogada = 0;
        }
        if(velha[2][1] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[2][1] = simbolos[1];
            jogada = 0;
        }
        if(velha[1][0] == "     " && jogada == 1)   ///prioridade numero 5 = jogar
        {
            velha[1][0] = simbolos[1];
            jogada = 0;
        }
        start = 0;
    }

    contador++;

    Jogar(velha);
}

void Decisao(string velha[3][3], char instrucao)
{
    char instruc;
    if(instrucao != 's' && instrucao != 'j')
    {
        instruc = Menu();
        Decisao(velha, instruc);
    }
    if(instrucao == 's')
        exit(0);
    else if(instrucao == 'j')
    {
        Reset_Jogo(velha);
        srand(time(NULL));
        randomic = rand() % 100;
        if(randomic%2 == 0)
            start = 0;
        else
            start = 1;
        Jogar(velha);
        Reset_Jogo(velha);
        contador = 0;
        instruc = Menu();
        Decisao(velha, instruc);
    }
}
