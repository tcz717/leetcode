#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <array>
class TrieNode
{
  public:
    array<TrieNode *, 26> children;
    bool isEnd;
    TrieNode() : isEnd(false), children()
    {
    }
};
class Trie
{
    TrieNode root;

  public:
    /** Initialize your data structure here. */
    Trie() : root()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *current = &root;
        for (char c : word)
        {
            auto &ch = current->children[c - 'a'];
            if (ch == nullptr)
                ch = new TrieNode();
            current = ch;
        }
        current->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *current = &root;
        for (char c : word)
        {
            auto &ch = current->children[c - 'a'];
            if (ch == nullptr)
                return false;
            current = ch;
        }
        return current->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *current = &root;
        for (char c : prefix)
        {
            auto &ch = current->children[c - 'a'];
            if (ch == nullptr)
                return false;
            current = ch;
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
// END UPLOAD ZONE
main(int argc, char const *argv[])
{
    Trie obj;
    obj.insert("dasdsa");
    cout << obj.search("dasdsa") << endl;
    cout << obj.search("daeqw") << endl;
    cout << obj.startsWith("das") << endl;
    return 0;
}
