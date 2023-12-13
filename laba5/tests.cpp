#include <gtest/gtest.h>
#define DEBUG
#include "forward_list.h"
#include "allocator.h"

TEST(TEST_1, construct) {
    MForwardList<int, 10, MAllocator<int, 10>> list;
    ASSERT_TRUE(list.empty());
}

TEST(TEST_2, fill_list) {
    MForwardList<int, 11, MAllocator<int, 10>> list;
    for (int i = 0; i < 10; i++) {
        list.push_front(i);
    }
    ASSERT_EQ(list.front(), 9);
}

TEST(TEST_3, rm_from__list) {
    MForwardList<int, 11, MAllocator<int, 10>> list;
    for (int i = 0; i < 10; i++) {
        list.push_front(i);
    }
    for (int i = 0; i < 10; i++) {
        list.pop_front();
    }
    ASSERT_TRUE(list.empty());
}

TEST(TEST_4, clear) {
    MForwardList<int, 10, MAllocator<int, 10>> list;
    list.clear();
    ASSERT_TRUE(list.empty());
}

TEST(TEST_5, insert_after) {
    MForwardList<int, 10, MAllocator<int, 10>> list;
    list.push_front(1);
    list.push_front(2);
    MForwardList<int, 10, MAllocator<int, 10> >::MyIterator it1(list.begin());
    MForwardList<int, 10, MAllocator<int, 10> >::MyIterator it2 = it1.operator++();
    list.insert_after(it2, 3);
    MForwardList<int, 10, MAllocator<int, 10> >::MyIterator it3 = it2.operator++();
    ASSERT_EQ(it3.getPtr()->value, 3);
}

TEST(TEST_6, begin) {
    MForwardList<int, 10, MAllocator<int, 10>> list;
    list.push_front(1);
    MForwardList<int, 10, MAllocator<int, 10> >::MyIterator it(list.begin());
    ASSERT_EQ(it.getPtr()->value, 1);

}

TEST(TEST_7, end) {
    MForwardList<int, 10, MAllocator<int, 10> > list;
    list.push_front(1);
    list.push_front(2);
    MForwardList<int, 10, MAllocator<int, 10> >::MyIterator it(list.end());
    ASSERT_TRUE(it.getPtr() == NULL);

}

TEST(TEST_8, before_begin) {
    MForwardList<int, 10, MAllocator<int, 10> > list;
    list.push_front(1);
    MForwardList<int, 10, MAllocator<int, 10> >::MyIterator it1(list.before_begin());
    MForwardList<int, 10, MAllocator<int, 10> >::MyIterator it2 = it1.operator++();
    ASSERT_EQ(it2.getPtr()->value, 1);
    
}

TEST(TEST_9, bad_list) {
    bool check = true;
    try{
        MForwardList<int, 10, MAllocator<int, 10> > list;
        list.front();
    } catch (std::exception &ex) {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(TEST_10, wrong_inserting_after) {
    MForwardList<int, 3, MAllocator<int, 2> > list;
    MForwardList<int, 3, MAllocator<int, 2> >::MyIterator it1(list.end());
    ASSERT_THROW(list.insert_after(it1, 3), std::out_of_range);
}

TEST(TEST_11, empty_allocator) {
    MAllocator<int, 10> alloc;
    ASSERT_EQ(0, (MAllocator<int, 10>::allocator_count));
}

TEST(TEST_12, allocate) {
    MAllocator<int, 10> alloc;
    alloc.allocate(1);
    alloc.allocate(1);
    alloc.allocate(1);
    ASSERT_EQ(3, (MAllocator<int, 10>::allocator_count));
}

TEST(TEST_13, deallocate) {
    MAllocator<int, 2> alloc;
    int* ptr1 = alloc.allocate(1);
    int* ptr2 = alloc.allocate(1);
    alloc.deallocate(ptr2, 1);
    ASSERT_EQ(1, (MAllocator<int, 2>::allocator_count));
}

TEST(TEST_14, wrong_allocate_1) {
    MAllocator<int, 1> alloc;
    alloc.allocate(1);
    ASSERT_THROW(alloc.allocate(1), std::bad_alloc);
}

TEST(TEST_15, wrong_allocate_2) {
    MAllocator<int, 10> alloc;
    ASSERT_THROW(alloc.allocate(2), std::bad_alloc);
}

TEST(TEST_16, wrong_deallocate) {
    MAllocator<int, 1> alloc;
    int* ptr = alloc.allocate(1);
    alloc.deallocate(ptr, 1);
    ASSERT_THROW(alloc.deallocate(nullptr, 1), std::invalid_argument);
} 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
