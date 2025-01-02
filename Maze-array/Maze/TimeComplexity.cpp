#include "pch.h"
#include <iostream>
#include "Array.h"
#include "Vector.h"

using namespace std;

int main()
{
	// Vector
	// [1][1][1][1][1][1][1][1][1]

	// 삽입/삭제
	// - 시작		O(N)
	// - 중간		O(N)
	// - 끝			O(1)
	// 임의 접근?		O(1)

	// List
	//   [1][2][3]
	// [head]	[tail]

	// 삽입/삭제
	// - 시작				O(1)
	// - 중간				O(1)
	// - 끝					O(1)
	// 임의의 index 접근?		O(N)
}