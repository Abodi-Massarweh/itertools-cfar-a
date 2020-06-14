//
// Created by abodi on 13/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_RANGE_HPP
#define ITERTOOLS_CFAR_A_RANGE_HPP

namespace itertools {

    class range {
        int m_first;
        int m_last;
    public:
        class iterator
        {
        public:
            int m_ptr;
            iterator(const int& val):m_ptr(val){}
            iterator& operator++()
            {
                this->m_ptr=m_ptr+1;
                return *this;
            }
            bool operator!=(const iterator& itr)
            {
                return (this->m_ptr)!=(itr.m_ptr);
            }
            bool operator ==(const iterator& itr) {
                return (m_ptr == itr.m_ptr);
            }
            int operator*()
            {
                return (this->m_ptr);
            }
        };
        range(int first,int last):m_first(first),m_last(last){}
        range::iterator end(){return iterator(this->m_first);}
        range::iterator begin()
        {
            return iterator(this->m_last);
        }

    private:


    };

}
#endif //ITERTOOLS_CFAR_A_RANGE_HPP
