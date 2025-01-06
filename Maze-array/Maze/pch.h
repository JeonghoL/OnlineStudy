#pragma once

#include "Types.h"
#include <Windows.h>
#include <iostream>
#include <random>

using namespace std;

struct Pos
{
	Pos() {};
	Pos(int32 y, int32 x) : x(x), y(y) { }

	bool operator==(const Pos& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Pos& other)
	{
		return !(*this == other);
	}

	Pos operator+(const Pos& other)
	{
		Pos ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	Pos& operator+=(const Pos& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	int32 y = 0;
	int32 x = 0;
};

enum Dir
{
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4
};

inline int MyRandom(int min, int max)
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}