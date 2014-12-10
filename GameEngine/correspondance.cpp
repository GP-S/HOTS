#include "correspondance.h"

Correspondance::Correspondance(){

}
Correspondance::Correspondance(std::list<T*> GEObjects,std::list<U*>* IHMObject){

	this->GEObjects=GEObjects;
	this->IHMObject=IHMObject;
}
Correspondance::~Correspondance();
Correspondance::addGEObject();
Correspondance::add(T* GEObject,U* IHMObject);
Correspondance::findGEObject(T* GEObject);
Correspondance::deleteGEObject(T* GEObject);
Correspondance::findIHMObject(U* IHMObject);
Correspondance::deleteIHMObject(U* IHMObject);
Correspondance::checkValidity();
