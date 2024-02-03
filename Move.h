#pragma once
class MOVE {
public:
	void Out() {
		Cal();
		Draw();
	}

private:
	struct {
		int X = 100;
		int Y = 100;
		const int X_Lim = 10;
		const int Y_Lim = 10;
	}Cur;
	void Cal();
	void Draw();
};
MOVE Mov;

void MOVE::Cal() {
	//Cursol Move
	if (Key[KEY_INPUT_RIGHT] == 1) {
		Cur.X = Cur.X + POKEMON_CELL;
	}
	else if (Key[KEY_INPUT_LEFT] == 1) {
		Cur.X = Cur.X - POKEMON_CELL;
	}
	else if (Key[KEY_INPUT_UP] == 1) {
		Cur.Y = Cur.Y - POKEMON_CELL;
	}
	else if (Key[KEY_INPUT_DOWN] == 1) {
		Cur.Y = Cur.Y + POKEMON_CELL;
	}

	//Cursol Limit
	if (Cur.X < 0) Cur.X = 0;
	if (Cur.X > (Cur.X_Lim - 1) * POKEMON_CELL) {
		Cur.X = (Cur.X_Lim - 1) * POKEMON_CELL;
	}
	if (Cur.Y < 0) Cur.Y = 0;
	if (Cur.Y > (Cur.Y_Lim - 1) * POKEMON_CELL) {
		Cur.Y = (Cur.Y_Lim - 1) * POKEMON_CELL;
	}

	//バトル開始
	if (Cur.X == 0 && Cur.Y == 0) {
		Cur.X = 100;
		Cur.Y = 100;
		Sce = MEN::MEN_02_Battle_start;

	}
}

void MOVE::Draw() {
	DrawGraph(0, 0, Pic.Gym_Leader, TRUE);
	DrawGraph(Cur.X, Cur.Y, Pic.Chara, TRUE);
}