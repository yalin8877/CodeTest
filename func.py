from sys import argv
import random
from urllib import urlopen

word_url="http://learncodethehardway.org/words.txt"
words=[]
phrases={
    "class ###(###):" :
        "Make a class named ### that is-a ###.",
    "class ###(object):\n\tdef __init__(self, ***)" :
        "class ### has-a __init__ that takes self and *** parameters.",
    "class ###(object):\n\tdef ***(self, @@@)":
        "class ### has-a function named *** that takes self and @@@ parameters.",
    "*** = ###()":
        "Set *** to an instance of class ###.",
    "***.***(@@@)":
        "From *** get the *** function, and call it with parameters self, @@@.",
    "***.*** = '***'":
        "From *** get the *** attribute and set it to '***'."
    }

def convert(x,y):
    


try:
    for word in urlopen(word_url).readline():
        words.append(word)

    while True:
        xs=phrases.keys()
        random.shuffile(xs)
        for x in xs:
            choosed=phrases[random.randint(0,len(phrases))]
            x=xs[choosed]
            x,y = convert(x,phrases[x])
            print x
            rawinput(">")
            print y,"\n\n"
except EOFError:
    print "\nBye"
