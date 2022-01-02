import  random
from nltk.parse.chart import LeafEdge
from newspaper import Article
import string
import nltk
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrices.pairwise import cosine_similarity
import numpy np
import warning
warnings.filterwarnings('ignore')

# download the punkt package
nltk.download('punkt', quiet = True)

# get the article

article = Article('link of the page')
article.download()
article.parse()
article.nlp()
corpous = article.text

test = corpous
sentence_list = nltk.sent_tokenize(test) # a list of sentences

# a function to return a random greeting message to a user
def greet_res(text):
    text  text.lower()

    # bot's greeting response
    bot_greeting = ['hello', 'hi', 'hey', 'wassup']
    # user greeting response
    user_greeting = ['hello', 'hii', 'hi', 'wassup', 'helo', 'hellooo']

    for word in text.split():
        if word in user_greeting:
            return random.choice(bot_greeting)

# function to sort the Index
def index_sort(list_var):
    length = len(list_var)
    list_index = list(range(0, length))
    
    x = list_var
    for i in range(length):
        for j in range(length):
            if x[list_index[i]] > x[list_index[j]]:
                temp = list_index[i]
                list_index[i] = list_index[j]
                list_index[j] = temp
    return list_index
 
# funtion for bot response
def bot_res(user_input):
    user_input = user_input.lower()
    sentence_list.append(user_input)
    bot_res = ''
    cm = CountVectorizer().fit_transform(sentence_list)
    s_score = cosine_similarity(cm[-1], cm)
    s_score_list = s_score.flatten()
    index = index_sort(s_score_list)
    index = index[1:]
    res_flag = 0

    j = 0
    for i in range(len(index)):
        if s_score_list[index[i]] > 0.0:
            bot_res = bot_res+' '+sentence_list[index[i]]
            res_flag = 1
            j = j + 1
        if j 

# start the chat
print('Covid Helpline: I am here to help you with the information regarding corona virus. If you want to exit type by')

exit_list = ['bye', 'exit', 'byee', 'break', 'quit']
while(True):
    user_input = input()
    if user_input.lower() in exit_list:
        print('Bot: Thanks for your queries. See you later.')
        break
    else:
        if greet_res(user_input) != None:
            print('Bot: '+greet_res(user_input))
        else:
            print('Bot: '+bot_res(user_input))

