#include <string.h>
#include "../model/Model.h"

class Gameobject {
private:
	Model *model;

    time_t secondes;
    struct tm instant;

    float x1 = 4;
    float y1 = 2;

    float x2 = 45;
    float y2 = 9;

    float x3 = 25;
    float y3 = 26;

    float x4 = 18;
    float y4 = 2;

    float ennemyspeed = 0.1;

    int up_y;
    int up_x;    //up

    int down_y;
    int down_x;  //down

    int left_y;
    int left_x;   //left

    int right_y;
    int right_x;   //right

    float tempx;
    float tempy;


public:
	Gameobject(Model *model);

	void CreateCoin(int x, int y);

	void CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z);

	void CreateSol();

	~Gameobject();

	void GenerateMap();

    void Ghost1();

    void Ghost2();

    void Ghost3();

    void Ghost4();
};

