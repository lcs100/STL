template<class T>
struct unary_function {
    typedef T argument_type;
    typedef T result_type;
};

template<class T>
struct binary_function {
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;
};

template<class T>
struct less {
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;

    result_type operator() (const first_argument_type& x, const second_argument_type& y){
        return x < y;
    }
};

template<class T>
struct equal_to {
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;

    result_type operator() (const first_argument_type& x, const second_argument_type& y){
        return x == y;
    }
};

template<class T>
struct identity: public unary_function<T> {
    const T& operator()(const T& x) const { return x;}
};

template<class T>
struct select1st: public unary_function<T, typename T::first_type>{
    const typename T::first_type& operator()(const T& x) const { return x.first; }
};