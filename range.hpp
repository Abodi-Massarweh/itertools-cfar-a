//
// Created by abodi on 13/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_RANGE_HPP
#define ITERTOOLS_CFAR_A_RANGE_HPP

namespace itertools {
    class range {
        int* head;
    public:
        class iterator
        {
        public:
            int* m_ptr;
            iterator(int* iptr):m_ptr(iptr){}
            iterator& operator++()
            {
                this->m_ptr=m_ptr+1;
                return *this;
            }
            bool operator!=(const iterator& itr)
            {
                return *(this->m_ptr)!=*(itr.m_ptr);
            }
            int operator*()
            {
                return *(this->m_ptr);
            }
        };
        range(int x,int y){}
        range::iterator end(){return iterator(this->head);}
        range::iterator begin()
        {
            return iterator(this->head);
        }

    private:


    };

}
#endif //ITERTOOLS_CFAR_A_RANGE_HPP
