#include "model/Model.h"
#include "view/View.h"

const bool DEBUG = true;

int main(int, char const **) {

	Model *model = new Model(DEBUG);
	View *view = new View(model);
	view->initialisation();

	return 0;
}