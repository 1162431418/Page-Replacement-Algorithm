#include<bits/stdc++.h>
using namespace std;
int n;//表示系统所允许的最大的页面数 
stack<int> s;//表示系统内部的页面情况
int ans;//表示页面置换的次数 
bool check(int x){//判断页面是否位于系统中 
	stack<int> ss; 
	bool flag=false;
	while(!s.empty()){
		int res=s.top();
		if(res==x){
			flag=true;
			printf("页面位于系统中，无需置换。\n");
			s.pop();
			continue;
		}
		ss.push(res);
		s.pop();	
	}
	while(!ss.empty()){
		int res=ss.top();
		s.push(res);
		ss.pop();	
	}
	return flag;
}
int main(){
	freopen("rand.in","r",stdin);
	freopen("LRU.out","w",stdout);
	scanf("%d",&n);
	int x;
	while(scanf("%d",&x)&&x>=0){
		if(s.size()==0){
			printf("此时系统内页面为空，%d页面进入系统。\n",x);
			s.push(x); 
		} 
		else if(s.size()<n){
			if(!check(x)){
				printf("%d页面不在系统中，此时系统内页面未满，%d页面进入系统。\n",x,x);
			}
			s.push(x);
		}
		else{
			if(!check(x)){
				printf("%d页面不在系统中，此时系统页面已满，页面置换。\n",x);
				ans++;
				stack<int> ss;
				while(s.size()!=1){
					ss.push(s.top());
					s.pop();
				} 
				s.pop();
				while(!ss.empty()){
					s.push(ss.top());
					ss.pop();
				}
			}
			s.push(x);
		}
	} 
	printf("页面置换次数%d\n",ans);
	return 0;
} 
