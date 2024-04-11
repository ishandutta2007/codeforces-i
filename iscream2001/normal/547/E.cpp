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
const int N=5e5+10;
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
vector<int> st[N];
int num[N];
queue<int>que;
struct ACAutoMaton{
    int c[N][26],fail[N],cnt;
    void init(){
    	cnt=0;
    	memset(c[cnt],0,sizeof(c[cnt]));
	}
    int ins(char *s){
        int len=strlen(s);int now=0;
        for(int i=0;i<len;i++){
            int v=s[i]-'a';
            if(!c[now][v]){
            	c[now][v]=++cnt;
            	memset(c[cnt],0,sizeof(c[cnt]));
			}
            now=c[now][v];
        }
        return now;
    }
    void build(){
        for(int i=0;i<26;i++) if(c[0][i]) {
        	fail[c[0][i]]=0;
			que.push(c[0][i]);
		}
        while(!que.empty()){
            int u=que.front();que.pop();
            for(int i=0;i<26;i++){
            	if(c[u][i]){
            		fail[c[u][i]]=c[fail[u]][i];
					que.push(c[u][i]);
				}
				else c[u][i]=c[fail[u]][i];
			}
            
        }
    }
}AC;

char s[N];

int ans[N];

vector<int> V[N];

int tot;
int L[N],R[N];
void dfs(int x){
	L[x]=++tot;
	for(auto y:V[x]){
		dfs(y);
	}
	R[x]=tot;
}

int t[N];
void add(int x,int w){
	while(x<=tot){
		t[x]+=w;
		x+=lowbit(x);
	}
}
int ask(int x){
	int re=0;
	while(x>0){
		re+=t[x];
		x-=lowbit(x);
	}
	return re;
}
struct query{
	int x,r,id,f;
}q[N<<1];
void MAIN(){
	int u,v,w;
	cin>>n>>Q;
	AC.init();
	for(int i=1;i<=n;++i){
		st[i].clear();
		cin>>s;
		num[i]=AC.ins(s);
		st[i].pb(0);
		int now=0,len=strlen(s);
		for(int j=0;j<len;++j){
			v=s[j]-'a';
            now=AC.c[now][v];
            st[i].pb(now);
		}
	}
	AC.build();
	m=AC.cnt;
	for(int i=0;i<=m;++i) V[i].clear();
	for(int i=1;i<=m;++i){
		V[AC.fail[i]].pb(i);
//		cout<<AC.fail[i]<<" ";
	}
//	cout<<endl;
	tot=0;
	dfs(0);
//	for(int i=0;i<=m;++i) cout<<L[i]<<" "<<R[i]<<endl;
	for(int i=1;i<=Q;++i){
		cin>>u>>v>>w;
		q[i].f=-1;q[i].id=i;q[i].x=w;q[i].r=u-1;
		q[i+Q].f=1;q[i+Q].id=i;q[i+Q].x=w;q[i+Q].r=v;
		ans[i]=0;
	}
	sort(q+1,q+1+Q+Q,[&](query &x,query &y){
		return x.r<y.r;
	});
	for(int i=1,j=0;i<=Q+Q;++i){
		while(j<q[i].r){
			++j;
			for(auto z:st[j]){
				add(L[z],1);
			}
		}
		ans[q[i].id]+=q[i].f*ask(R[num[q[i].x]]);
		ans[q[i].id]-=q[i].f*ask(L[num[q[i].x]]-1);
	}
	for(int i=1;i<=Q;++i) cout<<ans[i]<<"\n";
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