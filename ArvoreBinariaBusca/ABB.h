#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <string.h>

using namespace std;

struct Nodo {
	int chave;
	string dado;
	Nodo *maior;
	Nodo *menor;
};

struct ABB {
	Nodo *raiz;
	int qtd;
};

void inicializarABB(ABB &a) {
	a.raiz = NULL;
	a.qtd = 0;
}

bool inserirABB(int chave, string dado, ABB &a) {
	Nodo *novo = new Nodo;
	if (novo == NULL)
	{
		return false;
	}
	novo->chave = chave;
	novo->dado = dado;
	novo->maior = NULL;
	novo->menor = NULL;
	if (a.qtd == 0)
	{
		a.raiz = novo;
		a.qtd++;
		return true;
	}

	Nodo *nav = a.raiz;
	while (!((nav->maior == NULL && chave > nav->chave) || (nav->menor == NULL && chave < nav->chave))) {
	
		if (chave == nav->chave)
		{
			delete novo;
			return false;
		}
		else
		{
			if (chave > nav->chave)
			{
				nav = nav->maior;
			}
			else
			{
				nav = nav->menor;
			}
		}
	}
	if (chave > nav->chave)
	{
		nav->maior = novo;
	}
	else
	{
		nav->menor = novo;
	}
	a.qtd++;
	return true;
}

bool inserirABB_Rec(Nodo *&nodo, int chave, string dado) {
	if (nodo == NULL)
	{
		nodo = new Nodo;
		nodo->chave = chave;
		nodo->dado = dado;
		nodo->maior = NULL;
		nodo->menor = NULL;
		return true;
	}
	else
	{
		if (chave == nodo->chave)
		{
			return false;
		}
		if (chave > nodo->chave)
		{
			return inserirABB_Rec(nodo->maior, chave, dado);
		}
		else
		{
			return inserirABB_Rec(nodo->menor, chave, dado);
		}
	}
	return true;
}

bool inserirABB_Rec_Definitivo(ABB &a, int chave, string dado) {
	bool r = inserirABB_Rec(a.raiz, chave, dado);
	if (r == true)
	{
		a.qtd++;
	}
	return r;
}

void infixaABB(Nodo *nodo) {
	if (nodo != NULL) {
		infixaABB(nodo->menor);
		cout << nodo->chave << " ,";
		infixaABB(nodo->maior);
	}
}

string busca(ABB a, int chave) {
	Nodo *nav = a.raiz;
	while (nav != NULL)
	{
		if (chave == nav->chave)
		{
			return nav->dado;
		}
		if (chave > nav->chave)
		{
			nav = nav->maior;
		}
		else 
		{
			nav = nav->menor;
		}
	}

	return "A chave nao existe";
}


string busca_rec(Nodo *nodo, int chave) {
	if (nodo == NULL)
	{
		return "chave desconhecida";
	}
	if (nodo->chave == chave)
	{
		return nodo->dado;
	}
	else
	{
		if (chave > nodo->chave)
		{
			return busca_rec(nodo->maior, chave);
		}
		else
		{
			return busca_rec(nodo->menor, chave);
		}
	}
}

bool removerNodo(Nodo *&nodo) {
	Nodo *maiorMenores = nodo->menor;
	if (maiorMenores == NULL)
	{
		Nodo *rem = nodo;
		nodo = nodo->maior;
		delete rem;
		return true;
	}
	Nodo *pai = NULL;
	while (maiorMenores->maior != NULL)
	{
		pai = maiorMenores;
		maiorMenores = maiorMenores->maior;
	}
	maiorMenores->maior = nodo->maior;
	if (pai != NULL)
	{
		pai->maior = maiorMenores->menor;
		maiorMenores->menor = nodo->menor;
	}

	delete nodo;
	nodo = maiorMenores;
}

bool encontraRemove(Nodo *&nodo, int chave) {
	if (nodo == NULL)
	{
		return false;
	}
	if (chave == nodo->chave)
	{
		removerNodo(nodo);
		return true;
	}
	if (chave > nodo->chave)
	{
		return encontraRemove(nodo->maior, chave);
	}
	else
	{
		return encontraRemove(nodo->menor, chave);
	}
}


int buscaPeloDado(Nodo *nodo, string dado) {
	if (nodo != NULL)
	{
		if (nodo->dado == dado)
		{
			return nodo->chave;
		}
		int r = buscaPeloDado(nodo->menor, dado);
		if (r == -1)
		{
			r = buscaPeloDado(nodo->maior, dado);
		}
		return r;
	}
	return -1;
}



#endif
