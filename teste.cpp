/************************************************************
 *	 Parte II 
 *   arquivo...: main.cpp
 *   descrição.: Arquivo principal do jogo
 *
 *   autor.....: Augusto Soares                            <gutosoares@outlook.com>
 *   autor.....: Diego Adenir Ferreira de Paula Carvalho   <dcarvalho@sistemas.ufla.br>
 *   autor.....: Leonardo Magalhães
 *   data......: 16/11/2014
 *
 ***********************************************************/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "classes.cpp"
#define PESOTOTAL 100
#define BS_SZ 60 // Tamanho da barra de status

using namespace std;

int main()
{
	char nome[10];
	char opcao;
	int profissao = 0;

	int x = 0;
	int y = 0;
	int resultadoBatalha = 0;
	int escolha;

	int status;
    long int d1, d2;

	Pocao p1(10,(char *)"Aumenta_vida", 15), p2(5,(char *)"Aumenta_defesa", 12);
	Arma a1(20,(char *)"Escalibur",50), a2(50,(char *)"Garra Longa",70);
	Heroi heroi((char *)"Goku", 100, 40, 50, 1, 1);
	Mapa mapa;
	Mochila mochila(0);
	Cinto cinto;
	Alado alado((char *)"Aerodactyl", 10, 50), alado1((char *)"Smaug", 30, 30);
	Terrestre terrestre((char *)"Capiroto", 20, 40), terrestre1((char *)"Golem", 40, 30);
	Marinho marinho((char *)"Lula Gigante", 10, 50), marinho1((char *)"Gyarados", 30, 20);
	Boss boss((char *)"Capiroto Boss", 80, 50);
	Guerreiro guerreiro((char *)"Goku", 1, 1, 1, 1, 1);
	Mago mago((char *)"Goku", 1, 1, 1, 1, 1);
	Ladino ladino((char *)"Goku", 1, 1, 1, 1, 1);



//-----------------------------------------------------------------------------------------------//

	// Barra de loading
	cout << "                                       Jogo de RPG                                              " << endl;
	 for(status = 0; status <= BS_SZ; status++) {
            printf("\rCarregando: ["); // Abre a barra de status
                for(d1 = 1; d1 <= status; d1++) printf("="); // Exibe status atual
            for(d1 = (status + 1); d1 <= BS_SZ; d1++) printf(" "); // Preenche com espaco em branco
                printf("]"); // Fecha a barra de status
                fflush(stdout);
            for(d1 = 1; d1 <= 7000; d1++) for(d2 = 1; d2 <= 7000; d2++);
        }

    cout << "\nFinalizado!" << endl;
    cout << "Jogo carregado com sucesso!" << endl << endl;

   	cout << "Foi tudo que consegui lembrar para perguntar - a ideia da vingança " << endl;
   	sleep(2);
	cout << "povoava meus pensamentos. O voou terminou na hora exata para ele,  " << endl;
	sleep(2);
	cout << "um momento antes dos seu braços sederem." << endl;
	sleep(2);
	cout << "Smaug rouba-rá o tesouro dos anões e o leva-rá para a Montanha Solitária!" << endl;

    sleep(2);

	cout << "\nO jogo está começando... " << endl << endl;
	cout << "Digite o nome do heroi: " << endl;
	cin >> nome;
	heroi.setNomeHeroi(nome);

	bool loop = true;
	do
	{
		cout << "Digite a coordenada x e y da posição do heroi:" << endl;
		cin >> x >> y;
		cout << "\nPosição do Heroi no mapa(onde está o *): " << endl;
		mapa.imprimirMapa(x, y);
		cout << endl;

		if(x == 1 && y == 2)
		{
			// Profissão é um Ladino.
			if(ladino.efeitoLadino == true)
			{
				cout << "\nDeseja enfrentar o inimigo?(S/N): ";
				cin >> opcao;

				if(opcao == 'S' || opcao == 's')
				{
					cout << "-------------------------------------------" << endl;
					cout << "Informaçãoes do Heroi: " << endl;
					heroi.imprimir();
					cout << "-------------------------------------------" << endl;
					cout << "Informaçãoes do Inimigo: " << endl;
					alado.imprimir();

					resultadoBatalha = ((heroi.getAtaqueHeroi() + heroi.getDefesaHeroi()) - alado.getVida());
					heroi.setVidaHeroi(heroi.getVidaHeroi() - alado.getAtaqueInimigo());
					alado.setVida(alado.getVida() - heroi.getAtaqueHeroi());

					if(heroi.getVidaHeroi() >= 1)
					{
						cout << "-------------> Heroi vivo! <-------------" << endl;
						cout << "-----------> Inimigo morto! <------------" << endl;
						cout << "Dados atualizados: " << endl;
						heroi.imprimir();
						cout << endl;
						alado.imprimir();
						cout << endl;

						if(profissao <= 10)
								profissao++;

						if(profissao == 10)
						{
							cout << "Seu heroi ja pode adquirir uma profissao, va para" << endl;
							cout << "o Ponto de Treinamento (posicao 3,1)!!!" << endl;
						}
					}

					else
					{
						cout << "-------------> Heroi morto! <-------------" << endl;
						cout << "-------------> GAME OVER!!! <-------------" << endl;
						break;
					}
				}
			}

			// Profissão não é um Ladino
			if(ladino.efeitoLadino == false)
			{
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Heroi: " << endl;
				heroi.imprimir();
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Inimigo: " << endl;
				alado.imprimir();

				resultadoBatalha = ((heroi.getAtaqueHeroi() + heroi.getDefesaHeroi()) - alado.getVida());
				heroi.setVidaHeroi(heroi.getVidaHeroi() - alado.getAtaqueInimigo());
				alado.setVida(alado.getVida() - heroi.getAtaqueHeroi());

				if(heroi.getVidaHeroi() >= 1)
				{
					cout << "-------------> Heroi vivo! <-------------" << endl;
					cout << "-----------> Inimigo morto! <------------" << endl;
					cout << "Dados atualizados: " << endl;
					heroi.imprimir();
					cout << endl;
					alado.imprimir();
					cout << endl;

					if(profissao <= 10)
							profissao++;

					if(profissao == 10)
					{
						cout << "Seu heroi ja pode adquirir uma profissao, va para" << endl;
						cout << "o Ponto de Treinamento (posicao 3,1)!!!" << endl;
					}
				}

				else
				{
					cout << "-------------> Heroi morto! <-------------" << endl;
					cout << "-------------> GAME OVER!!! <-------------" << endl;
					break;
				}
			}
		}

		if (x == 1 && y == 3)
		{
			cout << "Obaaah!!" << endl;
			cout << "Você encontrou uma arma, o que você deseja fazer com ela:" << endl;
			cout << "1 - Utiliza-la." << endl;
			cout << "2 - Adicionar à mochila." << endl;
			cin >> escolha;

			if(escolha == 1)
			{
				cout << "-------------------------------------------" << endl;
				cout << "\nInformação da arma:" << endl;
				a2.imprimir();
				heroi.setAtaqueHeroi(heroi.getAtaqueHeroi() + a2.getAtaqueArma());
				cout << "Dados atualizados: " << endl;
				heroi.imprimir();
				cout << endl;

			}

			else if(escolha == 2)
			{
				cout << "Colocando a arma na mochila..." << endl;
				mochila.inserirArma(1, a1);
			}
		}

		if (x == 2 && y == 1)
		{
			// A profissão é um Ladino.
			if(ladino.efeitoLadino == true)
			{
				cout << "\nDeseja enfrentar o inimigo?(S/N): ";
				cin >> opcao;

				if(opcao == 'S' || opcao == 's')
				{
					cout << "-------------------------------------------" << endl;
					cout << "Informaçãoes do Heroi: " << endl;
					heroi.imprimir();
					cout << "-------------------------------------------" << endl;
					cout << "Informaçãoes do Inimigo: " << endl;
					terrestre.imprimir();

					resultadoBatalha = ((heroi.getAtaqueHeroi() + heroi.getDefesaHeroi()) - terrestre.getVida());
					heroi.setVidaHeroi(heroi.getVidaHeroi() - terrestre.getAtaqueInimigo());
					terrestre.setVida(terrestre.getVida() - heroi.getAtaqueHeroi());

					if(heroi.getVidaHeroi() >= 1)
					{
						cout << "-------------> Heroi vivo! <-------------" << endl;
						cout << "-----------> Inimigo morto! <------------" << endl;
						cout << "Dados atualizados: " << endl;
						heroi.imprimir();
						cout << endl;
						terrestre.imprimir();
						cout << endl;

						if(profissao <= 10)
							profissao++;

							if(profissao == 10)
							{
								cout << "Seu heroi ja pode adquirir uma profissao, va para" << endl;
								cout << "o Ponto de Treinamento (posicao 3,1)!!!" << endl;
							}
						}

					else
					{
						cout << "-------------> Heroi morto! <-------------" << endl;
						cout << "-------------> GAME OVER!!! <-------------" << endl;
						break;
					}
				}
			}

			// Profissão não é um Ladino.
			if(ladino.efeitoLadino == false)
			{
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Heroi: " << endl;
				heroi.imprimir();
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Inimigo: " << endl;
				terrestre.imprimir();

				resultadoBatalha = ((heroi.getAtaqueHeroi() + heroi.getDefesaHeroi()) - terrestre.getVida());
				heroi.setVidaHeroi(heroi.getVidaHeroi() - alado.getAtaqueInimigo());
				terrestre.setVida(terrestre.getVida() - heroi.getAtaqueHeroi());

				if(heroi.getVidaHeroi() >= 1)
				{
					cout << "-------------> Heroi vivo! <-------------" << endl;
					cout << "-----------> Inimigo morto! <------------" << endl;
					cout << "Dados atualizados: " << endl;
					heroi.imprimir();
					cout << endl;
					terrestre.imprimir();
					cout << endl;

					if(profissao <= 10)
					{
						profissao++;

						if(profissao == 10)
						{
							cout << "Seu heroi ja pode adquirir uma profissao, va para" << endl;
							cout << "o Ponto de Treinamento (posicao 3,1)!!!" << endl;
						}
					}

					else
					{
						cout << "-------------> Heroi morto! <-------------" << endl;
						cout << "-------------> GAME OVER!!! <-------------" << endl;
						break;
					}
				}
			}
		}

		if(x == 2 && y == 3)
		{
			// A profissão é um Ladino.
			if(ladino.efeitoLadino == true)
			{
				cout << "\nDeseja enfrentar o inimigo?(S/N): ";
				cin >> opcao;

				if(opcao == 'S' || opcao == 's')
				{
					cout << "-------------------------------------------" << endl;
					cout << "Informaçãoes do Heroi: " << endl;
					heroi.imprimir();
					cout << "-------------------------------------------" << endl;
					cout << "Informaçãoes do Inimigo: " << endl;
					terrestre1.imprimir();

					resultadoBatalha = ((heroi.getAtaqueHeroi() + heroi.getDefesaHeroi()) - terrestre1.getVida());
					heroi.setVidaHeroi(heroi.getVidaHeroi() - terrestre1.getAtaqueInimigo());
					terrestre1.setVida(terrestre1.getVida() - heroi.getAtaqueHeroi());

					if(heroi.getVidaHeroi() >= 1)
					{
						cout << "-------------> Heroi vivo! <-------------" << endl;
						cout << "-----------> Inimigo morto! <------------" << endl;
						cout << "Dados atualizados: " << endl;
						heroi.imprimir();
						cout << endl;
						terrestre1.imprimir();
						cout << endl;

						if(profissao <= 10)
						{	profissao++;

							if(profissao == 10)
							{
								cout << "Seu heroi ja pode adquirir uma profissao, va para" << endl;
								cout << "o Ponto de Treinamento (posicao 3,1)!!!" << endl;
							}
						}

						else
						{
							cout << "-------------> Heroi morto! <-------------" << endl;
							cout << "-------------> GAME OVER!!! <-------------" << endl;
							break;
						}
					}
				}
			}

			// Profissão não é um Ladino.
			if(ladino.efeitoLadino == false)
			{
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Heroi: " << endl;
				heroi.imprimir();
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Inimigo: " << endl;
				terrestre1.imprimir();

				resultadoBatalha = ((heroi.getAtaqueHeroi() + heroi.getDefesaHeroi()) - terrestre1.getVida());
				heroi.setVidaHeroi(heroi.getVidaHeroi() - alado.getAtaqueInimigo());
				terrestre1.setVida(terrestre1.getVida() - heroi.getAtaqueHeroi());

				if(heroi.getVidaHeroi() >= 1)
				{
					cout << "-------------> Heroi vivo! <-------------" << endl;
					cout << "-----------> Inimigo morto! <------------" << endl;
					cout << "Dados atualizados: " << endl;
					heroi.imprimir();
					cout << endl;
					terrestre1.imprimir();
					cout << endl;

					if(profissao <= 10)
					{
						profissao++;

						if(profissao == 10)
						{
							cout << "Seu heroi ja pode adquirir uma profissao, va para" << endl;
							cout << "o Ponto de Treinamento (posicao 3,1)!!!" << endl;
						}
					}

					else
					{
						cout << "-------------> Heroi morto! <-------------" << endl;
						cout << "-------------> GAME OVER!!! <-------------" << endl;
						break;
					}
				}
			}
		}

		// Boss do jogo
		if(x == 3 && y == 2)
		{
			cout << "\nDeseja enfrentar o CapirotoBoss ?(S/N): ";
			cin >> opcao;

			if(opcao == 'S' || opcao == 's')
			{
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Heroi: " << endl;
				heroi.imprimir();
				cout << "-------------------------------------------" << endl;
				cout << "Informaçãoes do Boss: " << endl;
				boss.imprimir();

				resultadoBatalha = ((heroi.getAtaqueHeroi() + heroi.getDefesaHeroi()) - boss.getVida());
				heroi.setVidaHeroi(heroi.getVidaHeroi() - (boss.getAtaqueInimigo())*2);
				boss.setVida(boss.getVida() - (heroi.getAtaqueHeroi()/2));

				if(heroi.getVidaHeroi() >= 1)
				{
					cout << "-------------> Heroi vivo! <-------------" << endl;
					cout << "-----------> Inimigo morto! <------------" << endl;
					cout << "Dados atualizados: " << endl;
					heroi.imprimir();
					cout << endl;
					boss.imprimir();
					cout << endl;

					if(profissao <= 10)
						profissao++;

					if(profissao == 10)
					{
						cout << "Seu heroi ja pode adquirir uma profissao, va para" << endl;
						cout << "o Ponto de Treinamento (posicao 3,1)!!!" << endl;
					}
				}

				else
				{
					cout << "-------------> Heroi morto! <-------------" << endl;
					cout << "-------------> GAME OVER! <-------------" << endl;
					break;
				}
			}
		}

		if(x == 1 && y == 1)
		{
			cout << "Obaaah!!" << endl;
			cout << "Você encontrou uma poção, o que você deseja fazer com ela:" << endl;
			cout << "1 - Utiliza-la." << endl;
			cout << "2 - Adicionar ao cinto." << endl;
			cin >> escolha;

			if(escolha == 1)
			{
				cout << "-------------------------------------------" << endl;
				cout << "\nInformação da poção:" << endl;
				p1.imprimir();
				cout << endl;
				heroi.setVidaHeroi(heroi.getVidaHeroi() + p1.getEfeitoPocao());
				cout << "Dados atualizados: " << endl;
				heroi.imprimir();
				cout << endl;

			}

			else if(escolha == 2)
			{
				cout << "Colocando a poção no cinto..." << endl;
				cinto.inserirPocao(1, p1);
			}
		}

		if(x == 3 && y == 3)
		{
			cout << "Obaaah!!" << endl;
			cout << "Você encontrou uma poção, o que você deseja fazer com ela:" << endl;
			cout << "1 - Utiliza-la." << endl;
			cout << "2 - Adicionar ao cinto." << endl;
			cin >> escolha;

			if(escolha == 1)
			{
				cout << "-------------------------------------------" << endl;
				cout << "\nInformação da poção:" << endl;
				p2.imprimir();
				heroi.setDefesaHeroi(heroi.getDefesaHeroi() + p2.getEfeitoPocao());
				cout << endl;
				cout << "Dados atualizados: " << endl;
				heroi.imprimir();
				cout << endl;

			}

			else if(escolha == 2)
			{
				cout << "Colocando a poção no cinto..." << endl;
				cinto.inserirPocao(2, p2);
			}
		}

		if(x == 3 && y == 1)
		{
			if(profissao == 10 && heroi.getNivelHeroi() >= 5)
			{
				cout << "Bem vindo ao ponto de treinamento, aqui o seu heroi podera" << endl;
				cout << "adquirir uma profissao. Voce deve escolher entre:" << endl;
				cout << "(1) - Guerreiro" << endl;
				cout << "(2) - Mago" << endl;
				cout << "(3) - Ladino" << endl;

				cin >> escolha;

				// Profissão Guerreiro
				if(escolha == 1)
				{
					cout << "-------------------------------------------" << endl;
					cout << "\nVoce escolheu a profissao Guerreiro." << endl;
					cout << "\nSeus status serao atualizados para esta profissao." << endl;

					//Definindo os valores de ataque e vida do guerreiro com base nos
					//dados do heroi
					guerreiro.setAtaqueGuerreiro(heroi.getAtaqueHeroi());
					guerreiro.setVidaGuerreiro(heroi.getVidaHeroi());

					//Pegando os valores do objeto guerreiro e passando novamente para o objeto heroi
					//para nao ter que modificar o codigo inteiro. Depois de escolhida essa profissao,
					//o heroi adquiri status do guerreiro
					heroi.setAtaqueHeroi(guerreiro.getAtaqueGuerreiro());
					heroi.setVidaHeroi(guerreiro.getVidaGuerreiro());

					cout << "Dados atualizados: " << endl;
					heroi.imprimir();
					cout << endl;

				}

				// Profissão Mago
				if(escolha == 2)
				{
					cout << "-------------------------------------------" << endl;
					cout << "\nVoce escolheu a profissao Mago." << endl;
					cout << "\nSeus status serao atualizados para esta profissao." << endl;

					//Definindo os valores do mago
					mago.setAtaqueMago(heroi.getAtaqueHeroi());
					mago.setVidaMago(heroi.getVidaHeroi());

					//Pegando os valores do objeto mago e passando novamente para o objeto heroi
					//para nao ter que modificar o codigo inteiro. Depois de escolhida essa profissao,
					//o heroi adquiri status do mago
					heroi.setAtaqueHeroi(mago.getAtaqueMago());
					heroi.setVidaHeroi(mago.getVidaMago());

					cout << "Dados atualizados: " << endl;
					heroi.imprimir();
					cout << endl;
				}

				// Profissão Ladino
				if(escolha == 3)
				{
					cout << "-------------------------------------------" << endl;
					cout << "\nVoce escolheu a profissao Ladino." << endl;
					cout << "\nSeus status serao atualizados para esta profissao." << endl;

					ladino.setEfeitoLadino(true);

					cout << "Dados atualizados: " << endl;
					heroi.imprimir();
					cout << endl;
				}
			}

			else
			{
				cout << "Aqui é uma area de treinamento! Você tem que matar mais de " << endl;
				cout << "10 inimigo e estar no nível 5!" << endl;
			}
		}

		if(x == 2 && y == 2)
		{
			cout << "Mudou de nível!!! \n";

			// Atualizando os dados do heroi
			heroi.setAtaqueHeroi(heroi.getAtaqueHeroi() + 10);
			heroi.setVidaHeroi(heroi.getVidaHeroi() + 10);
			heroi.setDefesaHeroi(heroi.getDefesaHeroi() + 10);
			heroi.setNivelHeroi(heroi.getNivelHeroi() + 1);

			// Atualizando os dados dos inimigos
			alado.setAtaque(alado.getAtaqueInimigo() + 5);
			alado.setVida(alado.getVida() + 5);

			alado1.setAtaque(alado1.getAtaqueInimigo() + 5);
			alado1.setVida(alado1.getVida() + 5);

			terrestre.setAtaque(terrestre.getAtaqueInimigo() + 5);
			terrestre.setVida(terrestre.getVida() + 5);

			terrestre1.setAtaque(terrestre1.getAtaqueInimigo() + 5);
			terrestre1.setVida(terrestre1.getVida() + 5);

			marinho.setAtaque(marinho.getAtaqueInimigo() + 5);
			marinho.setVida(marinho.getVida() + 5);

			marinho1.setAtaque(marinho1.getAtaqueInimigo() + 5);
			marinho1.setVida(marinho1.getVida() + 5);

			// Atualizando os status do boss
			boss.setAtaque(boss.getAtaqueInimigo() + 5);
			boss.setVida(boss.getVida() + 5);
		}
	} while (loop == true);

	return 0;
}
