/** Fore ecah macro far list
 *
 * Use as follow :
 * foreach(std::list<int>, intList, i)
 *   (*i) *= 2;
*/
#define foreach(T, c, i) for(T::iterator i = c->begin(), e=c->end(); i!=e; ++i)


