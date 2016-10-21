#include <string.h>

class Coin
{
public:
    Coin();
    ~Coin();
    void CreateCoin();

private:
    bool isVisible;
    int xc;
    int yc;
};
