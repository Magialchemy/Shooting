#define winwidth 240
#define winheight 160
#define stageheight 120
#define shanspeed 3
#define scrollspeed 2
#define pi 3.1415926535f
#define shotlimit 6
#define shotspeed 6

#include <windows.h>
//���b�Z�[�W�{�b�N�X
#define MSG(m) {\
	MessageBox(NULL,m,"���b�Z�[�W",MB_OK);}

//extern�錾����key�z��ɂǂ�����ł��A�N�Z�X�ł���悤�ɂ���
extern char key[256];

extern int g_count;

struct SHOT{
	bool flag;//�e�����˒����ǂ���
	double x;//x���W
	double y;//y���W
	int gh;//�O���t�B�b�N�n���h��
	int width;
	int height;//�摜�̕��ƍ���
};