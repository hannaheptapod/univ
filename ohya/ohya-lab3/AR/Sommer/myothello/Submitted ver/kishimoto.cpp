#include "kishimoto.h"
#include "state.h"

using kishimoto::Bit;

int kishimoto::AI(state* field, state color) {
	Bit now_mine = make_bit(field, color);
	state o_color;
	if (color == black) o_color = white;
	else o_color = black;
	Bit now_oppo = make_bit(field, o_color);
	Bit occu = now_mine | now_oppo;
	int turn_num = count(occu) - 4;
	if (turn_num == 0) return 19;
	int put = -1;
	int score = -0xffffLL;
	Bit now_lega = make_legal(now_mine, now_oppo);
	Bit posi = 0x8000000000000000ULL;
	for (int i = 0; i < 64; i++, posi >>= 1) {
		if ((posi & now_lega) == posi) {
			if (put == -1) put = i;
			Bit rev = reverse(posi, now_mine, now_oppo);
			now_mine ^= posi | rev;
			now_oppo ^= rev;
			int temp = -nega_max(now_oppo, now_mine, score, turn_num, 1);
			now_mine ^= posi | rev;
			now_oppo ^= rev;
			if (temp > score) {
				score = temp;
				put = i;
			}
		}
		else continue;
	}
	return put;
}
Bit kishimoto::make_bit(state* field, state color) {
	Bit temp = 0ULL;
	for (int i = 0; i < 64; i++) {
		temp <<= 1;
		if (field[i] == color) temp += 1;
		else continue;
	}
	return temp;
}
Bit kishimoto::make_legal(Bit mine, Bit oppo) {
	const Bit hor = oppo & 0x7e7e7e7e7e7e7e7eULL;
	const Bit ver = oppo & 0x00ffffffffffff00ULL;
	const Bit all = oppo & 0x007e7e7e7e7e7e00ULL;
	Bit empt = ~(mine | oppo);
	Bit temp, lega;

	temp = hor & (mine << 1);
	temp |= hor & (temp << 1);
	temp |= hor & (temp << 1);
	temp |= hor & (temp << 1);
	temp |= hor & (temp << 1);
	temp |= hor & (temp << 1);
	lega = empt & (temp << 1);

	temp = hor & (mine >> 1);
	temp |= hor & (temp >> 1);
	temp |= hor & (temp >> 1);
	temp |= hor & (temp >> 1);
	temp |= hor & (temp >> 1);
	temp |= hor & (temp >> 1);
	lega |= empt & (temp >> 1);
	
	temp = ver & (mine << 8);
	temp |= ver & (temp << 8);
	temp |= ver & (temp << 8);
	temp |= ver & (temp << 8);
	temp |= ver & (temp << 8);
	temp |= ver & (temp << 8);
	lega |= empt & (temp << 8);

	temp = ver & (mine >> 8);
	temp |= ver & (temp >> 8);
	temp |= ver & (temp >> 8);
	temp |= ver & (temp >> 8);
	temp |= ver & (temp >> 8);
	temp |= ver & (temp >> 8);
	lega |= empt & (temp >> 8);
	
	temp = all & (mine << 7);
	temp |= all & (temp << 7);
	temp |= all & (temp << 7);
	temp |= all & (temp << 7);
	temp |= all & (temp << 7);
	temp |= all & (temp << 7);
	lega |= empt & (temp << 7);

	temp = all & (mine >> 7);
	temp |= all & (temp >> 7);
	temp |= all & (temp >> 7);
	temp |= all & (temp >> 7);
	temp |= all & (temp >> 7);
	temp |= all & (temp >> 7);
	lega |= empt & (temp >> 7);
	
	temp = all & (mine << 9);
	temp |= all & (temp << 9);
	temp |= all & (temp << 9);
	temp |= all & (temp << 9);
	temp |= all & (temp << 9);
	temp |= all & (temp << 9);
	lega |= empt & (temp << 9);

	temp = all & (mine >> 9);
	temp |= all & (temp >> 9);
	temp |= all & (temp >> 9);
	temp |= all & (temp >> 9);
	temp |= all & (temp >> 9);
	temp |= all & (temp >> 9);
	lega |= empt & (temp >> 9);

	return lega;
}
Bit kishimoto::reverse(Bit posi, Bit mine, Bit oppo) {
	Bit reversed = 0ULL;
	for (int k = 0; k < 8; k++) {
		Bit temp_rev = 0ULL;
		Bit mask = transfer(posi, k);
		while ((mask != 0ULL) && ((mask & oppo) != 0)) {
			temp_rev |= mask;
			mask = transfer(mask, k);
		}
		if ((mask & mine) != 0) reversed |= temp_rev;
	}
	return reversed;
}
Bit kishimoto::transfer(Bit posi, int k) {
	switch (k) {
		case 0:
		return (posi << 1) & 0xfefefefefefefefeULL;
		case 1:
		return (posi >> 1) & 0x7f7f7f7f7f7f7f7fULL;
		case 2:
		return (posi << 8) & 0xffffffffffffff00ULL;
		case 3:
		return (posi >> 8) & 0x00ffffffffffffffULL;
		case 4:
		return (posi << 7) & 0x7f7f7f7f7f7f7f00ULL;
		case 5:
		return (posi >> 7) & 0x00fefefefefefefeULL;
		case 6:
		return (posi << 9) & 0xfefefefefefefe00ULL;
		case 7:
		return (posi >> 9) & 0x007f7f7f7f7f7f7fULL;
		default: return posi;
	}
}
int kishimoto::count(Bit x) {
    x -= ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
    x += (x >> 8);
    x += (x >> 16);
    x += (x >> 32);
	x &= 0x7fULL;
	int xi = (int)x;
    return xi;
}

