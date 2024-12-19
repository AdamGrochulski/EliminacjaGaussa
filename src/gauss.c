#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

void row_changer(Matrix *mat, Matrix *b, int k, int p_i) {

	unsigned int m_r = mat->r;
	int j=0;
	double temp;
	temp=b->data[k][0];
	b->data[k][0]=b->data[p_i][0];
	b->data[p_i][0]=temp;

	while(j<m_r) {
		temp=mat->data[k][j];
		mat->data[k][j]=mat->data[p_i][j];
		mat->data[p_i][j]=temp;
		j++;
	}
}

int pivot_picker(Matrix *mat, int k) {
	unsigned int m_c = mat->c;
	int i=k;
	int i_max;
	double number;
	double max= 0;
	while (i<m_c) {
		number=mat->data[i][k];
		printf("%f ", number);
		if (abs(number)>=max) {
			i_max=i;
			max=abs(number);
		}
		i++;
	}
	if (max == 0)
		return -1;
	return i_max;
}

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

		//* pivotseeker(mat,b,k); Wywoływanie komendy studenta A, dodany komentarz, ponieważ wybraliśmy rozwiązanie studenta B

		int p_i=pivot_picker(mat,k);

		if (p_i==-1)
			return 1;

		row_changer(mat,b,k,p_i);


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