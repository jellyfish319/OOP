#include <algorithm>
#include <utility>

template<typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end) {
  N n;
  typename T::iterator endd = std::prev(end);
  for (; begin != endd ; --endd) {
    typename T::iterator temp = begin;
    for (; temp != endd ; ++temp) {
      typename T::iterator comp = std::next(temp);
      if (n(*temp, *comp) == 1) {
        std::swap(*temp, *comp);
      }
    }
  }
}

