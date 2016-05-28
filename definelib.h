#define winwidth 240
#define winheight 160
#define stageheight 120
#define shanspeed 3
#define scrollspeed 2
#define pi 3.1415926535f
#define shotlimit 6
#define shotspeed 6

#include <windows.h>
//メッセージボックス
#define MSG(m) {\
	MessageBox(NULL,m,"メッセージ",MB_OK);}

//extern宣言してkey配列にどこからでもアクセスできるようにする
extern char key[256];

extern int g_count;

struct SHOT{
	bool flag;//弾が発射中かどうか
	double x;//x座標
	double y;//y座標
	int gh;//グラフィックハンドル
	int width;
	int height;//画像の幅と高さ
};