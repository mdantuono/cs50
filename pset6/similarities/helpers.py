from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""
    # Until a \n
    aLines = a.split('\n')
    bLines = b.split('\n')
    return list(set(aLines).intersection(bLines))

def sentences(a, b):
    """Return sentences in both a and b"""
    # Until a '.'
    aSentences = sent_tokenize(a)
    bSentences = sent_tokenize(b)
    return list(set(aSentences).intersection(bSentences))

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    # extract substrings
    aSubstrings = []
    bSubstrings = []
    dup_items = set()
    matchingSubstrings = []

    if n > len(a) or n > len(b):
        return []

    # Iterate through a and b and append all substrings of length n to lists
    for i in range(len(a)):
        aSubstrings.append(a[i:i + n])
    for i in range(len(b)):
        bSubstrings.append(b[i:i + n])

    tempSubstrings = list(set(aSubstrings).intersection(bSubstrings))

    # Check for duplicates
    for x in tempSubstrings:
        if x not in dup_items:
            matchingSubstrings.append(x)
            dup_items.add(x)

    return matchingSubstrings