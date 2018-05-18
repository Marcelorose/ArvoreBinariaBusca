// ArvoreBinariaBusca.cpp : define o ponto de entrada para o aplicativo do console.
//
 
#include "stdafx.h"
#include "ABB.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{

	ABB arvore;
	inicializarABB(arvore);
	inserirABB_Rec_Definitivo(arvore, 50, "a");
	inserirABB_Rec_Definitivo(arvore, 100, "b");
	inserirABB_Rec_Definitivo(arvore, 25, "c");
	inserirABB_Rec_Definitivo(arvore, 10, "d");
	inserirABB_Rec_Definitivo(arvore, 40, "e");
	inserirABB_Rec_Definitivo(arvore, 30, "f");
	inserirABB_Rec_Definitivo(arvore, 27, "g");
	inserirABB_Rec_Definitivo(arvore, 35, "h");
	inserirABB_Rec_Definitivo(arvore, 20, "i");
	inserirABB_Rec_Definitivo(arvore, 28, "j");
	encontraRemove(arvore.raiz, 50);
	

    return 0;
}

