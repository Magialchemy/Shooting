#include "precom.h"
#include "control.h"

CONTROL::CONTROL()
{
	//プレイヤークラスの生成
	player = new PLAYER;

	back = new BACK;

	enemy = new ENEMY;
}

void CONTROL::All()
{
	SetDrawArea(0,0,winwidth,winheight);
	//背景描画が先
	back->All();
	//プレイヤークラスのAll関数実行
	player->All();

	if(enemy!=NULL){
		if(enemy->All()){
		delete enemy;
		enemy=NULL;
		}}
	++g_count;
}