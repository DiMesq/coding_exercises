#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using my_pair_t = std::pair<int, std::pair<int, int>>;

void update(std::vector<my_pair_t>& v, int t){
    for (auto it=v.begin(); it!=v.end(); ++it) it->second.second-=t;
}

int main(int argc, char const *argv[])
{
    int t, p, l;
    scanf("%d", &t);

    auto my_comp = 
        [](const my_pair_t& c1, const my_pair_t& c2) 
        { return c1.second.second > c2.second.second; };

    while (t--){
        int n_p = 0, tot_time = 0, rank;
        
        std::vector<my_pair_t> cooks;

        scanf("%d %d", &p, &l);

        for (int i=0; i<l; i++){
            std::cin >> rank;
            auto cook = std::make_pair(rank, std::make_pair(1, rank));
            cooks.push_back(cook);
        }
        std::make_heap(cooks.begin(), cooks.end(), my_comp);

        while (n_p < p){

            auto cook = cooks.front();
            tot_time+= cook.second.second;
            update(cooks, cook.second.second);
            cook = cooks.front();

            while (cook.second.second == 0){
                n_p++;
                std::pop_heap(cooks.begin(), cooks.end(), my_comp); cooks.pop_back();

                cook.second.second = cook.first * ++cook.second.first;
                cooks.push_back(cook); std::push_heap(cooks.begin(), cooks.end(), my_comp);

                cook = cooks.front();
            } 
        }
        std::cout << tot_time<<"\n";
    }
    return 0;
}

