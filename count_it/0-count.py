#!/usr/bin/python3
"""count_words"""

import requests


def count_words(subreddit, word_list, after=None):
    """Recursive function to get count of words"""
    if after is None:
        url = 'https://www.reddit.com/r/' + subreddit + '/hot.json'
    else:
        url = 'https://www.reddit.com/r/' + subreddit\
            + '/hot.json?after=' + after
    headers = {'User-Agent': 'Python3'}
    response = requests.get(url, headers=headers)
    count = {}
    if response.status_code == 200:
        for word in word_list:
            word = word.lower()
            if word not in count:
                count[word] = 0
            for post in response.json().get('data').get('children'):
                title = post.get('data').get('title').lower().split(' ')
                count[word] += title.count(word)
            after = response.json().get('data').get('after')
        if after is None:
            for key, value in sorted(count.items(), key=lambda x: (-x[1],
                                                                   x[0])):
                if value != 0:
                    print(f"{key}: {value}")
            return
        return count_words(subreddit, word_list, after, count)
    else:
        return []
