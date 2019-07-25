import cs50
import sys

def main():
    
    # check for two argv
    if len(sys.argv) != 2:
        usage()
    
    # name input keyword
    keyword = sys.argv[1]
    
    # see if only alphabetical
    if not keyword.isalpha():
        usage()
    
    # get string
    print("plaintext: ", end="")
    s = cs50.get_string()
    
    answer = encipher(s, keyword)
    print("ciphertext: " + answer)
    
    


def encipher(plaintext, keyword):
    
    # get length
    length = len(keyword)
    
    # counter
    j = 0
    
    enciphered = []
    
    for i in plaintext:
        if i.isalpha():
            key = ord(keyword[j % length].lower()) - 97
            j += 1
            enciphered.append(ceasar(i, key))
        else:
            enciphered.append(i)
              
    
    return("".join(enciphered))     
 
    
    
    
def ceasar(character, key):
    if character.isupper():
        return chr(((ord(character) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(character) - 97 + key) % 26) + 97)
    
def usage():
    print("Usage: vigenere <keyword>")
    exit(1)
    

if __name__ == "__main__":
    main()