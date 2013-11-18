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

	int* used;
	int cn;
	int sn;
	int N;


public:
	int secureNetwork(vector<string> cli, vector<string> srv){
		cn = cli[0].length();
		sn = srv[0].length();
		vector<vector<int> > cf;
		for(int i = 0; i < cn; i++){
			vector<int> tmp;
			for(int j = 0; j < cn; j++){
				tmp.push_back(0);
			}
			cf.push_back(tmp);
		}
		for(int i = 0; i < cn; i++){
			for(int j = 0; j < cn; j++){
				if(cli[i][j] == 'Y'){
					cf[i][j] = 1;
				}
				else{
					cf[i][j] = 0;
				}
			}
		}

		int csf[cn][sn];
		for(int i = 0; i < srv.size(); i++){
			string s = srv[i];
			for(int j = 0; j < sn; j++){
				if(s[j] == 'Y'){
					csf[i][j] = 1;
				}
				else csf[i][j] = 0;
			}
		}

		int ans = 0;
		for(int i = 0; i < sn; i++){
			set<int> cset;
			for(int j = 0; j < cn; j++){
				if(csf[j][i]){
					cset.insert(j);
				}
			}
			set<int> cantset;
			while(true){
				int flag = 0;
				set<int>::iterator ite = cset.begin();
				while(ite != cset.end()){
					int target = *ite;
					if(cantset.find(target) != cantset.end()){
						ite++;
						continue;
					}
					set<int> vis;
					if(dfs(target, vis, cset, cf)){
						cset.erase(ite);
						flag = 1;
						break;
					}
					else{
						cantset.insert(target);
					}
					ite++;
				}
				if(!flag){
					break;
				}
			}
			ans += cset.size();
		}


		return ans;
	}

	int dfs(int p, set<int> vis, set<int> cset, vector<vector<int> > cf){

		vis.insert(p);
		for(int i = 0; i < cn; i++){
			if(i != p && vis.find(i) == vis.end() && cf[p][i]){
				if(cset.find(i) != cset.end()){
					return 1;
				}
				dfs(i, vis,cset, cf);
			}
		}
		return 0;
	}



};

int main(){

	vector<string> i1;
	vector<string> i2;

	i1.push_back("NYN");
	i1.push_back("NNN");
	i1.push_back("NYN");
	i2.push_back("YN");
	i2.push_back("YN");
	i2.push_back("NY");

	NetworkSecurity n;
	int ret = n.secureNetwork(i1, i2);
	cout << ret << endl;
	return 0;
}


/*
 *
 *
Problem: 450
Test Case: 29
Succeeded: No
Execution Time: 0 ms
Args:
{{"NNNNYNNYN", "YNNNYNNYN", "YNNYNNNYY", "NNNNNNNNN", "NNNNNNNNN", "NYNNYNNNN", "NYYYYYNNN", "NNNYNNNNN", "YNNNNNNYN"}, {"NNYN", "NNNY", "YYYN", "NYYY", "YYYY", "NYNY", "YYYY", "YYYN", "YYYY"}}

Expected:
8

Received:
11
 */

