#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

bool compare(int x, int y)
{
    return x<y;
}

int binary_search(std::vector<int>& sorted_vec, int key) {
    int mid, left = 0 ;
    int right = sorted_vec.size();
    while (left < right) {
        mid = left + (right - left)/2;
        if (key > sorted_vec[mid]){
            left = mid+1;
        }
        else if (key < sorted_vec[mid]){
            right = mid;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int main() {
    srand(time(NULL));
    std::vector<int> test_stuff;
    for(int x =0;x<100;x++)
        test_stuff.emplace_back(rand()%10000);

    test_stuff.emplace_back(1000);

    std::sort(test_stuff.begin(),test_stuff.end(),compare);


    for(auto& t:test_stuff)
        std::cout<< t<<std::endl;

    std::cout <<"Position in array "<< binary_search(test_stuff,1000) << std::endl;
    std::cout <<"Position in array "<< binary_search(test_stuff,5000) << std::endl;

}
