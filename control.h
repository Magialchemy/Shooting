#include "player.h"	
#include"back.h"
#include"enemy.h"

class CONTROL{
private:
	//�v���C���[�N���X�̃|�C���^
	PLAYER *player;

	//�w�i�N���X�̃|�C���^
	BACK *back;
	
	ENEMY *enemy;

public:
	CONTROL();
	void All();
};
