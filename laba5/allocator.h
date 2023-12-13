#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

template <typename T, size_t Block_count>

class MAllocator {
public:
    #ifdef DEBUG
        static size_t allocator_count;
        static size_t block_allocator_count;
    #endif

    using value_type = T;
    using pointer = T *;
    using const_point = const T *;
    using size_type = std::size_t;

    template <typename U>
    struct rebind {
       using other = MAllocator<U, Block_count>;
    };

    MAllocator() {
        if (Block_count == 0) throw std::logic_error("Can't create empty allocator");
        buffer = new value_type[Block_count];
        for (int i = 0; i < Block_count; ++i) {
            allocator_blocks.push_back(std::make_pair(buffer + i, false));
        }
    }

    ~MAllocator() {
        delete[] buffer;
    }

    template <typename U>
    MAllocator(const MAllocator<U, Block_count>&) noexcept {}

    pointer allocate(size_t n) {
        #ifdef DEBUG
            allocator_count += n;
        #endif
        if (n != 1) throw std::bad_alloc();
        auto it = std::find_if(allocator_blocks.begin(), allocator_blocks.end(), [](const auto& pair) {
            return !pair.second;
        });

        if (it == allocator_blocks.end()) throw std::bad_alloc();
        it->second = true;
        return it->first;
        
    }

    void deallocate(pointer ptr, size_t n) {
        #ifdef DEBUG
            allocator_count -= n;
        #endif
        if (n != 1) return;
        auto it = std::find_if(allocator_blocks.begin(), allocator_blocks.end(), [ptr](const auto& pair) {
            return pair.first == ptr;
        });

        if(it == allocator_blocks.end()) throw std::invalid_argument("wrong pointer");
        
        it->second = false;
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args){
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

private:
    pointer buffer;
    std::vector<std::pair<pointer, bool>> allocator_blocks;
};

#ifdef DEBUG
    template <typename T, size_t Block_count>
    size_t MAllocator<T, Block_count>::allocator_count = 0;
#endif