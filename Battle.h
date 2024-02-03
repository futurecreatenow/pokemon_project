#pragma once
class BATTLE {
public:
	void Out() {
		Cal();
		Draw();
	}

private:
	enum ACT {
		ACT_00_Battle,
		ACT_01_Exchange,
		ACT_02_Tool,
		ACT_03_Give_up,
	};

	enum TEC {
		TEC_00,
		TEC_01,
		TEC_02,
		TEC_03,
	};

	enum ENT {
		ENT_00_ACT,
		ENT_01_TEC,
		ENT_02_FIR_CAL,
		ENT_03_FIR_OUT,
		ENT_04_SEC_CAL,
		ENT_05_SEC_OUT,
	};

	enum STR {
		STR_00_FIR,
		STR_01_SEC,
	};
	struct {

		struct {
			int X = 300;
			int Y = 310;
		}Act;

		struct {
			int X = 10;
			int Y = 310;

		}Tec;
	}Cur;
	struct {
		struct {
			int X = 1300;
			int Y = 10;
			int X_Lim = 1000;
		}Ene;
		struct {
			int X = 50;
			int Y = 500;
			int X_Lim = 200;
		}Pla;
	}Poke_move;

	struct {
		int Recover = 0;
		int Ent = 0;
		bool Str = 0;
		int First = 1;
		int Next = -1;
		int End = -1;
	}Fla;

	struct SUB {
		char Tec_n[100];
		int Tec_a = 0;
		char Poke_n[100];
		int Poke_a = 0;
		int Poke_b = 0;
		bool Fal = 0;
	};
	SUB Fir;
	SUB Sec;
	void Cal();
	void Draw();
	void CPU();
	void Bat();
	void Pokemove();
	int Damage(int tec_a, int a, int b);
};
BATTLE Bat;

