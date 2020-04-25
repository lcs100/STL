#ifndef _ITERATOR_H
#define _ITERATOR_H
#include <cstddef>

namespace mySTL{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag: public input_iterator_tag {};
    struct bidirectional_iterator_tag: public forward_iterator_tag {};
    struct random_access_iterator_tag: public bidirectional_iterator_tag {};

    template<typename T, class Distance>
    struct input_iterator {
        typedef input_iterator_tag iterator_category;
        typedef T                  value_type;
        typedef Distance           difference_type;
        typedef T*                 pointer;
        typedef T&                 reference;
    };

    struct output_iterator {
        typedef output_iterator_tag iterator_category;
        typedef void                value_type;
        typedef void                difference_type;
        typedef void                pointer;
        typedef void                reference;
    };

    template<typename T, class Distance> 
    struct forward_iterator {
        typedef forward_iterator_tag iterator_category;
        typedef T                    value_type;
        typedef Distance             difference_type;
        typedef T*                   pointer;
        typedef T&                   reference;
    };

    template<typename T, class Distance>
    struct bidirectional_iterator {
        typedef bidirectional_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef Distance                   difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template<typename T, class Distance>
    struct random_access__iterator {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef Distance                   difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template<class Category, class T, class Distance = ptrdiff_t,
    class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef Category   iterator_category;
        typedef T          value_type;
        typedef Distance   
    }




}







