#ifndef MATCH_H
#define MATCH_H

#include <string>
#include <list>
#include <iterator>
#include <stdexcept>

/*
* Template Match . Used to communicate between IHM and GE
* @author armand
*/

template <class V,class U> class Match
{
	typedef typename std::list<V*> listV_type;
	typedef typename std::list<U*> listU_type;
	public:
		Match(){

		}
		Match(listV_type* GEObjects,listU_type* IHMObject){

			this->GEObjects=GEObjects;
			this->IHMObject=IHMObject;
		}
		~Match();
	
		void add(V* GEObject,U* IHMObject){
			this->GEObjects->push_back(GEObject);
			this->IHMObject->push_back(IHMObject);
		}
		int getPositionsGEObject(V* GEObject){
			int i=0;
			typename listV_type::iterator GEIterator = GEObjects->begin() ;
			typename listV_type::iterator GEObjectsEnd = GEObjects->end() ;
			for( GEIterator; GEIterator!=GEObjectsEnd; ++GEIterator){
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

			typename listU_type::iterator IHMIterator = IHMObjects->begin() ;
			typename listU_type::iterator IHMObjectsEnd = IHMObjects->end() ;
			for( IHMIterator; IHMIterator!=IHMObjectsEnd; ++IHMIterator){

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

#endif // MATCH_H