#include<bits/stdc++.h>
using namespace std;
int n;//��ʾϵͳ�����������ҳ���� 
queue<int> q;//��ʾϵͳ�ڲ���ҳ�����
int ans;//��ʾҳ���û��Ĵ��� 
bool check(int x){//�ж�ҳ���Ƿ���Ҫ�û� 
	if(q.size()==0){
		printf("��ʱϵͳ��ҳ��Ϊ�գ�%dҳ�����ϵͳ��\n",x);
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
			printf("%dҳ������ϵͳ�У������û���\n",x);
		}
		else {
			printf("%dҳ�治��ϵͳ�У�ϵͳδ���������û���\n",x);
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
		printf("%dҳ������ϵͳ�У������û���\n",x);
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
			printf("%dҳ�治��ϵͳ�У�ϵͳ��������Ҫ�û���\n",x);
			q.pop();
			q.push(x); 
			ans++;
		} 
	} 
	printf("ҳ���û�����%d\n",ans);
	return 0;
}
