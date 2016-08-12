#include<stdio.h>
#include<stdlib.h>

int *allocateMemory(int rows) {
	int *mat = (int *) malloc(sizeof(int) * rows);
	return mat;
}

int *read_matrix(int* mat, int rows) {

	int i;
	for (i = 0; i < rows; i++) {
		scanf("%d", &mat[i]);
	}
	return mat;
}
int  longestIncDecSeq(int arr[], int n) {
// write your code here
}

int main() {
	int *arr;
	int n;
	scanf("%d", &n);
	arr = allocateMemory(n);
	arr = read_matrix(arr, n);
	printf("%d\n", longestIncDecSeq(arr, n));
	return 0;
}
