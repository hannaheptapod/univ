#pragma once
enum state;

namespace kishimoto{
	using Bit = unsigned long long;
	int AI(state* field, state color);
	Bit make_bit(state* field, state color);
	Bit make_legal(Bit mine, Bit oppo);
	Bit reverse(Bit posi, Bit mine, Bit oppo);
	Bit transfer(Bit posi, int k);
	int count(Bit x);
	int eval(Bit mine, Bit oppo, int dep, int mode);
	int nega_max(Bit mine, Bit oppo, int max, int turn_num, int dep);
};