#include "GameLogic.h"


int main(){

	//Needed variables and pointers
	TAFF::TAFFRESULT tr;
	TAFF::ITaffFactory * p_TaffFactory = NULL;
	TAFF::TaffNodeObject * p_TaffFirstObject = NULL;
	TAFF::TaffNodeObject *p_tObjIterator = new TAFF::TaffNodeObject;

	char choice;
	int counter = 0;

	printf("WELCOME TO TAFFER ENTITY EDITOR v 0.01!\n");

	tr = TAFF::CreateTaffFactory(&p_TaffFactory);

	if (tr == TAFF_OK) {
		tr = p_TaffFactory->CreateTaffObject(TAFF::TAFF_NODE_OBJECT, &p_TaffFirstObject);
	}
	else { printf("Error occured creating Taff Factory!\n"); }

	p_TaffFirstObject->nextObject = NULL;
	p_tObjIterator = p_TaffFirstObject;

	while (1)
	{
		std::cout << "If you want to create new object press [ENTER]..." << std::endl;

		choice = _getch();

		if (choice == 13) {

			p_TaffFactory->CreateTaffObject(TAFF::TAFF_NODE_OBJECT, &p_tObjIterator->nextObject);

			p_tObjIterator = p_tObjIterator->nextObject;

			counter++;
		}

		else { break; }
	}

	p_tObjIterator = p_TaffFirstObject;

	for (int i = 0; i <= counter; i++)
	{
		float x, y;

		p_tObjIterator->GetObjCoordinates(&x, &y);
		std::cout << x << " " << y << std::endl;

		p_tObjIterator = p_tObjIterator->nextObject;
	}

	system("pause");

	return 0;

}

//Here goes TaffFactory fucntions implementations.

TAFF::TAFFRESULT TAFF::CreateTaffFactory(TAFF::ITaffFactory **ppTaffFactory){
	TAFF::ITaffFactory *createdTaffFactory = new TAFF::FactoryObject;
	*ppTaffFactory = createdTaffFactory;

	return TAFF::TAFFRESULT(TAFF_OK);
}

//TaffObjects functions implementations.

TAFF::TAFFRESULT TAFF::FactoryObject::CreateTaffObject(TAFF::TAFF_OBJECT_TYPE tot, TAFF::TaffNodeObject ** ppTaffObject) {
	if (tot == TAFF::TAFF_NODE_OBJECT) {
		*ppTaffObject = new TaffNodeObject;
		float x, y;
		int choice2;
		std::cout << "Please, provide the x and y coordinate for object created... ";
		std::cin >> x;
		std::cin >> y;
		(*ppTaffObject)->SetObjCoordinates(x, y);
		
		std::cout << "Press [ENTER] to make this node a town." << std::endl;;
		choice2 = _getch();

		if (choice2 == 13)
		{
			(*ppTaffObject)->setBooleanParams(true);
		}
	}

	else {
		return TAFF_NULL_RESULT;
	}
	
	if (*ppTaffObject != NULL) {
		return TAFF_OK;
	}

	else { return TAFF_NULL_RESULT; }
}

void TAFF::TaffNodeObject::SetObjCoordinates(float x, float y){
	objX = x; objY = y;
}

void TAFF::TaffNodeObject::GetObjCoordinates(float *x, float *y){
	*x = objX;
	*y = objY;
}

/*void TAFF::TaffNodeObject::SetNextObj(TaffNodeObject * tNextNodeObj)
{
	this->nextObject = tNextNodeObj;
}*/

void TAFF::TaffNodeObject::GetNextObj(TaffNodeObject * tObjectToGet)
{
	tObjectToGet = this->nextObject;
}

void TAFF::TaffNodeObject::setBooleanParams(bool town)
{
	isTown = town;
}

void TAFF::TaffNodeObject::getBooleanParams(bool * town)
{
	*town = isTown;
}
