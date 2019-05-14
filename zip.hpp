#include "iostream"


namespace itertools {
//template class zip, that have the method of:begin, end.
template <typename Template1, typename Template2>
class zip {

private:
Template1 it1;
Template2 it2;

public:
zip(Template1 start, Template2 end) :  it1(start), it2(end) {
}

auto begin(){
        return iterator<decltype(it1.begin()),decltype(it2.begin())>(it1.begin(), it2.begin());
}                                                                                                   // iteratable object

auto end() {
        return iterator<decltype(it1.end()),decltype(it2.end())>(it1.end(), it2.end());
}                                                                                          // iteratable object
//template class iterator, that have the method of:++, *(), !=,==.
template <typename C1, typename C2>
class iterator {

private:
C1 it1;             // iterator A
C2 it2;             // iterator B

public:
iterator(C1 itA, C2 itB) : it1(itA), it2(itB)  {
}

iterator<C1,C2>& operator++() {
        ++it1;
        ++it2;
        return *this;

}


std::pair<decltype(*it1),decltype(*it2)> operator*() const {

        return std::pair<decltype(*it1),decltype(*it2)> (*it1, *it2);
}

bool operator!=(iterator<C1,C2>  it){
        return (it1 != it.it1) && (it2 != it.it2);

}
bool operator==(iterator<C1,C2>  it){
        return (it1 == it.it1) && (it2 != it.it2);

}


};        


};
template <typename T,typename E>
std::ostream &operator<<(std::ostream &os, const std::pair<T,E> &c){
        os << c.first << ',' << c.second;

        return os;
}
}
