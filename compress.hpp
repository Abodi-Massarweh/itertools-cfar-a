//
// Created by abodi on 13/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_COMPRESS_HPP
#define ITERTOOLS_CFAR_A_COMPRESS_HPP

namespace itertools {
    template<class CONTAINER,class BOOL_CONTAINER>
    class Compress {
    private:
        CONTAINER m_container;
        BOOL_CONTAINER m_bool_container;
    public:
        class iterator;
        Compress(const CONTAINER& other_container,const BOOL_CONTAINER& other_bool_container):m_container(other_container),m_bool_container(other_bool_container){}
        iterator begin(){return iterator(m_container.begin());}
        iterator end(){return iterator(m_container.end());}
        class iterator
        {
        private:
            typename CONTAINER::iterator m_itr;
        public:
            iterator(const typename CONTAINER::iterator& other):m_itr(other){}
            iterator& operator++()
            {
                ++m_itr;
                return *this;
            }
            bool operator!=(const iterator& other){return m_itr!=other.m_itr;}
            auto operator*()
            {
                return *m_itr;
            }
        };
    };


    template<class CONT,class BOOL_CONT>
    auto compress(CONT container,BOOL_CONT bool_container)
    {
        return Compress<CONT,BOOL_CONT>(container,bool_container);
    }


}
#endif //ITERTOOLS_CFAR_A_COMPRESS_HPP
