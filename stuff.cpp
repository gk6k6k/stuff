template <typename ...Ts> void __lcp(const char* file, int line, Ts&&... args) { std::cout<<"==>"<<file<<":"<<line; using expander = int[]; (void) expander {0, (void(std::cout << ' ' << std::forward<Ts>(args)), 0)...}; std::cout<<std::endl; } 
#define log(...) __lcp(__FILE__, __LINE__, __VA_ARGS__)

template <template <typename> typename Field>
struct Config {
    Field<int> a;
    Field<int> b;
};

template <typename T>
struct Static {
    T value;
    T& operator->() {
        return value;
    }

    Static<T>& operator=(const T& t) {
        value = t;
        return *this;
    }
};

int main() {

Config<Static> c;
c.a = 1;
c.b = 2;

Config<std::optional> delta;

delta.b = 3;
//c.apply(delta); //could be done
//c.apply(c);     //to override all config

}
