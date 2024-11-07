template <Scalar T>
Hexagon<T>::Hexagon() {
    for (auto& vertex : vertices) {
        vertex = std::make_unique<Point<T>>();
    }
}

template <Scalar T>
Hexagon<T>::Hexagon(const std::array<Point<T>, 6>& points) {
    for (size_t i = 0; i < 6; ++i) {
        vertices[i] = std::make_unique<Point<T>>(points[i]);
    }
}

template <Scalar T>
Hexagon<T>::Hexagon(const Hexagon& other) {
    for (size_t i = 0; i < 6; ++i) {
        vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
    }
}

template <Scalar T>
Hexagon<T>::Hexagon(Hexagon&& other) noexcept {
    for (size_t i = 0; i < 6; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

template <Scalar T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon& other) {
    if (this != &other) {
        for (size_t i = 0; i < 6; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*(other.vertices[i]));
        }
    }
    return *this;
}

template <Scalar T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < 6; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

template <Scalar T>
void Hexagon<T>::Print() const {
    std::cout << "Вершины шестиугольника:\n";
    for (const auto& vertex : vertices) {
        std::cout << *vertex << "\n";
    }
}

template <Scalar T>
double Hexagon<T>::Area() const {
    double area = 0.0;
    for (size_t i = 0; i < 6; ++i) {
        T x1 = vertices[i]->x;
        T y1 = vertices[i]->y;
        T x2 = vertices[(i + 1) % 6]->x;
        T y2 = vertices[(i + 1) % 6]->y;
        area += static_cast<double>(x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

template <Scalar T>
Point<T> Hexagon<T>::Center() const {
    T x_sum = 0;
    T y_sum = 0;
    for (const auto& vertex : vertices) {
        x_sum += vertex->x;
        y_sum += vertex->y;
    }
    return Point<T>(x_sum / 6, y_sum / 6);
}

template <Scalar T>
bool Hexagon<T>::operator==(const Hexagon<T>& other) const {
    for (size_t i = 0; i < 6; ++i) {
        if (*(this->vertices[i]) != *(other.vertices[i])) {
            return false;
        }
    }
    return true;
}

template <Scalar T>
bool Hexagon<T>::operator==(const Figure<T>& other) const {
    const Hexagon<T>* hex = dynamic_cast<const Hexagon<T>*>(&other);
    if (!hex) return false;
    return *this == *hex;
}

template <Scalar T>
Hexagon<T>::operator double() const {
    return Area();
}

template <Scalar T>
std::shared_ptr<Figure<T>> Hexagon<T>::Clone() const {
    return std::make_shared<Hexagon<T>>(*this);
}

template <Scalar U>
std::istream& operator>>(std::istream& is, Hexagon<U>& h) {
    for (auto& vertex : h.vertices) {
        vertex = std::make_unique<Point<U>>();
        is >> *(vertex);
    }
    return is;
}

template <Scalar U>
std::ostream& operator<<(std::ostream& os, const Hexagon<U>& h) {
    for (const auto& vertex : h.vertices) {
        os << *vertex << " ";
    }
    return os;
}
