#include "pch.h"
#include "Classes/ponto.h"
#include "Classes/letra.h"
#include "Classes/palavra.h"
#include "Classes/imports.h"
#include "Classes/tabuleiro.h"
#include "Classes/jogador.h"
#include "Classes/jogo.h"

void tt(Jogo& a) {
	
}

int main()
{
	srand(time(0));
	int opt;
	string aux;
	Jogo jogo;
	int times;
	Tabuleiro tab;
	
	while (!jogo.endGame()) {
		jogo.clrScr();

		opt = jogo.menu();

		if (opt == 1) {
			
			jogo.getInfo();
			jogo.getSizes();

			/*int x = jogo.getSizes();
			Tabuleiro ta(10, 10);
			jogo.setTabuleiro(ta);*/

			jogo.pause();
			times = 0;

			while (!jogo.getTabuleiro().done()) {
				

				jogo.clrScr();

				aux = "";

				jogo.getTabuleiro().showPalavras();
				cout << endl;
				jogo.getTabuleiro().printTabuleiro();
				cout << endl;
				jogo.getTabuleiro().showEncontradas();


				// Lê a palavra
				aux = jogo.getJogador().readPlayOpt(times);

				if (aux == "sair") {
					break;
				}

				else{
					if(jogo.getJogador().tryWord(jogo.getTabuleiro(), aux)){
						if (jogo.getJogador().inArray(jogo.getTabuleiro().getEncontradas(), aux, jogo.getTabuleiro().getNEncontradas())) {
							cout << "A palavra ja foi escrita!" << endl;
						}
						else{
							cout << "Boa! Palavra certa!" << endl;

							tab = jogo.getTabuleiro();
							tab.addEncontrada(aux);
							jogo.setTabuleiro(tab);

							jogo.getTabuleiro().addEncontrada(aux);
							
							// cout << jogo.getTabuleiro().getNEncontradas() << endl;
							
						}
					}
					else{ 
						cout << "Palavra nao existe na sopa de letras: " << aux  << endl;
					}

					jogo.pause();
					times++;
				}

			}

			cout << endl << "Fim de jogo..." << endl << endl;
			jogo.pause();
			jogo.clrScr();

		}
		if (opt == 2) {
			cout << "Em desenvolvimento!!" << endl;
			jogo.pause();
			jogo.clrScr();
		}
		if (opt == 3) {
			jogo.clrScr();
			cout << "Obrigado por jogar ^^" << endl;
			exit(-1);
		}


		
	}



























	// Código usado em testes!

	/*Ponto ponto1(1, 2);
	Ponto ponto2(10, 20);
	Letra letra[30];*/

	/*letra[0].setAll('a', ponto1);
	letra[1].setAll('h', ponto1);
	letra[2].setAll(' ', ponto1);
	letra[3].setAll('m', ponto1);
	letra[4].setAll('l', ponto1);
	letra[5].setAll('k', ponto1);*/



	/*Palavra pala("horizontal", "not found", ponto2, "funcionando dos dois jeitos");

	for (int i = 0; i < pala.getNLetras(); i++){
		cout << pala.getVetLetras()[i].getLetra() << "";
	}

	cout << endl;

	if (pala == "funcionando dos dois jeitos") {
		cout << "eh igual" << endl;
	}
	else {
		cout << "NAO eh igual!" << endl;
	}

	cout << "Localizacao da letra 2 da palavra: " << pala.getVetLetras()[1].getPonto().getX() << endl;*/

		
	/*Tabuleiro ta(20, 20, "default");

	ta.printTabuleiro();*/
	
	// ta.printTabuleiro();

	//Jogador player;
	//cout << player.existeJogador() << endl;
	//player.saveScore();
	/*player.loadInfo("Joao Rua2");
	player.setPontos(100);
	cout << player.getNome()  << " idade: " << player.getIdade() << " Pontos: " << player.getPontos() << endl;
	player.saveInfo();
	player.showScore();*/

	/*cout << endl << "ma oi aqui vai ein valendo 100 reais: " << ta.getPalavras()[0].getVetLetrasStr() << endl;
	for (int i = 0; i < 60; i++) {
		cout << "Linha " << i << " " << ta.getPalavras()[i].getVetLetrasStr() << endl;
	}*/

	// ta.loadTabuleiro("Joao Rua2");

	// cout << endl << endl << endl;

	// ta.printTabuleiro();

	//cout << letra.getPonto().getX() << endl;

	return 0;
}
