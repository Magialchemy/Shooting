class PLAYER{
private:
	//x���W,y���W
	double x,y;

	//�摜��
	int width,height;

	//�O���t�B�b�N�n���h���i�[�p�z��
	int gh[4];

	//�ړ��W��
	float move;

	//�������Əc�����̃J�E���g���B
	int flamecounter,flip;
	//�����Ă邩�ǂ����̃t���O
	int life;
	//�e
	struct SHOT shot[shotlimit];

	int count;
private:
	void Move();
	void Draw();
	void Shot();

public:
	PLAYER();
	void All();

};