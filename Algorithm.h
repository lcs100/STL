#include "Iterator.h"

template<typename InputIterator, class Distance>
void _advance(InputIterator& it, Distance n, input_iterator_tag){
    assert(n >= 0);
    while(n--){
        ++it;
    }
}

void advance(InputIterator& it, Distance n){
    typedef typename iterator_traits<InputIterator>::iterator_category iterator_category;
    _advance(it, n, iterator_category());
}

template<class InputIterator>
typename iterator_traits<InputIterator>::difference_type
_distance(InputIterator first, InputIterator last, input_iterator_tag){
    typename iterator_traits<InputIterator>::difference_type dist = 0;
    while(first++ != end){
        ++dist;
    }
    return dist;
}

template<class Iterator>
typename iterator_traits<Iterator>::difference_type
distance(Iterator first, Iterator last){
    typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    return _distance(first, last, iterator_category());
}