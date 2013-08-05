#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)
#define _CO(x) { cout << x << endl;}
#define _CI(x) { cin >> x;}


#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}


class TheAirTripDivOne{

	vector<vector<vector<int> > > ds;
	int answ;
	int N;
	int T;
	int WTH;
	int* used;
	ll* fail;
public:
	int find(int n, vector<string> fs, int time){

		N = n;
		T = time;
		int answ = -1;
		string s;
		ll INF = (ll)200000000000000000000;
		for(int i = 0; i < fs.size(); i++){
			s += fs[i];
		}
		vector<string> sp = split(s, ' ');


		for(int i = 0; i < n+1; i++){
			vector<vector<int> > v;
			ds.push_back(v);
		}


		for(int i = 0; i < sp.size(); i++){
			string s = sp[i];
			vector<string> sp = split(s, ',');
			vector<int> d;
			int idx = 0;
			for(int j = 0; j < sp.size(); j++){
				int ti = atoi(sp[j].c_str());
				d.push_back(ti);
				if(j == 0) idx = ti;
			}

			ds[idx].push_back(d);
		}

		vector<vector<int> > v = ds[1];
		for(int i = 0; i < v.size(); i++){
			vector<int> vc = v[i];
			int to = vc[1];
			int F = vc[2];
			int TM = vc[3];

			WTH = 1;
			if(answ != -1){
				WTH = answ;
			}
			used = new int[N+1];
			fail = new ll[N+1];
			for(int i = 0; i < N+1; i++) {
				used[i] = 0;
				fail[i] = INF;
			}
			if(!check(to, F + TM)) continue;
			int l = WTH;
			int r = 1000000001;

			while(l + 1 < r){
				int mid = (l + r) / 2;
				WTH = mid;
				for(int i = 0; i < N+1; i++) {
					used[i] = 0;
					fail[i] = INF;
				}
				if(check(to, F + TM)){
					l = mid;
				}
				else{
					r = mid;
				}
			}
			answ = max(answ, l);

		}



		return answ;
	}

	int check(int idx, ll time){

		if(time > T) return 0;
		if(fail[idx] <= time){
			return 0;
		}


		if(idx == N){
			return 1;
		}
		used[idx] = 1;
		vector<vector<int> > vec = ds[idx];
		for(int i = 0; i < vec.size(); i++){
			vector<int> v = vec[i];
			int to = v[1];
			if(used[to]) continue;
			int F = v[2];
			int TM = v[3];
			int P = v[4];
			ll nexttime = 0;
			int newtime = time + WTH;
			if(newtime == F){
				nexttime = newtime;
			}
			else if(newtime < F){
				nexttime = F;
			}
			else{
				int nt = newtime - F;
				if(nt % P == 0){
					nexttime = newtime;
				}
				else{
					nexttime = F + (ll)(nt / P + 1) * P;
				}
			}

			if(check(to,nexttime + TM)){
				return 1;
			}
		}
		used[idx] = 0;
		fail[idx] = time;
		return 0;

	}


	vector<string> split(const string &str, char delim){
		vector<string> res;
		size_t current = 0, found;
		while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
		}
		res.push_back(string(str, current, str.size() - current));
		return res;
	}

};


