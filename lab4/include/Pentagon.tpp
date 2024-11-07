template <Scalar T>
Pentagon<T>::Pentagon() {
    for (auto& vertex : vertices) {
        vertex = std::make_unique<Point<T>>();
    }
}

template <Scalar T>
Pentagon<T>::Pentagon(const std::array<Point<T>, 5>& points) {
    for (size_t i = 0; i < 5; ++i) {
        vertices[i] = std::make_unique<Point<T>>(points[i]);
    }
}

template <Scalar T>
Pentagon<T>::Pentagon(const Pentagon& other) {
    for (size_t i = 0; i < 5; ++i) {
        vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
    }
}

template <Scalar T>
Pentagon<T>::Pentagon(Pentagon&& other) noexcept {
    for (size_t i = 0; i < 5; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon& other) {
    if (this != &other) {
        for (size_t i = 0; i < 5; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
        }
    }
    return *this;
}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < 5; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

template <Scalar T>
void Pentagon<T>::Print() const {
    std::cout << "Вершины пятиугольника:\n";
    for (const auto& vertex : vertices) {
        std::cout << *vertex << "\n";
    }
}

template <Scalar T>
double Pentagon<T>::Area() const {
    double area = 0.0;
    for (size_t i = 0; i < 5; ++i) {
        T x1 = vertices[i]->x;
        T y1 = vertices[i]->y;
        T x2 = vertices[(i + 1) % 5]->x;
        T y2 = vertices[(i + 1) % 5]->y;
        area += static_cast<double>(x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

template <Scalar T>
Point<T> Pentagon<T>::Center() const {
    T x_sum = 0;
    T y_sum = 0;
    for (const auto& vertex : vertices) {
        x_sum += vertex->x;
        y_sum += vertex->y;
    }
    return Point<T>(x_sum / 5, y_sum / 5);
}

template <Scalar T>
bool Pentagon<T>::operator==(const Pentagon<T>& other) const {
    for (size_t i = 0; i < 5; ++i) {
        if (*(this->vertices[i]) != *(other.vertices[i])) {
            return false;
        }
    }
    return true;
}

template <Scalar T>
bool Pentagon<T>::operator==(const Figure<T>& other) const {
    const Pentagon<T>* pent = dynamic_cast<const Pentagon<T>*>(&other);
    if (!pent) return false;
    return *this == *pent;
}

template <Scalar T>
Pentagon<T>::operator double() const {
    return Area();
}

template <Scalar T>
std::shared_ptr<Figure<T>> Pentagon<T>::Clone() const {
    return std::make_shared<Pentagon<T>>(*this);
}

template <Scalar U>
std::istream& operator>>(std::istream& is, Pentagon<U>& p) {
    for (auto& vertex : p.vertices) {
        vertex = std::make_unique<Point<U>>();
        is >> *(vertex);
    }
    return is;
}

template <Scalar U>
std::ostream& operator<<(std::ostream& os, const Pentagon<U>& p) {
    for (const auto& vertex : p.vertices) {
        os << *vertex << " ";
    }
    return os;
}
