#include "model/Model.h"
#include "view/View.h"

const bool DEBUG = true;

int main(int, char const **) {
    Model* pmodel(0);
    View* pview(0);
	pmodel = new Model(DEBUG);
	pview = new View(pmodel);
    pview->initialisation();


    pmodel = 0;
    delete pmodel;
    pview = 0;
    delete pview;


	return 0;
}