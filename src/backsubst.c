#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

double previx(Matrix *x, Matrix *mat, Matrix *b, int row){
	int i;
	double output;
	if (row==(mat->c)){
		output=(b->data[row-1][0])/(mat->data[row-1][row-1]);
	}
	else{
		double sum=(b->data[row-1][0]);
		for(i=row-1;i<(mat->c);i++){
			if (i!=row-1){
				sum-=(mat->data[row-1][i])*previx(x,mat,b,row+i);
				/*int j;
				double szuk;
				for (j = 1; j<mat->r;j++){
				//szuk = (1/(mat->data[i][i]))*((b->data[i][0])-1); < poprawić ten syf
				}*/
			}
			//sum -= każde a razy wynik x dla większego row
		}
		output=(1/(mat->data[row-1][row-1]))*sum;
	}
	return output;
}

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/*  
				
				double previous=1;

				for(i=(mat->c)-1;i>0;i--){
					int j;
					double szuk;
					for (j = 1; j<mat->r;j++){
						//szuk = (1/(mat->data[i][i]))*((b->data[i][0])-1); < poprawić ten syf
					}
					x->data[i][0];
				}
				*/
				//To ponizej jest przepisaniem b do x. Nalezy to popra

				int i;
				for (i = 0; i < mat->c; i++) {
								x->data[i][0] = previx(x,mat,b,i);
				}

				return 0;
}



