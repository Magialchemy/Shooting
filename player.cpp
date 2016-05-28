#include "precom.h"
#include "player.h"


PLAYER::PLAYER()
{
	//�摜�ǂݍ���
	
	if(-1==LoadDivGraph("image/shanghaiD.png",4,4,1,32,32,gh)){
		MSG("�G���[����");
	}

	width=32;
	height=32;
		

	//�ړ��W��
	move=1.0f;

	//�������Əc�����̃J�E���g��
	flamecounter=0;
	flip=0;

	//�����ʒu
	x=5;
	y=80;
	
	life=1;

	//�e������������
	memset(shot,0,sizeof(shot));

	//�e�̓ǂݍ���
	int temp[6];
	int w[6],h[6];
	LoadDivGraph("image/bullet.png",6,6,1,32,32,temp);
	for(int i=0;i<6;++i)
	{GetGraphSize(temp[i],&w[i],&h[i]);}

	//�t���O�͑S��false
	//�O���n���Ɖ摜�̃T�C�Y����
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
				//�ړ��W����1/��Q�ɐݒ�
				move=0.71f;
			}else{
				//�΂߂���Ȃ���΂P�D�O�ɐݒ�
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
		if(y>winheight-height/2){y=winheight-height/2;} //�������������炻�̒l�łƂ߂�
}

void PLAYER::Draw()
{
	//�e�̕`��

	for(int k=0; k<shotlimit;++k){
		if(shot[k].flag){
			DrawGraph(shot[k].x-shot[k].width/2,shot[k].y-shot[k].height/2,shot[k].gh,TRUE);
	}}
	//�����Ă�Ε`��
	if(life!=0){
		//�`��
		DrawGraph(x-width/2,y-height/2,gh[flip],TRUE);
	}
}

void PLAYER::Shot(){
	//�L�[��������A6���[�v�Ŕ���
	if(key[KEY_INPUT_Z]==1 &&count%6==0)
	{for(int i=0;i<shotlimit;++i)
	{if(shot[i].flag==false){
		shot[i].flag=true;
		shot[i].x=x;
		shot[i].y=y;
		break;
	}}}

	//�e�𓮂�����
	for(int i=0;i<shotlimit;++i)
	//���˂��Ă�e����
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