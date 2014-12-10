#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>
#include <iterator>
#include <stdexcept>


template <class T,class U> class Correspondance
{
	public:
		Correspondance();
		Correspondance(std::list<T*> GEObjects,std::list<U*>* IHMObject);
		~Correspondance();
		void add(T* GEObject,U* IHMObject);
		bool findGEObject(T* GEObject);
		void deleteGEObject(T* GEObject);
		bool findIHMObject(U* IHMObject);
		void deleteIHMObject(U* IHMObject);
		checkValidity();


	protected:
    std::list<T*>* GEObjects;
    std::list<U*>* IHMObjects;
};

#endif // CARD_H