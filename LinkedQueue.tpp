template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty. Cannot access back element.");
    }
    return this->last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (!isEmpty()) {
        dequeue();
    }
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
    Node* current = copyObj.head;
    while (current != nullptr) {
        enqueue(current->value);
        current = current->next;
    }
    this->length = copyObj.length;

}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty. Cannot dequeue.");
    }
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->length--;
    if (this->head == nullptr) {
        this->last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);
    if (isEmpty()) {
        this->head = newNode;
        this->last = newNode;
    } else {
        this->last->next = newNode;
        this->last = newNode;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty. Cannot access front element.");
    }
    return this->head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
