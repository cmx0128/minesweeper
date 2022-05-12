#include<bits/stdc++.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
double x,y; 
void abc(int y,int x){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void shubiao() {	
	POINT a1;HWND h=GetForegroundWindow(); GetCursorPos(&a1); ScreenToClient(h,&a1);
	x=double(a1.y)/16,y=double(a1.x)/16;
	return;
}
bool a[50][50],f[50][50];
int b[50][50],i,j,h,k=225,d[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
void dfs(int c,int g){
	if(c<1||c>15||g<1||g>15)return;
	if(b[c][g]==-1)return;
	if(f[c][g])return;
	f[c][g]=1;
	a[c][g]=1;
	abc(c-1,g*2-2);
	printf(" %c",b[c][g]==0?' ':char(b[c][g]+48));
	if(b[c][g]>0)return;
	for(int o=0;o<8;o++){
		dfs(c+d[o][0],g+d[o][1]);
	}
}
int main()
{
	srand(time(0));
	for(i=1;i<=7;i++)cout<<' ';
	cout<<"É¨À×\n";
	system("pause");
	system("cls");
	for(i=1;i<=25;i++){
		int u=rand()%15+1,v=rand()%15+1;
		while(b[u][v]==-1)u=rand()%15+1,v=rand()%15+1;
		b[u][v]=-1;
	}
	for(i=1;i<=15;i++){
		for(j=1;j<=15;j++){
			if(b[i][j]==0)
				for(h=0;h<8;h++)
					if(b[i+d[h][0]][j+d[h][1]]==-1)b[i][j]++;
			cout<<"¡ö";
		}
		cout<<endl;
	}
	while(k!=25){
		if(KEY_DOWN(MOUSE_MOVED)){
		
			shubiao();
			a[int(x)+1][int(y)+1]=1;
			if(b[int(x)+1][int(y)+1]==-1){
				cout<<">>";
				abc(int(x),int(y)*2);
				cout<<"£¿";
				Sleep(100);
				abc(int(x),int(y)*2);
				cout<<"£¡";
				Sleep(100);
				abc(int(x),int(y)*2);
				cout<<"¡ð";
				Sleep(100);
				abc(15,32);
				return 0;
			}
			else{
				memset(f,0,sizeof(f));
				dfs(int(x)+1,int(y)+1);
			}
		}
		k=0;
		for(i=1;i<=15;i++)
			for(j=1;j<=15;j++)
				if(!a[i][j])k++;
		abc(15,32);
	}
	abc(0,0);
	for(i=1;i<=15;i++){
		for(j=1;j<=15;j++){
			if(b[i][j]==-1)cout<<"£¤";
			else cout<<' ';
		}
		Sleep(50);
		cout<<endl;
	}
	cout<<"³É¹¦!";
	return 0;
}