int main(){
	TheAirTripDivOne t;

	vector<string> vs;
	vs.push_back("19,40,17,52,54 43,37,28,37,65 29,22,91,91,43 37");
	vs.push_back(",35,40,97,67 22,37,17,97,67 8,39,27,49,10 5,37,");
	vs.push_back("46,49,81 20,1,64,1,82 2,8,1,66,12 6,22,73,94,1 ");
	vs.push_back("8,25,11,42,1 28,34,79,85,74 4,16,3,22,53 23,14,");
	vs.push_back("45,1,5 31,40,27,15,85 47,44,75,34,52 42,27,63,3");
	vs.push_back("0,73 21,29,37,18,97 31,46,24,70,10 16,32,26,10,");
	vs.push_back("17 43,12,51,16,93 8,23,94,90,55 45,41,62,95,50 ");
	vs.push_back("5,31,77,30,35 20,34,40,79,67 11,39,82,46,43 4,2");
	vs.push_back("7,55,81,26 4,44,91,64,1 13,44,50,82,78 19,33,1,");
	vs.push_back("46,27 16,36,79,64,97 39,8,98,67,54 33,35,27,16,");
	vs.push_back("43 16,28,57,1,61 18,44,89,31,98 19,16,91,96,56 ");
	vs.push_back("6,9,46,97,43 44,26,84,61,9 31,28,61,28,84 43,3,");
	vs.push_back("90,96,8 1,10,21,4,20 27,19,46,10,82 33,10,81,56");
	vs.push_back(",88 25,1,3,17,53 31,18,93,78,21 1,27,69,43,48 2");
	vs.push_back("0,8,6,99,28 17,3,74,1,16 11,24,39,33,67 28,44,2");
	vs.push_back(",71,6 21,25,67,28,21 10,34,4,23,81 38,1,12,69,4");
	vs.push_back(" 22,19,28,55,7 40,34,34,8,82 19,31,1,76,92 3,13");
	vs.push_back(",68,19,12 6,40,67,87,13 5,39,67,51,58 5,24,40,1");
	vs.push_back("6,79 16,25,35,37,22 35,28,58,43,46 5,47,34,56,1");
	vs.push_back("2 10,13,82,90,5 14,4,80,44,34 27,16,95,37,94 26");
	vs.push_back(",9,10,77,91 35,27,19,83,61 46,3,46,44,63 28,40,");
	vs.push_back("16,53,58 33,38,67,18,73 42,24,1,4,6 28,22,64,25");
	vs.push_back(",67 19,41,23,26,34 34,31,74,37,87 24,2,64,51,91");
	vs.push_back(" 3,36,5,88,97 46,15,61,1,27 30,34,44,34,10 38,2");
	vs.push_back("1,28,76,46 45,21,31,26,64 38,27,49,86,89 19,41,");
	vs.push_back("56,43,14 20,41,47,88,36 26,21,49,12,45 19,21,55");
	vs.push_back(",67,67 27,46,13,33,19 25,28,82,78,98 31,19,8,1,");
	vs.push_back("3 27,15,1,46,22 6,27,82,1,79 28,18,31,55,99 37,");
	vs.push_back("24,95,42,28 16,21,52,37,82 1,32,93,3,52 4,10,9,");
	vs.push_back("87,76 25,42,91,15,52 12,35,89,73,6 7,34,42,46,9");
	vs.push_back("7 1,38,64,85,19 38,17,45,40,3 31,11,7,30,52 47,");
	vs.push_back("39,64,4,24 43,32,49,49,14 27,6,29,34,91 24,1,71");
	vs.push_back(",10,78 1,10,38,75,75 36,10,1,37,34 2,14,19,1,22");
	vs.push_back(" 4,33,30,1,29 15,1,84,1,48 36,11,28,37,34 13,41");
	vs.push_back(",53,46,97 17,4,30,10,1 30,29,37,1,37 19,7,49,59");
	vs.push_back(",99 12,16,43,78,48 30,41,55,19,2 26,21,50,47,96");
	vs.push_back(" 20,1,73,82,22 14,20,34,46,85 15,37,34,78,2 28,");
	vs.push_back("27,30,61,1 36,22,34,43,19 29,3,19,78,95 5,40,67");
	vs.push_back(",28,42 7,14,21,1,35 32,21,29,79,4 1,36,7,94,64 ");
	vs.push_back("29,39,21,50,93 14,11,19,83,4 22,12,44,49,13 12,");
	vs.push_back("4,31,24,98 14,32,51,37,55 2,26,65,47,66 7,4,1,1");
	vs.push_back(",37 31,35,90,58,55 20,36,62,71,1 3,9,19,87,86 6");
	vs.push_back(",24,11,25,35 40,46,6,4,78 30,27,91,79,67 14,4,4");
	vs.push_back("7,58,37 42,26,88,23,55 39,16,10,92,94 12,29,10,");
	vs.push_back("75,16 42,44,31,37,88 19,42,10,43,4 2,39,67,1,19");
	vs.push_back(" 10,3,72,54,64 44,19,83,34,28 28,13,54,16,10 20");
	vs.push_back(",33,97,7,27 9,38,91,24,87 41,21,94,76,88");


	int ret = t.find(47, vs, 301413357);


	cout << ret << endl;
	return 0;
}

