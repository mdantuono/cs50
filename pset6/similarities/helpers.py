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

    if n > len(a) or n > len(b):
        return []
    # extract substrings
    # Iterate through a and b and append all substrings of length n to lists
    aSubstrings = []
    for i in range(len(a) - n + 1):
        aSubstrings.append(a[i:i + n])
    bSubstrings = []
    for j in range(len(b) - n + 1):
        bSubstrings.append(b[j:j + n])

    return set(aSubstrings) & set(bSubstrings)

# Check for duplicates
# def checkDup(tempList):
#     dup_items = set()
#     nonDuplicates = []
#     for x in tempList:
#         if x not in dup_items:
#             nonDuplicates.append(x)
#             dup_items.add(x)
#     return nonDuplicates