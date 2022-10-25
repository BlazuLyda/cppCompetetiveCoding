#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

const int resX = 22, resY = 22;

struct Window {
	char win[resX][resY];
		
	struct Ball {
		float x, y;
		float v, a;
	};
	
	vector<Ball> objects;
	
	void runPhysics() {
		for (int x = 0; x < resX; ++x) {
			win[x][0] = '-';
			win[x][resY-1] = '-';
		}
		
		for (int y = 0; y < resY; ++y) {
			win[0][y] = '|';
			win[resX-1][y] = '|';
		}
		
		for (unsigned int i = 0; i < objects.size(); i++) {
			win[(int)objects[i].x][(int)objects[i].y] = ' ';
			
			/*
			if (objects[i].y < 0.005) {
				objects[i].a = 0;
			}
			else 
				objects[i].a = -0.5;
			*/
			
			objects[i].v += objects[i].a;
			objects[i].y += objects[i].v;
			
			
			if (objects[i].y <= 0) {
				objects[i].y *= -1;
				objects[i].v *= -1;
			}
			
			
			printf("%d. x:%2.4f y:%2.4f | v:%2.4f a:%2.4f\n", i, objects[i].x, objects[i].y, objects[i].v, objects[i].a);
			
			
			win[(int)objects[i].x][(int)objects[i].y] = 'o';
		}
	}
	
	void spawnBall(float x, float y) {
		Ball ball = {x, y, 0, -0.5};
		objects.push_back(ball);
	}
	
	void drawFrame() {
		system("clear");
		
		runPhysics();
		
		for (int y = resY-1; y >= 0; --y) {
			for (int x = 0; x < resX; ++x) {
				printf("%c", win[x][y]);
			}
			printf("\n");
		}
	}
	
	void emptyWindow() {
		for (int x = 0; x < resX; ++x) {
			for (int y = 0; y < resY; ++y) {
				win[x][y] = ' ';
			}
		}
		
		for (int x = 0; x < resX; ++x) {
			win[x][0] = '-';
			win[x][resY-1] = '-';
		}
		
		for (int y = 0; y < resY; ++y) {
			win[0][y] = '|';
			win[resX-1][y] = '|';
		}
		
	}
};

int main() {
	Window window;
	
	window.emptyWindow();
	
	for (int i = 1; i < 20; i+=2) {
		window.spawnBall(i, i);
	}
		
	
	//getchar(); getchar();
	usleep(1000000);
	
	while (true) {
		getchar(); getchar();
		
		window.drawFrame();
		
		usleep(1000000);
	}
	
	return 0;
}
