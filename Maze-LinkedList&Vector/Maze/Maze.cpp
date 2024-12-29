#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List li;

    li.AddAtTail(1);
    Node* node = li.AddAtTail(2);       // Node 기억
    li.AddAtTail(3);

    li.Print();

    li.Remove(node);                    // 기억한 Node 삭제
                                        // 연결리스트에서 중간에 노트 삽입 삭제가 빠르다.
                                        // 하지만, 노드 위치를 알때 빠른거지, 모르면 매우 느림`
                                        // 즉, 중간 위치 임의 접근은 느리다.
    li.Print();
}