#include <vector>

#ifndef H_SPECVEC
#define H_SPECVEC

template <typename T>
class VectorWrapper : public std::vector<T> {
    public: 
    
    struct triplet 
    {
        T e0, e1, e2;
    };
    
    triplet get_triplet(int index, T default_val); 

    T get_element(int index, T default_val); 

};

#endif