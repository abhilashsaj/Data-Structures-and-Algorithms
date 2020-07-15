#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    int max_index1 =-1;
    int max_index2 = -1;
    
    for(int i =0; i< n; i++)
    {
        if(max_index1 == -1 || numbers[max_index1]<numbers[i] ){
            max_index1 = i;
        }
        
    }
    
    for(int j =0; j< n; j++)
    {
        if((j!=max_index1) && (max_index2 == -1 || numbers[max_index2]<numbers[j]) ){
            max_index2 = j;
        }
        
    }
    
    return (long long) numbers[max_index1] *numbers[max_index2];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
