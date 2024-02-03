#pragma once
class {
public:
	int Tit;
	int Chara;
	int Gym_Leader;
	int Battle_start;
	int Poke_ene;
	int Poke_ene_next;
	int Poke_ene_end;
	int Poke_pla;
	void Read() {
		Tit = LoadGraph("picture/title.png");
		Chara = LoadGraph("picture/person.png");
		Gym_Leader = LoadGraph("picture/hyouta.png");
		Battle_start = LoadGraph("picture/Battle_start.jpg");
		Poke_ene = LoadGraph("picture/zugaidosu.png");
		Poke_ene_next = LoadGraph("picture/iwa-ku.jpg");
		Poke_ene_end = LoadGraph("picture/isitubute.png");
		Poke_pla = LoadGraph("picture/moukazaru.png");
	}

private:

}Pic;