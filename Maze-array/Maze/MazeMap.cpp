#include "pch.h"
#include "Vector.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

#include "Stack.h"

int main()
{
	/*Stack<int> st;
	
	st.push(1);
	st.push(2);
	st.push(3);

	int a = st.top();
	st.pop();*/

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;

	while (true)
	{
#pragma region ������ ����
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion

		// �Է�


		// ����
		player.Update(deltaTick);

		// ������
		board.Render();
	}
}