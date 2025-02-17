#include <iostream>
#include "linklist.h"

int main() {
    LinkedList llist;

    // Add node
    llist.insert_at_beginning(10);
    llist.insert_at_end(20);
    llist.insert_at_beginning(5);
    llist.insert_at_end(30);

    // Print list
    llist.traverse();

    // Find node
    std::cout << "Position of 20: " << llist.search(20) << std::endl;

    // Delete node
    llist.delete_node(20);
    std::cout << "After deleting 20:" << std::endl;
    llist.traverse();

    return 0;
}