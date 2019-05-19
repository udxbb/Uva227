#include<stdio.h>
#define MAXN 100
#define ROW 5
#define COL 5
#include<cstring>

int excute(char c, char (*str)[5], int *spaceRow, int *spaceCol) {
	//printf("%s\n", str);
	//printf("%s\n", str[0]);
	//printf("%s\n", str[1][1]);
	//printf("%s\n", str[2][3]);
	//printf("%s\n", str[3]);
	//printf("%s\n", str[4]);
	int result = 1;
	switch (c) {
	case 'A': {
		if (*spaceRow == 0) {
			result = 0;
			break;
		}
		else {
			str[*spaceRow][*spaceCol] = str[*spaceRow - 1][*spaceCol];
			str[*spaceRow - 1][*spaceCol] = ' ';
			(*spaceRow)--;
			break;
		}
	}
	case 'B': {
		if (*spaceRow == 4) {
			result = 0;
			break;
		}
		else {
			str[*spaceRow][*spaceCol] = str[*spaceRow + 1][*spaceCol];
			str[*spaceRow + 1][*spaceCol] = ' ';
			(*spaceRow)++;
			break;
		}
	}
	case 'L': {
		if (*spaceCol == 0) {
			result = 0;
			break;
		}
		else {
			str[*spaceRow][*spaceCol] = str[*spaceRow][*spaceCol - 1];
			str[*spaceRow][*spaceCol - 1] = ' ';
			(*spaceCol)--;
			break;
		}
	}
	case 'R': {
		if (*spaceCol == 4) {
			result = 0;
			break;
		}
		else {
			str[*spaceRow][*spaceCol] = str[*spaceRow][*spaceCol + 1];
			str[*spaceRow][*spaceCol + 1] = ' ';
			(*spaceCol)++;
			break;
		}
	}
	default: break;
	}
	return result;
}

int main() {
	char s[ROW][COL];
	memset(s, 0, sizeof(s));
	int count = 1;
	int spaceRow = 10;
	int spaceCol = 10;
	int status = 2;
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			s[row][col] = getchar();
			if (col == 4) {
				char _ = getchar();
			}
			if (s[row][col] == ' ') {
				spaceRow = row;
				spaceCol = col;
			}
		}
	}
	//printf("\n%d %d is blank", spaceRow, spaceCol);
	char movement[MAXN];
	movement[0] = '\0';
	memset(movement, 0, sizeof(movement));
	scanf_s("%s", &movement, MAXN);
	int length = strlen(movement);
	for (int i = 0; i < length; i++) {
		if (spaceRow == 10) {
			status = 0;
			break;
		}
		else if (movement[i] == '0') {
			break;
		}
		else {
			if (excute(movement[i], s, &spaceRow, &spaceCol)) {
				status = 1;
				continue;
			}
			else {
				status = 0;
				break;
			}
		}
	}
	if (status) {
		printf("Puzzle #%d:\n", count);
		for (int p = 0; p < ROW; p++) {
			for (int q = 0; q < COL; q++) {
				printf("%c ", s[p][q]);
				if (q == 4) {
					printf("\n");
				}
			}
		}
		count++;
	}
	else {
		printf("This puzzle has no final configuration.");
	}
}