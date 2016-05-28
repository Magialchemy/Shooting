class ENEMY{
private:
	double x,y;
	int gh[4];
	int wid,hei;
	int intime,stoptime,outtime;
	int count;
	bool endflag;
	int life;

public:
	bool All();
	void Move();
	void Draw();
	ENEMY();

};