#include <iostream>
#include <memory>
#include <vector>

struct Element {
    Element() :m_elem{0} {
        std::cout << "Element::Element(" << m_elem << ")\n";
    }

    explicit Element(int i) : m_elem{i} {
        std::cout << "Element::Element(" << m_elem << ")\n";
    }

    ~Element() {
        std::cout << "Element::~Element(" << m_elem << ")\n";
    }

    int m_elem;
};


struct Item {
    Item() : m_item{0} {
        std::cout << "Item::Item(" << m_item << ")\n";
    }

    explicit Item(int i) : m_item{i} {
        std::cout << "Item::Item(" << m_item << ")\n";
    }

    ~Item() {
        std::cout << "Item::~Item(" << m_item << ")\n";
    }

    int m_item;
};


struct Container {
    Container() {
        std::cout << "Container::Container()\n";
    }
    ~Container() {
        std::cout << "Container::~Container()\n";
    }
};


struct Member {
    Member() {
        std::cout << "Member::Member()\n";
    }
    ~Member() {
        std::cout << "Member::~Member()\n";
    }
};


