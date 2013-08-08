/*
 * 500.cpp
 *
 *  Created on: 2013/08/01
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


class BatchSystemRoulette{
public:

	vector<double> expectedFinishTimes(vector<int> duration, vector<string> user){


		map<string, long> mp;
		for(int i = 0; i < user.size(); i++){
			if(mp.find(user[i]) == mp.end()){
				mp[user[i]] = 0;
			}
			mp[user[i]] += duration[i];
		}

		vector<long> vec;
		set<long> set;

		map<long, int> rmap;

		for(map<string,long>::iterator it = mp.begin(); it != mp.end(); it++){
			long val = (*it).second;
			if(set.find((*it).second) == set.end()){
				vec.push_back((*it).second);
			}
			set.insert((*it).second);
			if(rmap.find((*it).second) == rmap.end()){
				rmap[(*it).second] = 1;
			}
			else{
				rmap[(*it).second]++;
			}
		}
		sort(vec.begin(), vec.end());

		map<string, double> befm;
		long add = 0;

		for(int i = 0; i < vec.size(); i++){
			long sum = vec[i];
			int cnt = rmap[sum];
			double nadd = add + (cnt - 1) * sum  / 2.0;

			for(map<string,long>::iterator it = mp.begin(); it != mp.end(); it++){
				if((*it).second == sum){
					befm[(*it).first] = nadd;
				}
			}
			add += sum * cnt;
		}

		vector<double> ans;
		for(int i = 0; i < duration.size(); i++){
			double add = befm[user[i]];
			double sum = mp[user[i]];
			double a = add + (sum - duration[i]) / 2 + duration[i];
			ans.push_back(a);
		}

		return ans;
	}

};

int main(){
	BatchSystemRoulette c;
	vector<int> d;
	vector<string> u;

	int ti[5] = {13, 14, 15, 56, 56};
	string ts[5] = {"Tim Speedle", "Tim Speedle", "Tim Speedle", "Horatio Caine", "YEEEAAAAAAAAAAH"};
	for(int i = 0; i < 5; i++){
		d.push_back(ti[i]);
		u.push_back(ts[i]);
	}

	vector<double> r = c.expectedFinishTimes(d, u);
	for(int i = 0; i < r.size(); i++){
		cout << r[i] << endl;
	}

	return 0;
}

