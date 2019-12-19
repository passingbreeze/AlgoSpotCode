#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;
using vecint = vector<int>;

vector<vecint> board;
vector<vecint> cache;

void printboard(const vector<vecint>& v)
{
	for(auto it: v){	
		for(auto vit : it)
			cout << vit << ' ';
		cout << '\n';
	}
}

int jump(int n, int y, int x){
	if(y>=n || x>=n)
		return 0;
	if(y == n-1 && x == n-1)
		return 1;
	int& ret = cache[y][x];
	if(ret != -1)
		return ret;
	int jumpsize= cache[y][x];
	return ret = (jump(n,y-jumpsize, x) || jump(n,y,x+jumpsize));

}

int main()
{
	// test codes
	system_clock time;
	duration<double> exetime;
	auto start = time.now();
	exetime = time.now() - start;

	string endsig;
	int n;

	random_device rd;
	mt19937_64 rseed(rd());
	uniform_int_distribution<int> dist1(1, 50), dist2(1,9);
	
	cout << "\nYou can quit with pushing 'Q' keys on keyboard.\n";
	while((cin >> endsig)){
		if(endsig == "q" || endsig == "Q"){
			cout << "total exec time : "<< exetime.count() << " sec(s)\n"; 
			return EXIT_FAILURE;
		}

		n = dist1(rseed);
		cout << "random value : "<< n << '\n';
		for(int i=0; i<n; ++i){	
			vecint boardtemp, cachetemp;
			for(int j=0; j<n; ++j){
				boardtemp.push_back(dist2(rseed));
				cachetemp.push_back(-1);
			}
			board.push_back(move(boardtemp));
			cache.push_back(move(cachetemp));
		}	
		int result = jump(n, n-1, 0);
		if(result == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
		printboard(board);
		board.clear();
		cache.clear();
	}


	cout << "total exec time : "<< exetime.count() << " sec(s)\n"; 
	return EXIT_SUCCESS;
}
