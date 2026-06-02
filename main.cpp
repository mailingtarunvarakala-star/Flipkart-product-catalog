#include <iostream>
#include <vector>
using namespace std;

struct LeafNode {
    vector<int> keys;
    LeafNode* next;

    LeafNode() {
        next = nullptr;
    }
};

class BPlusTree {
private:
    LeafNode* firstLeaf;

public:
    BPlusTree() {
        firstLeaf = new LeafNode();
    }

    void insert(int key) {
        firstLeaf->keys.push_back(key);
    }

    int rangeCount(int low, int high) {
        LeafNode* leaf = firstLeaf;
        int count = 0;

        while (leaf) {
            for (int key : leaf->keys) {
                if (key >= low && key <= high)
                    count++;

                if (key > high)
                    return count;
            }
            leaf = leaf->next;
        }
        return count;
    }

    void display() {
        LeafNode* leaf = firstLeaf;

        cout << "\nProduct Prices:\n";
        while (leaf) {
            for (int key : leaf->keys)
                cout << key << " ";
            leaf = leaf->next;
        }
        cout << endl;
    }
};

int main() {
    BPlusTree tree;

    int prices[] = {
        500, 700, 1000, 1200, 1500,
        2000, 2500, 3000, 3500, 4000,
        4500, 5000, 5500, 6000
    };

    for (int price : prices)
        tree.insert(price);

    tree.display();

    int low = 1000;
    int high = 5000;

    int result = tree.rangeCount(low, high);

    cout << "\nRange Query: "
         << low << " to " << high << endl;

    cout << "Matching Products = "
         << result << endl;

    return 0;
}
