//
// Created by abodi on 13/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_FILTERFALSE_HPP
#define ITERTOOLS_CFAR_A_FILTERFALSE_HPP

namespace itertools{
    template<class FUNCTOR,class CONTAINER>
class FilterFalse {
public:
    class iterator;
    FilterFalse(FUNCTOR& functor,CONTAINER& container):m_functor(functor),m_container(container){}
    iterator begin(){return iterator(m_container.begin(),m_functor,m_container);}
    iterator end(){return iterator(m_container.end(),m_functor,m_container);}
    class iterator
    {
    public:
        iterator(const typename CONTAINER::iterator& itr,const FUNCTOR& functor, CONTAINER& m_container):m_iterator(itr),m_functor(functor),m_container_(m_container){
        }

        iterator& operator++()
        {
            if(m_functor(*m_iterator))
            while(m_functor(*m_iterator)) {
                if(this->m_iterator==m_container_.end()) break;
                ++m_iterator;

            }
            else ++m_iterator;
            return *this;
        }
        auto operator*()
        {
//            while(m_functor(*m_iterator)) {
//                //if(this->m_iterator==m_container_.end()) break;
//                ++(*this);
//
//            }

            return *m_iterator;
        }

        bool operator!=(const iterator& other){return m_iterator!=other.m_iterator;}
        //bool operator!=(const typename CONTAINER::iterator& other){return m_iterator!=other;}
        //bool operator==(const iterator& other){return !(m_iterator!=other);}

    private:
        typename CONTAINER::iterator m_iterator;
        FUNCTOR m_functor;
        CONTAINER m_container_;

    };

private:
    FUNCTOR m_functor;
    CONTAINER m_container;
};

    template<typename F,typename CONTAINER>
    auto filterfalse(F functor,CONTAINER container)
    {
        return FilterFalse<F,CONTAINER>(functor,container);
    }
}
#endif //ITERTOOLS_CFAR_A_FILTERFALSE_HPP
