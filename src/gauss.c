#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

void pivotseeker(Matrix *mat, Matrix *b, int k){
	unsigned int m_r = mat->r;
	unsigned int m_c = mat->c;
	int pivotseek=0;
	int maxpivotrow=k;
	double maxpivot=0;
	while (pivotseek<m_r-k){
			if (abs(mat->data[k+pivotseek][k])>maxpivot){
				maxpivot=abs(mat->data[k+pivotseek][k]);
				maxpivotrow=k+pivotseek;
			}
			pivotseek++;
		}
	double* temporary=mat->data[k];
	mat->data[k]=mat->data[maxpivotrow];
	mat->data[maxpivotrow]=temporary;
	double temporary2=b->data[k][0];
	b->data[k][0]=b->data[maxpivotrow][0];
	b->data[maxpivotrow][0]=temporary2;
}

int eliminate(Matrix *mat, Matrix *b){
	unsigned int m_r = mat->r;
	unsigned int m_c = mat->c;
	int k = 0;
	int i;
	int j;
	double pivot;
	double first;

	while (k<m_r || k<m_c ) {
		pivotseeker(mat,b,k);
		pivot = mat->data[k][k];
		i = k+1;  
		while(i<m_c){
			j=0;
			first=mat->data[i][k];
			while(j<m_r) {
				mat->data[i][j]=mat->data[i][j]-(first/pivot)*mat->data[k][j];
				j++;
			}
			b->data[i][0]=b->data[i][0]-(first/pivot)*b->data[k][0];
			i++;
		}
		j=0;
		b->data[k][0]=b->data[k][0]/pivot;
		while(j<m_r){
			mat->data[k][j]=mat->data[k][j]/pivot;
			j++;
		}
		k++;
	}

	return 0;
}