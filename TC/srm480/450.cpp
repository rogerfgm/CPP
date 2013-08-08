/*
 * 250.cpp
 *
 *  Created on: 2013/07/31
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

// Segfault okinai
class NetworkSecurity{
	vector<vector<int> >G;
	int* used;
	int cn;
	int sn;
	int N;
public:
	int secureNetwork(vector<string> cli, vector<string> srv){
		cn = cli[0].length();
		sn = srv[0].length();

		N = cn + sn;

		for(int i = 0; i < N; i++){
			vector<int> v;
			G.push_back(v);
		}

		for(int i = 0; i < cli.size(); i++){
			string s = cli[i];
			for(int j = 0; j < s.length(); j++){
				if(s[j] == 'Y'){
					G[j].push_back(i);
				}
			}
		}
		for(int i = 0; i < srv.size(); i++){
			string s = srv[i];
			for(int j = 0; j < s.length(); j++){
				if(s[j] == 'Y'){
					G[cn + j].push_back(i);
				}
			}
		}

		int ans = 0;
		used = new int[cn];
		for(int j = 0; j < cn; j++) used[j] = 0;
		for(int i = 0; i < sn; i++){
			if(check(i + cn)){
				ans++;
			}
		}

		return ans;
	}

	int check(int idx){
		int ret = 0;
		if(idx < cn) used[idx] = 1;
		vector<int> v = G[idx];
		for(int i = 0; i < v.size(); i++){
			int to = v[i];
			if(used[to]) continue;
			ret = 1;
			check(to);
		}


		return ret;
	}

};

int main(){

	vector<string> i1;
	vector<string> i2;

//	i1.push_back("NYYY");
//	i1.push_back("NNYY");
//	i1.push_back("NNNY");
//	i1.push_back("NNNN");
//
//	i2.push_back("YYYYNNNNNNN");
//	i2.push_back("YYYNYYYNNNN");
//	i2.push_back("YYNNYYNYYNN");
//	i2.push_back("YNNNYNNYNYY");

	i1.push_back("N");
	i2.push_back("NYYYYYYYY");

	NetworkSecurity n;
	int ret = n.secureNetwork(i1, i2);
	cout << ret << endl;
	return 0;
}


//Problem: 450
//Test Case: 5
//Succeeded: No
//Execution Time: 0 ms
//Args:
//{{"NYYY", "NNYY", "NNNY", "NNNN"}, {"YYYYNNNNNNN", "YYYNYYYNNNN", "YYNNYYNYYNN", "YNNNYNNYNYY"}}
//
//Expected:
//11
//
//Received:
//uncaught exception
//
//
//
//Problem: 450
//Test Case: 9
//Succeeded: No
//Execution Time: 0 ms
//Args:
//{{"N"}, {"NYYYYYYYY"}}
//
//Expected:
//8
//
//Received:
//segmentation fault

