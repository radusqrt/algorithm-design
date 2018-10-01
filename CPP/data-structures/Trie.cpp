#include <vector>
#include <string>
#include <iostream>

#define ALPHABET_SIZE  26

using std::vector;
using std::string;
using std::cout;
using std::endl;

template <typename T>
class Trie {
 private:
    int count, suffix;
    vector<Trie<T> *> children;
    T value;
    bool isEndOfWord;
  public:
    Trie() {}

    Trie(int capacity, T value)
      : count(0),
        suffix(0),
        children(capacity, NULL),
        value(value) { }

    Trie(int capacity)
      : count(0),
        suffix(0),
        children(capacity, NULL) { }

    ~Trie() {}
 	void insert(string key, T value) {
		if (!key.size()) {
            this->value = value;
            isEndOfWord = true;
            return;
        }

        int x = 0;
        if (!search(key, x))
            ++suffix;

        int nextNode = key[0] - 'a';
        if (!children[nextNode]) {
            children[nextNode] = new Trie<T>(ALPHABET_SIZE);
            ++count;
        }

        key = key.erase(0, 1);
        children[nextNode]->insert(key, value); 
    }
	bool search(string key, T &val) {
        if (!key.size()) {
            val = value;
            return isEndOfWord;
        }

        int nextNode = key[0] - 'a';

        if (!children[nextNode])
            return false;

        key = key.erase(0, 1);
        return children[nextNode]->search(key, val);
    }

    bool hasChildren() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (children[i] != NULL)
                return true;
        }

        return false;
    }

    bool remove(string key) {
        if (!key.size()) {
            isEndOfWord = false;
            value = 0;
            if (!hasChildren() && !isEndOfWord)
                return true;
        }

        int nextNode = key[0] - 'a';

        if (children[nextNode]) {
            key = key.erase(0, 1);
            --suffix;

            if (children[nextNode]->remove(key)) {
                delete children[nextNode];
                --count;
                if (!hasChildren() && !isEndOfWord)
                    return true;
            }
        }

        return false;
    }

    int numWordsWithPrefix(string prefix) {
        if (!prefix.size()) {
            return suffix;
        }

        int nextNode = prefix[0] - 'a';

        if (!children[nextNode])
            return 0;

        prefix = prefix.erase(0, 1);
        return children[nextNode]->numWordsWithPrefix(prefix);
    }

};

int main() {
    Trie<int> *trie = new Trie<int>(ALPHABET_SIZE);
    string s;
    int val;

    s = "arta";
    trie -> insert(s, 1);
    s = "artilerie";
    trie -> insert(s, 2);
    s = "artist";
    trie -> insert(s, 3);
    s = "artistic";
    trie -> insert(s, 4);
    s = "arma";
    trie -> insert(s, 5);
    s = "pusca";
    trie -> insert(s, 6);

	if (!trie -> search(s, val)) {
		cout << s << " should be in Trie\n";
	}
	cout << "Value of " << s << " : " << val << endl;
	s = "artistic";
	if (!trie -> search(s, val)) {
		cout << s << " should be in Trie\n";
	}
	cout << "Value of " << s << " : " << val << endl;
	s = "artist";
	if (!trie -> search(s, val)) {
		cout << s << " should be in Trie\n";
	}
	cout << "Value of " << s << " : " << val << endl;
	s = "artilerie";
	if (!trie -> search(s, val)) {
		cout << s << " should be in Trie\n";
	}
	cout << "Value of " << s << " : " << val << endl;
	s = "arma";
	if (!trie -> search(s, val)) {
		cout << s << " should be in Trie\n";
	}
	cout << "Value of " << s << " : " << val << endl;
	s = "arta";
	if (!trie -> search(s, val)) {
		cout << s << " should be in Trie\n";
	}
	cout << "Value of " << s << " : " << val << endl;
	s = "artis";
	if (trie -> search(s, val)) {
		cout << s << " should not be in Trie\n";
	}
	s = "pusca";
	trie -> remove(s);
	if (trie -> search(s, val)) {
		cout << s << " should not be in Trie after removal\n";
	}
	s = "artilerie";
	trie -> remove(s);
	if (trie -> search(s, val)) {
		cout << s << " should not be in Trie after removal\n";
	}
	s = "arta";
	if (!trie -> search(s, val)) {
		cout << s << " should still be in Trie\n";
	}
	s = "artist";
	trie -> remove(s);
	if (trie -> search(s, val)) {
		cout << s << " should not be in Trie after removal\n";
	}
	s = "artistic";
	if (!trie -> search(s, val)) {
		cout << s << " should still be in Trie\n";
	}

	s = "artist";
	trie -> insert(s, 3);
	s = "artilerie";
	trie -> insert(s, 3);
	s = "pusca";
	trie -> insert(s, 3);
	s = "";
	cout << trie->numWordsWithPrefix(s) << endl;
	s = "a";
	cout << trie->numWordsWithPrefix(s) << endl;
	s = "art";
	cout << trie->numWordsWithPrefix(s) << endl;
	s = "arti";
	cout << trie->numWordsWithPrefix(s) << endl;
	s = "articulatie";
	cout << trie->numWordsWithPrefix(s) << endl;
	
    return 0;
}
