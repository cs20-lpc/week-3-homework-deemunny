// #include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* addMe = new Node(elem);
    if (!head) head = addMe;
    
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = addMe;
    }
    ++this->length;
}

template <typename T>
void LinkedList<T>::append(T&& elem) {
    Node* addMe = new Node(std::move(elem));
    if (!head) head = addMe;
    
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = addMe;
    }
    ++this->length;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* delMe = head;
    Node* temp2 = nullptr;
    while (delMe) {
        temp2 = delMe->next;
        delete delMe;
        delMe = temp2;
    }
    head == nullptr;
    this->length = 0;
}

// we assume position is an index? ie, starting at 0?
template <typename T>
T& LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) throw std::out_of_range("Invalid position passed for getting element");
    
    Node* temp = head;
    for (int i = 0; i < position; ++i) temp = temp->next;
    return temp->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    //return this->length == 0;
    return head == nullptr;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) throw std::out_of_range("Invalid position passed for replace");
    Node* temp = head;
    for (int i = 0; i < position; ++i) temp = temp->next;
    temp->value = elem;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) throw std::out_of_range("Invalid position passed for removing element");
    Node* removeMe = head;

    if (position == 0) {
        head = head->next;
        delete removeMe;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < position-1; ++i) temp = temp->next;

        removeMe = temp->next;
        temp->next = removeMe->next;
        delete removeMe;    
        }

    --this->length;
}


template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
