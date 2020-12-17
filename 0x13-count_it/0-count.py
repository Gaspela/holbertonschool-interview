#!/usr/bin/python3
"""
Count it!
"""
import operator
import requests


def count_words(subreddit, word_list, hot_list=[], init=0, after="null"):
    """
    Recursive method
    """

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    agent = {"User-Agent": "linux:1:v2.1 (by /u/heimer_r)"}
    load = {"limit": "100", "after": after}
    hot = requests.get(url, headers=agent,
                       params=load, allow_redirects=False)

    if hot.status_code == 200:
        posts = hot.json().get("data").get("children")
        hot_list += [post.get("data").get("title") for post in posts]
        after = hot.json().get("data").get("after")

        if after is not None:
            count_words(subreddit, word_list, hot_list, 1, after)
        if init == 0:
            hot_str = " ".join(hot_list)
            hot_words = hot_str.split(" ")
            word_list_low = sorted(word_list)
            reddit_t = []
            for word in word_list_low:
                num = len(
                    list(
                        filter(
                            lambda hot_w: hot_w.lower() == word.lower(),
                            hot_words)))
                if num != 0:
                    reddit_t.append([word, num])
            if len(reddit_t) != 0:
                i = 0
                while i < len(reddit_t) - 1:
                    if reddit_t[i + 1][0] is not None and reddit_t[i][0]\
                            == reddit_t[i + 1][0]:
                        reddit_t[i][1] += reddit_t[i + 1][1]
                        reddit_t.pop(i + 1)
                        reddit_t.append([None, None])
                        i -= 1
                    i += 1
                r = list(filter(lambda x: x != [None, None], reddit_t))
                r_sorted = sorted(r, key=lambda x: (x[1]), reverse=True)
                for i in r_sorted:
                    print(*i, sep=": ")
