#pragma once
class BATTLE_Start {
public:
	void Out() {
		Cal();
		Draw();
	}

private:
	struct {
		struct {
			struct {
				int name_X = 50;
				int name_Y = 280;
				int H_X = 200;
				int H_Y = 280;
			}Poke;
			int X = 50;
			int Y = 250;
		}Me;
		struct {
			struct {
				int name_X = 1000;
				int name_Y = 280;
				int H_X = 1150;
				int H_Y = 280;
			}Poke_fir;
			struct {
				int name_X = 1000;
				int name_Y = 320;
				int H_X = 1150;
				int H_Y = 320;
			}Poke_Sec;
			struct {
				int name_X = 1000;
				int name_Y = 370;
				int H_X = 1150;
				int H_Y = 370;
			}Poke_Thi;
			int X = 1000;
			int Y = 250;
		}PC;
	}Hava;
	void Cal();
	void Draw();
};
BATTLE_Start Battle_sta;

void BATTLE_Start::Cal() {
	Pla.poke_my = 1;
	Ene.poke_hyota[0] = 0;
	Ene.poke_hyota[1] = 2;
	Ene.poke_hyota[2] = 3;
	Pla.poke_now = Pla.poke_my;
	Ene.poke_now = Ene.poke_hyota[0];

	if (Key[KEY_INPUT_NUMPADENTER] == 1) {
		Sce = MEN::MEN_03_Battle;
	}
	if (CheckSoundMem(Sound.Bat_Sou) == 0) {
		PlaySoundMem(Sound.Bat_Sou, DX_PLAYTYPE_BACK);
	}
}

void BATTLE_Start::Draw() {
	DrawGraph(0, 0, Pic.Battle_start, TRUE);
	DrawFormatString(20, 200,
		Col.Red, "ジムリーダーヒョウタが現れた");
	DrawFormatString(20, 220,
		Col.Red, "Enter　Keyを押してください");
	//--------------------------私のポケモン---------------------------
	DrawFormatString(Hava.Me.X,Hava.Me.Y,
		Col.Bla, "あなたの手持ちポケモン");
	//ポケモン名
	DrawFormatString(Hava.Me.Poke.name_X, Hava.Me.Poke.name_Y,
		Col.Bla, "%s",Pokemon[Pla.poke_my].Name);
	//HP
	DrawFormatString(Hava.Me.Poke.H_X, Hava.Me.Poke.H_Y,
		Col.Bla, "HP>>>>>%d", Pokemon[Pla.poke_my].Hp_original);
	//--------------------------PCのポケモン---------------------------

	DrawFormatString(Hava.PC.X, Hava.PC.Y,
		Col.Bla, "PCの手持ちポケモン");
	//ポケモン名_First
	DrawFormatString(Hava.PC.Poke_fir.name_X, Hava.PC.Poke_fir.name_Y,
		Col.Bla, "%s", Pokemon[Ene.poke_hyota[0]].Name);
	//HP
	DrawFormatString(Hava.PC.Poke_fir.H_X, Hava.PC.Poke_fir.H_Y,
		Col.Bla, "HP>>>>>%d", Pokemon[Ene.poke_hyota[0]].Hp_original);
	//ポケモン名_Sec
	DrawFormatString(Hava.PC.Poke_Sec.name_X, Hava.PC.Poke_Sec.name_Y,
		Col.Bla, "%s", Pokemon[Ene.poke_hyota[1]].Name);
	//HP
	DrawFormatString(Hava.PC.Poke_Sec.H_X, Hava.PC.Poke_Sec.H_Y,
		Col.Bla, "HP>>>>>%d", Pokemon[Ene.poke_hyota[1]].Hp_original);
	//ポケモン名_Third
	DrawFormatString(Hava.PC.Poke_Thi.name_X, Hava.PC.Poke_Thi.name_Y,
		Col.Bla, "%s", Pokemon[Ene.poke_hyota[2]].Name);
	//HP
	DrawFormatString(Hava.PC.Poke_Thi.H_X, Hava.PC.Poke_Thi.H_Y,
		Col.Bla, "HP>>>>>%d", Pokemon[Ene.poke_hyota[2]].Hp_original);



}