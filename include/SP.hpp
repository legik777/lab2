// Copyright 2020 Andreytorix
#pragma once
#include <atomic>
#include <memory>
#include <vector>
#include <string>
#include <utility>

template <typename T>
class SCP {
public:
    explicit SCP(T* p) : ptr(p), counter(1) {}

    void add() noexcept {  //AddPointer
        ++counter;
    }
    void clearPtr() noexcept { //Clear
        if (!--counter) {
            ptr = nullptr;
            delete this;
        }
    }
    auto getCount() const noexcept -> size_t { //GetCount
        return counter.load();
    }
private:
    T* ptr;
    std::atomic<size_t> counter;
};

template <typename T>
class SharedPtr {
public:
    SharedPtr() noexcept
        : ptr(nullptr), counter(nullptr) {}

    explicit SharedPtr(T* p) {
        std::unique_ptr<T> temp(p);
        counter = new SCP<T>(temp.get());
        ptr = temp.release();
    }
    SharedPtr(const SharedPtr& r)
    {
        if (std::is_move_constructible<T>::value) {
            ptr = r.ptr;
            counter = r.counter;
            counter->add();
        } else {
            throw std::runtime_error("value is not move constructible");
        }
    }
    SharedPtr(SharedPtr&& r) {
        if (std::is_move_assignable<T>::value) {
            std::swap(ptr, r.ptr);
            std::swap(counter, r.counter);
        } else {
            throw std::runtime_error("value is not move assignable");
        }
    }
    ~SharedPtr() noexcept {
        Clear();
    }
    auto operator=(const SharedPtr& r) -> SharedPtr& {
        if (std::is_move_constructible<T>::value && &r != this) {
            Clear();
            ptr = r.ptr;
            counter = r.counter;
            AddPoint();
        } else if (&r == this) {
            std::cout << "objects are equal";
        } else {
            throw std::runtime_error("value is not move constructible");
        }
        return *this;
    }
    auto operator=(SharedPtr&& r) -> SharedPtr& {
        if (std::is_move_assignable<T>::value && &r != this) {
            Clear();
            ptr = std::move(r.ptr);
            counter = std::move(r.counter);
        } else if (&r == this) {
            std::cout << "objects are equal";
        } else {
            throw std::runtime_error("value is not move assignable");
        }
        return *this;
    }
    explicit operator bool() const {
        return (ptr != nullptr);
    }
    auto operator*() const -> T& {
        return *(ptr);
    }
    auto operator->() const -> T* {
        return ptr;
    }
    inline auto Get() const -> T* {
        return ptr;
    }
    inline void Swap(SharedPtr& r) {
        std::swap(ptr, r.ptr);
        std::swap(counter, r.counter);
    }
    inline auto GetCount() const -> size_t {
        return (counter != nullptr) ? counter->getCount() : 0;
    }
private:
    inline void AddPoint() {
        if (counter) {
            counter->AddPointer();
        }
    }
    inline void Clear() {
        if (counter) {
            counter->clearPtr();
        }
    }
private:
    T* ptr;
    SCP<T>* counter;
};
