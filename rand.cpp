#include <bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))
stringstream ss;

int main( int argc, char *argv[] ) {
	freopen("rand.in", "w", stdout);
	int seed=time(NULL);
	if(argc) {
		ss.clear();
		ss<<argv[1];
		ss>>seed;
	}
	srand(seed);
	printf("%d\n",random(3,200));
	int T=20000;
	while(T--){
		printf("%d ",random(0,99));
	}
	printf("-1\n");
	return 0;
}
