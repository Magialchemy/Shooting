#include"precom.h"
#include"back.h"
BACK::BACK()
{
	gh = LoadGraph("image/BG.png");
	GetGraphSize(gh,&width,&height);
	x=y=0;
}

void BACK::Draw()
{
	
	DrawGraph(x,y,gh,FALSE);

	DrawGraph(x+width,y,gh,FALSE);

	if(x==-1*width)
		x=0;
}
void BACK::Move(){
	x-=scrollspeed;}


void BACK::All()
{
	Draw();
	Move();
}