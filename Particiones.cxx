#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<double> particionar3(double total, vector<double> res, double init, int cc);
vector<double> particionar4(double total, vector<double> res, double init, int cc);

double g,m,c,t,v;

int main() {
	
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	double lima,limb;
	cout<<"Ecuaci�n gm/c *(1-e^-((c/m)*t)) -v"<<endl;
	m=61.8;
	g=9.8;
	t=10;
	v=40;
	
	cout<<"Limite inferior: ";
	cin>>lima;
	cout<<"Limite superior: ";
	cin>>limb;
	
	if(lima>limb){
		cout<<"El limite inferior no puede ser mayor al superior"<<endl;
		return 0;
	}
	vector<double> y;
	vector<double> res;
	
	for(double i = lima;i<limb; i++){
		c = i;
		y.push_back(g*m/c *(1-exp(-1*(c/m)*t))-v); 
	}
	for(int i=0;i<y.size();i++)
		cout<<y[i]<<endl;
		
	int part;
	cout<<"Numero de particiones (3-4): ";
	cin>>part;
	
	double total = limb-lima;
	if(part == 3){
		res = particionar3(total,res,lima, 0);
	}
	else{
		total = total / 4;
		res = particionar4(total,res,lima, 0);
	}

	return 0;
}

vector<double> particionar3(double total, vector<double> res, double init,int cc){
	double zer = init, one = init+(total/3), two = init+(total*2/3), tre = init+total;
	
	zer = g*m/zer *(1-exp(-1*(zer/m)*t))-v;
	one = g*m/one *(1-exp(-1*(one/m)*t))-v;
	two = g*m/two *(1-exp(-1*(two/m)*t))-v;
	tre = g*m/tre *(1-exp(-1*(tre/m)*t))-v;
	
	if(zer = 0){
		res.push_back(init);
		return res;
	}
	if(one = 0){
		res.push_back(init+(total/3));
		return res;
	}
	if(two = 0){
		res.push_back(init+(total*2/3));
		return res;
	}
	if(tre = 0){
		res.push_back(init+total);
		return res;
	}
	
	total = total/3;
	if(cc<=10){
		if(zer*one<0){
		res = particionar3(total,res, zer,cc+1);
		}if(one*two<0){
			res = particionar3(total,res, one,cc+1);
		}if(two*tre<0){
			res = particionar3(total,res, two,cc+1);
		}
	}
	else{
		if(zer*one<0){
			res.push_back((one-zer)/2);
		}if(one*two<0){
			res.push_back((two-one)/2);
		}if(two*tre<0){
			res.push_back((tre-two)/2);
		}
	}
	return res;
}

vector<double> particionar4(double total, vector<double> res, double init,int cc){
	double zer = init, one = init+(total/4), two = init+(total*2/4), tre = init+(total*3/4), fou = init+total;
	
	zer = g*m/zer *(1-exp(-1*(zer/m)*t))-v;
	one = g*m/one *(1-exp(-1*(one/m)*t))-v;
	two = g*m/two *(1-exp(-1*(two/m)*t))-v;
	tre = g*m/tre *(1-exp(-1*(tre/m)*t))-v;
	fou = g*m/tre *(1-exp(-1*(fou/m)*t))-v;
	
	if(zer = 0){
		res.push_back(init);
		return res;
	}
	if(one = 0){
		res.push_back(init+(total/4));
		return res;
	}
	if(two = 0){
		res.push_back(init+(total*2/4));
		return res;
	}
	if(tre = 0){
		res.push_back(init+(total*3/4));
		return res;
	}
	if(fou = 0){
		res.push_back(init+total);
		return res;
	}
	
	total = total/4;
	if(cc<=10){
		if(zer*one<0){
		res = particionar4(total,res, zer,cc+1);
		}if(one*two<0){
			res = particionar4(total,res, one,cc+1);
		}if(two*tre<0){
			res = particionar4(total,res, two,cc+1);
		}if(tre*fou<0){
			res = particionar4(total,res, tre,cc+1);
		}
	}
	else{
		if(zer*one<0){
			res.push_back((one-zer)/2);
		}if(one*two<0){
			res.push_back((two-one)/2);
		}if(two*tre<0){
			res.push_back((tre-two)/2);
		}if(tre*fou<0){
			res.push_back((fou-tre)/2);
		}
	}
	
	return res;
}

