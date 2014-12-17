#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>
#include <iterator>
#include <stdexcept>
#include "../utils/tool.inc"
//ne fonctionne pas . regarder la ligne 31 .
template <class V,class U> class Correspondance
{
	typedef typename std::list<V*> listV_type;
	typedef typename std::list<U*> listU_type;
	public:
		Correspondance(){

		}
		Correspondance(listV_type* GEObjects,listU_type* IHMObject){

			this->GEObjects=GEObjects;
			this->IHMObject=IHMObject;
		}
		~Correspondance();
	
		void add(V* GEObject,U* IHMObject){
			this->GEObjects->push_back(GEObject);
			this->IHMObject->push_back(IHMObject);
		}
		int getPositionsGEObject(V* GEObject){
			int i=0;
			foreach(listV_type, GEObjects, GEIterator){
				if ((*GEIterator)==GEObject){
					return i;
				}
				else i++;
			}
			return -1;
		}
		void deleteGEObject(V* GEObject){

			int i=getPositionsGEObject(GEObject);
			if (i==-1){
		    throw std::logic_error( "this GEObject isn't in the list" ); 
		  	}
		  GEObjects->erase(i);
		  IHMObjects->erase(i);
		}
		int getPositionIHMObject(U* IHMObject){
			int i=0;
				foreach(listU_type, IHMObjects, IHMIterator){

				if ((*IHMIterator)==IHMObject){
					return i;
				}
				else i++;
			}
			return -1;

		}
		void deleteIHMObject(U* IHMObject){

			int i=getPositionsIHMObject(IHMObject);
			if (i==-1){
		    throw std::logic_error( "this IHMObject isn't in the list" ); 
		  	}
		  GEObjects->erase(i);
		  IHMObjects->erase(i);
		}


	protected:
    listV_type* GEObjects;
    listU_type* IHMObjects;
};

#endif // CARD_H