//
// Created by abodi on 13/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_ACCUMULATE_HPP
#define ITERTOOLS_CFAR_A_ACCUMULATE_HPP

namespace itertools {
    template <typename T>
    struct operation
            {
    public:
        T operator()(T a,T b){
            return  a+b;
        }
    };
    template <class M,class F=itertools::operation<M>>
    class accumulate {
    public:


        class iterator
        {
        public:
            iterator(typename M::iterator first, typename M::iterator last,typename F::operation operation):m_first(first),m_last(last),m_operation(operation),m_current_sum(*first){}
            iterator(const iterator& itr){}
            M& operator*()
            {
                return m_current_sum;
            }
            iterator& operator++(){return *this;}

        private:
           typename M::iterator m_first;
            typename M::iterator m_last;
            typename F::operation m_operation;
            M m_current_sum;
        };

        iterator begin(){return this->m_container.begin();}
        iterator end(){return this->m_container.end();}
        accumulate(const range& rng):m_container(){}
    private:
        M m_container;
        F m_function;


    };
}

#endif //ITERTOOLS_CFAR_A_ACCUMULATE_HPP
