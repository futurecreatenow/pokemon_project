#pragma once
struct POKEMON {
	int No = -1;
	char Name[100];
	char Type1[10];
	char Type2[10];
	int H = 0; //HP
	int A = 0; //攻撃
	int B = 0; //防御
	int C = 0; //特殊攻撃
	int D = 0; //特殊防御
	int S = 0; //素早さ
	int Hp_original = 0; //もともとのHP
	int Tec[4] = { -1,-1,-1,-1 };
};


struct POK
{
	int poke_hyota[3] = {-1,-1,-1}; //ヒョウタのポケモンNo
	int poke_my = 0; //私のポケモンNo
	int poke_now = 0; //今戦闘中のポケモンNo
	int Act = 0;
	int Tec = 0; //どの技を出すのか
	int Dam = 0;
};

POK Pla;
POK Ene;

POKEMON Pokemon[]{
	//ヒョウタ
	{0,"ズガイドス","岩","",
		67,125,40,30,30,58,67,
		0,1,2,3},
	//主人公、自分
	{1,"モウカザル","炎","格闘",
		1000,78,52,78,52,81,1000,
		6,7,8,12},
	//ヒョウタ 2匹目
	{2,"イワーク","岩","地面",
		100,100,100,100,100,100,100,
		9,10,11,0},
	//ヒョウタ 3匹目
	{3,"イシツブテ","岩","地面",
		50,50,50,50,50,50,50,
		9,10,11,0},

};