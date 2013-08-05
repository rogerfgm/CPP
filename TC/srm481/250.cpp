/*
 * 250.cpp
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


class ChickenOracle{
public:


	string theTruth(int n, int egg, int lieCount, int liarCount){
		int fegg = 0;
		int fchi = 0;

		int chi = n - egg;

		int tmpbig = max(lieCount, liarCount);
		int tmpsmall = min(lieCount, liarCount);
		int remain = n - tmpbig;

		int large = 0;
		if(remain < tmpsmall){
			large = tmpbig - (tmpsmall - remain);
		}
		else{
			large = lieCount + liarCount;
		}



		int small = abs(lieCount - liarCount);
		{
			if(egg >= small && egg <= large){
				fchi = 1;
			}
			if(chi >= small && chi <= large){
				fegg = 1;
			}
		}

		string ans;
		if(fegg && fchi){
			ans = "Ambiguous";
		}
		else if(fegg){
			ans = "The egg";
		}
		else if(fchi){
			ans = "The chicken";
		}
		else{
			ans = "The oracle is a lie";
		}
		return ans;
	}
};

int main(){
	ChickenOracle c;

	string r = c.theTruth(1, 1, 1, 1);
	cout << r << endl;
	return 0;
}


//Problem: 250
//Test Case: 4
//Succeeded: No
//Execution Time: 0 ms
//Args:
//{1, 1, 1, 1}
//
//Expected:
//"The egg"
//
//Received:
//"Ambiguous"
