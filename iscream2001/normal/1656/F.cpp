#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
//const LD PI=acos(-1.0);
const LL M=998244353;
//const LL M=1e9+7;
const int N=3e5+10;
const LD eps=1e-8;
const LD eps2=1e-10;
//
LL qpow(LL x,LL y,LL mod=M){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
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
//
//
//
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

__int128_t ans;

void cal(LL K,LL B,LL L,LL R){
	__int128_t re;
	re=L;re*=K;re+=B;if(re>(__int128_t)ans) ans=re;
	re=R;re*=K;re+=B;if(re>(__int128_t)ans) ans=re;
	return;
}
const LL inf=1e18;
int n;
LL a[N],b[N],sum[N];
vector<int> V[N];

void MAIN(){
	int u,v;
	cin>>n;ans=-INF;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	LL val;
	val=a[1]*(LL)(n-1);
	for(int i=2;i<=n;++i){
		val+=a[i];
	}
	if(val>0) {
		cout<<"INF\n";
		return;
	}
	val=a[n]*(LL)(n-1);
	for(int i=1;i<n;++i){
		val+=a[i];
	}
	if(val<0) {
		cout<<"INF\n";
		return;
	}
	LL now=-inf;
	LL K=0,B=0;
	for(int i=1;i<n;++i){
		B+=a[i]*a[n];
		K+=a[i]+a[n];
	}
	cal(K,B,now,-a[n]);
	now=-a[n];
	for(int i=n-1;i>1;--i){
		cal(K,B,now,-a[i]);
		B-=a[i]*a[n];
		K-=a[i]+a[n];
		B+=a[i]*a[1];
		K+=a[i]+a[1];
		now=-a[i];
	}
	cal(K,B,now,inf);
	LL re=ans;
	cout<<re<<"\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
//	init_pri();
	int ttt=1;cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*

4 3
0 0
1 0
1 1
0 1
*/