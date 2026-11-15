class AuthenticationManager {
private:
    struct Token {
        string tokenId;
        int expirationTime;
    };

    struct Node {
        Token token;
        Node* next;
        Node* prev;

        Node(string tokenId, int expirationTime) {
            Token t;
            t.tokenId = tokenId;
            t.expirationTime = expirationTime;
            token = t;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    int timeToLive;

    unordered_map<string, Node*> db;

    Node* insert_tail(string tokenId, int expirationTime) {

        Node* newNode = new Node(tokenId, expirationTime);
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        return newNode;
    }

    void remove_front() {
        if (head == nullptr)
            return;

        Node* temp = head;

        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }

        size--;
        delete temp;
    }

    void remove(Node* node) {
        if (node == nullptr)
            return;

        if (node == head) {
            remove_front();
            return;
        }

        if (node == tail) {
            tail = node->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        size--;
        delete node;
    }
    Token top() { return head->token; }

    Token get(string tokenId) { return db.at(tokenId)->token; }

public:
    AuthenticationManager(int _timeToLive) { timeToLive = _timeToLive; }

    void generate(string tokenId, int currentTime) {
        int expirationTime = currentTime + timeToLive;

        Node* newNode = insert_tail(tokenId, expirationTime);

        db[tokenId] = newNode;
    }

    void renew(string tokenId, int currentTime) {
        if (db.contains(tokenId)) {

            Token token = get(tokenId);

            if (token.expirationTime > currentTime) {

                int newExpirationTime = currentTime + timeToLive;

                remove(db[tokenId]);
                Node* newNode = insert_tail(tokenId, newExpirationTime);
                db[tokenId] = newNode;
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        while (head != nullptr && top().expirationTime <= currentTime) {
            db.erase(top().tokenId);
            remove_front();
        }

        return size;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */