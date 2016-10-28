#include "model/Model.h"
#include "view/View.h"

int main(int, char const **) {

	Model* model = new Model();
	View* view = new View(model);
	view->initialisation();

	return 0;
}