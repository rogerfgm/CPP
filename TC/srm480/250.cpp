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

class InternetSecurity{

public:

	vector<string> determineWebsite(vector<string> address, vector<string> keyword, vector<string> dangerous, int threshold){

		set<string> ds;
		set<int> dsi;

		vector<vector<string> > kvs;
		for(int i = 0; i < keyword.size(); i++){
			string kwd = keyword[i];
			vector<string> ks = split(kwd, ' ');
			kvs.push_back(ks);
		}

		for(int i = 0; i < dangerous.size(); i++){
			ds.insert(dangerous[i]);
		}

		while(1){
			int flag = 0;
			for(int i = 0; i < address.size(); i++){
				if(dsi.find(i) != dsi.end()){
					continue;
				}
				int cnt = 0;
				vector<string> ks = kvs[i];
				for(int j = 0; j < ks.size(); j++){
					if(ds.find(ks[j]) != ds.end()){
						cnt++;
					}
				}
				if(cnt >= threshold){
					flag = 1;
					for(int j = 0; j < ks.size(); j++){
						ds.insert(ks[j]);
					}
					dsi.insert(i);
				}

			}

			if(!flag){
				break;
			}
		}
		vector<string> ans;
		for(int i = 0; i < address.size(); i++){
			if(dsi.find(i) != dsi.end()){
				ans.push_back(address[i]);
			}
		}

		return ans;
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
//
//int main(){
//	vector<string> add;
//	add.push_back("www.topcoder.com");
//	add.push_back("www.sindicate_of_evil.com");
//	add.push_back("www.happy_citizens.com");
//
//	vector<string> kwd;
//	kwd.push_back("hack encryption decryption internet algorithm");
//	kwd.push_back("signal interference evil snake poison algorithm");
//	kwd.push_back("flower baloon topcoder blue sky sea");
//
//	vector<string> ds;
//	ds.push_back("hack");
//	ds.push_back("encryption");
//	ds.push_back("decryption");
//	ds.push_back("interference");
//	ds.push_back("signal");
//	ds.push_back("internet");
//
//
//	InternetSecurity t;
//	vector<string> ret = t.determineWebsite(add, kwd, ds, 3);
//	for(int i = 0; i < ret.size(); i++){
//		cout << ret[i] << endl;
//	}
//	return 0;
//}


