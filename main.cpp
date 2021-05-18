#include <iostream>
#include <stdlib.h>
#include <clocale>
using namespace std;

//Array para exibir o tabuleiro
char tabuleiro[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

int escolha;
int linha, coluna;
char turno = 'X';
bool empate = false;

//Função que mostra o estado atual do tabuleiro

void mostrar_tabuleiro(){
	
	//Layout do tabuleiro
	cout << "JOGADOR - 1 [X] JOGADOR - 2 [O]\n\n";
	cout << "     |     |     \n";
	cout << "  " << tabuleiro[0][0] << "  |  " << tabuleiro[0][1] << "  |  " << tabuleiro[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << tabuleiro[1][0] << "  |  " << tabuleiro[1][1] << "  |  " << tabuleiro[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << tabuleiro[2][0] << "  |  " << tabuleiro[2][1] << "  |  " << tabuleiro[2][2] << "\n";
    cout << "     |     |     \n\n";
}

//Função para receber a entrada do jogador e atualizar o tabuleiro

void turno_jogador(){
    if(turno == 'X'){
        cout << "Turno do Jogador - 1 [X]: ";
    }
    else if(turno == 'O'){
        cout << "Turno do Jogador - 2 [O]: ";
    }
    
    //Recebendo a entrada do jogador
    
    //Atualizando o tabuleiro de acordo com a escolha e redistribuindo o início do turno

    cin >> escolha;
    cout << "\n";

    //Estrutura seletiva para receber qual linha e coluna serão atualizadas

    switch(escolha){
        case 1: linha=0; coluna=0; break;
        case 2: linha=0; coluna=1; break;
        case 3: linha=0; coluna=2; break;
        case 4: linha=1; coluna=0; break;
        case 5: linha=1; coluna=1; break;
        case 6: linha=1; coluna=2; break;
        case 7: linha=2; coluna=0; break;
        case 8: linha=2; coluna=1; break;
        case 9: linha=2; coluna=2; break;
        default:
            cout<<"Movimento Inválido";
    }
    
    if(turno == 'X' && tabuleiro[linha][coluna] !='X' && tabuleiro[linha][coluna] !='O'){
    	//Atualizando a posição para o símbolo 'X' se ela ainda não estiver ocupada
    	tabuleiro[linha][coluna] = 'X';
    	//Trocando o turno para 'O'
    	turno = 'O';
	}
	else if(turno == 'O' && tabuleiro[linha][coluna] !='X' && tabuleiro[linha][coluna] !='O'){
		//Atualizando a posição para o símbolo 'X' se ela ainda não estiver ocupada
    	tabuleiro[linha][coluna] = 'O';
    	//Trocando o turno para 'X'
    	turno = 'X';	
	}
	else{
		//Se a posição já estiver ocupada
		cout << "Posição já ocupada. Por favor, selecione outra";
		turno_jogador();
	}
	
	system("cls");
}

//Função para obter o estado do jogo, como JOGO VENCIDO, EMPATE OU JOGO EM CONTINUIDADE

bool gameover(){
	
	//Verificando se houve vitória para linhas e colunas simples
	for(int i=0; i<3; i++)
	if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2] || tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
	return false;
	
	//Verificando se houve vitória em ambas as diagonais
	if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2] || tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])
	return false;
	
	//Verificando se o jogo continua ou não
	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++)
	if(tabuleiro[i][j] !='X' && tabuleiro[i][j] != 'O')
	return true;
	
	//Verificando se houve empate
	empate = true;
	return false;
}

	int main(){
		setlocale (LC_ALL,"");
		
		cout << "JOGO - DA - VELHA";
		cout << "\nPARA 2 JOGADORES\n\n";
		
		while(gameover()){
			mostrar_tabuleiro();
			turno_jogador();
			gameover();
		}
	if(turno == 'X' && empate == false){
		cout << "\nParabéns! Jogador 'O' é o vencedor!";
	}
	else if(turno == 'O' && empate == false){
		cout << "\nParabéns! Jogador 'X' é o vencedor!";
	}
	else
		cout << "\nEmpate!";

	return 0;
}
