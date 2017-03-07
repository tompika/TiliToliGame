#ifndef GAME_H
#define GAME_H


#include <vector>
#include <iostream>
#include <stdio.h>

class Game {

private:

	int N = 3;
	int M = 3;

	int nullPosI;
	int nullPosJ;

	int matrix[3][3];


public:

	Game() {

	}

	Game(const int m[3][3]) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				this->matrix[i][j] = m[i][j];

				if (m[i][j] == 0) {
					nullPosI = i;
					nullPosJ = j;
				}
			}

		}

		

		if (nullPosI < 0 || nullPosI > 2 || nullPosJ < 0 || nullPosJ > 2)
			std::cout << "Nincs megadva kezdo allapot!" << std::endl;
		else
			std::cout << "NULL POS: (" << nullPosI + 1 << ", " << nullPosJ + 1 << ")" << std::endl;

		std::cout << "IntervalCheck: " << this->checkInterval() << std::endl;
		std::cout << "DistinctCheck: " << this->checkDistinct() << std::endl;

		if (check())
		{

			std::cout << "OK!" << std::endl << std::endl;
		}
		else {


			std::cout << "Rossz kezdeti allapot van megadva!" << std::endl << std::endl;
		}

	}

	bool check() {

		if (this->checkInterval() && this->checkDistinct())
			return true;
		else
			return false;
	}



	bool checkInterval() {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				if (matrix[i][j] < 0 || matrix[i][j] > 8)
					return false;
		}


		return true;
	}

	bool checkDistinct() {

		std::vector<int> numbers = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (numbers[matrix[i][j]] != -1)
					return false;
				else
					numbers[matrix[i][j]] = 0;
		
					}
			
		}

		return true;
	}

	void print() {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	void up() {
		if (nullPosI - 1 > 0 || nullPosI - 1 == 0) {
			move(nullPosI, nullPosJ, nullPosI - 1, nullPosJ);
			nullPosI--;

			std::cout << ">> UP <<" << std::endl;
			checkEnd();
			print();
		}
	}

	void  down() {

		if (nullPosI + 1 < 2 || nullPosI + 1 == 2) {
			move(nullPosI, nullPosJ, nullPosI + 1, nullPosJ);
			nullPosI++;

			std::cout << ">> DOWN <<" << std::endl;
			checkEnd();
			print();
		}



	}

	void left() {

		if (nullPosJ - 1 > 0 || nullPosJ - 1 == 0) {
			move(nullPosI, nullPosJ, nullPosI, nullPosJ - 1);
			nullPosJ--;

			std::cout << ">> LEFT <<" << std::endl;
			checkEnd();
			print();
		}

	}

	void right() {

		if (nullPosJ + 1 < 2 || nullPosJ + 1 == 2) {
			move(nullPosI, nullPosJ, nullPosI, nullPosJ + 1);
			nullPosJ++;

			std::cout << ">> RIGHT <<" << std::endl;
			checkEnd();
			print();

		}

	}

	void move(int i1, int j1, int i2, int j2) {

		int temp;

		temp = this->matrix[i1][j1];
		this->matrix[i1][j1] = this->matrix[i2][j2];
		this->matrix[i2][j2] = temp;

	}

	void checkEnd() {

		int value = 1;

		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (matrix[i][j] != value) {
					exit;
				}
				value++;
			}

		if (matrix[2][2] == 0)
			std::cout << "--- Megoldas! ---" << std::endl;
		
			
	}



};





#endif