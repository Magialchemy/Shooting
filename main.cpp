#include "precom.h"
#include "control.h"

//�L�[�擾�p�z��
char key[256];

int g_count;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	SetGraphMode( winwidth , winheight , 32 ) ;
	SetWindowSizeExtendRate( 2.0 );
	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}


	CONTROL *control = new CONTROL;



	while(ScreenFlip()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll(key)==0){
		
		control->All();
		
	}


	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}