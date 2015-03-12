/************************************************************
 *   Parte II 
 *   arquivo...: classes.cpp
 *   descrição.: Arquivo de definição de todas as classes do jogo
 *
 *   autor.....: Augusto Soares                             <gutosoares@outlook.com>
 *   autor.....: Diego Adenir Ferreira de Paula Carvalho    <dcarvalho@sistemas.ufla.br>
 *   autor.....: Leonardo Magalhães
 *   data......: 16/11/2014
 *
 ***********************************************************/

#include <iostream>
#include <string.h>


#define TAM_L 4
#define TAM_C 4
#define PESOTOTAL 100

using namespace std;

// classe de Elementos do jogo
class Elemento
{

protected:
	char nome[30];
	double peso;

public:
	Elemento(char nome[30], double p)
	{
		setNomeElemento(nome);
		setPesoElemento(p);
	}

	Elemento()
	{
	}

	void setNomeElemento(char nome[30])
	{
		strcpy(this->nome,nome);
	}

	char *getNomeElemento()
	{
		return nome;
	}

	void setPesoElemento(double p)
	{
		if(p > 0)
			peso = p;
		else
			peso = 0;
	}

	double getPesoElemento()
	{
		return peso;
	}

	virtual void imprimir()
	{
		cout << "Nome: " << nome << endl;
		cout << "Peso: " << peso << endl;
	}

};

// classe de Armas do jogo, herança simple de Elemento
class Arma : public Elemento
{

private:
 	int numAtaque;

public:
 	Arma(int num, char nome[30], double p) : Elemento(nome, p)
 	{
		setAtaqueArma(num);
	}

	Arma() : Elemento()
	{
	}

 	void setAtaqueArma(int num)
 	{
		if(num > 0)
			numAtaque = num;
		else
			numAtaque = 1;
	}

 	int getAtaqueArma()
 	{
		return numAtaque;
	}

 	virtual void imprimir()
 	{
		cout << "Nome da arma: " << nome << endl;
		cout << "Pontos de ataque: " << numAtaque << endl;
		cout << endl;
	}
};

// Classe Mochila, reposavel em armazenar as armas do Heroi
class Mochila
{

private:
	int carga;
	int topo;
	Arma arma[PESOTOTAL];
	Arma obj;

public:
	Mochila(int t)
	{
		setTopo(t);
		carga = 0;
	}

	void setTopo(int t)
	{
		topo = t;
	}

    void retirarArma(int i, Arma obj)
    {
		for (int i = PESOTOTAL; i > 0; i--)
		{
			arma[i] = arma[i - 1];
		}
	}

	void inserirArma(int i, Arma obj)
	{
		if(obj.getPesoElemento() <= PESOTOTAL)
		{
			arma[i] = obj;
			carga += obj.getPesoElemento();
		}
	}
};

// classe de Poções do jogo, herança simple de Elemento
class Pocao : public Elemento
{

private:
 	int efeito;

public:
 	Pocao(int num, char nome[30], double p) : Elemento(nome, p)
 	{
		setEfeitoPocao(num);
	}

	Pocao() : Elemento()
	{
	}

 	void setEfeitoPocao(int num)
 	{
		if(num > 0)
			efeito = num;
		else
			efeito = 1;
	}

 	int getEfeitoPocao()
 	{
		return efeito;
	}

 	virtual void imprimir()
 	{
		cout << "Efeito da Poção: " << efeito << endl;
		cout << "Nome da Poção: " << nome << endl;
	}

};

// Classe Cinto, responsavel por armazenar todas as poções do Heroi
class Cinto
{

private:
      Pocao cinto[5];
      Pocao obj;

public:
	Cinto ()
	{

    }

    void retirarPocao(int i, Pocao obj)
    {
		for (int i = 5; i > 0; i--)
		{
			cinto[i] = cinto[i - 1];
		}
	}

    void inserirPocao(int i, Pocao obj)
	{
		cinto[i] = obj;

	}

    Pocao consulta (int posicao)
    {
		return cinto[posicao];
    }
};

// classe Heroi do jogo
class Heroi
{

protected:
	int ataque, vida, defesa, coordX, coordY, nivel;
	char nome[30];

public:
	Heroi(char nome[30], int a, int v, int d, int x, int y)
	{
			setNomeHeroi(nome);
			setAtaqueHeroi(a);
			setVidaHeroi(v);
			setDefesaHeroi(d);
			setCoordXHeroi(x);
			setCoordYHeroi(y);
			nivel = 1;
	}

    void setNomeHeroi(char nome[30])
    {
		strcpy(this->nome, nome);
	}

    char *getNomeHeroi()
    {
		return nome;
	}

