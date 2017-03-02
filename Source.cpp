
#include "Game.h"
#include <conio.h>



int main() {


	int matrix[3][3] = {1, 2, 0,
						4, 6, 3,
						7, 5, 8};

	Game game = Game(matrix);

	game.print();


	int c = 0;
	char key;
	while (1)
	{
		
		key = _getch();
		c = key;

		if (c == 97) {
			game.left();
			//std::cout << 'a' << std::endl;
		}
		else if (c == 100) {
			game.right();
			//std::cout << 'd' << std::endl;
		}
		else if (c == 119) {
			game.up();
			//std::cout << 'w' << std::endl;
		}
		else if (c == 115) {
			game.down();
			//std::cout << 's' << std::endl;
		}

		
	}


	system("pause");

	return 0;
}