int kishimoto::eval(Bit mine, Bit oppo, int dep, int mode) {
	int val;
	int wa = 100;
	int wb = -40;
	int wc = 20;
	int wd = 5;
	int we = -80;
	int wf = -1;
	int wg = 5;
	int wh = 1;
	const Bit a0 = 0x8000000000000000ULL;
	const Bit b0 = 0x4080000000000000ULL;
	const Bit c0 = 0x2000800000000000ULL;
	const Bit d0 = 0x1000008000000000ULL;
	const Bit e0 = 0x0040000000000000ULL;
	const Bit a1 = 0x0100000000000000ULL;
	const Bit b1 = 0x0201000000000000ULL;
	const Bit c1 = 0x0400010000000000ULL;
	const Bit d1 = 0x0800000100000000ULL;
	const Bit e1 = 0x0002000000000000ULL;
	const Bit a2 = 0x0000000000000080ULL;
	const Bit b2 = 0x0000000000008040ULL;
	const Bit c2 = 0x0000000000800020ULL;
	const Bit d2 = 0x0000000080000010ULL;
	const Bit e2 = 0x0000000000004000ULL;
	const Bit a3 = 0x0000000000000001ULL;
	const Bit b3 = 0x0000000000000102ULL;
	const Bit c3 = 0x0000000000010040ULL;
	const Bit d3 = 0x0000000001000008ULL;
	const Bit e3 = 0x0000000000000200ULL;
	const Bit f = 0x003c424242423c00ULL;
	const Bit g = 0x0000240000240000ULL;
	const Bit h = 0x0000183c3c180000ULL;
	switch (mode) {
	case 0:
		val = 0;
		if ((a0 & mine) == a0) val += wa + wa * count(b0 & mine) + wc * count(c0 & mine) + wd * count(d0 & mine) + we * count(e0 & oppo);
		else if ((a0 & oppo) == a0) val -= wa + wa * count(b0 & oppo) + wc * count(c0 & oppo) + wd * count(d0 & oppo) + we * count(e0 & mine);
		val += wb * (count(b0 & mine) - count(b0 & oppo)) + wc * (count(c0 & mine) - count(c0 & oppo)) + wd * (count(d0 & mine) - count(d0 & oppo)) + we * (count(e0 & mine) - count(e0 & oppo));
		if ((a1 & mine) == a1) val += wa + wa * count(b1 & mine) + wc * count(c1 & mine) + wd * count(d1 & mine) + we * count(e1 & oppo);
		else if ((a1 & oppo) == a1) val -= wa + wa * count(b1 & oppo) + wc * count(c1 & oppo) + wd * count(d1 & oppo) + we * count(e1 & mine);
		val += wb * (count(b1 & mine) - count(b1 & oppo)) + wc * (count(c1 & mine) - count(c1 & oppo)) + wd * (count(d1 & mine) - count(d1 & oppo)) + we * (count(e1 & mine) - count(e1 & oppo));
		if ((a2 & mine) == a2) val += wa + wa * count(b2 & mine) + wc * count(c2 & mine) + wd * count(d2 & mine) + 2*we * count(e2 & oppo);
		else if ((a2 & oppo) == a2) val -= wa + wa * count(b2 & oppo) + wc * count(c2 & oppo) + wd * count(d2 & oppo) + we * count(e2 & mine);
		val += wb * (count(b2 & mine) - count(b2 & oppo)) + wc * (count(c2 & mine) - count(c2 & oppo)) + wd * (count(d2 & mine) - count(d2 & oppo)) + we * (count(e2 & mine) - count(e2 & oppo));
		if ((a3 & mine) == a3) val += wa + wa * count(b3 & mine) + wc * count(c3 & mine) + wd * count(d3 & mine) + we * count(e3 & oppo);
		else if ((a3 & oppo) == a3) val -= wa + wa * count(b3 & oppo) + wc * count(c3 & oppo) + wd * count(d3 & oppo) + we * count(e3 & mine);
		val += wb * (count(b3 & mine) - count(b3 & oppo)) + wc * (count(c3 & mine) - count(c3 & oppo)) + wd * (count(d3 & mine) - count(d3 & oppo)) + we * (count(e3 & mine) - count(e3 & oppo));
		val += wf * (count(f & mine) - count(f & oppo)) + wg * (count(g & mine) - count(g & oppo)) + wh * (count(h & mine) - count(h & oppo));
		break;
	case 1:
		val = 0;
		wa /= 2;
		if ((a0 & mine) == a0) val += wa + wa * count(b0 & mine) + wc * count(c0 & mine) + wd * count(d0 & mine) + we * count(e0 & oppo);
		else if ((a0 & oppo) == a0) val -= wa + wa * count(b0 & oppo) + wc * count(c0 & oppo) + wd * count(d0 & oppo) + we * count(e0 & mine);
		val += wb * (count(b0 & mine) - count(b0 & oppo)) + wc * (count(c0 & mine) - count(c0 & oppo)) + wd * (count(d0 & mine) - count(d0 & oppo)) + we * (count(e0 & mine) - count(e0 & oppo));
		if ((a1 & mine) == a1) val += wa + wa * count(b1 & mine) + wc * count(c1 & mine) + wd * count(d1 & mine) + we * count(e1 & oppo);
		else if ((a1 & oppo) == a1) val -= wa + wa * count(b1 & oppo) + wc * count(c1 & oppo) + wd * count(d1 & oppo) + we * count(e1 & mine);
		val += wb * (count(b1 & mine) - count(b1 & oppo)) + wc * (count(c1 & mine) - count(c1 & oppo)) + wd * (count(d1 & mine) - count(d1 & oppo)) + we * (count(e1 & mine) - count(e1 & oppo));
		if ((a2 & mine) == a2) val += wa + wa * count(b2 & mine) + wc * count(c2 & mine) + wd * count(d2 & mine) + we * count(e2 & oppo);
		else if ((a2 & oppo) == a2) val -= wa + wa * count(b2 & oppo) + wc * count(c2 & oppo) + wd * count(d2 & oppo) + we * count(e2 & mine);
		val += wb * (count(b2 & mine) - count(b2 & oppo)) + wc * (count(c2 & mine) - count(c2 & oppo)) + wd * (count(d2 & mine) - count(d2 & oppo)) + we * (count(e2 & mine) - count(e2 & oppo));
		if ((a3 & mine) == a3) val += wa + wa * count(b3 & mine) + wc * count(c3 & mine) + wd * count(d3 & mine) + we * count(e3 & oppo);
		else if ((a3 & oppo) == a3) val -= wa + wa * count(b3 & oppo) + wc * count(c3 & oppo) + wd * count(d3 & oppo) + we * count(e3 & mine);
		val += wb * (count(b3 & mine) - count(b3 & oppo)) + wc * (count(c3 & mine) - count(c3 & oppo)) + wd * (count(d3 & mine) - count(d3 & oppo)) + we * (count(e3 & mine) - count(e3 & oppo));
		val += wf * (count(f & mine) - count(f & oppo)) + wg * (count(g & mine) - count(g & oppo)) + wh * (count(h & mine) - count(h & oppo));
		break;
	case 2:
		int m_stone = count(mine);
		int o_stone = count(oppo);
		if (m_stone > o_stone) val = 0x7fffffff;
		else if (m_stone == o_stone) val = 0;
		else val = -0x7fffffff;
		break;
	}
	return val;
}
int kishimoto::nega_max(Bit mine, Bit oppo, int max, int turn_num, int dep) {
	int score = max;
	int search_dep = 6;
	if (turn_num < 5 || turn_num > 30) search_dep += 2;
	if (turn_num > 45) search_dep += 2;
	if (dep >= search_dep) {
		if (turn_num < 40) return eval(mine, oppo, dep, 0);
		else return eval(mine, oppo, dep, 1);
	}
	else if (turn_num + dep >= 60) return eval(mine, oppo, dep, 2);
	else {
		Bit lega = make_legal(mine, oppo);
		if (lega == 0ULL) {
			Bit op_lega = make_legal(oppo, mine);
			if (op_lega == 0ULL) return eval(mine, oppo, dep, 2);
			else {
				int temp = nega_max(oppo, mine, score, turn_num, dep);
				if (temp > score) score = temp;
			}
		}
		else {
			for (Bit posi = 0x8000000000000000ULL; posi > 0x0ULL; posi >>= 1) {
				if ((posi & lega) == posi) {
					Bit rev = reverse(posi, mine, oppo);
					mine ^= posi | rev;
					oppo ^= rev;
					int temp = -nega_max(oppo, mine, score, turn_num, dep+1);
					mine ^= posi | rev;
					oppo ^= rev;
					if (temp > score) score = temp;
				}
			}
		}		
	}
	return score;
}