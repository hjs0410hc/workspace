#include <bits/stdc++.h>
using namespace std;

int score = 2000;
double W,L,D;
double bronze{0},silver{0},gold{0},plat{0},dia{0};

int comb(int n,int r){
	if(n==r || r==0){
		return 1;
	}
	return comb(n-1,r-1)+comb(n-1,r);
}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> W>>L>>D;
	for(int i=0;i<=20;i++){
		for(int j=0;j<=20;j++){
			for(int p=0;p<=20;p++){
				if(i+j+p != 20){
					continue;
				}
				int tscore = 2000+50*i-50*j;
				
				double poss = comb(20,i)*pow(W,i) * comb(20-i,j)*pow(L,j) * comb(20-i-j,p)*pow(D,p);
				//cout << i << " " << j << " " << p << " " << fixed << setprecision(8) << poss << "\n";
				if(tscore >= 1000 && tscore <= 1499){
					bronze += poss;
				}else if(tscore >= 1500 && tscore <= 1999){
					silver += poss;
				}else if(tscore >= 2000 && tscore <= 2499){
					gold += poss;
				}else if(tscore >= 2500 && tscore <= 2999){
					plat += poss;
				}else if(tscore >= 3000 && tscore <= 3499){
					dia += poss;
				}
			}
		}
	}cout << fixed << setprecision(8) << bronze << "\n" << silver << "\n" << gold << "\n" << plat << "\n" << dia;
	
}