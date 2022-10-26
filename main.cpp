#include <iostream>

class Persion {
public:
    Persion(int age) {
        this->age = age;
        std::cout << "Persion()" << std::endl;
    }

    Persion(const Persion& p) {
        age = p.age;
        std::cout << "Persion(const Persion& p)" << std::endl;
    }

    Persion(Persion&& p) {
        age = p.age;
        p.age = 0;
        std::cout << "Persion(Persion&& p)" << std::endl;
    }

    Persion& operator=(const Persion& p) {
        age = p.age;
        std::cout << "Persion& operator=(const Persion& p)" << std::endl;
        return *this;
    }

    Persion& operator=(Persion&& p) {
        age = p.age;
        p.age = 0;
        std::cout << "Persion& operator=(Persion&& p)" << std::endl;
        return *this;
    }

    ~Persion() {
        std::cout << "~Persion()" << std::endl;
    }
    
    int age = 0;
};


//wrong
Persion&& get() {
    auto p = Persion{10};
    return std::move(p);
}

Persion get2() {
    auto p = Persion{10};
    return p;
}


template<typename T>
void consume_persion(T&& p) {
    std::cout << p.age << std::endl;
}


int main(int argc, const char * argv[]) {
//    consume_persion(get());
    
    
//    Persion p = get();
    Persion p = get2();
    consume_persion(p);
    
    return 0;
}
