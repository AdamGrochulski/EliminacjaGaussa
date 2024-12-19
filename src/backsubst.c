#include "backsubst.h"
#include <stdlib.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	unsigned int m_r = mat->r;
	unsigned int m_c = mat->c;

	if (m_r!=m_c)
		return 2;

	int k;
	for(k=0;k<m_r;k++) {
		if(mat->data[k][k]==0)
			return 1;
	}

	int i=m_c-1;
	int j;
	double s;

	while (i >= 0) {
		j=0;
		while(j<m_r) {
			s=s+(mat->data[i][j]*x->data[j][0]);
			j++;
		}
		x->data[i][0]=b->data[i][0]-s;
		s=0;
		i--;
	}
	return 0;
}