    void setAtaqueHeroi(int a)
    {
		ataque = a;
	}

	void setVidaHeroi(int v)
	{
		vida = v;
	}

	void setDefesaHeroi(int d)
	{
		defesa = d;
	}

	int getAtaqueHeroi()
	{
		return ataque;
	}

	int getVidaHeroi()
	{
		return vida;
	}

	int getDefesaHeroi()
	{
		return defesa;
	}

	void setCoordXHeroi(int x)
	{
		coordX = x;
	}

	void setCoordYHeroi(int y)
	{
		coordY = y;
	}

	int getCoordXHeroi()
	{
		return coordX;
	}

	int getCoordYHeroi()
	{
		return coordY;
	}

	void setNivelHeroi(int n)
	{
		nivel = n;
	}

	int getNivelHeroi()
	{
		return nivel;
	}

	virtual void imprimir()
	{
		cout << "Nome Heroi: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
		cout << "Defesa: " << defesa << endl;
		cout << "Nível do Heroi: " << nivel << endl;
	}
};

// classe Guerreiro
class Guerreiro : public Heroi
{
public:
	Guerreiro(char nome[30], int a, int v, int d, int x, int y) : Heroi(nome, a, v, d, x, y)
	{
		setAtaqueGuerreiro(a);
		setVidaGuerreiro(v);
		setNomeGuerreiro(nome);
		setDefesaGuerreiro(d);
		setCoordXGuerreiro(x);
		setCoordYGuerreiro(y);
	}

    void setAtaqueGuerreiro(int a)
    {
		ataque = (2 * a);
	}

	void setVidaGuerreiro(int v)
	{
		vida = (2 * v);
	}

	void setNomeGuerreiro(char nome[30])
	{
		strcpy(this->nome, nome);
	}

	void setDefesaGuerreiro(int d)
	{
		defesa = d;
	}

	void setCoordXGuerreiro(int x)
	{
		coordX = x;
	}

	void setCoordYGuerreiro(int y)
	{
		coordY = y;
	}

	int getAtaqueGuerreiro()
	{
		return ataque;
	}

	int getVidaGuerreiro()
	{
		return vida;
	}

	char *getNomeGuerreiro()
	{
		return nome;
	}

	int getDefesaGuerreiro()
	{
		return defesa;
	}

	int getCoordXGuerreiro()
	{
		return coordX;
	}

	int getCoordYGuerreiro()
	{
		return coordY;
	}

	virtual void imprimir()
	{
		cout << "Nome Guerreiro: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
		cout << "Defesa: " << defesa << endl;
		cout << "Nível do Guerreiro: " << nivel << endl;
	}
};

// classe Ladino
class Ladino : public Heroi
{
public:
	bool efeitoLadino; // Ira permitir a ativaçao do efeito do ladino

public:
	Ladino(char nome[30], int a, int v, int d, int x, int y) : Heroi(nome, a, v, d, x, y)
	{
		setAtaqueLadino(a);
		setVidaLadino(v);
		setNomeLadino(nome);
		setDefesaLadino(d);
		setCoordXLadino(x);
		setCoordYLadino(y);
		setEfeitoLadino(false);
	}

    void setAtaqueLadino(int a)
    {
		ataque = a;
	}

	void setVidaLadino(int v)
	{
		vida = v;
	}

	void setNomeLadino(char nome[30])
	{
		strcpy(this->nome, nome);
	}

	void setDefesaLadino(int d)
	{
		defesa = d;
	}

	void setCoordXLadino(int x)
	{
		coordX = x;
	}

	void setCoordYLadino(int y)
	{
		coordY = y;
	}

	int getAtaqueLadino()
	{
		return ataque;
	}

	int getVidaLadino()
	{
		return vida;
	}

	char *getNomeLadino()
	{
		return nome;
	}

	int getDefesaLadino()
	{
		return defesa;
	}

	int getCoordXLadino()
	{
		return coordX;
	}

	int getCoordYLadino()
	{
		return coordY;
	}

	void setEfeitoLadino(bool efeito)
	{
		efeitoLadino = efeito;
	}

	bool getEfeitoLadino()
	{
		return efeitoLadino;
	}

	virtual void imprimir()
	{
		cout << "Nome Ladino: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
		cout << "Defesa: " << defesa << endl;
		cout << "Nível do Ladino: " << nivel << endl;
	}
};

// Classe Mago, herança simples de Heroi
class Mago : public Heroi
{
public:
	Mago(char nome[30], int a, int v, int d, int x, int y) : Heroi(nome, a, v, d, x, y)
	{
		setAtaqueMago(a);
		setVidaMago(v);
		setNomeMago(nome);
		setDefesaMago(d);
		setCoordXMago(x);
		setCoordYMago(y);
	}

