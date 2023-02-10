#include <iostream>


//template - шаблон, для беспроблемного использования итераторов
template <typename InputIt,typename OutputIt>
void custom_copy(InputIt begin, InputIt end, OutputIt d_begin){
    int plus = 8/sizeof(*begin);
        while(begin<end-1){
            auto src = (long long*)begin;
            auto point = (long long*)d_begin;
            *point = *src;
            begin+=plus;
            d_begin+=plus;
        }
    }


int main(){
    const int n = 10;
    char mas [n];
    char mas2 [n];
    for (int i = 0; i < n; ++i){
        mas[i] = i*2;
    }
    custom_copy(&mas[0],&(mas[0])+n,&mas2[0]);
    for (int i = 0;i<n;++i){
        std::cout<< (int)mas2[i] << std::endl;
    }
    return 0;
}
