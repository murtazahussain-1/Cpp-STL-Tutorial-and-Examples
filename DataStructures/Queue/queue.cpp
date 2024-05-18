#include <iostream>
#include <queue>    // For STL implementation

#define CUSTOM_IMPLEMENTATION 1

#if CUSTOM_IMPLEMENTATION
class Node
{
    uint32_t data;
    Node *addr_next_node;
    
public:

    Node(const uint32_t &d = 0)
    {
        data = d;
        addr_next_node = nullptr;
    }

    // Getters
    uint32_t get_data()
    {
        return data;
    }
    
    Node* get_addr_next_node()
    {
        return addr_next_node;
    }
    
    // Setters
    void set_data(uint32_t dat)
    {
        data = dat;
    }
    
    void set_next_node_addr(Node *next_ptr)
    {
        addr_next_node = next_ptr;
    }
};

class Queue
{
    Node *first;
    uint32_t total_nodes;
    
public:

    Queue(Node *ptr = nullptr)
    {
        first = ptr;
        total_nodes = 0;
    }
    
    void insert(uint32_t data)
    {
        Node *obj_new = new Node(data);
        
        if (first)
        {
            Node *temp = first;
            
            while (temp->get_addr_next_node())
            {
                temp = temp->get_addr_next_node();
            }
            
            temp->set_next_node_addr(obj_new);
            total_nodes++;
            
        }
        else    // queue has not been created
        {
            first = obj_new;
            total_nodes++;
        }
        
    }
    
    uint32_t pop()
    {
        Node *temp = first;
        uint32_t data = first -> get_data();
        first = first -> get_addr_next_node();
        delete temp;
        
        return data;
    }
    
    void print_queue()
    {
        std::cout << "Printing Queue" << std::endl;
        Node *temp = first;
        
        while (temp)
        {
            std::cout << temp->get_data() << std::endl;
            temp = temp -> get_addr_next_node();
        }
    }
    
    uint32_t get_count()
    {
        return total_nodes;
    }    
};

int main()
{
    Queue q1;
    
    q1.insert(1);
    q1.insert(2);    
    q1.insert(3);
    q1.insert(4);
    q1.insert(5);
    
    q1.print_queue();
    
    std::cout << "Total nodes are: " << q1.get_count() << std::endl;

    std::cout << "pop = " << q1.pop() << std::endl;
    q1.print_queue();
    
}
#endif
