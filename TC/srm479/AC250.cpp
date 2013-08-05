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
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}


class TheCoffeeTimeDivOne{

public:
	long long find(int n, vector<int> tea){
		long long ans = 0;
		sort(tea.begin(), tea.end());
		int tn = tea.size();
		{
			vector<pair<int, int> > tv;
			int idx = 0;
			while(idx < tea.size()){
				int first = tea[idx];
				int second = first;
				while(idx < tea.size() -1 && tea[idx+1] == second + 1){
					idx++;
					second++;
				}
				pair<int, int> p;
				p.first = first;
				p.second = second;
				tv.push_back(p);
				idx++;
			}
			ans += get(tv);
		}
		if(tn < n){
			vector<pair<int, int> > cv;
			if(tea.size() == 0){
				pair<int, int> p;
				p.first = 1;
				p.second = n;
				cv.push_back(p);
			}
			else{
				if(tea[0] != 1){
					pair<int, int> p;
					p.first = 1;
					p.second = tea[0] -1;
					cv.push_back(p);
				}

				for(int i = 0; i < tea.size() - 1; i++){
					if(tea[i] != tea[i+1] -1){
						pair<int, int> p;
						p.first = tea[i]+1;
						p.second = tea[i+1]-1;
						cv.push_back(p);
					}
				}

				if(tea[tea.size() - 1] != n){
					pair<int, int> p;
					p.first = tea[tea.size() - 1] +1;
					p.second = n;
					cv.push_back(p);
				}
			}

			ans += get(cv);
		}
		return ans;
	}

	long long get(vector<pair<int, int> > dt){
		long long ans = 0;
		if(dt.size() == 0){
			return ans;
		}

		int size = 0;
		for(int i = 0; i < dt.size(); i++){
			size += dt[i].second - dt[i].first + 1;
		}
		int cnt = size / 7;
		if(size % 7 > 0){
			cnt++;
		}
		ans += (long long)47 * cnt;
		ans += (long long)size * 4;


		int rem = size % 7;
		if(rem == 0){
			rem = 7;
		}

		//ans += (long long) 2 * dt[dt.size()].second;

		for(int i = 0; i < dt.size(); i++){
			int sz = dt[i].second - dt[i].first + 1;
			if(sz >= rem){
				int st = dt[i].first + rem - 1;
				int ed = 0;
				for(int j = 0; j < 7; j++){
					if(st % 7 == (dt[i].second - j) % 7){
						ed = dt[i].second - j;
					}
				}

				if(st == ed){
					ans += st * 2;
				}
				else{
					long long num = (ed - st) / 7 + 1;
					ans += (ed + st) * num / 2 * 2;
				}

				rem = 7 - (dt[i].second - ed);
			}
			else{
				rem -= sz;
			}
		}


		return ans;
	}


};





