#include<bits/stdc++.h>
using namespace std;
int n;//��ʾϵͳ�����������ҳ���� 
stack<int> s;//��ʾϵͳ�ڲ���ҳ�����
int ans;//��ʾҳ���û��Ĵ��� 
bool check(int x){//�ж�ҳ���Ƿ�λ��ϵͳ�� 
	stack<int> ss; 
	bool flag=false;
	while(!s.empty()){
		int res=s.top();
		if(res==x){
			flag=true;
			printf("ҳ��λ��ϵͳ�У������û���\n");
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
			printf("��ʱϵͳ��ҳ��Ϊ�գ�%dҳ�����ϵͳ��\n",x);
			s.push(x); 
		} 
		else if(s.size()<n){
			if(!check(x)){
				printf("%dҳ�治��ϵͳ�У���ʱϵͳ��ҳ��δ����%dҳ�����ϵͳ��\n",x,x);
			}
			s.push(x);
		}
		else{
			if(!check(x)){
				printf("%dҳ�治��ϵͳ�У���ʱϵͳҳ��������ҳ���û���\n",x);
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
	printf("ҳ���û�����%d\n",ans);
	return 0;
} 
