// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include<list>
#include<array>
#include<utility>
#include <stdlib.h>
#include<Windows.h>
#include <SDL.h>

using namespace std;

class snake {
	private:
		pair<int,int> head = { 0,0 };	
		//pair<int,int> tail = { 0,0 };
		int length = 1;
		char direction = 'r';
	public:
		list<pair<int, int>> body;
		snake() {
			this->body.push_back({ 0,0 });
			this->body.push_back({ 1,0 });
			this->body.push_back({ 2,0 });
			this->body.push_back({ 3,0 });
			this->body.push_back({ 4,0 });
		}
		void print_body() {
			for (auto x : body) {
				cout << x.first << "-" << x.second << ",";
			}
			cout<< endl;
		}
		void move(char dir) {
			this->direction = dir;
			head = body.back();
			body.pop_front();
			switch (dir) {
				case 'u':
					head.first = body.back().first;
					head.second = body.back().second -1;
					break;
				case'd':
					head.first = body.back().first;
					head.second = body.back().second + 1;
					break;
				case 'r':
					head.first = body.back().first +1;
					head.second = body.back().second;
					break;
				case'l':
					head.first = body.back().first;
					head.second = body.back().second - 1;
					break;
			}
			this->body.push_back(make_pair(head.first, head.second));
		}
		void enlarge() {
			this->body.push_back(make_pair(head.first, head.second));
		}
};
class u_interface {

public:
	const int GRID_SIZE = 20;
	array<array<int,50>, 50> BG;
	SDL_Window* window;
	SDL_Renderer* renderer;
	u_interface(int WINDOW_WIDTH = 250, int WINDOW_HEIGHT =250) {
		SDL_Init(SDL_INIT_VIDEO);
		// Create a window
		this->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	void printUI() {
		for (int x = 0; x < 50; x++) {
			for (int y = 0; y < 50; y++)
				cout << BG[x][y] << " ";
			cout << endl;
		}


	}
	// Draw the background and the body using SDL
	void drawBGandBody(std::array<std::array<int, 50>, 50> bg, std::list<std::pair<int, int>> body) {
		// Loop through the background array
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				// Create a rectangle with the grid size and position
				SDL_Rect rect;
				rect.x = i * GRID_SIZE;
				rect.y = j * GRID_SIZE;
				rect.w = GRID_SIZE;
				rect.h = GRID_SIZE;

				// Check if the current position is in the body list
				bool inBody = false;
				for (auto p : body) {
					if (p.first == i && p.second == j) {
						inBody = true;
						break;
					}
				}

				// Set the draw color to green or red depending on the inBody flag
				if (inBody) {
					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
				}
				else {
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
				}

				// Render the rectangle
				SDL_RenderFillRect(renderer, &rect);
			}
		}
		SDL_RenderPresent(renderer);
	}



	void redrawUI(snake sna) {
		system("cls");
		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 50; x++) {
				for (auto item : sna.body) {
					if ((item.first == x) && (item.second == y)) {
						BG[x][y] = 1;
						//cout << 1;
					}
					else {
						BG[x][y] = 0;
						//cout << 0;
					}
					if (BG[x][y] == 1){
						break;
					}
						
				}
				//cout << "(" << BG[x][y] << "," << x << "," << y << ")";
				cout << BG[x][y];
			}
			cout << endl;
		}
		Sleep(500);
	}
	~u_interface() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
};
int main(int argc, char* argv[])
{
	const int rate = 500;
	u_interface interfaces(250,250);
    cout << "start\n";
	snake sn;
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('d');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('d');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('d');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('d');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('r');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('r');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('r');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('u');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	sn.move('u');
	Sleep(rate);
	interfaces.drawBGandBody(interfaces.BG, sn.body);
	Sleep(5000);
	return 0;
}

