#include<iostream>
#include<stdlib.h>
using namespace std;
const int INT_MAX = 2E31-1;
class Pace { // lol
public:
	int timeReq;		// in sec
	int healthReq;

	Pace(int timeReq=-1, int healthReq=-1) {
		this->timeReq = timeReq;
		this->healthReq = healthReq;
	}
};

int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}

const int D_MAX = 40;
const int H_MAX = 300;
int opt[D_MAX][H_MAX];  // holds optimal times
int numPaces;
Pace* paces;


void printOpt(int D, int H) {
	cout << "\nOpt:\n";
	int i, j;
	for (i = 0; i <= D; i++) {
		for (j = 0; j <= H; j++) {
			cout << opt[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


int runYRun(int D, int H) {
	int i, j, k;
	int currentHealthOfPace;
	int currentTimeOfPace;

	// Initialize first row
	for (j = 0; j <= H; j++)
		opt[0][j] = INT_MAX;
	// Initialize first column
	for (i = 0; i <= D; i++)
		opt[i][0] = INT_MAX;

	// Initialize second row (the important one):
	for (j = 0; j <= H; j++) {
		opt[1][j] = INT_MAX;
		for (k = 0; k < numPaces; k++) {
			currentHealthOfPace = paces[k].healthReq;
			currentTimeOfPace = paces[k].timeReq;
			if(j >= currentHealthOfPace)
				opt[1][j] = min(opt[1][j], currentTimeOfPace);
		}
	}
	// printOpt(D, H);

	for (i = 2; i <= D; i++) {
		for (j = 1; j <= H; j++) {
			opt[i][j] = INT_MAX;
			for (k = 0; k < numPaces; k++) {
				currentHealthOfPace = paces[k].healthReq;
				currentTimeOfPace = paces[k].timeReq;
				if(j-currentHealthOfPace >= 0 && opt[i - 1][j - currentHealthOfPace]!=INT_MAX)
					opt[i][j] = min(opt[i][j], opt[i - 1][j - currentHealthOfPace] + currentTimeOfPace);
			}
		}
	}
	// printOpt(D, H);

	int minVal = INT_MAX;
	for (j = 0; j <= H; j++)
		minVal = min(minVal, opt[D][j]);
	return minVal;
}

int main() {
	//cout << INT_MAX;
	numPaces = 3;
	paces = new Pace[numPaces];
	paces[0] = *(new Pace(90, 5));
	paces[1] = *(new Pace(150, 1));
	paces[2] = *(new Pace(100, 4));
	cout << "\nMin = " << runYRun(2, 8);
	cout << endl;
	return 0;
}
