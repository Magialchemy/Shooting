class PLAYER{
private:
	//x座標,y座標
	double x,y;

	//画像幅
	int width,height;

	//グラフィックハンドル格納用配列
	int gh[4];

	//移動係数
	float move;

	//横方向と縦方向のカウント数。
	int flamecounter,flip;
	//生きてるかどうかのフラグ
	int life;
	//弾
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