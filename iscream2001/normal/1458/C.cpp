#include<bits/stdc++.h>
#define LD long double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9;
const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=1000000007;
//const LL P=998244353;
const int N=1e6+10;
const LD eps=1e-6;
const LD eps2=1e-10;

int ran=0;
bool rand01(){
	while(!ran) ran=abs(rand());
	bool res=ran&1;ran>>=1;
	return res;
}

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
LL B_S2(LL *a,int l,int r,LL x){
	int mid;
	if(a[r]<x) return -1;
	while(l!=r){
		mid=(l+r)/2;
		if(a[mid]<x) l=mid+1;
		else r=mid;
	}
	return l;
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
//

//LL fac[1000005],finv[1000005];
//LL C(LL x,LL y,LL mod=M){
//	if(x<y) return 0;
//	if(x<=1000000) return fac[x]*finv[y]%mod*finv[x-y]%mod;
//	LL re=1;
//	y=min(y,x-y);
//	for(LL i=x-y+1;i<=x;++i){
//		re=re*(i%M)%M;
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
//
//LL S2[2005][2005];
//void initS2(){
//	S2[1][1]=1;
//	for(int i=2;i<=2000;i++){
//        for(int j=1;j<=i;j++){
//            S2[i][j]=(S2[i-1][j-1]+j*S2[i-1][j])%M;
//        }
//    }
//}
//
//
//
//LL cal_S2(LL n,LL m){
//	LL re=0,now;
//	for(LL k=0;k<=m;++k){
//		now=qpow(m-k,n,M)*C(m,k,M)%M;
//		if(k&1) re-=now;
//		else re+=now;
//	}
//	re=(re%M+M)%M;
//	re=re*finv[m]%M; 
//	return re;
//}



//struct P{
//	LD x,y;
//	P(LD _x=0,LD _y=0){x=_x;y=_y;}
//}used,a[1050],b[550];
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
//
//double rad(double d){
//    return d*PI/180.0;
//}
//double cal(double lat1,double lng1,double lat2,double lng2){
//	double a,b,radLat1 = rad(lat1),radLat2 = rad(lat2);
//    a = radLat1 - radLat2;
//    b = rad(lng1) - rad(lng2);
//    double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
//    return s;
//}


int n,m;
int a[1005*1005][3],ans[1005][1005];
int pos[3],mov[3];
char s[100005];
void MAIN(){
	int cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			++cnt;
			a[cnt][0]=i;
			a[cnt][1]=j;
			cin>>a[cnt][2];
		}
	}
//	for(int i=1;i<=cnt;++i){
//		int x=a[i][pos[0]],y=a[i][pos[1]],z=a[i][pos[2]];
//		cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
//	}
	pos[0]=0;pos[1]=1;pos[2]=2;
	mov[0]=0;mov[1]=0;mov[2]=0;
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;++i){
		if(s[i]=='R') ++mov[pos[1]];
		if(s[i]=='L') --mov[pos[1]];
		if(s[i]=='D') ++mov[pos[0]];
		if(s[i]=='U') --mov[pos[0]];
		if(s[i]=='I') swap(pos[1], pos[2]);
		if(s[i]=='C') swap(pos[0], pos[2]);
	}
//	cout<<"now "<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<endl; 
//	cout<<"now "<<mov[0]<<" "<<mov[1]<<" "<<mov[2]<<endl; 
	for(int i=1;i<=cnt;++i){
		int x=a[i][pos[0]],y=a[i][pos[1]],z=a[i][pos[2]];
//		cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
		x+=mov[pos[0]];x%=n;if(x<=0) x+=n;
		y+=mov[pos[1]];y%=n;if(y<=0) y+=n;
		z+=mov[pos[2]];z%=n;if(z<=0) z+=n;
		ans[x][y]=z;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
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
//	initS2();
	
	int ttt=1;cin>>ttt; 
	for(int i=1;i<=ttt;++i){
//		printf("Case %d: ",i);
		//printf("Case #%d: ",i);
		MAIN();
	}
	return 0;
}
/*

p[q[i]]=i
id 1 2 3 4 5
p  4 2 1 3 5
q  3 2 4 1 5
(1,4)
(2,2)
(3,1)
(4,3)
(5,5)

(1,3)
(2,2)
(3,4)
(4,1)
(5,5)
*/