void BATTLE::Cal() {
	if (Key[KEY_INPUT_RIGHT] == 1) {
		switch (Fla.Ent)
		{
		case ENT::ENT_00_ACT:
			Cur.Act.X = 400;
			break;
		case ENT::ENT_01_TEC:
			Cur.Tec.X = 130;
			break;
		}
	}
	else if (Key[KEY_INPUT_LEFT] == 1) {

		switch (Fla.Ent)
		{
		case ENT::ENT_00_ACT:
			Cur.Act.X = 300;
			break;
		case ENT::ENT_01_TEC:
			Cur.Tec.X = 10;
			break;
		}

	}
	else if (Key[KEY_INPUT_UP] == 1) {

		switch (Fla.Ent)
		{
		case ENT::ENT_00_ACT:
			Cur.Act.Y = 310;
			break;
		case ENT::ENT_01_TEC:
			Cur.Tec.Y = 310;
			break;
		}

	}
	else if (Key[KEY_INPUT_DOWN] == 1) {

		switch (Fla.Ent)
		{
		case ENT::ENT_00_ACT:
			Cur.Act.Y = 350;
			break;
		case ENT::ENT_01_TEC:
			Cur.Tec.Y = 350;
			break;
		}

	}
	if (CheckSoundMem(Sound.Bat_Sou) == 0) {
		PlaySoundMem(Sound.Bat_Sou, DX_PLAYTYPE_BACK);
	}
	//Enter Flag
	if (Key[KEY_INPUT_NUMPADENTER] == 1) {
		switch (Fla.Ent) {
		case ENT::ENT_00_ACT:
			Fla.Ent = ENT::ENT_01_TEC;
			break;
		case ENT::ENT_01_TEC:
			Fla.Ent = ENT::ENT_02_FIR_CAL;
			break;
		case ENT::ENT_02_FIR_CAL:
			Fla.Ent = ENT::ENT_03_FIR_OUT;
			break;
		case ENT::ENT_03_FIR_OUT:
			Fla.Ent = ENT::ENT_04_SEC_CAL;
			break;
		case ENT::ENT_04_SEC_CAL:
			Fla.Ent = ENT::ENT_00_ACT;
			break;
		case ENT::ENT_05_SEC_OUT:
			Fla.Ent = ENT::ENT_00_ACT;
			break;

		}

	}
	else if (Key[KEY_INPUT_BACK] == 1) {
		if (Fla.Ent == ENT::ENT_01_TEC) {
			Fla.Ent = ENT::ENT_00_ACT;
		}
	}
	//recover 
	else if (Key[KEY_INPUT_P] == 1) {
		switch (Pla.Act)
		{
		case ACT::ACT_02_Tool:
			Pokemon[Pla.poke_now].H = Pokemon[Pla.poke_now].H + 40; //40HPを回復
			Fla.Recover = 1;
			break;
		}
	}

	//Win of Lose 
	else if (Key[KEY_INPUT_A] == 1) {
		if (Fla.Ent == ENT::ENT_03_FIR_OUT || Fla.Ent == ENT::ENT_05_SEC_OUT) {
			Fir.Fal = 0;
			Sec.Fal = 0;
			Fla.Recover = 0;
			Fla.Str = 0;
			Fla.First = -1;
			Fla.Next = 1;
			Ene.poke_now = Ene.poke_hyota[1];
			Sce = MEN::MEN_03_Battle;
			Fla.Ent = ENT::ENT_00_ACT;
		}
	}
	else if (Key[KEY_INPUT_Z] == 1) {
		if (Fla.Ent == ENT::ENT_03_FIR_OUT || Fla.Ent == ENT::ENT_05_SEC_OUT) {
			Fir.Fal = 0;
			Sec.Fal = 0;
			Fla.Recover = 0;
			Fla.Str = 0;
			Fla.First = -1;
			Fla.Next = -1;
			Fla.End = 1;
			Ene.poke_now = Ene.poke_hyota[2];
			Sce = MEN::MEN_03_Battle;
			Fla.Ent = ENT::ENT_00_ACT;
		}
	}
	//Act Deside
	if (Fla.Ent == ENT::ENT_00_ACT) {
		if (Cur.Act.X == 300 && Cur.Act.Y == 310) {
			Pla.Act = ACT::ACT_00_Battle;
		}
		else if (Cur.Act.X == 400 && Cur.Act.Y == 310) {
			Pla.Act = ACT::ACT_01_Exchange;
		}
		else if (Cur.Act.X == 300 && Cur.Act.Y == 350) {
			Pla.Act = ACT::ACT_02_Tool;
		}
		else if (Cur.Act.X == 400 && Cur.Act.Y == 350) {
			Pla.Act = ACT::ACT_03_Give_up;
		}
	}

	else if (Fla.Ent == ENT::ENT_01_TEC) {
		switch (Pla.Act) {
		case ACT::ACT_00_Battle:
			if (Cur.Tec.X == 10 && Cur.Tec.Y == 310) {
				Pla.Tec = TEC::TEC_00;
			}
			else if (Cur.Tec.X == 130 && Cur.Tec.Y == 310) {
				Pla.Tec = TEC::TEC_01;
			}
			else if (Cur.Tec.X == 10 && Cur.Tec.Y == 350) {
				Pla.Tec = TEC::TEC_02;
			}
			else if (Cur.Tec.X == 130 && Cur.Tec.Y == 350) {
				Pla.Tec = TEC::TEC_03;
			}
			break;

		case ACT::ACT_01_Exchange:
			break;
		case ACT::ACT_02_Tool:
			break;
		case ACT::ACT_03_Give_up:
			break;
		}
	}
	else if (Fla.Ent >= ENT::ENT_02_FIR_CAL) {
		CPU();
		Bat();
	}
}
void BATTLE::CPU() {
	Ene.Tec = 0;
	for (int i = 0; i < 3; i++) {
		if (Technique[Pokemon[Ene.poke_now].Tec[i]].A
			< Technique[Pokemon[Ene.poke_now].Tec[i + 1]].A) {
			Ene.Tec = i + 1; //最も攻撃力の高い技を繰り出す
		}
	}
}
void BATTLE::Bat() {
	//素早さを比較し、高いポケモンを決定する
	if (Fla.Ent == ENT::ENT_02_FIR_CAL) {
		if (Fla.Recover == 1) {
			Fla.Str = STR::STR_01_SEC;
			Fla.Recover = 0;
		}
		else if (Pokemon[Ene.poke_now].S < Pokemon[Pla.poke_now].S) {
			Fla.Str = STR::STR_00_FIR;
		}
		else if (Pokemon[Ene.poke_now].S > Pokemon[Pla.poke_now].S) {
			Fla.Str = STR::STR_01_SEC;
		}
		else if (Pokemon[Ene.poke_now].S == Pokemon[Pla.poke_now].S) {
			int r = GetRand(99);
			if (0 <= r && r <= 49) {
				Fla.Str = STR::STR_00_FIR;
			}
			else if (50 <= r && r <= 99) {
				Fla.Str = STR::STR_01_SEC;
			}
		}
	}
	//自分のポケモンが先行時の、技の攻撃力、ポケモンの攻撃力、防御力を格納
	if (Fla.Str == STR::STR_00_FIR) {
		//-----------Player-----------
		//選択した技が物理攻撃
		if (Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].A != 0) {
			Fir.Tec_a = Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].A;
			Fir.Poke_a = Pokemon[Pla.poke_now].A; //ポケモンの攻撃力
			Fir.Poke_b = Pokemon[Ene.poke_now].B; //相手ポケモンの防御力
		}
		//選択した技が特殊攻撃
		else if (Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].C != 0) {
			Fir.Tec_a = Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].C;
			Fir.Poke_a = Pokemon[Pla.poke_now].C;
			Fir.Poke_b = Pokemon[Ene.poke_now].D;
		}
		//-----------PC-----------
		if (Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].A != 0) {
			Sec.Tec_a = Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].A;
			Sec.Poke_a = Pokemon[Ene.poke_now].A;
			Sec.Poke_b = Pokemon[Pla.poke_now].B;
		}
		else if (Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].C != 0) {
			Sec.Tec_a = Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].C;
			Sec.Poke_a = Pokemon[Ene.poke_now].C;
			Sec.Poke_b = Pokemon[Pla.poke_now].D;
		}
	}
	//PCが先行
	else if (Fla.Str == STR::STR_01_SEC) {
		//-----------PC-----------
		//選択した技が物理攻撃
		if (Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].A != 0) {
			Fir.Tec_a = Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].A;
			Fir.Poke_a = Pokemon[Ene.poke_now].A;
			Fir.Poke_b = Pokemon[Pla.poke_now].B;
		}
		//選択した技が特殊攻撃
		else if (Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].C != 0) {
			Fir.Tec_a = Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].C;
			Fir.Poke_a = Pokemon[Ene.poke_now].C;
			Fir.Poke_b = Pokemon[Pla.poke_now].D;
		}
		//-----------Player-----------
		if (Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].A != 0) {
			Sec.Tec_a = Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].A;
			Sec.Poke_a = Pokemon[Pla.poke_now].A;
			Sec.Poke_b = Pokemon[Ene.poke_now].B;
		}
		else if (Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].C != 0) {
			Sec.Tec_a = Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].C;
			Sec.Poke_a = Pokemon[Pla.poke_now].C;
			Sec.Poke_b = Pokemon[Ene.poke_now].D;
		}
	}

	//自分とPCのポケモン名、技名の格納
	if (Fla.Str == STR::STR_00_FIR) {
		//自分が先行
		for (int n = 0; n < 100; n++) {
			Fir.Poke_n[n] = Pokemon[Pla.poke_now].Name[n];
			Sec.Poke_n[n] = Pokemon[Ene.poke_now].Name[n];
			Fir.Tec_n[n] = Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].Name[n];
			Sec.Tec_n[n] = Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].Name[n];
		}
	}
	else if (Fla.Str == STR::STR_01_SEC) {
		//PCが先行
		for (int n = 0; n < 100; n++) {
			Fir.Poke_n[n] = Pokemon[Ene.poke_now].Name[n];
			Sec.Poke_n[n] = Pokemon[Pla.poke_now].Name[n];
			Fir.Tec_n[n] = Technique[Pokemon[Ene.poke_now].Tec[Ene.Tec]].Name[n];
			Sec.Tec_n[n] = Technique[Pokemon[Pla.poke_now].Tec[Pla.Tec]].Name[n];
		}
	}

	//自分が先行時のHP計算
	if (Fla.Str == STR::STR_00_FIR) {
		//First Attack(Player)
		if (Fla.Ent == ENT::ENT_02_FIR_CAL) {
			Ene.Dam = Damage(Fir.Tec_a, Fir.Poke_a, Fir.Poke_b);
			Pokemon[Ene.poke_now].H = Pokemon[Ene.poke_now].H - Ene.Dam;
			Fla.Ent = ENT::ENT_02_FIR_CAL + 1;
			if (Pokemon[Ene.poke_now].H <= 0) {
				Sec.Fal = 1;
			}
		}
		else if (Fla.Ent == ENT::ENT_04_SEC_CAL) {
			Pla.Dam = Damage(Sec.Tec_a, Sec.Poke_a, Sec.Poke_b);
			Pokemon[Pla.poke_now].H = Pokemon[Pla.poke_now].H - Pla.Dam;
			Fla.Ent = ENT::ENT_04_SEC_CAL + 1;
			if (Pokemon[Pla.poke_now].H <= 0) {
				Fir.Fal = 1;
			}
		}

	}
	//PCが先行時のHP計算
	if (Fla.Str == STR::STR_01_SEC) {
		//First Attack(Ene)
		if (Fla.Ent == ENT::ENT_02_FIR_CAL) {
			Pla.Dam = Damage(Fir.Tec_a, Fir.Poke_a, Fir.Poke_b);
			Pokemon[Pla.poke_now].H = Pokemon[Pla.poke_now].H - Pla.Dam;
			Fla.Ent = ENT::ENT_02_FIR_CAL + 1;
			if (Pokemon[Pla.poke_now].H <= 0) {
				Sec.Fal = 1;
			}
		}
		else if (Fla.Ent == ENT::ENT_04_SEC_CAL) {
			Ene.Dam = Damage(Sec.Tec_a, Sec.Poke_a, Sec.Poke_b);
			Pokemon[Ene.poke_now].H = Pokemon[Ene.poke_now].H - Ene.Dam;
			Fla.Ent = ENT::ENT_04_SEC_CAL + 1;
			if (Pokemon[Ene.poke_now].H <= 0) {
				Fir.Fal = 1;
			}
		}

	}
}
int BATTLE::Damage(int tec_a, int a, int b) {
	int level = 50;
	return (int)((((level * 2.0 / 5.0 + 2.0) * tec_a * a) / b / 50.0 + 2.0));
}
void BATTLE::Pokemove() {
	
	if (Poke_move.Ene.X_Lim < Poke_move.Ene.X) {
		Poke_move.Ene.X -= 10;
	}
	else if (Poke_move.Ene.X_Lim == Poke_move.Ene.X) {
		Poke_move.Ene.X = Poke_move.Ene.X_Lim;
	}
	if (Poke_move.Pla.X < Poke_move.Pla.X_Lim) {
		Poke_move.Pla.X += 10;
	}
	else if (Poke_move.Pla.X == Poke_move.Pla.X_Lim) {
		Poke_move.Pla.X = Poke_move.Pla.X_Lim;
	}

		DrawGraph(Poke_move.Pla.X, Poke_move.Pla.Y, Pic.Poke_pla, TRUE);
	if (Fla.First == 1) {
		DrawGraph(Poke_move.Ene.X, Poke_move.Ene.Y, Pic.Poke_ene, TRUE);
	}
	else if (Fla.Next == 1) {
		DrawGraph(Poke_move.Ene.X, Poke_move.Ene.Y, Pic.Poke_ene_next, TRUE);
	}
	else if (Fla.End == 1) {
		DrawGraph(Poke_move.Ene.X, Poke_move.Ene.Y, Pic.Poke_ene_end, TRUE);
	}
}
void BATTLE::Draw() {
	Pokemove();

	//Name,HP(PC)
	DrawFormatString(65, 50, Col.Bla, "%s", Pokemon[Ene.poke_now].Name);
	if (Pokemon[Ene.poke_now].H > 0) {
		DrawFormatString(65, 90, Col.Bla, "%d/%d", Pokemon[Ene.poke_now].H, Pokemon[Ene.poke_now].Hp_original);
	}
	else {
		DrawFormatString(65, 90, Col.Bla, "0/%d", Pokemon[Ene.poke_now].Hp_original);
	}
	//Name,HP(My)
	DrawFormatString(650, 500, Col.Bla, "%s", Pokemon[Pla.poke_now].Name);
	if (Pokemon[Pla.poke_now].H > 0) {
		DrawFormatString(650, 590, Col.Bla, "%d/%d", Pokemon[Pla.poke_now].H, Pokemon[Pla.poke_now].Hp_original);
	}
	else {
		DrawFormatString(650, 590, Col.Bla, "0/%d", Pokemon[Pla.poke_now].Hp_original);
	}
	//Act Out
	switch (Fla.Ent) {
	case ENT::ENT_00_ACT:
		DrawFormatString(130, 330, Col.Bla, "何をしますか ??");
		DrawFormatString(Cur.Act.X, Cur.Act.Y, Col.Bla, "→");
		DrawFormatString(320, 310, Col.Bla, "戦う");
		DrawFormatString(420, 310, Col.Bla, "ポケモン");
		DrawFormatString(320, 350, Col.Bla, "道具");
		DrawFormatString(420, 350, Col.Bla, "諦める");
		break;
	case ENT::ENT_01_TEC:
		switch (Pla.Act) {
		case ACT::ACT_00_Battle:
			DrawFormatString(Cur.Tec.X, Cur.Tec.Y, Col.Bla, "→");
			DrawFormatString(30, 310, Col.Bla, "%s", Technique[Pokemon[Pla.poke_now].Tec[0]].Name);
			DrawFormatString(150, 310, Col.Bla, "%s", Technique[Pokemon[Pla.poke_now].Tec[1]].Name);
			DrawFormatString(30, 350, Col.Bla, "%s", Technique[Pokemon[Pla.poke_now].Tec[2]].Name);
			DrawFormatString(150, 350, Col.Bla, "%s", Technique[Pokemon[Pla.poke_now].Tec[3]].Name);
			break;
		case ACT::ACT_01_Exchange:
			DrawFormatString(30, 310, Col.Bla, "change pokemon");
			break;
		case ACT::ACT_02_Tool:
			DrawFormatString(30, 310, Col.Bla, "回復薬(p)");
			break;
		case ACT::ACT_03_Give_up:
			DrawFormatString(30, 310, Col.Bla, "give up");
			break;
		}
		break;
	case ENT::ENT_02_FIR_CAL:
		break;
	case ENT::ENT_03_FIR_OUT:
		DrawFormatString(30, 310, Col.Bla, "%s_%s", Fir.Poke_n, Fir.Tec_n);
		DrawFormatString(30, 350, Col.Bla, "%d ダメージを%sに与えた", Damage(Fir.Tec_a, Fir.Poke_a, Fir.Poke_b), Sec.Poke_n);

		if (Sec.Fal == 1 && Fla.First == 1) {
			if (Fla.Str == STR::STR_00_FIR) {
				DrawFormatString(30, 390, Col.Bla, "%sに勝利", Sec.Poke_n);
			}
			else if (Fla.Str == STR::STR_01_SEC) {
				DrawFormatString(30, 390, Col.Bla, "PCの勝利");
			}
			DrawFormatString(30, 410, Col.Bla, "Aを押下してください。");
			DrawFormatString(30, 430, Col.Bla, "次のポケモンと対戦します");
			
		}
		if (Sec.Fal == 1 && Fla.End == 1) {
			if (Fla.Str == STR::STR_00_FIR) {
				DrawFormatString(30, 390, Col.Bla, "%sに勝利", Sec.Poke_n);
			}
			else if (Fla.Str == STR::STR_01_SEC) {
				DrawFormatString(30, 390, Col.Bla, "PCの勝利");
			}
			DrawFormatString(30, 410, Col.Bla, "ジムリーダーに勝利");

		}
		break;
	case ENT::ENT_04_SEC_CAL:
		break;
	case ENT::ENT_05_SEC_OUT:
		DrawFormatString(30, 310, Col.Bla, "%s_%s", Sec.Poke_n, Sec.Tec_n);
		DrawFormatString(30, 350, Col.Bla, "%d ダメージを%sに与えた", Damage(Sec.Tec_a, Sec.Poke_a, Sec.Poke_b), Fir.Poke_n);

		if (Fir.Fal == 1 && Fla.First == 1) {
			if (Fla.Str == STR::STR_00_FIR) {
				DrawFormatString(30, 390, Col.Bla, "PCの勝利");
			}
			else if (Fla.Str == STR::STR_01_SEC) {
				DrawFormatString(30, 390, Col.Bla, "あなたの勝利");
			}
			DrawFormatString(30, 410, Col.Bla, "Aを押下してください");
			DrawFormatString(30, 430, Col.Bla, "次のポケモンと対戦します");
		}
		if (Fir.Fal == 1 && Fla.Next == 1) {
			if (Fla.Str == STR::STR_00_FIR) {
				DrawFormatString(30, 390, Col.Bla, "PCの勝利");
			}
			else if (Fla.Str == STR::STR_01_SEC) {
				DrawFormatString(30, 390, Col.Bla, "あなたの勝利");
			}
			DrawFormatString(30, 410, Col.Bla, "Zを押下してください");
			DrawFormatString(30, 430, Col.Bla, "次のポケモンと対戦します");
		}
		break;

	}


}