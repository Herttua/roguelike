#ifndef COMPONENT_SYSTEM_HH_
#define COMPONENT_SYSTEM_HH_

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array> 

class component;
class entity;

using component_id = std::size_t;

inline component_id get_component_id()
{
    static component_id last_id = 0;
    return last_id++;
}

template<typename T> inline component_id get_component_id() noexcept
{
    static component_id type_id = get_component_id();
    return type_id;
}

#endif //COMPONENT_SYSTEM_HH_