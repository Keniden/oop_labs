template <class T>
Array<T>::Array() : data(nullptr), capacity(0), size(0) {}

template <class T>
Array<T>::Array(const Array& other) : capacity(other.capacity), size(other.size) {
    data = std::shared_ptr<T[]>(new T[capacity], std::default_delete<T[]>());
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <class T>
Array<T>::Array(Array&& other) noexcept : data(std::move(other.data)), capacity(other.capacity), size(other.size) {
    other.capacity = 0;
    other.size = 0;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        data = std::shared_ptr<T[]>(new T[other.capacity], std::default_delete<T[]>());
        capacity = other.capacity;
        size = other.size;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <class T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        capacity = other.capacity;
        size = other.size;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

template <class T>
void Array<T>::resize(size_t new_capacity) {
    std::shared_ptr<T[]> new_data(new T[new_capacity], std::default_delete<T[]>());
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = std::move(data[i]);
    }
    data = new_data;
    capacity = new_capacity;
}

template <class T>
void Array<T>::push_back(const T& element) {
    if (size == capacity) {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        resize(new_capacity);
    }
    data[size++] = element;
}

template <class T>
void Array<T>::removeAt(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Invalid index");
    }
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size;
}

template <class T>
T& Array<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Invalid index");
    }
    return data[index];
}

template <class T>
size_t Array<T>::getSize() const {
    return size;
}

template <class T>
T* Array<T>::begin() const {
    return data.get();
}

template <class T>
T* Array<T>::end() const {
    return data.get() + size;
}
