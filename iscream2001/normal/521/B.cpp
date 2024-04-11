#include<bits/stdc++.h>
#define LD long double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
//LL M=1e9+7;
LL mod=1e9+9;
//const LL P=998244353;
const int N=1e6+10;
const LD eps=1e-11;
const LD eps2=1e-10;
//
LL qpow(LL x,LL y,LL mod=998244353){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
	}
	return re;
}

int lowbit(int x){
	return (x&-x);
}
int popcount(int x){
	return x==0?0:1+popcount(x-lowbit(x));
}

LL getphi(LL x){
	LL re=1;
	for(LL i=2;i*i<=x;++i){
		if(x%i==0){
			x/=i;re*=(i-1);
			while(x%i==0){
				x/=i;
				re*=i;
			}
		}
	}
	if(x>1){
		re=re*(x-1);
	}
	return re;
}

//struct jz{
//	LL x[12][12];
//};
//jz operator * (jz A,jz B){
//	jz C;
//	for(int i=1;i<=9;++i){
//		for(int j=1;j<=9;++j){
//			C.x[i][j]=0;
//		}
//	}
//	for(int i=1;i<=9;++i){
//		for(int k=1;k<=9;++k){
//			if(A.x[i][k]!=0){
//				for(int j=1;j<=9;++j){
//					(C.x[i][j]+=A.x[i][k]*B.x[k][j]%M)%=M;
//				}
//			}
//		}
//	}
//	return C;
//}
////inline char gc(){return getchar();}
//bool is_pri[N+10];
//LL pri[6000000];
////int mu[N+10];
//int cntp=0;
//
//void init_pri(){
////	mu[1]=1;
//    for(int i=2;i<=N;++i){
//        if(!is_pri[i]) {
//            pri[++cntp]=i;
//  //          mu[i]=-1;
//        }
//        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
//            is_pri[pri[j]*i]=1;
//            if(i%pri[j]==0) {
//    //        	mu[pri[j]*i]=0;
//                break;
//            }
//            else{
//      //      	mu[pri[j]*i]=-mu[i];
//			}
//        }
//    }
//}

//struct P{
//	LD x,y;
//	P(LD _x=0,LD _y=0){x=_x;y=_y;}
//}used,a[550],b[550];
//
//LD dis(P x){return x.x*x.x+x.y*x.y;}
//P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
//P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
//LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
//P operator * (P x,LD y){return P(x.x*y,x.y*y);}
//LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}
//P operator / (P x,LD y){return P(x.x/y,x.y/y);}
//P dwh(P x){LD w=sqrt(dis(x));return x/w;}
//
//LL fac[1000005],finv[1000005];
//LL C(LL x,LL y,LL mod=M){
//	if(x<y) return 0;
//	if(x<=1000000) return fac[x]*finv[y]%mod*finv[x-y]%mod;
//	LL re=1;
//	y=min(y,x-y);
//	for(LL i=x-y+1;i<=x;++i){
//		re=re*i%M;
//	}
//	re=re*finv[y]%M;
//	return re;
//}
//void init(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
//	finv[1000000]=qpow(fac[1000000],M-2,M);
//	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
//	return;
//}

#define mp make_pair

LL n,x[100010],y[100010],ans[100010];
bool vis[100010];
priority_queue<LL> maxi;
priority_queue<LL,vector<LL>,greater<LL> > mini;
map<pair<LL,LL>,LL> M;

bool check(int a,int b){
	if(M[mp(a,b+1)]&&M[mp(a-1,b)]==0&&M[mp(a+1,b)]==0)
		return 0;
	if(M[mp(a-1,b+1)]&&M[mp(a-1,b)]==0&&M[mp(a-2,b)]==0)
		return 0;
	if(M[mp(a+1,b+1)]&&M[mp(a+1,b)]==0&&M[mp(a+2,b)]==0)
		return 0;
	return 1;
}

void update(int a,int b){
	if(M[mp(a,b-1)]&&check(a,b-1)){
		maxi.push(M[mp(a,b-1)]);
		mini.push(M[mp(a,b-1)]);
	}
	if(M[mp(a-1,b-1)]&&check(a-1,b-1)){
		maxi.push(M[mp(a-1,b-1)]);
		mini.push(M[mp(a-1,b-1)]);
	}
	if(M[mp(a+1,b-1)]&&check(a+1,b-1)){
		maxi.push(M[mp(a+1,b-1)]);
		mini.push(M[mp(a+1,b-1)]);
	}
	return;
}
void MAIN(){
	int u,v;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		M[mp(x[i],y[i])]=i;
	}
	for(int i=1;i<=n;i++)
		if(check(x[i],y[i])){
			maxi.push(M[mp(x[i],y[i])]);
			mini.push(M[mp(x[i],y[i])]);
		}
	for(int i=1;i<=n;i++){
		if(i%2){
			ans[i]=maxi.top();
			maxi.pop();
		}
		else {
			ans[i]=mini.top();
			mini.pop();
		}
		int t=ans[i];
		if(vis[t]||check(x[t],y[t])==0){
			i--;
			continue;
		}
		vis[t]=1;
		M.erase(mp(x[t],y[t]));
		update(x[t],y[t]);
	}
	int s=0,cj=1;
	for(int i=n;i>=1;i--){
		s=(s+(ans[i]-1)*cj%mod)%mod;
		cj=cj*n%mod;
	}
	cout<<s;
	return;
}

int main(){
	srand(time(0));
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
//	init_pri();
	int ttt=1;//cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*
aabbab
1 1 2 3 2 3
*/