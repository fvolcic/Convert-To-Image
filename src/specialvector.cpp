#include <vector>
#include "specialvector.h"

using namespace std;

template<class T>
typename VectorWrapper<T>::triplet VectorWrapper<T>::get_triplet(int index, T default_val){
    
    return triplet{get_element(index*3, default_val), get_element(index*3+1, default_val), get_element(index*3+2, default_val)};

}

template<class T>
T VectorWrapper<T>::get_element(int index, T default_val){
    if(index >= this->size()){
        return default_val; 
    }
    return this->operator[](index); 
}

template class VectorWrapper<unsigned char>; 
template class VectorWrapper<char>;
template class VectorWrapper<int>;