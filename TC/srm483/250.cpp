/*
 * 250.cpp
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
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
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


class BestApproximationDiv1{

public:
	string findFraction(int maxDen, string number){

		int cnt = -1;
		int bo = 0;
		int si = 0;

		for(int i = 1; i <= maxDen; i++){
			for(int j = 0; j < i; j++){
				string r = get(j, i);
				int c = 0;
				for(int k = 0; k < 6; k++){
					if(number[2 + k] != r[k]){
						break;
					}
					c++;
				}
				if(c > cnt){
					bo = i;
					si = j;
					cnt = c;
				}
				else if(c == cnt){
					if(bo > i){
						bo = i;
						si = j;
					}
					else if(bo == i){
						if(si > j){
							si = j;
						}
					}
				}
			}
		}
		string bos = intTostring(bo);
		string sis = intTostring(si);
		string cns = intTostring(cnt + 1);
		string has = sis + "/" + bos + " has ";
		string end = "exact " + cns + " digits";
		string ret = has + end;
		return ret;
	}

	string get(int si, int bo){
		string ret = "";
		for(int i = 0; i < 6; i++){
			si *= 10;
			int s = si / bo;
			char c = '0' + s;
			ret += c;
			si -= s * bo;
		}

		return ret;
	}

	string intTostring(int n){
		stringstream ss;
		ss << n;
		return ss.str();
	}
};

//int main(){
//	BestApproximationDiv1 b;
//	string r = b.findFraction(100, "0.909999");
//	cout << r << endl;
//	return 0;
//}
