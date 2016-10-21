#include <string.h>


class Ghost
{
    Ghost();
    ~Ghost();

private:
    bool canBeEat;
    bool ghostDisplay;
    int x;
    int y;

public:
    void Move();
    void CreateGhost();
};
