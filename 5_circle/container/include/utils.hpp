#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {
template <bool B, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {
  typedef T type;
};

template <class T, bool v>
struct integral_constatant {
  static const bool value = v;
  typedef T value_type;
  typedef integral_constant type;
  constexpr operator T() { return v; }
};

template <class T>
struct is_integral : public ft::integral_constatant<T, false> {};

}  // namespace ft
#endif