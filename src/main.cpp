// Noam shimshoviz 203565429


#include "GameFlow.h"
#include "Player.h"
#include "HumanPlayer.h"

int main() {

	Player* p1 = new HumanPlayer ('x');
	Player* p2 = new HumanPlayer ('0');

	Board b(8,8);


	GameLogic logic(b);

	Board u =  logic.getBoard();

	u.print();
	b.print();

	u.update(3,4,'x');
	b.update(1,1,'0');




delete p1;
delete p2;



	return 0;
}
