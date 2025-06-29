#include<iostream>
#include<sstream>
// Building our Hash Table
class HashTable
{
public:
    struct Entry
    {
        std::string Data; // Name of the entry
        std::string Status = "never used"; // Status of the entry, can be "never used", "tombstone", or "occupied"
    };
    static const int Size = 26; // Size of the hash table
public:
    HashTable() = default;

    void Add(const std::string& entryString)
    {
        bool exists = Find(entryString);
        if(exists)
        {
            return; // Entry already exists, no need to add it again
        }
        int insertIndex = GetInsertIndex(entryString);
        m_Entries[insertIndex].Data = entryString; // Set the data of the entry
        m_Entries[insertIndex].Status = "occupied"; // Set the status to occupied
    }

    void Delete(const std::string& entryString)
    {

    }

    void Print() // For debugging purposes
    {
        for(int i = 0; i < Size; ++i)
        {
            std::cout << i+1 << ". " << m_Entries[i].Data << "(" << m_Entries[i].Status << ")" << std::endl;
        }
    }

private:
    int GetIndex(const std::string& entryString)
    {
        return entryString.back() - 'a';
    }
    
    bool Find(const std::string& entryString)
    {
        int index = GetIndex(entryString);
        while(true)
        {
            if(m_Entries[index].Data == entryString)
            {
                return true; // Entry found
            }
            if(m_Entries[index].Status == "never used")
            {
                return false; // Entry not found
            }
            // If the entry is deleted, we continue searching
            // We get the mod of the index to wrap around the table
            // If we reach the end of the table [25], we wrap around to the beginning [0]
            index = (index + 1) % Size;
        }
        // If we reach here, it means we have searched through the entire table
        return false; // Entry not found
    }

    int GetInsertIndex(const std::string& entryString)
    {
        int index = GetIndex(entryString);
        while(true)
        {
            if(m_Entries[index].Status == "never used" || m_Entries[index].Status == "tombstone")
            {
                return index; // Found an empty slot or a tombstone
            }
            index = (index + 1) % Size; // Wrap around the table
        }
        return -1;
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
        std::string entryString = token.substr(1); // Get the entry name after 'A' or 'D'
        if(token[0] == 'A')
        {
            hashTable.Add(entryString); // Add the entry to the hash table
        }
        else if (token[0] == 'D')
        {
            hashTable.Delete(entryString); // Delete the entry from the hash table
        }
    }

    hashTable.Print();
}