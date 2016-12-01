#include "model/Model.h"
#include "view/View.h"

const bool DEBUG = true;
const bool FULLSCREEN = true;

int main(int, char const **) {
	Model *model = new Model(DEBUG);
	View *view = new View(model, FULLSCREEN);
	model->setJeu_active(false);
    view->Menu();

	//model->setJeu_active(true);
	//view->initialisation();

	// "delete" : Appelle le destructeur & désalloue la mémoire
	delete (view);
	delete (model);

	return 0;
}