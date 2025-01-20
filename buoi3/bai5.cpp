#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undo_stack;
    stack<string> redo_stack;

public:
    TextEditor() : text("") {}

    void type_text(const string& new_text) {
        undo_stack.push(text);
        text += new_text;
        while (!redo_stack.empty()) {
            redo_stack.pop();
        }
        cout << "Text after typing: " << text << endl;
        display_all();
    }

    void undo() {
        if (!undo_stack.empty()) {
            redo_stack.push(text);
            text = undo_stack.top();
            undo_stack.pop();
            cout << "Text after undo: " << text << endl;
            display_all();
        } else {
            cout << "Nothing to undo" << endl;
        }
    }

    void redo() {
        if (!redo_stack.empty()) {
            undo_stack.push(text);
            text = redo_stack.top();
            redo_stack.pop();
            cout << "Redo: " << text << endl;
            display_all();
        } else {
            cout << "Nothing to redo" << endl;
        }
    }

    void display_all() {
        cout << "display all: " << text << endl << endl;
    }
};

int main() {
    TextEditor editor;
    editor.type_text("hello");
    editor.type_text("world");
    editor.undo();
    editor.undo();
    editor.redo();

    return 0;
}