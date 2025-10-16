template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    this->head = nullptr;
    this->tail = nullptr;
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
        throw std::underflow_error("Queue is empty");
    }
    return this->tail->getItem();
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (!isEmpty()) {
        dequeue();
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    if (copyObj.isEmpty()) {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
        return;
    }
    Node<T>* current = copyObj.head;
    while (current != nullptr) {
        enqueue(current->getItem());
        current = current->getNext();
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    Node<T>* oldHead = this->head;
    this->head = this->head->getNext();
    delete oldHead;
    this->length--;
    if (this->head == nullptr) {
        this->tail = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node<T>* newNode = new Node<T>(elem);
    if (isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->setNext(newNode);
        this->tail = newNode;
    }
    this->length++;
}
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return this->head->getItem();
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
