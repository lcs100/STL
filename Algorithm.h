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

template<class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val){
    for(;first != last;first++){
        if(*first == val) break;
    }
    return first;
}

template<class RandomIterator>
void sort(RandomIterator first, RandomIterator last){
    return sort(first, last, less<typename iterator_traits<RandomIterator>::value_type());
}

template<class RandomIterator, class BinaryPredicate>
void sort(RandomIterator first, RandomIterator last, BinaryPredicate pred){
    if(first >= last || first + 1 == last)
        return;
    if(last - first <= 20)
        return bubble_sort(fist, last, pred);
    
    auto mid = mid3(first, last - 1, pred);
    auto p1 = first, p2 = last - 2;

    while(p1 < p2){
        while(pred(*p1, mid) && (p1 < p2)) ++p1;
        while(!pred(*p2, mid) && (p1 < p2)) --p2;
        if(p1 < p2){
            swap(*pq, *p2);
        }
    }

    swap(*p1, *(last - 2));
    sort(first, p1, pred);
    sort(p1 + 1, last, pred);
}

template<class InputIterator,class OutputIterator>
OutputIt set_intersection(InputIterator first1, InputIterator last1,
                            InputIterator first2, InputIterator last2,
                            OutputIterator d_first){
    while(first != last1 && first2 != last2){
        if(*first1 < *first2) ++first1;
        else {
            if(!(*first2 < *first1)){
                *d_first++ = *first1++;
            }
            ++first2;
        }
    }

    return d_first;
})