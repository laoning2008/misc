#include <iostream>


//https://www.cnblogs.com/wangpei0522/p/4472548.html
//https://blog.csdn.net/m0_37599645/article/details/112860603
//https://blog.csdn.net/Tanswer_/article/details/77005674
//https://blog.csdn.net/zhangzq86/article/details/80453199


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
    
    Persion&& p = get2();
//    Persion p = get2();
    consume_persion(p);
    
    return 0;
}
