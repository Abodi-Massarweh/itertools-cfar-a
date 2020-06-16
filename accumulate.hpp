//
// Created by abodi on 13/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_ACCUMULATE_HPP
#define ITERTOOLS_CFAR_A_ACCUMULATE_HPP
#include "range.hpp"
namespace itertools {

    struct operation {
    public:
        template<typename T>
         T operator()(T a, T b) {
            return a + b;
        }
    };

    template<typename CONT, class FUNC,class TYPE>
    class Accumulate {
    public:
        CONT m_container;
        FUNC m_function;
    public:
        class iterator;
        iterator begin() { return iterator(this->m_container.begin(), this->m_container.end(), m_function); }
        iterator end() { return iterator(this->m_container.end(), this->m_container.end(), m_function); }
        Accumulate(const CONT &container, FUNC functor) : m_container(container), m_function(functor) {}
        Accumulate(const range container) : m_container(container), m_function(FUNC()) {}
        CONT& get_container(){return m_container;}
        FUNC& get_function(){return m_function;}

        class iterator
        {
        public:
            typename CONT::iterator current;
            typename CONT::iterator end;
            TYPE sum;
            FUNC m_functor;
             iterator(const typename CONT::iterator& it, const typename CONT::iterator& end, FUNC other_functor):current(it),end(end),m_functor(other_functor),sum(*current){}
            //iterator(const typename CONT::iterator& it):current(it),m_functor(it.m_functor),sum(*current){}
            TYPE operator*()
            {
                return this->sum;
            }
            iterator& operator++()
            {
                ++current; ///legal
                //sum+=*current; //old
                if(current != end)
                    sum=m_functor(sum,*current);
                return *this;
            }
            bool operator !=(const iterator& other){return current!=other.current; }


        };



    };

    template<typename CONT,typename FUNC=operation>
    auto accumulate(CONT container,FUNC func=operation())
    {

        return Accumulate<CONT,FUNC,decltype(*(container.begin()))>(container,func);
    }
}
//using namespace itertools;


#endif //ITERTOOLS_CFAR_A_ACCUMULATE_HPP
