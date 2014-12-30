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
			this->IHMObjects->push_back(IHMObject);
		}
		int getGEObjectPosition(V* GEObject){
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

		V* getGEObject(int pos){

			typename listV_type::iterator GEIterator = GEObjects->begin() ;
			typename listV_type::iterator GEObjectsEnd = GEObjects->end() ;
			for( GEIterator; GEIterator!=GEObjectsEnd; ++GEIterator){

				if(!pos){
					pos--;
				}
				else return *GEIterator;
			}
			throw std::logic_error( "invalid position in IHMObject list" ); 
		}
		
		V* getGEObject(U* IHMObject){
			typename listV_type::iterator GEIterator = GEObjects->begin() ;
			typename listV_type::iterator GEObjectsEnd = GEObjects->end() ;
			typename listU_type::iterator IHMIterator = IHMObjects->begin() ;

			for ( GEIterator; GEIterator!=GEObjectsEnd; ++GEIterator ) {
			    ++IHMIterator;

			    if ( *IHMIterator == IHMObject ) {
				return *GEIterator;
			    } 
			}
			throw std::logic_error ( "this IHMObject is not in the list" );
		}

		void deleteGEObject(V* GEObject){

			int i=getGEObjectPosition(GEObject);
			if (i==-1){
		    throw std::logic_error( "this GEObject isn't in the list" ); 
		  	}
		  GEObjects->erase(i);
		  IHMObjects->erase(i);
		}
		int getIHMObjectPosition(U* IHMObject){
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

		U* getIHMObject(int pos){

			typename listU_type::iterator IHMIterator = IHMObjects->begin() ;
			typename listU_type::iterator IHMObjectsEnd = IHMObjects->end() ;
			for( IHMIterator; IHMIterator!=IHMObjectsEnd; ++IHMIterator){

				if(!pos){
					pos--;
				}
				else return *IHMIterator;
			}
			throw std::logic_error( "invalid position in IHMObject list" ); 
		}

		U* getIHMObject(V* GEObject){
			typename listU_type::iterator IHMIterator = GEObjects->begin() ;
			typename listU_type::iterator IHMObjectsEnd = GEObjects->end() ;
			typename listV_type::iterator GEIterator = IHMObjects->begin() ;

			for ( IHMIterator; IHMIterator!=IHMObjectsEnd; ++IHMIterator ) {
			    ++GEIterator;

			    if ( *GEIterator == GEObject ) {
				return *IHMIterator;
			    } 
			}
			throw std::logic_error ( "invalid position in IHMObject list" );
		}
		
		void deleteIHMObject(U* IHMObject){

			int i=getIHMObjectPosition(IHMObject);
			if (i==-1){
		    throw std::logic_error( "this IHMObject isn't in the list" ); 
		  	}
		  GEObjects->erase(i);
		  IHMObjects->erase(i);
		}

		U* operator[](V* i){
		  return getIHMObject(i);
		}
		
		V* operator[](U* i){
		  return getGEObject(i);
		}
		
		void setObject(U* IHMObject, V* newGEObject){
			typename listV_type::iterator GEIterator = GEObjects->begin() ;
			typename listV_type::iterator GEObjectsEnd = GEObjects->end() ;
			typename listU_type::iterator IHMIterator = IHMObjects->begin() ;

			for ( GEIterator; GEIterator!=GEObjectsEnd; ++GEIterator ) {
			    ++IHMIterator;

			    if ( *IHMIterator == IHMObject ) {
				*GEIterator=newGEObject;
				return;
			    } 
			}
			throw std::logic_error ( "this IHMObject is not in the list" );
		}
		
		void setObject(V* GEObject, U* newIHMObject){
			typename listU_type::iterator IHMIterator = GEObjects->begin() ;
			typename listU_type::iterator IHMObjectsEnd = GEObjects->end() ;
			typename listV_type::iterator GEIterator = IHMObjects->begin() ;

			for ( IHMIterator; IHMIterator!=IHMObjectsEnd; ++IHMIterator ) {
			    ++GEIterator;

			    if ( *GEIterator == GEObject ) {
				*IHMIterator=newIHMObject;
				return;
			    } 
			}
			throw std::logic_error ( "invalid position in IHMObject list" );
		}
	protected:
    listV_type* GEObjects;
    listU_type* IHMObjects;
};

#endif // MATCH_H