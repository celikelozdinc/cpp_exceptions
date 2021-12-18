#include "definitions.h"

struct Main {
    /**
     * @brief Construct a new Main object
     * If fails to acquire a resource,
     * the only wat it can indicate a failure is by
     * "throwing an exception", because
     * "can not return any value"
     */
    Main() {
        std::cout << "Main::Main()\n";
        Member m_1{};  //=> will be destructed due to stack unwinding

        new_item = new Item{};  //=> memory leakage if exceptions is thrown just after this line
        m_Item = std::make_unique<Item>(10);  //=> will be destructed due to stack unwinding

        myCont = static_cast<Container*>(malloc(sizeof(5*sizeof(Container))));  //=> does not construct any object
        m_Container = new Container[5];  //=> memory leakage if exceptions is thrown just after this line
        std::vector<Element> m_Elements;
        m_Elements.reserve(3);  //=> does not construct any object
        Element el1{10};  //=> will be destructed due to stack unwinding
        Element el2{};  //=> will be destructed due to stack unwinding
        m_Elements.push_back(el1);  //=> will be destructed due to stack unwinding

        throw std::runtime_error("Failed to acquire resources!");

        Member m_2{};
        Item m_item{};
    }
    ~Main() {
        std::cout << "Main::~Main()\n";
        delete new_item;
        delete[] m_Container;
        free(myCont);
    }

    Container* m_Container;
    Container* myCont;
    std::unique_ptr<Item> m_Item;
    Item* new_item;
};

int main() {
    try {
        Main m{};
    } catch(...) {
        std::cout << "Caught an exception via ellipsis notation!\n";
    }
    return 0;
}