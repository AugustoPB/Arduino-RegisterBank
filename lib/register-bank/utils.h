#ifndef UTILS_H
#define UTILS_H

namespace detail
{
    // FNV-1a 32bit hashing algorithm.
    constexpr unsigned long fnv1a_32(char const* s, unsigned int count)
    {
        return ((count ? fnv1a_32(s, count - 1) : 2166136261u) ^ s[count]) * 16777619u;
    }
}    // namespace detail

constexpr unsigned long operator"" _hash(char const* s, unsigned int count)
{
    return detail::fnv1a_32(s, count);
}


#endif /* UTILS_H */