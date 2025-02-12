import os

def generate_cpp_files(start: int, end: int, directory: str = "cpp_files"):
    # Ensure the directory exists
    os.makedirs(directory, exist_ok=True)
    
    # Template for C++ file
    cpp_template = """#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
    return 0;
}
"""
    
    # Generate files
    for i in range(start, end + 1):
        filename = f"{i:02d}_LeetCode.cpp"
        filepath = os.path.join(directory, filename)
        
        with open(filepath, "w") as f:
            f.write(cpp_template)
        
        print(f"Created: {filepath}")

# Generate files from 01 to 141
generate_cpp_files(1, 141)
