/* Mutant Flatworld Explorers */
#include <stdio.h>

int xmax, ymax;
int grid[100][100];

int incx(char dir)
{
	switch(dir) {
		case 'N':
			return 0;
		case 'E':
			return 1;
		case 'S':
			return 0;
		case 'W':
			return -1;
	}
	return 0;
}

int incy(char dir)
{
	switch(dir) {
		case 'N':
			return 1;
		case 'E':
			return 0;
		case 'S':
			return -1;
		case 'W':
			return 0;
	}
	return 0;
}

int main()
{
	freopen("D:/input.txt","r",stdin);
	int i, j;
	int x, y, x2, y2;
	char dir;
	char inst[120];

	scanf("%d %d", &xmax, &ymax);

	for(i=0; i<xmax; i++) {
		for(j=0; j<ymax; j++) {
			grid[i][j]=0;
		}
	}
	while(1) {
		int lost=0;
		if (scanf("%d %d %c %s", &x, &y, &dir, inst)!=4) {
			break;
		}
		for(i=0; !lost && inst[i]; i++) {
			switch(inst[i]) {
				case 'F':
					x2 = x + incx(dir);
					y2 = y + incy(dir);
					printf("%d %d %d %d %c\n",x,y,x2,y2,dir);
					if (x2<0 || x2>xmax || y2<0 || y2>ymax) {
						if (!grid[x][y]) {
							grid[x][y]=1;
							lost=1;
							break;
						}
					} else {
						x = x2;
						y = y2;
					}
					break;
				case 'L':
					switch(dir) {
						case 'N':
							dir='W';
							break;
						case 'E':
							dir='N';
							break;
						case 'S':
							dir='E';
							break;
						case 'W':
							dir='S';
							break;
					}
					break;
				case 'R':
					switch(dir) {
						case 'N':
							dir='E';
							break;
						case 'E':
							dir='S';
							break;
						case 'S':
							dir='W';
							break;
						case 'W':
							dir='N';
							break;
					}
					break;
				default:
					break;
			}
		}
		printf("%d %d %c", x, y, dir);
		if (lost) {
			printf(" LOST\n");
		} else {
			printf("\n");
		}
	}

}