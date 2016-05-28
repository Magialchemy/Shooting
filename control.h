#include "player.h"	
#include"back.h"
#include"enemy.h"

class CONTROL{
private:
	//プレイヤークラスのポインタ
	PLAYER *player;

	//背景クラスのポインタ
	BACK *back;
	
	ENEMY *enemy;

public:
	CONTROL();
	void All();
};
