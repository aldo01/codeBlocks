#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int cols = 1000;

/**
 * maximum length of string should be less than 1000
 */
char **allocateMemory(int rows) {
	char **mat = (char **) malloc(sizeof(char *) * rows);
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
		/* Allocate array, store pointer  */
		mat[i] = (char *) malloc(sizeof(char) * cols);
	return mat;
}

char **read_matrix(char** mat, int rows) {

	int i;
	for (i = 0; i < rows; i++) {
		scanf("%s", mat[i]);
	}
	return mat;
}

void print_matrix(int rows, int cols, char **mat) {
	int i = 0, j = 0;
	for (i = 0; i < rows; i++) {
		printf("%s", mat[i]);
		printf("\n");
	}
}

void free_matrix(int rows, char **mat) {
	int i = 0;
	for (i = 0; i < rows; i++)
		free(mat[i]);
	free(mat);
}

int countSlashes(char *nextExisiting, char *nextDirTocreate) {
//TODO : write your code here
}

char *getNextExisitingDirectoryToMatch(char **already, int rowsAl) {
// TODO: Write your code here
}

char *getNextDirectoryToCreate(char **tobeCreated, int rowsCreate) {
	static int indexCreate = 0;
	if (indexCreate == rowsCreate) {
		indexCreate = 0;
	}
	return tobeCreated[indexCreate++];
}

void addToExisitingDirectories(char **already, int *rowsAl,
		char *directoryToBeAdded) {
	already[*rowsAl] = directoryToBeAdded;
	(*rowsAl)++;
}

int maximumMatch(char **already, int rowsAl, char *nextDirTocreate,
		int rowsCreate) {
	int j, k;
	int slashes;
	int maximumSlashes = 0;
	char *nextExisiting = (char *) malloc(sizeof(char) * cols);
	for (j = 0; j < rowsAl; j++) {

		nextExisiting = getNextExisitingDirectoryToMatch(already, rowsAl);

		slashes = countSlashes(nextExisiting, nextDirTocreate);
		if (slashes > maximumSlashes) {
			maximumSlashes = slashes;
		}

	}
	return maximumSlashes;
}

int countMkdirNeeded(char **toBeCreated, int rowsCreate, int *slashCount) {
	int i, j;
	int lenTobeCreated;
	int *totalSlashesToCreate = (int*) malloc(sizeof(int) * rowsCreate);
	memset(totalSlashesToCreate, 0, sizeof(totalSlashesToCreate));

	for (i = 0; i < rowsCreate; i++) {
		lenTobeCreated = strlen(toBeCreated[i]);
		for (j = 0; j < lenTobeCreated; j++) {
			if (toBeCreated[i][j] == '/') {
				totalSlashesToCreate[i]++;
			}
		}
	}
	int finalCount = 0;
	for (i = 0; i < rowsCreate; i++) {
		finalCount += totalSlashesToCreate[i] - slashCount[i];
	}
	return finalCount;
}

int countMkdir(char **already, int rowsAl, char **toBeCreated, int rowsCreate) {
	int i, j, k, l;
	int lenAlreadyCreated;
	int lenTobeCreated;
	char *nextDirToCreate = (char *) malloc(sizeof(char) * cols);

	int slashes;
	int *slashCount = (int*) malloc(sizeof(int) * rowsCreate);
	memset(slashCount, 0, sizeof(slashCount));

	for (i = 0; i < rowsCreate; i++) {
		nextDirToCreate = getNextDirectoryToCreate(toBeCreated, rowsCreate);
		slashCount[i] = maximumMatch(already, rowsAl, nextDirToCreate,
				rowsCreate);

		addToExisitingDirectories(already, &rowsAl, toBeCreated[i]);
}
	return countMkdirNeeded(toBeCreated, rowsCreate, slashCount);
}

int main() {
	char **already;
	char **toCreate;
	int rowsAlready;
	int rowsToCreate;
	scanf("%d %d", &rowsAlready, &rowsToCreate);
	already = allocateMemory(rowsAlready + rowsToCreate);
	toCreate = allocateMemory(rowsToCreate);

	already = read_matrix(already, rowsAlready);
	toCreate = read_matrix(toCreate, rowsToCreate);

	printf("%d\n", countMkdir(already, rowsAlready, toCreate, rowsToCreate));

	/*print_matrix(rowsAlready,cols,already);
	 print_matrix(rowsToCreate,cols,toCreate);*/
	return 0;
}



