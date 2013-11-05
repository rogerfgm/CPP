/*
 * 500.cpp
 *
 *  Created on: 2013/08/06
 *      Author: dfukuda
 */

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


class Bribes{
	int dp[50][1<<16];
	int INF;
public:
	int minBribes(vector<int> inf, vector<int> res){
		INF = 10000000;

		for(int i = 0; i < 50; i++){
			for(int j = 0; j < 1 << 16; j++){
				dp[i][j] = INF;
			}
		}
		int ans = check(0, 0);
		return 0;
	}

	int check(int idx, int state){
		if(dp[idx][state] != INF){
			return dp[idx][state];
		}
		int cnt[8];
		for(int i = 0; i < 16; i++){

		}

		return 0;
	}

};

int main(){


	int iif[5] = { 10, 3, 5, 3, 1 };
	int rs[5] = { 11, 2, 7, 3, 1 };
	vector<int> inf;
	vector<int> res;
	for(int i = 0; i < 5; i++){
		inf.push_back(iif[i]);
		res.push_back(rs[i]);
	}
	Bribes b;
	int r = b.minBribes(inf, res);
	cout << r << endl;
}

