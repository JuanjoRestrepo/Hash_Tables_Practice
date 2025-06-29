#include<iostream>
#include<sstream>
// Building our Hash Table
class HashTable
{
public:
    struct Entry
    {
        std::string Data; // Name of the entry
        std::string Status = "never used"; // Status of the entry, can be "never used", "used", or "deleted"
    };
    static const int Size = 26; // Size of the hash table
public:
    HashTable() = default;

    void Print() // For debugging purposes
    {
        for(int i = 0; i < Size; ++i)
        {
            std::cout << i+1 << ". " << m_Entries[i].Data << "(" << m_Entries[i].Status << ")" << std::endl;
        }
    }
private:
    Entry m_Entries[Size];
};

int main() {
    /*
        Requirements:
        Aapple Aorange Dapple Astrawberry
        orange strawberry
    */

    // 1. We separate the input into words
    std::string input;
    getline(std::cin, input);

    HashTable hashTable; // Create an instance of the HashTable

    std::stringstream ss(input);
    while(ss.good()) 
    {
        std::string token; // Aapple
        ss >> token;

        // 2. We check if the word starts with 'A' or 'D'
        std::string entryName = token.substr(1); // Get the entry name after 'A' or 'D'
        if(token[0] == 'A')
        {
            
        }
        else if (token[0] == 'D')
        {
            
        }
    }

    hashTable.Print();
}