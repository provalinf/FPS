#include "model/Model.h"
#include "view/View.h"

const bool DEBUG = true;
const bool FULLSCREEN = false;

int main(int, char const **) {

	Model *model = new Model(DEBUG);
	View *view = new View(model, FULLSCREEN);
	view->initialisation();

	return 0;
}