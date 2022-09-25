import hashlib

path = "/home/menonsandu/Downloads/word-list-7-letters.txt"
# Read the contents line by line until the end of the file
with open(path, 'r') as f:
    for word in f:
        word = word.rstrip()
        word = word.lower()
        new_word = word + "0fcd9a8c52fe"
        res = hashlib.md5(new_word.encode())
        if res.hexdigest() == "7fe95c5f01654a01542f6766395dc5c8":
            print(word)
            break 
    