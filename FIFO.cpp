#include<bits/stdc++.h>
using namespace std;
int n;//表示系统所允许的最大的页面数 
queue<int> q;//表示系统内部的页面情况
int ans;//表示页面置换的次数 
bool check(int x){//判断页面是否需要置换 
	if(q.size()==0){
		printf("此时系统内页面为空，%d页面进入系统。\n",x);
		q.push(x); 
		return true;
	}
	if(q.size()<n){
		int flag=0;
		queue<int> qq;
		while(!q.empty()){
			int res=q.front();
			if(res==x) flag=1;
			qq.push(res);
			q.pop();
		}
		while(!qq.empty()){
			q.push(qq.front());
			qq.pop();
		}
		if(flag){
			printf("%d页面已在系统中，无需置换。\n",x);
		}
		else {
			printf("%d页面不在系统中，系统未满，无需置换。\n",x);
			q.push(x); 
		}
		return true;
	}
	int flag=0;
	queue<int> qq;
	while(!q.empty()){
		int res=q.front();
		if(res==x) flag=1;
		qq.push(res);
		q.pop();
	}
	while(!qq.empty()){
		q.push(qq.front());
		qq.pop();
	}
	if(flag){
		printf("%d页面已在系统中，无需置换。\n",x);
		return true;
	}
	else {
		return false;
	}
}
int main(){
	freopen("rand.in","r",stdin); 
	freopen("FIFO.out","w",stdout);
	scanf("%d",&n);
	int x;
	while(scanf("%d",&x)&&x>=0){
		if(!check(x)){
			printf("%d页面不在系统中，系统已满，需要置换。\n",x);
			q.pop();
			q.push(x); 
			ans++;
		} 
	} 
	printf("页面置换次数%d\n",ans);
	return 0;
}
