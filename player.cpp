#include "precom.h"
#include "player.h"


PLAYER::PLAYER()
{
	//画像読み込み
	
	if(-1==LoadDivGraph("image/shanghaiD.png",4,4,1,32,32,gh)){
		MSG("エラー発生");
	}

	width=32;
	height=32;
		

	//移動係数
	move=1.0f;

	//横方向と縦方向のカウント数
	flamecounter=0;
	flip=0;

	//初期位置
	x=5;
	y=80;
	
	life=1;

	//弾を初期化する
	memset(shot,0,sizeof(shot));

	//弾の読み込み
	int temp[6];
	int w[6],h[6];
	LoadDivGraph("image/bullet.png",6,6,1,32,32,temp);
	for(int i=0;i<6;++i)
	{GetGraphSize(temp[i],&w[i],&h[i]);}

	//フラグは全てfalse
	//グラハンと画像のサイズを代入
	for(int j=0;j<shotlimit;++j)
	{
		shot[j].flag=false;
		shot[j].gh=temp[j];
		shot[j].width=w[j];
		shot[j].height=h[j];
	
	}
	count=0;

}

void PLAYER::Move()
{
	
		if(key[KEY_INPUT_LEFT]==1 || key[KEY_INPUT_RIGHT]==1){
			
			if(key[KEY_INPUT_UP]==1 || key[KEY_INPUT_DOWN]==1){
				//移動係数を1/√２に設定
				move=0.71f;
			}else{
				//斜めじゃなければ１．０に設定
				move=1.0f;
			}
		}else if(key[KEY_INPUT_UP]==1 || key[KEY_INPUT_DOWN]==1){
			move=1.0f;
		}
		
		if(key[KEY_INPUT_LEFT]==1){
			x-=(int)shanspeed*move;
		}
		if(key[KEY_INPUT_RIGHT]==1){
			x+=(int)shanspeed*move;

		}
		if(key[KEY_INPUT_UP]==1){
			y-=(int)shanspeed*move;

		}
		if(key[KEY_INPUT_DOWN]==1){
			y+=(int)shanspeed*move;

		}
		flamecounter++;
		if(flamecounter%5==4)
		{flamecounter=0;
		flip++;}
		if(flip%4==0){flip=0;}
		if(x<width/2){x=width/2;}
		if(x>winwidth-width/2){x=winwidth-width/2;}
		if(y<winheight-stageheight+height/2){y=winheight-stageheight+height/2;}
		if(y>winheight-height/2){y=winheight-height/2;} //引っかかったらその値でとめる
}

void PLAYER::Draw()
{
	//弾の描画

	for(int k=0; k<shotlimit;++k){
		if(shot[k].flag){
			DrawGraph(shot[k].x-shot[k].width/2,shot[k].y-shot[k].height/2,shot[k].gh,TRUE);
	}}
	//生きてれば描画
	if(life!=0){
		//描画
		DrawGraph(x-width/2,y-height/2,gh[flip],TRUE);
	}
}

void PLAYER::Shot(){
	//キーが押され、6ループで発射
	if(key[KEY_INPUT_Z]==1 &&count%6==0)
	{for(int i=0;i<shotlimit;++i)
	{if(shot[i].flag==false){
		shot[i].flag=true;
		shot[i].x=x;
		shot[i].y=y;
		break;
	}}}

	//弾を動かそう
	for(int i=0;i<shotlimit;++i)
	//発射してる弾だけ
	{if(shot[i].flag){
		shot[i].x+=shotspeed;
	
		if(shot[i].x>winwidth+shot[i].width){
			shot[i].flag=false;
	}}}
}

void PLAYER::All()
{
	Move();
	Shot();
	Draw();

	++count;
}