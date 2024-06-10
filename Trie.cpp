struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool end_of_word;
    TrieNode()
    {
        end_of_word = 0;
    }
};
struct Trie
{
    TrieNode *root;
    Trie()
    {
        new TrieNode();
    }
    // Function to insert a word into the trie
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->end_of_word = true;
    }
    // Function to search for a word in the trie
    bool search(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                return false;
            }
            node = node->children[c];
        }
        return node->end_of_word;
    }
    // Function to check if there is any word in the trie that starts with the given prefix
    bool startsWith(const string &prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            if (node->children.find(c) == node->children.end())
            {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
}