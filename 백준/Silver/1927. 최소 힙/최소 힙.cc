#include <iostream>
#include <vector>

void cre_heap(std::vector <int> &heap, int key) {
    int k = heap.size();
    heap.push_back(key);
    while (k > 1) {
        if (heap[k/2] > heap[k]) {
            std::swap(heap[k], heap[k/2]);
            k /= 2;
        }
        else break;
    }
    return;
}

void del_heap(std::vector <int> &heap) {
    int k = 1;
    heap[1] = heap.back(), heap.pop_back();
    while (k * 2 <= heap.size()) {
        if (k * 2 + 1 < heap.size() && heap[k*2+1] < heap[k*2]) k = k*2+1;
        else k = k*2;

        if (heap[k/2] > heap[k]) std::swap(heap[k/2], heap[k]);
        else break;
    }
    return;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k, x;
    std::vector <int> min_heap = {0};

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x > 0) cre_heap(min_heap, x);
        else if (min_heap.size() > 1) {
            std::cout << min_heap[1] << '\n';
            del_heap(min_heap);
        }
        else std::cout << 0 << '\n';
    }
    
}