	void setAtaqueMago(int a)
	{
		ataque = a;
	}

	void setVidaMago(int v)
	{
		vida = v;
	}

	void setNomeMago(char nome[30])
	{
		strcpy(this->nome, nome);
	}

	void setDefesaMago(int d)
	{
		defesa = d;
	}

	void setCoordXMago(int x)
	{
		coordX = x;
	}

	void setCoordYMago(int y)
	{
		coordY = y;
	}

	int getAtaqueMago()
	{
		return ataque;
	}

	int getVidaMago()
	{
		return vida;
	}

	char *getNomeMago()
	{
		return nome;
	}

	int getDefesaMago()
	{
		return defesa;
	}

	int getCoordXMago()
	{
		return coordX;
	}

	int getCoordYMago()
	{
		return coordY;
	}

	virtual void imprimir()
	{
		cout << "Nome Mago: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
		cout << "Defesa: " << defesa << endl;
		cout << "Nível do Mago: " << nivel << endl;
	}
};

// classe Inimigo do jogo
class Inimigo
{

protected:
		int ataque, vida;
		char nome[30];

public:
	Inimigo(char nome [30], int a = 10, int v = 50)
	{
		setNomeInimigo(nome);
		setAtaque(a);
		setVida(v);
	}

	void setNomeInimigo(char nome[30])
	{
        strcpy(this->nome,nome);
	}

	char *getNomeInimigo()
	{
		return nome;
	}

	void setAtaque(int a)
	{
		ataque = a;
	}

	int getAtaqueInimigo()
	{
		return ataque;
	}

	void setVida(int v)
	{
		vida = v;
	}

	int getVida()
	{
		return vida;
	}

	void imprimir()
	{
		cout << "Nome Inimigo: " << nome << endl;
		cout << "Ataque Inimigo: " << ataque << endl;
		cout << "Vida Inimigo: " << vida << endl;
	}
};

// Classe Boss responsavel em criar um chefe para cada fase
class Boss : public Inimigo
{

public:
	Boss(char nome[30], int a, int v) : Inimigo(nome, a, v)
	{
		setNomeInimigo(nome);
		setAtaque(a);
		setVida(v);
	}

	void imprimir()
	{
		cout << "Boss: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
	}
};

// classe Inimigo Alado, herança simples de Inimigo
class Alado : public Inimigo
{

public:
	Alado(char nome[30], int a, int v) : Inimigo(nome, a, v)
	{
		setNomeInimigo(nome);
		setAtaque(a);
		setVida(v);
	}

	virtual void imprimir()
	{
		cout << "Inimigo Alado: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
	}
};

// classe Inimigo Marinho, herança simples de Inimigo
class Marinho : public Inimigo
{

public:
	Marinho(char nome[30], int a, int v) : Inimigo(nome, a, v)
	{
		setNomeInimigo(nome);
		setAtaque(a);
		setVida(v);
	}

	virtual void imprimir()
	{
		cout << "Inimigo Marinho: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
	}
};

// classe Inimigo Terrestre, herança simples de Inimigo
class Terrestre : public Inimigo
{

public:
	Terrestre(char nome[30], int a, int v) : Inimigo(nome, a, v)
	{
		setNomeInimigo(nome);
		setAtaque(a);
		setVida(v);
	}

	virtual void imprimir()
	{
		cout << "Inimigo Terrestre: " << nome << endl;
		cout << "Ataque: " << ataque << endl;
		cout << "Vida: " << vida << endl;
	}
};

// Classe Mapa, local onde é realizado as batalhas
class Mapa
{

private:
	int caminho[TAM_L][TAM_C];

public:
	Mapa()
	{
		for(int i = 1; i < TAM_L; i++)
		{
			for(int j = 1; j < TAM_C; j++)
			{
				caminho[i][j] = 0;
			}
		}
	}

	virtual void imprimir()
	{
		for(int i = 1; i < TAM_L; i++)
		{
			for(int j = 1; j < TAM_C; j++)
			{
				cout << caminho[i][j] << " ";
			}

			cout << endl;
		}
	}

	void imprimirMapa(int l, int c)
	{
		for(int i = 1; i < TAM_L; i++)
		{
			for(int j = 1; j < TAM_C; j++)
			{
				if(i == l && j == c)
				{
					cout << caminho[i][j] << "*";
				}

				else
					cout << caminho[i][j] << " ";
			}

			cout << endl;
		}
	}

	int getPosicao(int l,int c)
	{
		cout << "Linha: " << l << endl;
		cout << "Coluna: " << c << endl;

		return caminho[l][c];
	}
};
