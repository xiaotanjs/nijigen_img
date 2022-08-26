#include<iostream>
typedef long long ll;

using namespace std;
//n的二进制表示中第k位（从左到右）数字是什么:
	/*
	1.先将第k位移到最后一位n >> k
	2.看最后一位是几 & 1
	*/
	int bsk(int n,int k){
		return n>>k&1;
	}

ll mul(ll a,ll b,ll mod=100000000);
//快速幂：
ll qpow(ll a,ll b,ll mod){//求a的b次方,mod表示输出后n位（不包括前导0），则mod为1后面跟n个0
	ll ans=1;
	while(b!=0){
		if(b&1){//b的二进制位（最后一位）不为0，则进行
			ans=mul(ans,a)%mod;
		}
		a=mul(a,a)%mod;
		b>>=1; 
	}
	return ans%mod;
}

//龟速乘：(可防止数据溢出)
ll mul(ll a,ll b,ll mod){//求a乘b,mod表示输出后n位（不包括前导0），则mod为1后面跟n个0
	ll ans=0;
	while(b!=0){
		if(b&1){//b的二进制位（最后一位）不为0，则进行
			ans=(ans+a)%mod;
		}
		a=(a<<1)%mod; //等价于a*2%mod
		b>>=1; 
	}
	return ans%mod;
}
//lowbit返回x的二进制最低位1出现时所对应的值：
/*
在c++中 x & -x = x & (~x + 1)
*/
int lowbit(int x){
	return x&-x;
}
int main(){
	//通过&运算符（每位都是1则1，否则为0）判断最后一位的数：
	int a=100;
	cout<<(a&1)<<endl;
	//
	//输出1024二进制的第1~9位:
	for(int i=1;i<=10;i++){
		cout<<bsk(1024,i)<<' ';
	}
	cout<<endl;
	//截取18767二进制的第3~12位并按原二进制顺序输出:
	for(int i=12;i>=3;i--){
		cout<<bsk(18767,i)<<' ';
	}
	cout<<endl;
	//输出23456的二进制：
	int top=0,b[1000];
	int t=23456;
	while(t!=0){
		b[top++]=t&1;
		t>>=1;
	}
	while(top>=0){
		cout<<b[--top];
	}
	cout<<endl;
	//快速幂输出：
	cout<<qpow(2,10,1000)<<' '<<qpow(2,10,100)<<' '<<qpow(2,10,10000)<<endl;
	//龟速乘输出：
	cout<<mul(999999,999999)<<endl;
	//lowbit输出(12)10=(1100)2：
	cout<<lowbit(12)<<endl;
	//lowbit应用：
	//统计二进制n中1的个数：
	int ans=0;
	int n=240;
	while(n>0){
		n-=lowbit(n);
		ans++;
	}
	cout<<ans<<endl;
	int x=333,y=878;
    cout<<(x^qpow(2,3,100))<<endl;//将x的低4位取反
    cout<<(y^32)<<endl;//将x的低6（32=2的5次方）位取反
	cout<<(~0);
}
