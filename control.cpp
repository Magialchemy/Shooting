#include "precom.h"
#include "control.h"

CONTROL::CONTROL()
{
	//�v���C���[�N���X�̐���
	player = new PLAYER;

	back = new BACK;

	enemy = new ENEMY;
}

void CONTROL::All()
{
	SetDrawArea(0,0,winwidth,winheight);
	//�w�i�`�悪��
	back->All();
	//�v���C���[�N���X��All�֐����s
	player->All();

	if(enemy!=NULL){
		if(enemy->All()){
		delete enemy;
		enemy=NULL;
		}}
	++g_count;
}