//Args:
//{47, {"19,40,17,52,54 43,37,28,37,65 29,22,91,91,43 37", ",35,40,97,67 22,37,17,97,67 8,39,27,49,10 5,37,", "46,49,81 20,1,64,1,82 2,8,1,66,12 6,22,73,94,1 ", "8,25,11,42,1 28,34,79,85,74 4,16,3,22,53 23,14,", "45,1,5 31,40,27,15,85 47,44,75,34,52 42,27,63,3", "0,73 21,29,37,18,97 31,46,24,70,10 16,32,26,10,", "17 43,12,51,16,93 8,23,94,90,55 45,41,62,95,50 ", "5,31,77,30,35 20,34,40,79,67 11,39,82,46,43 4,2", "7,55,81,26 4,44,91,64,1 13,44,50,82,78 19,33,1,", "46,27 16,36,79,64,97 39,8,98,67,54 33,35,27,16,", "43 16,28,57,1,61 18,44,89,31,98 19,16,91,96,56 ", "6,9,46,97,43 44,26,84,61,9 31,28,61,28,84 43,3,", "90,96,8 1,10,21,4,20 27,19,46,10,82 33,10,81,56", ",88 25,1,3,17,53 31,18,93,78,21 1,27,69,43,48 2", "0,8,6,99,28 17,3,74,1,16 11,24,39,33,67 28,44,2", ",71,6 21,25,67,28,21 10,34,4,23,81 38,1,12,69,4", " 22,19,28,55,7 40,34,34,8,82 19,31,1,76,92 3,13", ",68,19,12 6,40,67,87,13 5,39,67,51,58 5,24,40,1", "6,79 16,25,35,37,22 35,28,58,43,46 5,47,34,56,1", "2 10,13,82,90,5 14,4,80,44,34 27,16,95,37,94 26", ",9,10,77,91 35,27,19,83,61 46,3,46,44,63 28,40,", "16,53,58 33,38,67,18,73 42,24,1,4,6 28,22,64,25", ",67 19,41,23,26,34 34,31,74,37,87 24,2,64,51,91", " 3,36,5,88,97 46,15,61,1,27 30,34,44,34,10 38,2", "1,28,76,46 45,21,31,26,64 38,27,49,86,89 19,41,", "56,43,14 20,41,47,88,36 26,21,49,12,45 19,21,55", ",67,67 27,46,13,33,19 25,28,82,78,98 31,19,8,1,", "3 27,15,1,46,22 6,27,82,1,79 28,18,31,55,99 37,", "24,95,42,28 16,21,52,37,82 1,32,93,3,52 4,10,9,", "87,76 25,42,91,15,52 12,35,89,73,6 7,34,42,46,9", "7 1,38,64,85,19 38,17,45,40,3 31,11,7,30,52 47,", "39,64,4,24 43,32,49,49,14 27,6,29,34,91 24,1,71", ",10,78 1,10,38,75,75 36,10,1,37,34 2,14,19,1,22", " 4,33,30,1,29 15,1,84,1,48 36,11,28,37,34 13,41", ",53,46,97 17,4,30,10,1 30,29,37,1,37 19,7,49,59", ",99 12,16,43,78,48 30,41,55,19,2 26,21,50,47,96", " 20,1,73,82,22 14,20,34,46,85 15,37,34,78,2 28,", "27,30,61,1 36,22,34,43,19 29,3,19,78,95 5,40,67", ",28,42 7,14,21,1,35 32,21,29,79,4 1,36,7,94,64 ", "29,39,21,50,93 14,11,19,83,4 22,12,44,49,13 12,", "4,31,24,98 14,32,51,37,55 2,26,65,47,66 7,4,1,1", ",37 31,35,90,58,55 20,36,62,71,1 3,9,19,87,86 6", ",24,11,25,35 40,46,6,4,78 30,27,91,79,67 14,4,4", "7,58,37 42,26,88,23,55 39,16,10,92,94 12,29,10,", "75,16 42,44,31,37,88 19,42,10,43,4 2,39,67,1,19", " 10,3,72,54,64 44,19,83,34,28 28,13,54,16,10 20", ",33,97,7,27 9,38,91,24,87 41,21,94,76,88"}, 301413357}
//
//Expected:
//-1
//
//Received:
//The code execution time exceeded the 2 second time limit.


