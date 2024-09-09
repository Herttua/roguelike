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

template <typename T> inline component_id get_component_id() noexcept
{
    static component_id type_id = get_component_id();
    return type_id;
}

constexpr std::size_t max_components = 32;
using component_bitset = std::bitset<max_components>;
using component_array = std::array<component*, max_components>;

class component
{
public:
    entity* ent;

    virtual void init()   {}
    virtual void update() {}
    virtual void draw()   {}

    virtual ~component() {}
};

class entity
{
public:
    void update()
    {
        for(auto& c : components) c->update();
        for(auto& c : components) c->draw();
    }

    void draw() {}
    bool is_active() const { return active; }
    void destroy() { active = false; }

    template <typename T> bool has_component() const
    {
        return comp_bits[get_component_id<T>];
    }

    template <typename T, typename... TArgs>
    T& add_component(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->ent = this;
        std::unique_ptr<component> u_ptr{c};
        components.emplace_back(std::move(u_ptr));

        comp_arr[get_component_id<T>()] = c;
        comp_bits[get_component_id<T>()] = true;

        c->init();
        return *c;
    }

    template <typename T> T& get_component() const
    {
        auto ptr(comp_arr[get_component_id<T>()]);
        return *static_cast<T>(ptr);
    }

private:
    bool active = true;
    std::vector<std::unique_ptr<component>> components;
    component_array comp_arr;
    component_bitset comp_bits;
};

#endif //COMPONENT_SYSTEM_HH_