#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <iterator>
#include <fstream>
#include <list>

#include <iomanip>
#include <locale>

using namespace std::string_literals;


std::string remove_repeating_spaces(const std::string& str){
    std::string result = str;

    auto it = std::unique(begin(result), end(result), [](char a, char b){
        return (::isspace(a) && isspace(b));
    });

    result.erase(it, end(result));

    return result;
}

std::string remove_spaces(const std::string& str){
    std::string result;
    return result;
}

std::string toLower(const std::string& str){
    std::string result;
    std::transform( begin(str), 
                    end(str), 
                    std::back_inserter(result), 
                    ::tolower );

    return result;
}

std::string trim(const std::string& s){
    const char spaces[] = {" \t\n"};
    std::size_t first = s.find_first_not_of(spaces);
    std::size_t last = s.find_last_not_of(spaces);

    //return {s.begin() + a, s.begin() + b + 1};
    return s.substr(first, (last - first + 1));
}

template<class Func, class T, class ...Args>
void test_func(Func func, T rightValue, Args... args){
    static int test_case_number = 0;
    ++test_case_number;

    T result = func(std::forward<Args>(args)...);

    bool testResult = (result == rightValue);
    std::string testCase = "Test case "s + std::to_string(test_case_number);

    if(testResult){
        std::cout << testCase << ": PASSED" << std::endl;
    }else{
        std::cout << testCase << ": NOT PASSED" << std::endl;
    }
}

// хочу другой разделитель
template<class Stream>
std::size_t words_count(Stream &stream){
    return std::distance(std::istream_iterator<std::string>{stream}, {});
}

void print_align_demo(int val, std::size_t width, char fill_char = ' '){
    std::cout << std::right 
    << std::setw(3) 
    << std::setfill(fill_char) 
    << std::hex 
    << std::showbase;

    std::cout << val << std::endl;

    std::cout << std::oct;
    std::cout << val << std::endl;

    // std::cout << std::binary;
    // std::cout << val;
}

void print_bool(bool f){
    std::cout << std::boolalpha;
    std::cout << f << std::endl;
}


struct city_t{
    std::string name;
    std::size_t population;
    double latitude;
    double longtitude;
};

std::istream& operator>>(std::istream& is, city_t& city){
    is >> city.name;
    is >> city.population >> city.latitude >> city.longtitude;

    return is;
}

// std::istream& operator>>(std::istream& stream, city_t &city){
//     is >> ws;
    
// }

#define LOG(X) std::cout << X << std::endl;

class A{
public:
    A(){
        LOG("Default constructor");
    }

    A(const A& a){
        LOG("Copy constructor A");
    }

    A& operator=(const A& a){
        LOG("Copy operator= A");
        return *this;
    }

    A(A&& a){
        LOG("Move constructor A");
    }

    A& operator=(A&& a){
        LOG("Copy operator= A");
        return *this;
    }
};

template<typename T>
void foo(T&& a){
    auto c = a;
    auto b = std::move(a);
}

int main(int argc, char* argv[]){

    // {
    //     std::string str1(" a b awd   awd   ");
    //     test_func(remove_repeating_spaces, " a b awd awd "s, str1);
    // }

    // {
    //     std::string str2{"ADdawdAdadawDWAddss"s};
    //     test_func(toLower, "addawdadadawdwaddss"s, str2);
    // }

    // {
    //     std::string str3{"   dawdawd  \n\t  "};
    //     test_func(trim, "dawdawd"s, str3);

    //     std::string str4{"     "};
    //     test_func(trim, ""s, str4);
    // }

    // if(argc == 2){
    //     std::ifstream file(argv[1]);
    //     std::cout << words_count(file) << std::endl;
    // }else{

    // }

    // print_align_demo(0x5, 6);
    // print_bool(true);

    // std::vector<city_t> citites;
    // std::copy(std::istream_iterator<city_t>(std::cin), {}, std::back_inserter(citites));

    // std::for_each(citites.begin(), citites.end(), [](const city_t& city){
    //     std::cout << city.name << std::endl;
    //     std::cout << city.population << std::endl;
    //     std::cout << city.latitude << ", " << city.longtitude << std::endl;
    // });

    // for(const auto& city : cities){
    //     std::cout << city
    // }
    
    A a;
    foo(a);

    return 0;   
}
