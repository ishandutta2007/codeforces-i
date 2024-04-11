#include<bits/stdc++.h>
#define LD double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=998244353;
//const LL P=998244353;
const int N=1e6+10;
const LD eps=1e-11;
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

int B_S(int *a,int l,int r,int x){
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x) return mid;
		a[mid]>x?r=mid-1:l=mid+1;
	}
	return -1;
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
//P rotate(P x,LD th){return P(x.x*cos(th)-x.y*sin(th),x.x*sin(th)+x.y*cos(th));}
//
//P waixin(LD x1,LD y1,LD x2,LD y2,LD x3,LD y3){
//double a,b,c,p;
//double  aa,bb,zz,aa1,bb1,zz1;
//	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//    b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
//    c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
//    aa=2*(x1-x2);
//    bb=2*(y1-y2);
//    zz=x1*x1-x2*x2+y1*y1-y2*y2;
//    aa1=2*(x3-x2);
//    bb1=2*(y3-y2);
//    zz1=x3*x3-x2*x2+y3*y3-y2*y2;
//    printf("%.2lf %.2lf\n",((zz*bb1)-(zz1*bb))/((aa*bb1)-(aa1*bb)),
//           ((aa*zz1)-(aa1*zz))/((aa*bb1)-(aa1*bb)));
//    return P(((zz*bb1)-(zz1*bb))/((aa*bb1)-(aa1*bb)),
//           ((aa*zz1)-(aa1*zz))/((aa*bb1)-(aa1*bb)));
//}

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
int n,m,Q;
vector<int> V[2][200005],us[200005];
int f[200005];
int l[2],r[2];
int q[2][2000000];
LL ans;
void bfs(int cur){
	l[0]=l[1]=1;r[0]=r[1]=0;
	for(int i=0;i<=n;++i){
		us[i].clear();
	}
	for(int i=1;i<=n;++i){
		if(f[i]<=n){
			us[f[i]].pb(i);
		}
	}
	for(int i=0;i<=n;++i){
		for(auto x:us[i]){
			q[0][++r[0]]=x;
		}
	}
	int x;
	while(l[0]<=r[0]||l[1]<=r[1]){
		if(l[0]>r[0]){
			x=q[1][l[1]++];
		}
		else if(l[1]>r[1]){
			x=q[0][l[0]++];
		}
		else{
			if(f[q[0][l[0]]]<f[q[1][l[1]]]){
				x=q[0][l[0]++];
			}
			else{
				x=q[1][l[1]++];
			}
		}
		for(auto y:V[cur][x]){
			if(f[x]+1<f[y]){
				f[y]=f[x]+1;
				q[1][++r[1]]=y;
			}
		}
	}
	return;
} 

LL dis[400005];
bool vis[400005];
void MAIN(){
	int u,v;
	cin>>n>>m;ans=INF;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		V[0][u].pb(v);
		V[1][v].pb(u);
	}
	f[1]=0;
	for(int i=2;i<=n;++i) f[i]=inf;
	int cur=0;
	for(int t=0;t<=18;++t){
		bfs(cur);
		if(f[n]+(1<<t)-1<ans){
			ans=f[n]+(1<<t)-1;
		}
		cur^=1;
	}
	if(ans!=inf){
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=n+n+1;++i){
		dis[i]=INF;
	}
	for(int i=1;i<=n;++i){
		if(f[i]!=inf){
			dis[i<<1]=(LL)f[i]+(LL)inf*18;
		}
	}
	l[0]=1;r[0]=0;
	for(int i=1;i<=n;++i){
		if(f[i]!=inf){
			dis[i<<1]=(LL)f[i]+(LL)inf*18;
			q[0][++r[0]]=i<<1;
			vis[i<<1]=1;
		}
	}
	while(l[0]<=r[0]){
		u=q[0][l[0]++];
		cur=u&1;
		u>>=1;
		for(auto y:V[cur][u]){
			if(dis[y<<1|cur]>dis[u<<1|cur]+1){
				dis[y<<1|cur]=dis[u<<1|cur]+1;
				q[0][++r[0]]=y<<1|cur;	
			}
		}
		if(dis[u<<1|(cur^1)]>dis[u<<1|cur]+inf){
			dis[u<<1|(cur^1)]=dis[u<<1|cur]+inf;
			q[0][++r[0]]=u<<1|(cur^1);
		}
	}
	ans=min(dis[n<<1],dis[n<<1|1]);
	LL sum=ans/inf;
	ans=ans%inf;
	LL re=1;
	while(sum--) re=(re+re)%M;
	re+=ans-1;
	cout<<(re%M+M)%M<<endl;
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
	for(int i=1;i<=ttt;++i){
		//printf("Case #%d: ",i);
		MAIN();
	}
	return 0;
} 
/*
123
*/