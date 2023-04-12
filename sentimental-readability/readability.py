import cs50


def count_letters(text):  # function to count letters
    letters = 0
    for i in range(len(text)):
        if (text[i].islower()) or (text[i].isupper()):
            letters = letters + 1
    return letters


def count_words(text):  # function to count words
    words = 1
    for j in range(len(text)):
        if (text[j].isspace()):
            words = words + 1
    return words


def count_sentences(text):  # function to count sentences
    sentences = 0
    for v in range(len(text)):
        if (text[v] == "!" or text[v] == "?" or text[v] == "."):
            sentences = sentences + 1
    return sentences


input_text = cs50.get_string("Text: ")  # input prompt

#  function calls
letters = count_letters(input_text)
words = count_words(input_text)
sentences = count_sentences(input_text)

#  print for sanity check
print(letters, "letters")
print(words, "words")
print(sentences, "sentences")

#  formula and index
L = float(letters) / words * 100
S = float(sentences) / words * 100
index = 0.0588 * L - 0.296 * S - 15.8

final_index = round(index)

#  conditionals for the answers
if (index < 1):
    print("Before Grade 1")

elif (final_index >= 16):
    print("Grade 16+")

else:
    print("Grade", final_index)